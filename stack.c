#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int shithappens=-1;

//stack_init
stack_t stack_init(unsigned size, unsigned item_size){
    //if(size<100) size = 100;
    stack_t s;
    s.used_space=0;
    s.stack_size=size;
    s.item_size=item_size;
    s.data=malloc(size*item_size);
    return s;
}

void stack_push(stack_t* stack, void* item){
    if(stack->used_space+1 >= stack->stack_size){
        stack->stack_size*=1.5;
        stack->data=realloc(stack->data, stack->item_size*stack->stack_size);
    } 
    memcpy(&stack->data[stack->used_space*stack->item_size], item, stack->item_size);
    stack->used_space++;
}
void * stack_pop(stack_t* stack){
    if(stack->used_space==0) return &shithappens;
    stack->used_space--;
    return &stack->data[stack->used_space*stack->item_size];
}

void * stack_peek(stack_t* stack, unsigned index){
    if(index >= stack->used_space) return &shithappens;
    return &stack->data[stack->item_size*(stack->used_space-index-1)];
}

void * stack_peek_top(stack_t* stack){
    return stack_peek(stack, 0);
}

void * stack_peek_bottom(stack_t* stack){
    return stack_peek(stack, stack->used_space-1);
}

void stack_print(stack_t* stack, char* fmt){
    int SP=stack->used_space-1;
    printf("--TOP--\n");
    while(SP>=0){
        printf(fmt, (int)stack->data[SP*stack->item_size]);
        SP--;
    }
    printf("--BOTTOM--\n");
}

void stack_free(stack_t* stack){
    if (stack!=NULL){
        if(stack->data!=NULL){
            free(stack->data);
        }
    }
}