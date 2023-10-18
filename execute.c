#include "monty.h"
/**
* execute - executes opcode
* @stack: head
* @counter: counter
* @file: poiner to file
* @content: content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	int i;
	char *operator;
	instruction_t funcs[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop}, {"swap", _swap}, {"add", _add},
				{"nop", _nop}, {"sub", f_sub}, {"div", f_div},
				{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
				{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};

	operator = strtok(content, " \n\t");
	if (operator && operator[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (funcs[i].opcode && operator)
	{
		if (strcmp(operator, funcs[i].opcode) == 0)
		{	funcs[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (operator && funcs[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, operator);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
