#include "vm.h"

void test_add(VM *vm, int a, int b, int expression) {
    vm_init(vm);

    printf("\033[32m[TEST]\033[0m - init test program to test ADD\n");
    printf("\033[32m[TEST]\033[0m - program is (PUSH %d PUSH %d ADD)\n", a, b);

    unsigned char program[] = {PUSH, a, PUSH, b, ADD, PUSH, 10, ADD, PUSH, 39, ADD, PUSH, 19, ADD}; // hardcoded on purpose

    printf("\033[32m[TEST]\033[0m - Load the program into VM's memory (using memcpy)\n");
    memcpy(vm->memory, program, sizeof(program));

    printf("\033[32m[TEST]\033[0m - Starting VM\n");
    vm_run(vm);

    if (vm->stack[vm->sp] == expression) {
       printf("\033[32m[TEST]\033[0m - test passed!\n");
    } else {
      printf("\033[31m[TEST]\033[0m - test failed!\n");
    }
}

int main() {
    VM newVM;
    int a = 40;
    int b = 2;
    int expression = a + b + 10 + 39 + 19; // 100
    test_add(&newVM, a, b, expression);
    
    return 0;
}
