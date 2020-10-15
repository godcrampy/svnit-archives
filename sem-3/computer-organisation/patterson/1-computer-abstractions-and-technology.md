# Computer Abstractions and Technology

## Underneath the Software

A word processor or any game is an application software. There are several layers between the application and software. Softwares are of two types:

* Application Software: Word Processor, Spreadsheet, Photoshop
* System Software: OS, Compilers

System software provide commonly used tools and functionalities. System software is built upon hardware and Appliation software is built upon this system software.

An _Operating System_ is a program that handles I/O, manages resources and provides an interface to other software to interact with the hardware utilities.

A _Compiler_ is a program that converts high-level code into machine code.

### Layers of Code
Computers take instructions in binary. An instruction to add two numbers may look like ```1000111101011``` in _machine code_. but this tedious and unproductive to write. So programmers instead starting using symbolic notations for common instructions. This code looked like ```add a, b```. This code was then maually converted into machine code. Then came programs which did this conversion. These were called _Assemblers_ and the language was thus called _Assembly Language_.

 But this too had various issues. Assembly language was different for different hardware. It forced the programmer to think like a machine and was'nt natural. This lead to the invention of highter level programming language like _C_. The code written in this language was compiled into machine code by a _compiler_. Thus development productivity increased, code was standerdised over all machines and programs became natural and not machine like.

 * High Level => ```a + b```
 * Assembly => ```ADD a, b```
 * Machine => ```10010011101110110```

## Underneath the Hardware

The hardware of a computer is made up of 5 main parts:

* Input Device
* Memory
* Datapath/ ALU
* Control Unit
* Output Device

The general flow of an instruction is as follows:
1. Input device takes the instructions from the user and stores it in the memory
2. The Control Unit reads the instruction, performs the instruction using the ALU and memory and stores the result on the memory
3. The output devide takes the result from the memory and return it to the user.

The CPU or Processor contains the Control Unit and the ALU. Programs are stored in the memory. Random Access Memory implies that taking a piece of data from the memory will take the same amount of time irrespective of where it is locared in the disk. This memory is of two types: The _DRAM_ (Dynamic) which is generally called as _RAM_ and _SRAM_ (Static) which is called cache. DRAM is slower than cache but less expensive. DRAM on a standard PC is of the order of GBs while cache is of the order of KBs or MBs. Cache holds only the data that the CPU might need frequently in the near future. Cache requires no refresing whereas DRAM does.

But this primary memory is volatile and gets erased when power is swithced off. Secondary memory like Hard Disk or SSD is used for storing data when  power goes as well. It is slower than Primary Memory but is Cheaper.

## Instruction Set Architecture

This is the interface between the hardware and the lowest level of software. An _instruction architecture_ defines the way to communicate via machine code, send instructions and access resources and memory of the hardware. Since two different types of hardware may have the same type of instruction set, the machine code for both of them becomes the same and leads to standardisations.