#sample Makefile for using OpenGL of Red Hat Linux 7.x
#CS 420, Tong Yu, Fall 2002

PROG	= roses
CFLAGS	= -w -s -O2 -ansi -DSHM
XLIBS	= -lX11 -lXext -lXmu -lXext -lXmu -lXt -lXi -lSM -lICE
LIBS	= -lglut -lGLU -lGL
INCLS	= -I/usr/X11R/include -I/share/mesa/include
LIBDIR	= -L/usr/X11/lib -L/usr/X11R6/lib 
#source codes
SRCS = rectangle.cpp canvas.cpp main.cpp $(PROG).cpp
#substitute .cpp by .o to obtain object filenames
OBJS = $(SRCS:.cpp=.o)

#$< evaluates to the target's dependencies, 
#$@ evaluates to the target

$(PROG): $(OBJS)
	g++ -o $@ $(OBJS)  $(LIBDIR) $(LIBS) $(XLIBS)

$(OBJS): 
	g++ -c  $*.cpp $(INCLS) 

clean:
	rm $(OBJS) 

