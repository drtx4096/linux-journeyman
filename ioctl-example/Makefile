DEBUG=

ifneq ($(strip $(DEBUG)),)
	ccflags-y += -DDEBUG=1
endif
obj-m += chardev.o

all: ioctl
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f *.o ioctl
test:
	# We put a — in front of the rmmod command to tell make to ignore
	# an error in case the module isn’t loaded.
	-sudo rmmod chardev
	# Clear the kernel log without echo
	sudo dmesg -C
	# Insert the module
	sudo insmod chardev.ko
	# Display the kernel log
	dmesg

ioctl: ioctl.c
	gcc -DDEBUG=$(MY_DEBUG) -o ioctl ioctl.c
