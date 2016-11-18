TARGET = xxx

all: clean $(TARGET)

$(TARGET):
	smlrcc main.c regs.c -I./include -o $(TARGET)

debug:
	gdb ./xxx \
		-ex "target remote localhost:1234" \
		-ex "set architecture i80386" \
		-ex "set disassembly-flavor intel" \
		-ex "layout asm" -ex "layout regs" \
		-ex "break *0x80490b0"

clean:
	rm -f $(TARGET)
