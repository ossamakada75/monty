#include "monty.h"

/**
 * custom_calloc - Allocates memory for an array of elements and initializes to zero.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to the allocated memory.
 */
void *custom_calloc(unsigned int nmemb, unsigned int size)
{
	void *memory = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	memory = malloc(nmemb * size);
	if (memory == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)(memory) + i) = 0;
	}
	return (memory);
}

/**
 * custom_realloc - Changes the size of the memory block and copies the content.
 * @ptr: Pointer to the memory block to reallocate.
 * @old_size: Old size of the memory block in bytes.
 * @new_size: New size of the memory block in bytes.
 * Return: Pointer to the reallocated memory block.
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < old_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < new_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (new_ptr);
}

