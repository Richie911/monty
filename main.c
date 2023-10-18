#include "monty.h"
/**
 * main - main program
 * @argc: arg count
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *file_path;
	ssize_t line = 1;
	size_t line_buf_size = 0;
	char *line_buf;
	int i;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_path = fopen(argv[1], "r");
	bus.file = file_path;
	if (file_path == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		line = getline(&line_buf, &line_buf_size, file_path);
		bus.content = line_buf;
		i++;
		if (line > 0)
			execute(line_buf, &stack, i, file_path);
		free(line_buf);
	}
	free_stack(stack);
	fclose(file_path);
	return (0);
}
