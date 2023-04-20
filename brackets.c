#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <string.h>

const int SIZE = 256;
struct STACK
{
    int top;
    int size;
    int data [SIZE];
};

int Push (STACK *pstack, char c);

int Pop (STACK *pstack, char c);

int main ()
{
  char open [3] = {'(', '{', '['};
  char close [3] = {')', '}', ']'};

  char string [256], c = 0;
  int i, k, error = 0;

  STACK stack;
  stack.top = 0;

  printf ("Enter the construction of brackets\n");
  scanf ("%s", string);
  puts (string); //checking the entering expression
  
  int n = strlen (string);
  stack.size = n;

  for (i = 0; i<n; i++) //passing through string []
  {
      c = string [i];
      for (k = 0; k<3; k++) //passing through able types of brackets 
      {
        if (c == open [k])
         {
           if (Push (&stack, c) == -1)
            {
              printf ("ERROR, STACK is overflowing\n");
              error ++;
              break;
            }
           Push (&stack, c);
         }

        if (c == close [k])
        {
          if (Pop (&stack, c) == -1)
           {
             printf ("ERROR, expression begins with a closing bracket or there is a closing bracket without an open bracket the same type before it\n");
             error ++;
             break;
           } 
          
          if (string [i-1] == open [k]) 
           {
             Pop (&stack,c);
           }
          else
          {
            printf ("ERROR, there is a closing bracket without an open bracket the same type before it\n");
            error ++;
          } 
        }
      }  
  }
  
  if (error == 0 && stack.top == 0)
   printf ("It is a right expression\n");
  else
   printf ("There is a incorrect expression\n");

  return 0;
}   

int Push (STACK *pstack, char c)
{
  if (pstack -> top == SIZE)
   return -1;
  else
  {
    pstack -> data [pstack -> top] = c;
    pstack -> top ++;
    return 1;
  }
}

int Pop (STACK *pstack, char c)
{
  if (pstack -> top == 0)
   return -1;
  else
  {
    pstack -> top --;
    return 1;
  }
}    
