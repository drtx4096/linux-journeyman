# LD_PRELOAD Example

* You must define `_GNU_SOURCE` for intercepting **library** calls to work. This does not allow interception of system calls.
* `strace` can be used to identify the system calls being invoked by the executable.
* `ltrace` can be used to identify the **library** call being invoked by the executable.
* Using `__attribute__((constructor))` on a void function in the library will cause it to be invoked when the library is loaded. No need for system or library call interception.

# Usage

```
make
./hello
LD_PRELOAD=./doubleputs.so ./hello
LD_PRELOAD=./doubleputs.so ./hello-static
```

* In the second invocation of `hello`, you will observe output from the library's constructor and the double output due to intercepting the `puts` library call. 
* Note in the third invocation where the statically linked binary is used, `LD-PRELOAD` has no effect.

