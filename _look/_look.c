#include "../main.h"

/**
 * _strlen - countes the length of a string
 * @s: Pointer to the first value of the string.
 *
 * Return: Void.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;
	return (len);
}
/**
 * concat_string - concatenates strings passed to it.
 * @str: The string to append the others to.
 *
 * Return: address of the concated string (success)
 * NULL (error)
 */
char *concat_string(char **str)
{
	ssize_t i, m, j, len = 0;
	char *all; /* the pointer to return after concatination */
	/*
	 * the returned address should be freed in case if someone uses
	 * this function in there code
	 */

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != NULL; i++)
		len = len + _strlen(str[i]);
	all = malloc(sizeof(char) * len + 1);
	if (all == NULL)
		return (NULL);
	m = 0;
	for (i = 0; str[i] != NULL; i++)
	{
		for (j = 0; j < _strlen(str[i]); j++, m++)
			all[m] = str[i][j];
	}
	all[len + 1] = '\0';
	return (all);
}

/**
 * main - checks for the exixstenc of files listd in
 * the array av in the current directory.
 * @av: Null terminated array containing list of file names.
 * descritption: arguments passed to the excutable program.
 * @ac: The number of arguments to passed to the program.
 *
 * Return: 0 (success), 1 (error)
 */
int main(int ac, char *av[])
{
	struct stat st;
	int ret, i;
	char *cwd = NULL, *str = NULL;
	char *path[] = {NULL, "/", NULL};

	if (ac == 1)
	{
		fprintf(stderr, "Usage: %s <files> ...\n", av[0]);
		return (1);
	}
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	path[0] = cwd;
	for (i = 1; av[i] != NULL; i++)
	{
		path[2] = av[i];
		str = concat_string(path);
		if (str == NULL)
			return (1);
		ret = stat(str, &st);
		if (ret == 0)
			printf("%s : FOUND\n", av[i]);
		else
			printf("%s : NOT FOUND\n", av[i]);
		free(str);
	}
	free(cwd);

	return (0);
}
