#include "lists.h"

/**
 * free_listtoken - frees a listtoken_t list
 * @head_ptr: Pointer to a pointer that points to the first node
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head_ptr)
{
	listtoken_t *current_node;

	if (head_ptr == NULL)
		return;

	while (*head_ptr != NULL)
	{
		current_node = *head_ptr;
		current_node = current_node->next;
		free(current_node->token);
		free(current_node);
	}
	head_ptr = NULL;
}
