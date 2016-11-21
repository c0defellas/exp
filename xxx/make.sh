#!/usr/bin/env nash

import nashlib/sed

Target    = "xxx"
Sources   = (main.c regs.c)
KSources = (
	kernel/init.c
	kernel/term.c
	kernel/vesa.c
	kernel/stdio.c
)

KernelImg = "flp144.img"

setenv PATH = $PATH+":"+"./scripts/BootProg"

fn help() {
	printf "Use %s <action>\n" $ARGS[0]
	printf "Actions:\n"
	printf "\tbuild\t\t Build the userspace debugger\n"
	printf "\tbuild-metal\tBuild the bare metal version\n"
	printf "\tclean\t Clean the repo\n"
}

fn build() {
	smlrcc $Sources -I./include -o $Target
	echo "Built successfully"
}

fn buildImage() {
	mkimg144 -bs ./scripts/BootProg/flp144.bin -o $KernelImg -us STARTUP.BIN
}

fn buildMetal() {
	smlrcc -dosu $Sources $KSources -I ./kernel/include -o STARTUP.BIN
}

fn baremetal() {
	buildMetal()
	buildImage()

	qemu-system-i386 -fda $KernelImg -m 128
}

fn clean() {
	rm -f $Target
}

fn main() {
	arglen <= len($ARGS)

	action = $ARGS[1]

	-expr $arglen "<" 2 >[1=]

	if $status == "0" {
		# too few arguments
		help()

		return
	}
	if $action == "clean" {
		clean()
	} else if $action == "build" {
		build()
	} else if $action == "baremetal" {
		baremetal()
	} else {
		printf "Unexpected command '%s'.\n" $action
	}
}

main()
