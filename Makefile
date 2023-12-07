INCLUDE = -I.

all: build

build:
	gcc -O3 -o main.exe main.c function.c gen_wav.c through_lpf.c $(INCLUDE) -lm

test:
	./main.exe

clean:
	rm -f  *.txt

.PHONY: build test clean