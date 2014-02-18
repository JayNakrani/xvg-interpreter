
all : xvg-interp

CC = g++
FLAGS = -O3 -lgraph
OUT_DIR= ./bin

xvg-interp : 
	$(CC) -o $(OUT_DIR)/xvg-interp app/xvg-interp.cpp $(FLAGS)

clean :
	rm $(OUT_DIR)/xvg-interp
