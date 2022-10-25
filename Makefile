TARGET = typewriter
SRC = typewriter.c
CC = gcc
INSTALL_DIR = /usr/local/bin

${TARGET}: ${SRC}
	gcc -o ${TARGET} ${SRC}

install:
	cp ${TARGET} ${INSTALL_DIR}

clean:
	rm -f *.o ${TARGET}
