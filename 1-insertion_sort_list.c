#include "sort.h"

/**
 * swap - swaps to nodes in a doubly linked list
 * @left_node: - pointer to the left node
 * @right_node: - pointer to the right node
 * @list: - pointer to the doubly linked list
 * Return: void
 */
void swap(listint_t **list, listint_t *left_node, listint_t *right_node)
{
	listint_t *left_prev;
	listint_t *right_next;

	left_prev = left_node->prev;
	right_next = right_node->next;

	right_node->next = left_node;
	right_node->prev = left_prev;
	if (left_prev)
		left_prev->next = right_node;
	else
		*list = right_node;
	left_node->prev = right_node;
	left_node->next = right_next;
	left_node->prev = right_node;
	if (right_next)
		right_next->prev = left_node;
}

/**
 * insertion_sort_list - sorts a list using insertion sort
 * @list: pointer to a doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *next_node = *list;

	if (next_node == NULL || next_node->next == NULL)
		return;

	while (next_node)
	{
		node = next_node;
		if (node->prev && node->prev->n > node->n)
		{
			next_node = node->prev;
			while (node->prev && node->prev->n > node->n)
			{
				swap(list, node->prev, node);
				print_list(*list);
			}
		}
		else
			next_node = node->next;
	}
}
