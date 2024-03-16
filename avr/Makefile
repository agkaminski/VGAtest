ISP ?= usbasp
#ISP ?= avrisp2

all: text_gen.c
	avr-gcc -DF_CPU=16E6 -Os -mmcu=atmega16 -Wall text_gen.c -o bin/text_gen
	avr-objcopy -Oihex bin/text_gen bin/text_gen.hex
	size -A -d bin/text_gen

fuse:
	avrdude -c${ISP} -pm16 -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m

install:
	avrdude -c${ISP} -pm16 -U flash:w:bin/text_gen.hex:i

clean:
	rm -f bin/*
