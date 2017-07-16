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
- in LC-3, each register stores 16 bits
- registers must be uniquely identifiable
- LC-3 specifies eight GPRs, each identified by a 3-bit register number

#### 5.1.3 The Instruction Set
- an instruction is made up of:
  - opcode - what the instruction is asking the computer to do
  - operands - who the computer is expected to do it to
- the instruction set of an ISA is defined by its set of opcodes, data types and addressing modes

#### 5.1.4 Opcodes
- LC-3 ISA has 15 instructions, each identified by its opcode
  - opcode is specified by bits [15:12]
- three types of opcodes: operates, data movement, control
  - operate instructions - process info
  - data movement instructions - move info between memory and the registers and between registers/memory and input/output devices
  - control instructions change the sequence of instructions that will be executed

#### 5.1.5 Data Types
- data type - a representation of info such that the ISA has opcodes that operate on that representation
- if the ISA has an opcode that operates on information represented by a data type, then we say that the ISA supports that data type

#### 5.1.6 Addressing Modes
- addressing mode - a mechanism for specifying where the operand is located
- if operand is part of the instruction, we refer to it as a literal or as an immediate operand
- LC-3 supports five addressing modes: immediate (literal), register, and three memory addressing modes: PC-relative, indirect, and Base+offset

#### 5.1.7 Condition Codes
- LC-3 has three single-bit registers that are set or cleared each time one of the eight general purpose registers is written
- the three single-bit registers are called N, Z, and P, corresponding to their meaning: negative, zero, and positive
- each time a GPR is written, the N, Z, and P registers are individually set to 0 or 1, corresponding to whether the result written to the GPR is negative, zero or positive
- each of the three single-bit registers is referred to as a condition code because the condition of that bit can be used by one of the control instructions to change the execution sequence

### 5.2 Operate Instructions
- process data
  - LC-3 has ADD, AND, NOT

### 5.3 Data Movement Instructions
- load - process of moving information from memory to a register
- store - moving information from a register to memory
- LC-3 has seven instructions that move info: LD, LDR, LDI, LEA, ST, STR, STI
- [15:12] - opcode
- [11:9] - specify one of these operands, the register
  - if the instruction is a load, DR refers to the destination register
  - if the instruction is a store, SR refers to the register that contains the value that will be written to memory
- [8:0] - address generation bits
  - encode information that is used to compute the 16-bit address of the second operand
  - in the case of the LC-3's data movement instructions, there are four ways to interpret the bits [8:0]
    - addressing modes
  - opcode specifies how to interpret bits [8:0]

#### 5.3.1 PC-Relative Mode
- LD (opcode = 0010), ST (opcode = 0011) specify PC-relative addressing mode
  - bits [8:0] of the instruction specify an offset relative to the PC
- memory address is computed by sign-extending bits [8:0] to 16 bits
- the incremented PC is the contents of the program counter after the FETCH phase
- if a load, the memory location corresponding to the computed memory address is read, and the result loaded into the register specified by bits [11:9] of the instruction

#### 5.3.2 Indirect Mode
- LDI (opcode = 1010) and STI (opcode = 1011) specify the indirect addressing mode
  - contains address of operand to be loaded or stored, rather than this address being the address of the operand to be loaded or stored
  -  destination register for the LDI and the source register for STI, like all the other loads and stores, are specified in bits [11:9] of the instruction

#### 5.3.3 Base+offset Mode
- LDR (opcode = 0110) and STR (opcode = 0111) specify the Base+offset addressing mode
  - address of operand is obtained by adding a sign-extended 6-bit offset to a base register
  - the 6-bit offset is literally taken from the instruction bits [5:0]
  - base register is specified by bits [8:6]
- Base+offset addressing uses the 6-bit value as a 2's complement integer between -32 and +31 (must first be sign-extended to 16 bits before it is added to the base register)
- allows the address of the operand to be anywhere in the computer's memory

#### 5.3.4 Immediate Mode
- used only with load effective address (LEA opcode = 1110) instruction
- LEA loads the register specified by bits [11:9] of the instruction with the value formed by adding the incremented program counter to the sign-extended bits [8:0] of the instruction
- useful to initialize a register with an address that is very close to the address of the instruction doing the initializing
- only load instruction that does not access memory to obtain the information it will load into the DR
  - loads into the DR the address formed from the incremented PC and the address generation bits of the instruction

### 5.4 Control Instructions
- change the sequence of instructions that are executed
  - if no control instructions, the next instruction fetched after the current instruction finishes would be the instruction located in the next sequential memory location (PC incremented in FETCH phrase of each instruction)
  - five opcodes: conditional branch, unconditional jump, subroutine (function) call, TRAP, return from interrupt

#### 5.4.1 Conditional Branches
- 0000NZP[PCoffset]
- [11], [10], [9] all correspond to the three condition codes discussed in 5.1.7
- condition codes are used by the conditional branch instruction to determine whether to change the instruction flow
- FETCH and DECODE same for all instructions
- PC is incremented during FETCH
- EVALUATE ADDRESS is same as that for LD and ST
- during EXECUTE phase, processor examines condition codes whose corresponding bits in the instruction are 1
  - if any of the condition codes that are examined are in state 1, then the PC is loaded with the address obtained in the EVALUATE ADDRESS phase
  - if none of the condition codes that are examined are in stat 1, the PC is left unchanged
- if all three examined - unconditional branch

#### 5.4.3 Two Methods for Loop Control
- use counter or sentinel

#### 5.4.5 The JMP Instruction
- limitation of conditional branch instruction: next instruction executed must be within the range of addresses that can be computed by adding the incremented range
- JMP (opcode = 1100)
  - loads the PC with the contents of the register specified by bits [8:6] of the instruction

#### 5.4.6 The TRAP Instruction
- TRAP (opcode = 1111) changes the PC to a memory address that is part of the operating system so the operating system will perform some task on behalf of the program that is executing
  - TRAP instruction invokes an operating system SERVICE CALL
- Bits [7:0] of the TRAP instruction form the trapvector

### 5.6 The Data Path Revised
#### 5.6.1 Basic Components of a Data Path
##### The Global Bus
- heavy black structure with arrows at both ends
- LC-3 global bus: 16 wires and associated electronics
- allows one structure to transfer up to 16 bits of information to another structure
- only one value can be transferred on the bus at one time
- tri-state device - allows the computer's control logic to enable exactly one supplier to provide information to the bus at any one time

##### Memory
- accessed by loading MAR with the address of the location to be accessed
- if load is being performed, control signals then read the memory, and the result of that read is delivered by the memory to the MDR

##### The ALU and the Register File
- ALU is processing element, has two inputs
- result of an ALU operation is a result that is stored in one of the registers, and the three single-bit condition codes
- ALU can supply 16 bits to the bus, and that value can then be written into the register specified by the 3-bit register number DR
- note that the 16 bits supplied to the bus are also input to logic that determines whether that 16-bit quantity is negative, zero, or positive, and sets the three registers N, Z, and P accordingly

##### The PC and the PCMUX
- the PC supplies via the global bus to the MAR the address of the instruction to be fetched at the start of the instruction cycle
  - PC is supplied via the three-to-one PCMUX, depending on the instruction being executed
- if the current instruction is a control instruction, then the relevant source of the PCMUX depends on which control instruction is currently being processed
- if the current instruction is a conditional branch and the branch is taken, then the PC is loaded with the incremented PC + PCoffset
  - this addition takes place in special adder and not in the ALU

##### The MARMUX
- controls which of two sources will supply the MAR with the appropriate address during the execution of a load, a store, or a TRAP instruction
- right input: adding either the incremented PC or a base register to a literal value or zero supplied by the IR
- left input: provides the zero-extended trapvector (needed to invoke service calls)

## 7 Assembly Language
### 7.1 Assembly Language Programming-Moving Up a Level
- assembly = low-level language
- symbolic addresses

### 7.2 An Assembly Language Program
- assembler - translation program
- assembly - translation process

#### 7.2.1 Instructions
- an instruction in assembly language consists of four parts: `LABEL OPCODE OPERANDS ; COMMENTS`
  - LABEL and COMMENTS are optional

##### Opcodes and Operands
- mandatory
- OPCODE - symbolic name for the opcode of the corresponding LC-3 instruction
- register operands - registers explicitly represented
- memory operands - symbolic name of the memory location is explicitly represented
- literal value must contain a symbol identifying the representation base of the number
  - # for decimal, x for hexadecimal, and b for binary

##### Labels
- symbolic names that are used to identify memory locations that are referred to explicitly in the program
- in LC-3 assembly language, a label consists of from one to 20 alphanumeric characters (i.e., a capital or lowercase letter of the alphabet, or a decimal digit), starting with a letter of the alphabet
  - location contains the target of a branch instruction
  - location contains a value that is loaded or stored

##### Comments
- identified by semicolons

#### 7.2.2 Pseudo-ops (Assembler Directives)
- the pseudo-op is strictly a message to the assembler to help the assembler in the assembly process
  - once assembler handles message, the psuedo-op is discarded
- .ORIG
  - tells the assembler where in memory to place the LC-3 program
    - e.g. .ORIG x3050
- .FILL
  - tells the assembler to set aside the next location in the program and initialize it with the value of the operand
- .BLKW
  - tells the assembler to set aside some number of sequential memory locations (i.e. a BLocK of Words) in the program
- .STRINGZ
  - tells the assembler to initialize a sequence of n + 1 memory locations
    - argument is a sequence of n characters, inside double quotation marks
- .END
  - tells the assembler where the program ends
    - any characters that come after .END will not be used by the assembler
  - does not stop the program during execution, only a delimiter
  - does not exist at the time of execution

### 7.3 The Assembly Process
#### 7.3.1 Introduction
- LC-3 assembly language program must first be translated into a machine language program

#### 7.3.2 A Two-Pass Process
- assembly process is done in two complete passes

#### 7.3.3 The First Pass: Creating the Symbol Table
- symbol table is simply a correspondence of symbolic names with their 16-bit memory addresses
  - passing through assembly language program once, noting which instruction is assigned to which address, and identifying each label with the address of its assigned entry
  - this assumes that entire program exists between .ORIG and .END pseudo-ops

#### 7.3.4 The Second Pass: Generating the Machine Language Program
- second pass consists of going through the assembly language program a second time, line by line, this time with the help of the symbol table
  - assembly language instruction is translated into an LC-3 machine language instruction

### 7.4 Beyond the Assembly of a Single Assembly Language Program
#### 7.4.1 The Executable Image
- when a computer begins execution of a program, the entity being executed is called an executable image

#### 7.4.2 More than One Object File
- use `.EXTERNAL STARTofFILE` (STARTofFILE is symbolic name of an address not known at the time the program is assembled)
  - STARTofFILE is a label in some other module that will be translated independently
- at link time, when modules are combined, linker would use symbol table entry for STARTofFILE in another module
- .EXTERNAL pseudo-op allows references by one module to symbolic locations in another module
