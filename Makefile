TARGET = test
DEPS =
CFLAGS = -g -std=c++11

all: ${TARGET}

test: test.cpp ${DEPS}
	g++ -o test test.cpp ${CFLAGS}

clean:
	rm -f ${TARGET}
	rm -rf *.dSYM 
