#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: head
 * @counter: count
 * Return: void
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;

	temp = *head;
	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
