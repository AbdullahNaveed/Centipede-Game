CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		Scorpion.o Spider.o Centipede.o LazySeg.o MagicSeg.o Segment.o Objects.o GunFire.o Player.o MoveableObject.o Mushroom.o ScoreBoard.o GameObject.o Position.o Board.o util.o game.o

LIBS = -L/usr/X11R6/lib  -lglut -lGLU -lGL -lX11 -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
