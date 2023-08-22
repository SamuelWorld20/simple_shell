#include "lists.h"

/**
 * add_nodetoken_end - adds a new node at the end of a listtoken_t list
 * @head_ptr: A pointer to a pointer that points to the first node of the list
 * @token: The token to be stored in the new node
 *
 * Return: A pointer to the new node, or NULL if the operation failed
 */
listtoken_t *add_nodetoken_end(listtoken_t **head_ptr, char *token)
{
	listtoken_t *new_node, *last_node;

	if (head_ptr == NULL)
		return (NULL);

	new_node = malloc(sizeof(listtoken_t));
	if (new_node == NULL)
		return (NULL);

	new_node->token = token;
	new_node->token_length = strlen(token);
	new_node->next = NULL;

	if (*head_ptr == NULL)
		*head_ptr = new_node;
	else
	{
		last_node = *head_ptr;
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (last_node);
}
