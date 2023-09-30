# Why?

What you see here is my try to teach myself something about Virtual Machines, so I decided to write toy VM
The first try probably would be with a lots of internet search and even LLM promprting, but maybe I will rewrite it later

# Glossary

First of all I want to define a simple glossary of terms
* Virtual Machine - basically, if I understood it correctly, this is some kind of emulation of the **real** computer
* Instruction Set - collection of **opcodes** the VM uderstands, also a set of their behavior
* Opcode (operation code) - unique identifier for a specific operation/command that VM will use
* Register - a small storage within VM, this is where I can store data that needs to be processed by VM
* Stack - **LIFO** data structure, that VM uses for temp. storage and function calls
* Stack Pointer - variable that points to the top of the **stack**
* Program Counter - variable keeping track of the VM's current execution, it ensures the correct, sequential flow of instruction execution

# What to do:
* More opcodes:
    * POP
    * ADD, SUB, MUL, DIV
    * JMP
* Function Calls
    * CALL, RETURN
* I/O
    * READ/WRITE
* Assembler maybe?

# Good resources to learn from
* [Write your Own Virtual Machine](https://www.jmeiners.com/lc3-vm/)
    * Found a lot good explanations of basic concepts here

