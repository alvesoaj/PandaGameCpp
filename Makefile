CXXFLAGS =		-fPIC -O2 -g -Wall -fmessage-length=0

OBJS =			src/Main.cpp

INCLUDES =		-I/usr/include/python2.6/ -I/usr/include/panda3d

LIBS =			-lp3framework -lpanda -lpandafx -lpandaexpress -lp3dtoolconfig -lp3dtool -lp3pystub -lp3direct

LIB_FOLDERS = 	-L/usr/lib64/panda3d

TARGET =		bin/Main.o

$(TARGET):	$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(INCLUDES) $(LIBS) $(LIB_FOLDERS)

all:	$(TARGET)

clean:
	rm -rf $(TARGET)