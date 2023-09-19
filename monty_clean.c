#include "monty.h"

/**
 * _not_empty - function honestly, idk.
 * @line: idk.
 * Return: 0 if empty, 1 if not empty..
 */
size_t _not_empty(char *line)
{
	size_t i;

	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break;
	}
if (i == strlen(line) || line[i] == '#')
{
return (0);
}
return (1);
}

/**
 * _clean_spaces - function honestly, idk.
 * @line: idk.
 * Return: data struct.
 */
_content_v _clean_spaces(char *line)
{
	_content_v data;
	char *token;
	size_t i;

	data.op_func = NULL;
	data.value = NULL;
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token, ""))
		{
			data.op_func = token;
			break;
		}
		token = strtok(NULL, " \n\t");
	}
	if (token == NULL)
		return (data);

	token = strtok(NULL, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token, ""))
		{
			for (i = 0; i < strlen(token); i++)
			{
				if (!(token[i] >= '0' && token[i] <= '9'))
					if (token[0] != '-')
						break;
			}
			if (i == strlen(token))
			{
				if (!strcmp(token, "-0"))
					data.value = 0;
				data.value = token;
			}
		}
		token = strtok(NULL, " \n\t");
	}
	return (data);
}
