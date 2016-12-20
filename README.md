# cpp-nostdlib

Simple C++ program with virtual inheritance, which compiles without libstdc++

## Example Usage

```
$ make
rm -f .depfile
gcc  -E -MM -I. -I.   src/emu.cc src/main.cc  -MF .depfile
Compiling src/emu.o from [ src/emu.cc ]
g++ -I. -c src/emu.cc -o src/emu.o
Compiling src/main.o from [ src/main.cc ]
g++ -I. -c src/main.cc -o src/main.o
Building binary demo from [ src/emu.o src/main.o ]
gcc -L. src/emu.o src/main.o -o demo
$ ldd ./demo
	linux-vdso.so.1 =>  (0x00007fffcef5f000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007efd8ea8a000)
	/lib64/ld-linux-x86-64.so.2 (0x00007efd8ee4f000)
$ ./demo
Hello, world
```
