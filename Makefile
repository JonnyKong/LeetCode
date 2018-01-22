TARGET = test
DEPS =
CFLAGS = -g		# Generate debugging files

all: ${TARGET}

test: test.cpp ${DEPS}
	g++ -o test test.cpp ${CFLAGS}

clean:
	rm -f ${TARGET}
	rm -rf *.dSYM 
