INCLUDE = -I.

all: build

build:
	gcc -O3 -o 123.exe 123.c function.c $(INCLUDE) -lm

test:
	./123.exe

clean:
	rm -f  123.exe

.PHONY: build test clean