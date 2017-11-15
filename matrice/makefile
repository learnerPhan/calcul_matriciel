CXX = g++
CFLAGS = -std=c++11 -c -g -Wall
LDFLAGS =

EXEC = main
SRC =  main.cpp matrice.cpp vecteur.cpp identityMatrice.cpp PLUdecompo.cpp

#OBJS = main.o matrice.o vecteur.o identityMatrice.o calcul_matrice.o
OBJS = $(SRC:.cpp=.o)

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
