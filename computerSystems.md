# Computer Systems

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
  * Running througout the system is a collection of electrical conduits called buses that carry bytes of information back and forth between the components. Buses are typically designed to transfer fixed-size chunks of bytes known as words. The number of bytes in a word (the word size) is a fundamental system parameter that varies across systems. Most machines today have word sizes of either 4 bytes (32 bits) or 8 bytes (64 bits).
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
  * There are only a few of these simple operations, and they revolve around main memory, the register file, and the arithmetic/logic unit (ALU). The register file is a small storage device that consists of a collection of word-size registers, each with its own unique name. The ALU computes new data and address values. 
  * Here are some examples of the simple operations that the CPU might carry out at the request of an instruction
    * Load: Copy a byte or a word from main memory into a register, overwriting the previous contents of the register.
    * Store: Copy a byte or a word from a register to a location in main memory, overwriting the previous contents of that location.
    * Operate: Copy the contents of two registers to the ALU, perform an arithmetic operation on the two words, and store the result in a register, overwriting the previous contents of that register.
    * Jump: Extract a word from the instruction itself and copy that word into the program counter, overwriting the previous value of the PC.

### Caches Matter
* The idea behind caching is that a system can get the effect of both a very large memory and a very fast one by exploiting *locality*, the tendency for programs to access data and code in locallized regions. By setting up caches to hold data that are likely to be accessed often, we can perform most memory operations using the fast caches. 

### Storage Devices Form a Hierarchy
* The storage devices in every computer system are organized as a memory hierarchy. 
* As we move from the top of the hierarchy to the bottom, the devices become slower, larger, and less costly per byte. The register file occupies the top level in the hierarchy, which is known as level 0. 
* The main idea of a memory hierarchy is that storage at one level serves as a cache for storage at the next lower level.

### The Operating System Manages the Hardware
* We can think of the operating system as a layer of software interposed between the application program and the hardware. All attempts by an application program to manipulate the hardware must go through the operating system. 
* **IMPORTANT** The operating system has two primary purposes.
  1. To protect the hardware from misuse by runaway applications
  2. To provide applications with simple and uniform mechanisms for manipulating complicated and often wildly different low-level hardware devices.
* The operating system achieves both goals via the fundamental abstractions:
  * processes - are abstractions for the processor, main memory, and I/O devices.
    * A process is the OS's abstraction for a running program.
    * Multiple processes can run concurrently on the same system, and each process appears to have exclusive use of the hardware. By concurrently, we mean that the instructions of one process are interleaved with the instructions of another process. 
    * The OS performs this interleaving with a mechanism known as context switching. 
    * The OS keeps track of all the state information that the process needs in order to run. This state, which is known as the context, includes information such as the current values of the PC, the register file, and the contents of main memory. When the OS decides to transfer control from the current process process to some new process, it performs a context switch by saving the context of the current process, restoring the context of the new process, and then passing control to the new process. The new process picks up exactly where it left off. 
    * The transition from one process to another is managed by the OS kernel. The kernel is the portion of the OS code that is always resident in memory. When an application program requires some action by the OS, such as to read or write a file, it executes a special system call instruction, transferring control to the kernel. The kernel then performs the requested operation and returns back to the application program. **Note**: The kernel is not a seperate process. Instead, it is a collection of code and data structures that the system uses to manage all the processes.
    * Implementing the process abstraction requires close cooperation between both the low-level hardware and the OS software. 
    * Threads
      * A process can consist of multiple execution units called threads, each running in the context of the process and sharing the same code and global data. 
      * Threads are an increasingly important programming model because of the requirement for concurrency in network servers, because it is easier to share data between multiple threads than between multiple processes, and because threads are typically more efficient than processes.
      * Multi-threading is also one way to make programs run faster when multiple processors are available.
  * virtual memory - is an abstraction for both the main memory and disk I.O devices
    * Each process has the same uniform view of memory, which is known as the virtual address space. 
    * The virtual address space seen by each process consists of a number of well-defined areas, each with a specific purpose. Starting with the lowest addresses and working uo
      * *Program code and data* - Code begins at the same fixed address for all processes, followed by data locations that correspond to global C variables. The code and data areas are initialized directly from the contents of an executable object file--in our case, the hello executable.
      * *Heap* - The code and data areas are followed immediately by the run-time heap. Unlike the code and data areas, which are fixed in size once the process begins running, the heap expands and contracts dynamically at run time as a result of calls to C standard library routines such as malloc and free.
      * *Shared libraries* - Near the middle of the address space is an area that holds the code and data for shared libraries such as the C standard library and the math library.
      * *Stack* - At the top of the user's virtual address space is the user stack that the compiler uses to implement function calls. Like the heap, the user stack expands and contracts dynamically during the execution of the program. In particular, each time we call a function, the stack grows. Each time we return from a function, it contracts. 
      * *Kernel virtual memory* - The top region of the address space is reserved for the kernel. Application programs are not allowed to read or write the contents of this area or to directly call functions defined in the kernel code. Instead, they must invoke the kernel to perform these operations. 
    * For virtual memory to work, a sophisticated interaction is required between the hardware and the operating system software, including a hardware translation of every address generated by the processor. The basic idea is to store the contents of a process's virtual memory on disk and then use the main memory as a cache for the disk.
  * files - are abstractions for I/O devices
