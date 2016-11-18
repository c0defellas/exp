TARGET = xxx

all: clean $(TARGET)

$(TARGET):
	smlrcc main.c regs.c -I./include -o $(TARGET)

debug:
	gdb 	-ex "set architecture 386:386" \
		-ex "set disassembly-flavor intel" \
		-ex "layout asm" -ex "layout regs" \
		-ex "br *0x80490b0" \
		-ex "set startup-with-shell off" \
		./xxx

clean:
	rm -f $(TARGET)
