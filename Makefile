TARGET = typewriter
SRC = typewriter.c
CC =gcc

${TARGET}: ${SRC}
	gcc -o ${TARGET} ${SRC}

clean:
	rm -f *.o ${TARGET}
