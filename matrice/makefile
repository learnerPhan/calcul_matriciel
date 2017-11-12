CXX = g++
CFLAGS = -c -g -Wall
LDFLAGS =

EXEC = main
SRC =  main.cpp matrice.cpp vecteur.cpp
OBJS = main.o matrice.o vecteur.o
#OBJS = $(SRC:.cpp=.o)

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
#	$(CXX) $(LDFLAGS) -o $@ $(OBJS)
#$@ : output file
#$^ : the filenames of all prerequisites, separated by spaces.
# g++ -o main main.o matrice.o

%.o : %.cpp
	$(CXX) $(CFLAGS) -o $@ $<

#$< : the filename of the first prerequisite
# g++ -c -o main.o main.cpp
# g++ -c -o matrice.cpp matrice.cpp

clean:
	rm *.o main
