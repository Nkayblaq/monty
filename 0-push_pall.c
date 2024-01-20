#include "monty.h"

/**
 * addnode - Adds a new node to the stack.
 * @head: Pointer to the top of the stack.
 * @n: Value of the new node.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;
}

/**
 * f_push - Implements the push opcode.
 * @head: Pointer to the top of the stack.
 * @counter: Line number in the Monty file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	if (!bus.arg || !isdigit(bus.arg[0]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	int value = atoi(bus.arg);

	addnode(head, value);
}

/**
 * f_pall - Implements the pall opcode.
 * @head: Pointer to the top of the stack.
 * @counter: Line number in the Monty file (unused in this function).
 */
void f_pall(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
