CC = gcc
CCFLAGS = -Wall -I. -lm 
CFLAGS = -Wall -I. -lm
TARGETS = manchester bits decode

.PHONY: all clean wipe

all: $(TARGETS)

manchester: manchester.o
	$(CC) -o $@ $^ $(CCFLAGS)

bits: bits.o
	$(CC) -o $@ $^ $(CCFLAGS) 

decode: decode.o
	$(CC) -o $@ $^ $(CCFLAGS) 

clean:
	rm -f *.o *~

wipe: clean
	rm -f $(TARGETS)
