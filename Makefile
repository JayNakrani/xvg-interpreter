
all : xvg-interp

CC = g++
FLAGS = -O3 

xvg-interp : 
	$(CC) $(FLAGS) -o bin/xvg-interp app/xvg-interp.cpp -lgraph

clean :
	rm bin/xvg-interp
