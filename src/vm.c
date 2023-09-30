#include "vm.h"

void vm_init(VM *vm) {
    memset(vm->memory, 0, sizeof(vm->memory));
    memset(vm->registers, 0, sizeof(vm->registers));
    memset(vm->stack, 0, sizeof(vm->stack));
    vm->pc = 0;
    vm->sp = 0;
    vm->isRunning = 0;
}

// Implementing essential operations
// HALT and PUSH

void vm_execute(VM *vm, unsigned char opcode) {
    switch (opcode) {
        case HALT:
            vm->isRunning = 0;
            break;
        case PUSH:
            vm->sp++;
            vm->stack[vm->sp] = vm->memory[vm->pc + 1]; // next byte in memory, push
            printf("\033[93m[PUSH]\033[0m - push the (%d) on the stack\n", vm->stack[vm->sp]);
            vm->pc++; // don't forget about incrementing the program counter
            break;
        case ADD:
            if (vm->sp < 1) {
                printf("Error \033[36m[ADD]\033[0m: Stack underflow");
                vm->isRunning = 0;
                return;
            }
            unsigned char a = vm->stack[vm->sp--]; // Pop first value
            unsigned char b = vm->stack[vm->sp]; // Peek second value
            printf("\033[36m[ADD]\33[0m  - add value %d and %d, and overwrite top value on the stack\n", a, b);
            vm->stack[vm->sp] = a + b; // ADD and overwrite second value
            printf("\033[36m[ADD]\33[0m  - value on the stack is %d\n", vm->stack[vm->sp]);
            break;
        case SUB:
            break;
        default:
            printf("Unknows opcode %02x\n", opcode);
    }
}

// Run it
void vm_run(VM *vm) {
    vm->isRunning = 1;
    while (vm->isRunning) {
        unsigned char opcode = vm->memory[vm->pc];
        vm_execute(vm, opcode);
        vm->pc++;
    }
}

