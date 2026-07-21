# Memory Allocator

A custom memory allocator written in C using `mmap()` to explore heap management, dynamic memory allocation, and low-level systems programming concepts.

## Features

* Custom `my_malloc()` implementation
* Custom `my_free()` implementation
* Free-list based allocator
* Block splitting to reduce internal fragmentation
* Coalescing adjacent free blocks
* Page allocation using `mmap()`

## Learning Objectives

This project was built to gain a deeper understanding of:

* Heap memory management
* Dynamic memory allocation internals
* Linked lists and allocator metadata
* Memory fragmentation and coalescing
* Pointer arithmetic and memory layouts
* Linux virtual memory using `mmap()`

## Future Improvements

* Memory alignment (8/16-byte alignment)
* Support for `calloc()`
* Support for `realloc()`
* Multiple page allocation for large requests
* Thread safety
* Returning unused pages back to the operating system

## Build

```bash
gcc -Iinclude src/allocator.c src/main.c -o allocator
```

## Run

```bash
./allocator
```
