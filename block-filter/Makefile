MY_MOD = filter

ifneq ($(KERNELRELEASE),)
obj-m += $(MY_MOD).o
else
KDIR := /usr/src/kernels/$(shell uname -r)

all:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	 $(MAKE) -C $(KDIR) M=$$PWD clean
endif

test:
	# We put a — in front of the rmmod command to tell make to ignore
	# an error in case the module isn’t loaded.
	-sudo rmmod $(MY_MOD)
	# Clear the kernel log without echo
	sudo dmesg -C
	# Insert the module
	sudo insmod $(MY_MOD).ko
	# Display the kernel log
	dmesg
