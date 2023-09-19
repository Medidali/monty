#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct _content  - opcode and its function
 * @op_func: the opcode
 * @value: function to handle the opcode
 * @line_n: number of the line
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct _content
{
	char *op_func;
	char *value;
	int line_n;
} _content_v;

/**
 * struct _stakit  - opcode and its function
 * @int_value: idk.AOA
 * @data: idk.
 * @fp: idk.
 * @line: idk.
 * Description: honestly, idk.
 */
typedef struct _stakit
{
	int int_value;
	_content_v data;
	FILE *fp;
	char *line;
} _extern_var_t;
extern _extern_var_t ex;

int main(int argc, char *argv[]);
void _read_file(FILE *fp);
void _execute_function(stack_t **stack);
size_t _not_empty(char *line);
_content_v _clean_spaces(char *line);

void _monty_push(stack_t **top, unsigned int line_n);
void _monty_pall(stack_t **top, unsigned int line_n);
void _monty_pint(stack_t **top, unsigned int line_n);
void _monty_pop(stack_t **top, unsigned int line_n);
void _monty_swap(stack_t **top, unsigned int line_n);
void _monty_add(stack_t **top, unsigned int line_n);
void _monty_sub(stack_t **top_ptr, unsigned int line_n);
void _monty_mul(stack_t **top_ptr, unsigned int line_n);
void _monty_nop(stack_t **top_ptr, unsigned int line_n);
void _monty_div(stack_t **top_ptr, unsigned int line_n);
void _monty_mod(stack_t **top_ptr, unsigned int line_n);
void _monty_pchar(stack_t **top_ptr, unsigned int line_n);
void _monty_pstr(stack_t **top_ptr, unsigned int line_n);

void _free_stack(stack_t *top_ptr);
#endif
