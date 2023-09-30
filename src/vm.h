#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define STACK_SIZE 256
#define NUM_REGISTERS 4

#define HALT 0x00
#define PUSH 0x01
#define ADD  0x02
#define SUB  0x03

typedef struct {
    unsigned char memory[UINT16_MAX];
    unsigned char registers[NUM_REGISTERS];
    unsigned char stack[STACK_SIZE];
    unsigned short pc;
    unsigned short sp;
    unsigned char isRunning;
} VM;

// function def
void vm_init(VM *vm);
void vm_run(VM *vm);
