# Introduction to Computing systems

## 3 Digital Logic Structures
### 3.1 The Transistor
- metal-oxide semiconductor (MOS) transistors
  - n-type
    - supplied with 0 volts > broken
    - supplied with 2.9 volts > closed
  - p-type
    - opposite of n-type
    - supplied with 0 volts > closed
    - supplied with 2.9 volts > broken
- complementary metal-oxide semiconductor (CMOS) circuits - circuits that contain both p-type and n-type transistors

### 3.2 Logic Gates
#### 3.2.1 The NOT Gate (Inverter)
- one p-type and one n-type in series

#### 3.2.2 OR and NOR Gates
- NOR has two p-type and two n-type
- OR is NOR + NOT

#### 3.2.3 AND and NAND Gates
- bubble represents NOT

### 3.3 Combinational Logic Circuits
#### 3.3.1 Decoder
- in general, decoders have n inputs and 2^n outputs
  - output line that detects the input line is asserted
- opcode - four-bit pattern that is part of the instruction in LC-3
- 4-to-16 decoder

#### 3.3.2 Mux
- mux (multiplexer)
  - selects one of the inputs and connects it to the output
  - e.g. two-input multiplexer: if S = 0, output is whatever A is; if S = 1, output is whatever B is

#### 3.3.3 Full Adder
- three inputs and two outputs

#### 3.3.4 The Programmable Logic Array (PLA)
- consists of an array of AND gates (AND array) followed by an array of OR gates (OR array)
  - for n input logic functions, need a PLA with 2^n n-input AND gates
  - number of OR gates corresponds to the number of output columns in the truth table
- basically hard-coding every row

#### 3.3.5 Logical Completeness
- set of gates {AND, OR, NOT} is logically complete because can build a circuit to carry out the specification of any truth table we wish without building another gates

### 3.4 Basic Storage Elements
#### 3.4.1 The R-S Latch
- stores one bit of information
- two 2-input NAND gates are connected such that the output of each is connected to one of the inputs of the other
- remaining inputs S and R are normally held at a logic level 1
- quiescent (quiet) state - both S and R have logic value 1
  - if a = 1, then b = 0, so a = 1, etc.
  - if a = 0, then b = 1, so a = 0, etc.
- latch can be set to 1 by momentarily setting S to 0, provided we keep the value of R at 1
- latch can be set to 0 by momentarily setting R to 0, provided we keep the value of S at 1
- if both S and R are allowed to be set to 0 at the same time
  - a and b are both 1, and the final state of the latch depends on the electrical properties of the transistors making up the gates and not on the logic being performed

#### 3.4.2 The Gated D Latch
- consists of R-S latch plus two additional gates that allow for the latch to be set to the value of D, but only when WE (write enable) is asserted
  - when WE = 0, S and R are both equal to 1
  - when WE is momentarily asserted (set to 1), exactly one of the outputs S or R is set to 0, depending on the value of D
    - if D equals 1, then S is set to 0
    - if D equals 0, then both inputs to the lower NAND gate are 1, resulting in R being set to 0

#### 3.4.3 A Register
- a structure that stores a number of bits, taken together as a unit

### 3.5 The Concept of Memory
- memory is made up of a (usually large) number of locations, each uniquely identifiable and each having the ability to store a value
- address - the unique identifier associated with each memory location
- addressability - number of bits of information stored in each location

#### 3.5.1 Address Space
- address space - total number of uniquely identifiable locations
- memory locations identified by binary addresses

#### 3.5.2 Addressability
- most memories are byte-addressable - each ASCII code occupies one location in memory

#### 3.5.3 A 2^2-by-3-Bit Memory
- a memory of size 2^2 by 3 bits has an address space of four locations, and an addressability of 3 bits

### 3.6 Sequential Logic Circuits
- combinatorial logic circuits - muxes, decoders, full adders
  - no sense of the past
- digital logic structures - can both process info and store information
  - sequential logic gates

#### 3.6.2 The Concept of State
- state of a system is a snapshot of all the relevant elements of the system at the moment the snapshot is taken

#### 3.6.3 Finite State Machines
- finite state machine consists of five elements:
  - a finite number of states
  - a finite number of external inputs
  - a finite number of external outputs
  - an explicit specification of all state transitions
  - an explicit specification of what determines each external output value

#### 3.6.4 An Example: The Complete Implementation of a Finite State Machine

## 4 The von Neumann Model
### 4.1 Basic Components
- instruction - smallest piece of work specified in a computer program
  - computer does not have the luxury of carrying out a piece of an instruction
- von Neumann model: memory, processing unit, input, output, and a control unit

#### 4.1.1 Memory
- typical memory of today's (well in 2005) computer system is 2^28 by 8 bits
- to read the contents of a memory location, we first place the address of that location in the memory's address register (MAR), and then interrogate the computer's memory
- info stored in the location having that address will be placed in the memory's data register (MDR)
- to write (or store) a value in a memory location, we first write the address of the memory location in the MAR, and then value to be stored in the MDR
- then interrogate the computers memory with the Write Enable signal asserted
- info contained in the MDR will be written into the memory location whose address is in the MAR

#### 4.1.2 Processing Unit
- carries out actual processing of information in the computer
  - can consist of many sophisticated complex functional units
- ALU (Arithmetic and Logic Unit) - simplest processing unit
  - capable of performing basic arithmetic and basic logic operations
  - word length - size of the quantities normally processed by the ALU
  - word - each element
- almost all computers have temporary storage to avoid the unnecessarily longer access time that would be necessary when it came time to multiply
  - most common form - set of registers

#### 4.1.3 Input and Output
- peripherals - devices that exist for the purposes of input and output
- LC-3: input - keyboard, output - monitor

#### 4.1.4 Control Unit
- control unit in charge of making all the other parts play together
  - keeps track of both where we are within the process of executing the program and where we are in the process of executing each instruction
- instruction register - keeps track of which instruction is being executed
- program counter (PC) - keeps track of which instruction is to be processed next
  - "instruction pointer"

### 4.3 Instruction Processing
- central idea in the von Neumann model of computer processing is that the program and data are both stored as sequences of bits in the computer's memory, and the program is executed one instruction at a time under the direction of the control unit

#### 4.3.1 The Instruction
- instruction is made of the opcode (what the instruction does) and the operands (who it is to do it to)

#### 4.3.2 The Instruction Cycle
- fetch, decode, evaluate address, fetch operands, execute, store result
- FETCH
  - obtains next instruction from memory and loads it into the instruction register (IR) of the control unit
  - step 1: load the MAR with the contents of the PC, and simultaneously increment the PC
  - step 2: interrogate memory, resulting in the instruction being placed in the MDR
  - step 3: load the IR with the instructions of the MDR
  - amount of time taken by each machine cycle is one clock cycle
- DECODE
  - examines instruction in order to figure out what the microarchitecture is being asked to do
  - LC-3: 4-to-16 decoder
- EVALUATE ADDRESS
  - computes the address of the memory location needed to process the instruction
- FETCH OPERANDS
  - obtains the source operands needed to process the instruction
- EXECUTE
  - carries out execution of the instruction
- STORE RESULT
  - result is written to its designated destination

### 4.4 Changing the Sequence of the Execution
- operate instruction - processes data
- data movement instruction - moves data from one place to another
- control instruction - changes the sequence of instruction execution
  - if we wish to change the sequence of instructions executed, we must change the PC between the time it is incremented (during the FETCH phase of one instruction) and the start of the FETCH phase of the next

### 4.5 Stopping the Computer
- instruction cycle continues whether a user program is being processed or the operating system is being processed
- stopping instruction cycle requires stopping the clock
  - clock generator is a crystal oscillator
  - if RUN latch is in 1 state (Q = 1), the output of the clock circuit is the same as the output of the clock generator
  - if the RUN latch is in the 0 state, the output of the clock circuit is 0

## 5 The LC-3
### 5.1 The ISA: Overview
- ISA specifies everything in the computer that is available to a programmer when he/she writes programs in the computer's own machine language
- ISA also specifies everything in the computer that is available to someone who wishes to translate programs written in a high-level language like C or Pascal or Fortran or COBOL into the machine language of the computer

#### 5.1.1 Memory Organization
- LC-3 memory has an address space of 2^16 locations
- addressability of 16 bits

#### 5.1.2 Registers
- general purpose register set
  - each register in the set is called a general purpose register (GPR)
