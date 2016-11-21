.PHONY: build debug gdb

NASHURL  = "https://github.com/NeowayLabs/nash/releases/download/v0.2.1/nash"
NASHPATH = ./scripts/.nash
NASHBIN  = ./scripts/bin/nash
NASHEXEC := NASHPATH=$(NASHPATH) $(NASHBIN)

all: clean deps build build-baremetal

clean:
	$(NASHEXEC) ./make.sh clean

deps: $(NASHBIN) scripts/BootProg/mkimg144 scripts/BootProg/flp144.bin

scripts/BootProg/flp144.bin: scripts/BootProg
	cd scripts/BootProg && nasm -f bin flp144.asm -o flp144.bin

scripts/BootProg/mkimg144: scripts/BootProg
	cd scripts/BootProg && smlrcc mkimg144.c -o mkimg144

scripts/BootProg:
	mkdir -p scripts
	cd scripts && git clone git@github.com:alexfru/BootProg.git

$(NASHBIN):
	mkdir -p ./scripts/bin
	wget -c $(NASHURL) -O $(NASHBIN)
	chmod +x $(NASHBIN)
	$(NASHBIN) -version
	mkdir -p $(NASHPATH)/lib
	cd $(NASHPATH)/lib && git clone git@github.com:NeowayLabs/nashlib.git

build: $(NASHBIN)
	$(NASHEXEC) ./make.sh build

baremetal: deps
	$(NASHEXEC) ./make.sh baremetal

test:
	$(NASHEXEC) ./make.sh test

gdb:
	$(NASHEXEC) ./make.sh debug-gdb

debug:
	gdb 	-ex "set architecture 386:386" \
		-ex "set disassembly-flavor intel" \
		-ex "layout asm" -ex "layout regs" \
		-ex "br *0x80490b0" \
		-ex "set startup-with-shell off" \
		./xxx
