# My attempt at writing a bytecode interpreter

### How the instructions are structured
 - Each instruction is 64-bits
 - The rightmost 8 bits hold values for different flags
 - The next 8 bits from the right hold information about which register to use
 - The next 16 bits from the right hold information about which operation to execute
 - The last 32 bits hold information about the data.

### Registers
- It has 8 general purpose (32-bit) named `R1..R8`.
- It has 8 floating-point registers (32-bit) named `FPR1..FPR8`.

### Structure of the assembly code
`OPERATION DEST, SOURCE`. The accepted data are integer literals and floating-point literals and other registers. Accessing the data stored in a register: `OPERATION REGISTER, $REGISTER`. 

### CPU Flags
As mentioned above, the 8 rightmost bits are used for CPU Flags. 

**FROM RIGHT TO LEFT**:
1. REGISTER_FLAG - Tells the CPU if the data is a literal or if should retrieve data from a register.
2. FLOAT_FLAG - Tells the CPU if the current instruction consists of floating-point data and operations.


### Commands supported currently
- #### Commands for general purpose registers.
	- `MOV` - Moves a value into a register. 
	- `ADD` - Adds a value to a register.
	- `SUB` - Subtracts a value from a register.
	- `MUL` - Multiplies a value to a register.
	- `DIV` - Divides a value by a register.
	- `RPRINT` - Prints the register's name and its value.
- #### Commands for floating-point registers.
 	- `FMOV` - Moves a floating-point value into a register. 
	- `FADD` - Adds a floating-point value to a register.
	- `FSUB` - Subtracts a floating-point value from a register.
	- `FMUL` - Multiplies a floating-point value to a register.
	- `FDIV` - Divides a floating-point value by a register.
	- `FPRINT` - Prints the floating-point register's name and its value.