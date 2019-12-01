#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "Board.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "Objects.h"

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void workingOfBullets();
void workingOfPlayer();
void workingOfScorpion();
void workingOfCentipede();
void workingOfMushroom();
void workingOfSpider();
void fileHandling();


Objects board;


/*
 * Main Canvas drawing function.
 * */
Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	//DrawSquare( 400 , 20 ,40,colors[RED]);
	//Mushroom
	//DrawSquare( 250 , 250 ,20,colors[GREEN]);
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)

	//DrawLine( 530 , 50 ,  550 , 480 , 20 , colors[ORANGE] );


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);

	////////////Displaying high-score,real time score etc///////////////////
	//DrawLine(10, 610, 1010,  610, 3, colors[45]);

	//DrawString( 40, 615, "Score : ", colors[45]);
	/////////////////////////////////////////////////////////////////////////


	//////////////////loading game/////////////////////////
	if(board.isGameLoading() == true) {

		if(board.getLoadingCounter() < 950) {
			DrawString( 400, 300 , "Loading Centipede..." , colors[45]);

			for(int i=50 ; i<board.getLoadingCounter() ; i++)
			DrawSquare(i,250,20,colors[45]);

			board.setLoadingCounter(board.getLoadingCounter()+5);
		}

		if(board.getLoadingCounter() >= 950) {
			DrawString( 370, 300 , "PRESS ENTER TO PLAY" , colors[45]);
			for(int i=50 ; i<board.getLoadingCounter() ; i++)
			DrawSquare(i,250,20,colors[45]);
		}

		DrawString( 800, 100 , "Abdullah Naveed" , colors[45]);
		DrawString( 800, 70 , "Centipede Game" , colors[45]);
	}
	///////////////////////////////////////////

	//////next level/////
	if ( (board.getDestroyHead(0) == 1) && (board.getDestroyHead(1) == 1) ) {

		board.setPlayGame(false);
		board.player.setCollision(false);
		board.setGameLoading(true);

		board.setLevelUp(true);
		board.nextLevel();
	}
	////////////////////////////////////

	//////////////////Playing game/////////////////////////
	if(board.isPlayGame() == true) {



			//drawing objects through polymorphism/////
			for(int i=0 ; i<4 ; i++) {
				board.arrayOfObjects[i]->draw();
			}
			/////////////////////////////////////////

			workingOfSpider();
			workingOfMushroom();
			workingOfScorpion();
			workingOfCentipede();
			workingOfPlayer();
			workingOfBullets();
	}


	fileHandling();

	glutSwapBuffers(); // do not modify this line..

}

void workingOfMushroom() {

	//////drawing mushrooms
	for(int i=0 ; i<board.getSizeOfMushrooms() ; i++)
	board.mushroom[i].draw();


	for (int i=0 ; i<board.centipede[0].getSizeOfBody() ; i++) {	//1st centipede adding mushroom

		bool check = board.centipede[0].getCollisionStatusToDrawMushroom(i);
		if( (check == true) && (board.centipede[0].getCheckingCollisionXY(i)==0) ) {
			board.addMushroom(board.centipede[0].getCollisionX(i) , board.centipede[0].getCollisionY(i) );
			board.centipede[0].setCheckingCollisionXY(i);
			board.info.setScore(board.info.getScore() + 10);
		}
	}

	if(board.centipede[0].isHitCenter() == true) {	//2nd centipede adding mushroom
		for (int i=0 ; i<board.centipede[1].getSizeOfBody() ; i++) {

			bool check1 = board.centipede[1].getCollisionStatusToDrawMushroom(i);
			if( (check1 == true) && (board.centipede[1].getCheckingCollisionXY(i)==0) ) {
				board.addMushroom(board.centipede[1].getCollisionX(i) , board.centipede[1].getCollisionY(i) );
				board.centipede[1].setCheckingCollisionXY(i);
				board.info.setScore(board.info.getScore() + 10);
			}
		}
	}
	//////////////////////////////

	//////next level/////
	if ( (board.getDestroyHead(0) == 1) && (board.getDestroyHead(1) == 1) ) {

		board.setPlayGame(false);
		board.player.setCollision(false);
		board.setGameLoading(true);

		board.setLevelUp(true);
		board.nextLevel();
	}
	////////////////////////////////////
}

void workingOfSpider() {

	//////drawing Spider
	board.spider.move(0,0);
	if(board.spider.isCollision() == true) {

		if(board.spider.getY() <= 100)
			board.info.setScore(board.info.getScore() + 900);


		if(board.spider.getY() >= 100 && board.spider.getY() <= 150)

			board.info.setScore(board.info.getScore() + 600);

		if(board.spider.getY() >= 150)
			board.info.setScore(board.info.getScore() + 300);

		board.newSpider();
	}

}

void workingOfBullets() {

	//////if firing///////////////
	if(board.player.isFired() == true) {

		while( (board.player.getBulletY()) < 640) { ///checking if bullet left the screen from top

			board.player.drawBullet(); //drawing bullet

			board.player.setBulletY((board.player.getBulletY())+1); //increasing y-axis of bullet

			/////checking if bullets hit the mushrooms
			for(int i=0 ; i<board.getSizeOfMushrooms() ; i++) {
				board.mushroom[i].checkCollision(board.player.getBulletX(),board.player.getBulletY());
			}
			//////////////////////////////


			/////checking if bullets hit the centipede
			board.centipede[0].checkCollisionOfCentipede(board.player.getBulletX(),board.player.getBulletY());
			board.centipede[1].checkCollisionOfCentipede(board.player.getBulletX(),board.player.getBulletY());
			if(board.centipede[0].getHeadCollision() == true) {

				board.info.setScore(board.info.getScore() + 100);

				if(board.centipede[0].isHeadCollisionAfterBody() == true) {
					board.setDestroyHead(0,1);
				}
				board.centipede[0].setHeadCollision(false);
			}
			if(board.centipede[1].getHeadCollision() == true) {
				board.info.setScore(board.info.getScore() + 100);
				if(board.centipede[1].isHeadCollisionAfterBody() == true) {
					board.setDestroyHead(1,1);
				}
				board.centipede[1].setHeadCollision(false);
			}


			//////////////////////////////

			/////checking if bullets hit the Spider
			board.spider.checkCollision(board.player.getBulletX(),board.player.getBulletY());
			//////////////////////////////

			cout<<"Bullet Fired"<<endl;

			if( (board.player.getBulletY()) >= 640) { //if bullet leaves the screen

				board.player.setBulletX(board.player.getX()); //new bullet with player
				board.player.setBulletY(board.player.getY());
				board.player.setFired(false); //to fire again
				cout<<"BULLED FIRED COMPLETE"<<endl;
				break;
			}
		}
	}

	//////next level/////
	if ( (board.getDestroyHead(0) == 1) && (board.getDestroyHead(1) == 1) ) {

		board.setPlayGame(false);
		board.player.setCollision(false);
		board.setGameLoading(true);

		board.setLevelUp(true);
		board.nextLevel();
	}
	////////////////////////////////////
}

void workingOfPlayer() {

	//////drawing & moving player////////////

	board.player.checkCollision(board.centipede[0].getHeadX(),board.centipede[0].getHeadY());
	board.player.checkCollision(board.centipede[1].getHeadX(),board.centipede[1].getHeadY());
	board.player.checkCollision(board.spider.getX(),board.spider.getY());
	board.player.checkCollision(board.scorpion.getMushroomX(),board.scorpion.getMushroomY());

	if(board.player.isCollision() == true) {

		{
			board.info.setNumberOfLives(board.info.getNumberOfLives()-1);
			board.player.setCollision(false);
			delete[]board.centipede;
			board.centipede = new Centipede[2];
			board.spider.setX(30);
			board.spider.setY(30);
			board.scorpion.setMushroomX(board.scorpion.getX());
			board.scorpion.setMushroomY(board.scorpion.getY());
			board.refreshMushrooms(board.getSizeOfMushrooms());
		}

		if(board.info.getNumberOfLives() < 1) {
			board.setGameOver(true);
			board.setPlayGame(false);

			DrawString( 410, 350 , "GAME OVER" , colors[45]);
			DrawString( 370, 300 , "PRESS R TO REPLAY" , colors[45]);
		}
	}

	if(board.player.getMovement() == 'u') {
		board.player.setY( board.player.getY() + 1);
		if(board.player.getY() > 200) {
			board.player.setY( 200 );
		}
	}
	else if(board.player.getMovement() == 'd') {
		board.player.setY( board.player.getY() - 1);
		if(board.player.getY() <= 10) {
			board.player.setY( 10 );
		}
	}
	else if(board.player.getMovement() == 'l') {
		board.player.setX(board.player.getX()-1);
		if(board.player.getX() <= 10) {
			board.player.setX( 10 );
		}
	}
	else if(board.player.getMovement() == 'r') {
		board.player.setX(board.player.getX()+1);
		if(board.player.getX() > 1010) {
			board.player.setX( 1010 );
		}
	}

}

void workingOfScorpion() {

	////moving scorpion///
	board.scorpion.move(0,0);

	//////////////////Drawing and moving scorpian////
	for (int i=0 ; i<board.getSizeOfMushrooms() ; i++) {	//1st centipede adding mushroom

		board.scorpion.checkCollision(board.mushroom[i].getX(),board.mushroom[i].getY());
	}

}

void workingOfCentipede() {

	//////drawing & moving centipede
	board.centipede[0].draw();
	board.centipede[1].draw();
	board.centipede[0].moveCentipede(0,0);
	board.centipede[1].moveCentipede(0,0);

	for(int i=0 ; i<board.getSizeOfMushrooms() ; i++) { //when centipede collide with mushroom
		if( (  (board.centipede[0].getHeadX() >= board.mushroom[i].getX()-14)   &&  (board.centipede[0].getHeadX() <= board.mushroom[i].getX()+1) ) && (board.centipede[0].getHeadY() >= board.mushroom[i].getY()-10)   &&  (board.centipede[0].getHeadY() <= board.mushroom[i].getY()+10) )  {

			if(board.centipede[0].isCheckStatus() == true) {
				board.centipede[0].setCheckStatus(false);
			}
			else if(board.centipede[0].isCheckStatus() == false) {
					board.centipede[0].setCheckStatus(true);
			}

			if(board.centipede[0].isHitCenter() == true) {
				if(board.centipede[0].isMovingDown() == true)
				board.centipede[0].setHeadY(board.centipede[0].getHeadY()-15);
				else if(board.centipede[0].isMovingDown() == false)
				board.centipede[0].setHeadY(board.centipede[0].getHeadY()+15);
			}
		}
	}

	for(int i=0 ; i<board.getSizeOfMushrooms() ; i++) { //when centipede collide with mushroom
		if( (  (board.centipede[1].getHeadX() >= board.mushroom[i].getX()-14)   &&  (board.centipede[1].getHeadX() <= board.mushroom[i].getX()+1) ) && (board.centipede[1].getHeadY() >= board.mushroom[i].getY()-10)   &&  (board.centipede[1].getHeadY() <= board.mushroom[i].getY()+10) )  {

			if(board.centipede[1].isCheckStatus() == true) {
				board.centipede[1].setCheckStatus(false);
			}
			else if(board.centipede[1].isCheckStatus() == false) {
					board.centipede[1].setCheckStatus(true);
			}

			if(board.centipede[0].isHitCenter() == true) {
				if(board.centipede[1].isMovingDown() == true)
				board.centipede[1].setHeadY(board.centipede[1].getHeadY()-15);
				else if(board.centipede[1].isMovingDown() == false)
				board.centipede[1].setHeadY(board.centipede[1].getHeadY()+15);
			}
		}
	}

	//////////////////////////////
}

void fileHandling() {

	//////////////////pause game/////////////////////////
	if(board.isPauseGame() == true) {
		board.setPlayGame(false);
		board.setGameLoading(false);
		DrawString( 410, 350 , "GAME PAUSED" , colors[45]);
		DrawString( 370, 300 , "PRESS ENTER TO PLAY" , colors[45]);
	}
	///////////////////////////////////////////

	//////////////////game over check/////////////////////////
	if(board.isGameOver() == true) {
		board.setPlayGame(false);
		board.setPauseGame(false);
		board.setGameLoading(false);
		DrawString( 410, 350 , "GAME OVER" , colors[45]);
		DrawString( 370, 300 , "PRESS R TO REPLAY" , colors[45]);
	}
	///////////////////////////////////////////
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//board.player.setX(board.player.getX()-5);
		board.player.setMovement('l');

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//board.player.setX(board.player.getX()+5);
		board.player.setMovement('r');

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//board.player.setY( board.player.getY() + 5);
		board.player.setMovement('u');
	}//

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//board.player.setY( board.player.getY() - 5);
		board.player.setMovement('d');
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		board.info.saveHighScore();
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if (key == 'r' || key == 'R') //Key for placing the bomb
			{
		//do something if r is pressed
		cout << "r pressed" << endl;
		board.setPauseGame(false);
		board.setGameOver(false);
		board.setPlayGame(false);
		board.player.setCollision(false);
		board.setGameLoading(true);
		delete[]board.centipede;
		board.centipede = new Centipede[2];
		board.refreshMushrooms(20);
		board.spider.setX(30);
		board.spider.setY(30);
		board.info.setNumberOfLives(1);
		board.info.saveHighScore();
		board.info.setScore(0);

	}

	if (key == 'p' || key == 'P') //Key for placing the bomb
			{
		//do something if p is pressed
		cout << "p pressed" << endl;
		board.setPauseGame(true);
		board.setGameLoading(false);
		board.setPlayGame(false);

	}
	if (key == ' ') //Key for placing the bomb
				{
			//do something if b is pressed
			cout << "Space pressed" << endl;

			//player firing/////
			board.player.setFired(true);
			board.player.setBulletX(board.player.getX());
			board.player.setBulletY(board.player.getY());
			//////////

		}
	if (key == 13) /* Enter key ASCII*/  {		// for entering the game
		board.setPauseGame(false);
		board.setGameLoading(false);
		board.setPlayGame(true);

		cout<<"Enter Pressed\n";
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;

	///player movement & firing
	board.player.setMouse(true);
	board.player.move(x,y);
	board.player.setFired(true);
	//////////////////////////////

	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	////// player firing
	cout <<"Mouse Moved : " << x << " " << y << endl;
	board.player.setMouse(true);
	board.player.move(x,y);
	//////////////////////////////

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
		/////player firing
		board.player.setFired(true);
		//////////////////////////////

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	srand(time(NULL));

	int width = 1020, height = 640; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	board.info.saveHighScore();
	return 1;
}
#endif /* AsteroidS_CPP_ */
