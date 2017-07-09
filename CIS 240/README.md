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
