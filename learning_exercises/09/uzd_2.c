#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int *array;
	int size;
}Stack;


void initStack(Stack *stack){
	
	stack->size = 0;
	stack->array = (int *)malloc(stack->size * sizeof(int));

	if(stack->array == NULL)
	exit(1);

	for(int i = 0; i < stack->size; ++i)
		stack->array[i] = 0;

}


void printStack(Stack *stack){
	for(int i = (stack->size - 1); i >= 0; --i)
	printf("%d\n", stack->array[i]);

}


int getStackSize(Stack *stack){
  return(stack->size * sizeof(int));
}


void push(Stack *stack, int value){
	stack->size += 1;
	stack->array = (int *)realloc(stack->array, stack->size * sizeof(int));

	if(stack->array == NULL)
		exit(1);

	stack->array[stack->size - 1] = value;
}


int top(Stack *stack){
  return(stack->array[stack->size - 1]);
}


int pop(Stack *stack){
	
	int last_num = top(stack);
	stack->size -= 1;
	stack->array = (int *)realloc(stack->array, stack->size * sizeof(int));

	if(stack->array == NULL && stack->size > 0)
		exit(1);
	
  return(last_num);
}

void destroyStack(Stack *stack){
	free(stack->array);
	initStack(stack);
}

int main() {
	
	Stack arr;
	initStack(&arr);
	
	printf("\nStakas pries push:\n");
	printStack(&arr);

	int arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);

	int value = 1;
	push(&arr, value);
	printf("\n\nStakas po push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	
	value = 5;
	push(&arr, value);
	printf("\n\nStakas po 2 push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	
	value = 7;
	push(&arr, value);
	printf("\n\nStakas po 3 push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);

	int pop_num = pop(&arr);
	printf("\nPopinatas skaicius: %d\n", pop_num);
	
	pop_num = pop(&arr);
	printf("\nPopinatas skaicius: %d\n", pop_num);

	printf("\nStakas po 2 pop:\n");
	printStack(&arr);
	
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	destroyStack(&arr);
	
	printf("\nStakas po destroy Stack:\n");
	printStack(&arr);

	free(arr.array);

return 0;
}
