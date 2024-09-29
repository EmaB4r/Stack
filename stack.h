#ifndef STACK_H
#define STACK_H
#include <stdint.h>
#include <stddef.h>
#include <string.h>

//used to store on the stack the size of the item below
#define PADDING sizeof(size_t)

typedef struct stack_s{
    uint8_t* data;
    unsigned stack_size;
    unsigned used_space;
    unsigned item_size;
}stack_t;

//initializes a stack obj
stack_t stack_init(unsigned size, unsigned item_size);

//saves <item_size> bytes starting from pointer item onto the given stack  
void stack_push(stack_t* stack, void* item);

//pops first item from the stack and returns a pointer to it
// #CAST NEEDED# like type var = *(type*)stack_pop(); 
void * stack_pop(stack_t* stack);

void * stack_peek(stack_t* stack, unsigned index);

void * stack_peek_top(stack_t* stack);

void * stack_peek_bottom(stack_t* stack);

void stack_print(stack_t* stack, char* fmt);

//frees given stack
void stack_free(stack_t*  stack);

//pushes an item variable onto the given stack
#define SSTACK_PUSH(STACK,ITEM) sstack_push(STACK, &ITEM, sizeof(ITEM))

//pops a value from the given stack and casts it to TYPE
#define SSTACK_POP(STACK, TYPE) (*(TYPE*)sstack_pop(STACK))




#endif