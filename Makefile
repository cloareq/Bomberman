##
## Makefile for hello in /home/ledu/projet/cpp_bomberman/Menu
##
## Made by ledu
## Login   <ledu@epitech.net>
##
## Started on  Tue May 20 09:47:31 2014 ledu
##

CC      =       g++ -o

RM      =       rm -f

NAME    =       bomberman

SRCS    =       source/main.cpp \
                source/Menu.cpp \
                source/GameEngine.cpp \
                source/AObject.cpp \
                source/Cube.cpp \
                source/Bomb.cpp \
                source/Player.cpp \
                source/Loading.cpp \
                source/Score.cpp \
                source/Wall.cpp \
                source/Ground.cpp \
                source/Settings.cpp \
                source/ADisplay.cpp \
                source/LoadGame.cpp \
                source/Manager.cpp \
                source/lunch.cpp \
                source/NewGame.cpp \
                source/ParsMap.cpp \
                source/ParsMapSecond.cpp \
                source/error_end.cpp \
                source/geometry.cpp \
                source/Music.cpp \
                source/Thread.cpp \
                source/Fire.cpp \
                source/Blife.cpp \
                source/Pp1.cpp \
                source/Pp2.cpp \
                source/Bpowerfull.cpp \
                source/SaveMap.cpp \
                source/Intro.cpp \
                source/IA.cpp \
                source/Ending.cpp

OBJS    =       $(SRCS:.cpp=.o)

OPTI    =       -msse -msse2 -msse3 -mmmx -m3dnow #-O3

CXXFLAGS	+=	-I./include -I./include/SDL -L./libs/ -ldl -lGLEW -lgdl_gl -lGL -ldl -lrt -lfbxsdk -lSDL2 -lpthread -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lsfeMovie -lswresample

CXXFLAGS	+=	-lm -ldl -Wall  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


all     :       $(NAME)

$(NAME) :       $(OBJS)
				$(CC) $(NAME) $(OBJS) $(CXXFLAGS) $(OPTI) -g -g3

clean   :
				$(RM) $(OBJS)

fclean  :       clean
				$(RM) $(NAME)

re      :       fclean all
