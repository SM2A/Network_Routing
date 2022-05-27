SRC_DIR = Source

COMPILER = g++
VERSION = -std=c++11
CC = ${COMPILER} ${VERSION}

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp, wildcard $(SRC_DIR)/*.h)

all: clean main.out

main.out: $(SRC_FILES_C)
	${CC} ${SRC_DIR}/*.cpp -o main.out

clean:
	rm -f *.out