#include "vm.h"

void test_add(VM *vm, int a, int b, int res) {
    vm_init(vm);

    printf("[TEST] - init test program to test ADD\n");
    printf("[TEST] - program is (PUSH %d PUSH %d ADD)\n", a, b);

    unsigned char program[] = {PUSH, a, PUSH, b, ADD};

    printf("[TEST] - Load the program into VM's memory (using memcpy)\n");
    memcpy(vm->memory, program, sizeof(program));

    printf("[TEST] - Starting VM\n");
    vm_run(vm);

    if (vm->stack[vm->sp] == res) {
       printf("[TEST] - test passed!\n");
    } else {
      printf("[TEST] - test failed!\n");
    }
}

int main() {
    VM newVM;
    int a = 40;
    int b = 2;
    int res = a + b;
    test_add(&newVM, a, b, res);
    
    return 0;
}
