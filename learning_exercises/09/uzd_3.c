#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
	double x;
	double y;
} Point;

Point createPoint(double x, double y){
	Point p = {x, y};
	return p;
}

void printPoint(Point p){
	printf("( %.1f , %.1f )\n", p.x, p.y);
	return;
}

typedef struct Stack{
Point *array;
int size;
}Stack;


void initStack(Stack *stack){

	stack->size = 0;
	stack->array = (Point *)malloc(stack->size * sizeof(Point));

	if(stack->array == NULL){
		exit(1);
	}
	
	for(int i = 0; i < stack->size; ++i){
		stack->array[i] = createPoint(0, 0);
	}
}


void printStack(Stack *stack){
	
	for(int i = (stack->size-1); i >= 0; --i)
		printPoint(stack->array[i]);
}


int getStackSize(Stack *stack){
  return (stack->size * sizeof(Point));
}


void push(Stack *stack, Point p){
	stack->size += 1;
	stack->array = (Point *)realloc(stack->array, stack->size * sizeof(Point));

	if(stack->array == NULL)
		exit(1);

	stack->array[stack->size - 1] = p;
}


Point top(Stack *stack){
  return(stack->array[stack->size - 1]);
}

Point pop(Stack *stack){

	Point last_point = top(stack);
	stack->size -= 1;
	stack->array = (Point *)realloc(stack->array, stack->size * sizeof(Point));

	if(stack->array == NULL && stack->size > 0)
	exit(1);

  return last_point;
}

void destroyStack(Stack *stack){
	free(stack->array);
	initStack(stack);
}

double getDistance(Point p){
	return (sqrt(pow(0 - p.x, 2) + pow(0 - p.y, 2)));
}


int main() {
	

	
	Stack arr;
	initStack(&arr);
	int arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);

	printf("\nStakas pries Push:\n");
	printStack(&arr);
	
	
	double x, y, distance;

	x = 2;
	y = -3;
	Point p = createPoint(x, y);
	
	push(&arr, p);
	printf("\nStakas po 1 Push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	
	x = -4;
	y = 5;
	p = createPoint(x, y);
	push(&arr, p);
	printf("\nStakas po 2 Push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	x = 10;
	y = -9.4;
	p = createPoint(x, y);
	push(&arr, p);
	printf("\nStakas po 3 Push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	x = 0;
	y = 0;
	p = createPoint(x, y);
	push(&arr, p);	
	printf("\nStakas po 4 Push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	x = 4;
	y = 3;
	p = createPoint(x, y);
	push(&arr, p);	
	printf("\nStakas po 5 Push:\n");
	printStack(&arr);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	
	
	printf("\nPopintas 5 pointas: ");
	Point p_v = pop(&arr);
	printPoint(p_v);
	distance = getDistance(p_v);
	printf("Jo atstumas iki ( 0 , 0 ) = %f\n", distance);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	printf("\nPopintas 4 pointas: ");
	p_v = pop(&arr);
	printPoint(p_v);
	distance = getDistance(p_v);
	printf("Jo atstumas iki ( 0 , 0 ) = %f\n", distance);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	printf("\nPopintas 3 pointas: ");
	p_v = pop(&arr);
	printPoint(p_v);
	distance = getDistance(p_v);
	printf("Jo atstumas iki ( 0 , 0 ) = %f\n", distance);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	printf("\nPopintas 2 pointas: ");
	p_v = pop(&arr);
	printPoint(p_v);
	distance = getDistance(p_v);
	printf("Jo atstumas iki ( 0 , 0 ) = %f\n", distance);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	
	printf("\nPopintas 1 pointas: ");
	p_v = pop(&arr);
	printPoint(p_v);
	distance = getDistance(p_v);
	printf("Jo atstumas iki ( 0 , 0 ) = %f\n", distance);
	arr_capacity = getStackSize(&arr);
	printf("Dydis: %d\n", arr_capacity);
	

	
	destroyStack(&arr);	
	printf("\n\nStakas po DestroyStack:\n");
	printStack(&arr);
	

	free(arr.array);

return 0;
}
