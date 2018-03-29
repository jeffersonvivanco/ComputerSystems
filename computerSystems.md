#Computer Systems

## A tour of computer systems
* All information in a system, including disk files, programs stored in memory, user data stored in memory and data transferred across a network, is represented as a bunch of bits. The only thing that distinguishes different data objects is the context in which we view them.

### Compiler System
* linux> gcc -o hello hello.c
 * Here, the gcc compiler driver reads the source file hello.c and translates it into an executable object file hello. The translation is performed in the sequence of four phases. The programs that perform the four phases (preprocessor, compiler, assembler, and linker) are known collectively as the compilation system.
  * Preprocessing phase: The preprocessor (cpp) modifies the original C program according to directives that begin with the '#' character. The result is another C program, typically with the .i suffix.
  * Compilation phase: The compiler (cc1) translates the text file hello.i into the text file hello.s which contains an assembly language program. Assembly language is useful because it provides a common output language for different compilers for different high-level languages.
  * Assembly Phase: Next the assembler (as) translates hello.s into machine-language instructions, packages them in a form known as a relocatable object program, and stores the result in the object file hello.o. This file is a binary file containing 17 bytes to encode the instructions for function main. 
  * Linking Phase: In the hello program, we call the print function to print hello world. The printf function is part of the standard C library provided by every C compiler. The printf function resides in a separate precompiled object file called printf.o, which must somehow be merged with our hello.o program. The linker (ld) handles the merging. The result is the hello file, which is an executable object file (or simply executable) that is ready to be loaded into memory and executed by the system. 

### Hardware organization of a system
* Buses
  * Running througout the system is a collection of electrical conduits called buses that carry bytes of information back and forth between the components. Buses are typically designed to transfer fixed-size chunks of bytes known as words. The number of bytes in a word (the word size) is a fundamental system paramter that varies across systems. Most machines today have word sizes of either 4 bytes (32 bits) or 8 bytes (64 bits).
* I/O Devices
 * I/O devices are the system's connection to the external world. 
 * Each I/O device is connected to the I/O bus by either a controller or an adapter. The distinction between the two is mainly one of packaging.
 * Controllers are chip sets in the device itself or on the system's main printed circuit board (often called the motherboard).
 * An adapter is a card that plugs into a slot on the motherboard. Regardless, the purpose of each is to transfer information back and forth between the I/O bus and an I/O device.
* Main Memory
 * The main memory is a temporary storage device that holds both a program and the data it manipulates while the processor is executing the program.
 * Physically, main memory consists of a collection of dynamic random access memory (DRAM) chips. 
 * Logically, memory is organized as a linear array of bytes, each with its own unique address (array index) starting at zero. 
* Processor
 * The central processing unit (CPU), or simply processor, is the engine that interprets (or executes) instructions stored in main memory. 
 * At its core is a word size storage device (or register) called the program counter (PC). At any point in time, the PC points at (contains the address of) some machine-language instruction in main memory.
 * From the time that power is applied to the system until the time that the power is shut off, a processor repeatedly executes the instruction pointed at by the program counter and updates the program counter to point to the next instruction.
 * A processor appears to operate according to a very simple instruction execution model, defined by its instruction set architecture. In this model, instructions execute in strict sequence, and executing a single instruction involves performing a series of steps. 
  * The processor reads the instruction from memory pointed at by the program counter (PC), interprets the bits in the instruction, performs some simple operation dictated by the instruction, and then updates the PC to point to the next instruction, which may or may not be contiguous in memory to the instruction that was just executed. 