# AVR GRAM generator

Onboard ATmega16 FW - populates the graphic RAM with data to view, along with
some animation.

## build

avr-gcc, avr-libc and avrdude are needed. USBasp used for target programming.
Makefile provides quick MPU configuration too - fuse setting and FW upload.

```bash
make
make fuse
make install
```
