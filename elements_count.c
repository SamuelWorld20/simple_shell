#include "lists.h"

/**
 * listtoken_len - Count the number of elements in a listtoken_t list
 * @list_head: Pointer to the first node of the list
 *
 * Return: The number of elements in the list
 */
size_t listtoken_len(const listtoken_t *list_head)
{
	int count = 0;
	const listtoken_t *current_node;

	if (list_head == NULL)
		return (0);

	current_node = list_head;
	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}

	return (count);
}
