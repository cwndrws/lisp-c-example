CC=cc
C_SOURCE=lispadd.c
LISP_BUILD=build.lisp
INCLUDE=/usr/local/include
LIBRARIES=-L/usr/local/lib -L.
OUTPUT=lispadd
CFLAGS=-I$(INCLUDE) $(LIBRARIES) -ladd -lecl

all: lispadd

libadd.a:
	ecl -load $(LISP_BUILD)

lispadd: libadd.a
	$(CC) $(C_SOURCE) $(CFLAGS) -o $(OUTPUT)

clean:
	rm -f libadd.a
	rm -f add.o
	rm -f lispadd
	rm -f add.fas
