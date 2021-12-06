#include "monty.h"

/**
 * main - Program entry point
 *
 * @argc: number of argument passed
 * @argv: A stream of arguement passed
 * Return: 1
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char **arr;
	int i;
	stack_t *stacklist;

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

	stacklist = NULL;

	i = 0;

	while (getline(&line, &len, fp) != -1)
	{
		i++;

		arr = _strtok(line, " \t\n\b");

		
		/*free(line);*/
		if (arr == NULL)
			continue;

		if (arr[0][0] == '#')
		{
			continue;
		}

		d_function(arr, &stacklist, i);
		/*printf("%s\n", arr[0]);*/

		/*
		for (i = 0; arr[i] != NULL; i++)
		{
			printf("%d - %s, ", i, arr[i]);
		}
		printf("\n");
		*/
		/*free(arr);*/
	}

	if (stacklist)
		free_dlistint(stacklist);

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
