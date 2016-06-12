
APP      = LightsOut

CC       = g++
CPPFLAGS = `wx-config --libs` `wx-config --cxxflags` -g

RM      = rm
RMFLAGS = -f

OBJS = \
lib/Game.o \
lib/GameWindow.o \
lib/GameCore.o \
lib/Grid.o \
lib/GridElement.o \
lib/Main.o \
$(APP).o \

.PHONY: build all clean

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(APP) $(OBJS)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

