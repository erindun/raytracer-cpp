CXX=g++
CFLAGS=-Wall -std=c++11
SRC=${wildcard *.cpp}
OBJ=${patsubst %.cpp,build/%.o,${SRC}}
TARGET=raytrace

all: ${OBJ}
	${CXX} ${CFLAGS} ${OBJ} -o ${TARGET}

build/%.o: %.cpp
	mkdir -p ${dir $@}
	${CXX} -o $@ $< -c ${CFLAGS}

clean:
		rm -rf ${TARGET} build output.ppm

run: all
	./${TARGET}
