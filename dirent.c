#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include "main.h"
/**
 * checkexe - checks if a file is in path
 * @s: file name
 *
 * Return: 1 (If found) 0 (Not found)
 */
int checkexe(char *s)
{
	struct dirent *dirent;
	DIR *dir;

	dir = opendir("/usr/bin/");

	if (dir)
	{
		while ((dirent = readdir(dir)))
		{
			if (_strcmp(dirent->d_name, s))
				return (1);
		}
	}
	else
	{
		printf("Error! Could not find path");
	}
	return (0);
}
