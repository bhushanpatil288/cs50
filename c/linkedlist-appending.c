#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  node *list = NULL;

  for (int i = 0; i < 3; i++)
  {
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      // todo free any momory already melloc'd
      node *ptr = list;
      while(ptr != NULL)
      {
        node next = ptr->next;
        free(ptr);
        ptr = next;
      }
      return 1;
    }

    n->number = get_int("Number: ");
    n->next = NULL;

    // if list is empty
    if(list == NULL)
    {
        list = n;
    }

    // if list has number already
    else
    {
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                ptr->next = n;
                break;
            }
        }
    }

  }

  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%i\n", ptr->number);
  }

  // freeing up memory
  node *ptr = list;
  while(ptr != NULL)
  {
    node next = ptr->next;
    free(ptr);
    ptr = next;
  }

  return 0;
}
