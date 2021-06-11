#include <stdio.h>

const int MAX = 10;
int g_stack[10];
int top;

void push(int x)
{
	if (top >= MAX - 1) {
		printf("stack overflow\n");
		return ;
	}
	g_stack[++top] = x;
}

int pop(void)
{
	if (top - 1 < 0) {
		printf("stack underflow\n");
		return (1);
	}
	--top;
	return (g_stack[top + 1]);
}

int main(void)
{
	for (int i = 0; i < 11; i++) {
		push(5);
	}
	for (int i = 0; i < MAX + 1 + 1; i++) {
		printf("%d ", g_stack[i]);
	}
	printf("\n");
	for (int i = 0; i < 11; i++) {
		pop();
	}
	printf("%d\n", top);
}
