#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 * PESSY KAPERE
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
 size_t numor = 0;

 while (h)
 {
 printf("%d\n", h->n);
 numor++;
 h = h->next;
 }

 return (numor);
}
