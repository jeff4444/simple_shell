#include "main.h"
/**
 * _realloc - reallocates memory
 * @ptr: pointer
 * @new: new size of pointer
 * Return: new pointer
 */

void *_realloc(void *ptr, unsigned int new)
{
	char *point;
	unsigned int old = sizeof(ptr);

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);

	point = malloc(new);
	if (!point)
		return (NULL);

	old = old < new ? old : new;
	while (old--)
		point[old] = ((char *)ptr)[old];
	free(ptr);
	return (point);
}
