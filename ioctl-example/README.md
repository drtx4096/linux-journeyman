# IOCTL Example

This module provides an example of a Linux kernel module (LKM) using IOCTLs for
communication. The code is based on the following:

https://www.tldp.org/LDP/lkmpg/2.6/html/x892.html

# Build

Debug build:

```
make DEBUG=1 clean all 
```

Non-debug build:

```
make clean all 
```

# Run

```
druck@localhost ioctl-example (master)]$ make test
# We put a — in front of the rmmod command to tell make to ignore
# an error in case the module isn’t loaded.
sudo rmmod chardev
# Clear the kernel log without echo
sudo dmesg -C
# Insert the module
sudo insmod chardev.ko
# Display the kernel log
dmesg
[18440.519718] Registeration is a success The major device number is 100.
[18440.519718] If you want to talk to the device driver,
[18440.519719] you'll have to create a device file. 
[18440.519719] We suggest you use:
[18440.519719] mknod char_dev c 100 0
[18440.519720] The device file name is important, because
[18440.519720] the ioctl program assumes that's the
[18440.519720] file you'll use.

[druck@localhost ioctl-example (master)]$ sudo mknod char_dev c 100 0

[druck@localhost ioctl-example (master)]$ ./ioctl 
get_nth_byte message: 
get_msg message: ''

[druck@localhost ioctl-example (master)]$ ./ioctl 
get_nth_byte message: Message passed by ioctl
get_msg message: 'Message passed by ioctl'

[druck@localhost ioctl-example (master)]$ ./ioctl 
get_nth_byte message: 
get_msg message: ''

[druck@localhost ioctl-example (master)]$ 
```


