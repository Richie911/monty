#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: head
 * @counter: count
 * Return: void
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int i = 0, j;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	j = temp->n + temp->next->n;
	temp->next->n = j;
	*head = temp->next;
	free(temp);
}
