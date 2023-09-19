#include "monty.h"

_extern_var_t ex;

/**
 * main - function honestly, idk.
 * @argc: idk.
 * @argv: idk.
 * Return: less find out god.
 */
int main(int argc, char *argv[])
{
	FILE *fp;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	_read_file(fp);
	fclose(fp);
	return (0);
}

/**
 * _read_file - function honestly, idk.
 * @fp: idk.
 */
void _read_file(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	int i;
	stack_t *top_ptr = NULL;

	ex.fp = fp;


	i = 1;
	while (getline(&line, &len, fp) != -1)
	{
		if (_not_empty(line))
		{
			ex.data = _clean_spaces(line);
			if (ex.data.value != NULL)
			{
				ex.int_value = atoi(ex.data.value);
			}
			ex.data.line_n = i;
			ex.line = line;
			_execute_function(&top_ptr);
		}
		i++;
	}
	free(line);
	_free_stack(top_ptr);
}

/**
 * _execute_function - function honestly, idk.
 * @stack: idk.
 * Return: less find out god.
 */
void _execute_function(stack_t **stack)
{
	instruction_t functions[] = {
		{"push", _monty_push}, {"pall", _monty_pall}, {"pint", _monty_pint},
		{"pop", _monty_pop}, {"swap", _monty_swap}, {"add", _monty_add},
		{"sub", _monty_sub}, {"nop", _monty_nop}, {"div", _monty_div},
		{"mul", _monty_mul}, {"mod", _monty_mod}, {"pchar", _monty_pchar},
		{"pstr", _monty_pstr}, {NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode; i++)
	{
		if (!strcmp(ex.data.op_func, functions[i].opcode))
		{
			functions[i].f(stack, ex.data.line_n);
			break;
		}
	}
	if (!functions[i].opcode)
	{

		fprintf(stderr, "L%d: unknown instruction", ex.data.line_n);
		fprintf(stderr, " %s\n", ex.data.op_func);
		free(ex.line);
		fclose(ex.fp);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * _free_stack - function honestly, idk.
 * @top_ptr: idk.
 * Return: less find out god.
 */
void _free_stack(stack_t *top_ptr)
{
	stack_t *last;
	stack_t *prevNode;

	last = top_ptr;

	if (last)
	{
		prevNode = last->prev;

		while (prevNode)
		{
			free(last);
			last = prevNode;
			prevNode = prevNode->prev;
		}
		free(last);
	}
}
