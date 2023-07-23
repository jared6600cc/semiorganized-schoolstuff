#include<stdio.h>
#include"defs.h"
#include<math.h>
#include"queue.h"

int main()
{
  puts("in main\n");
  x = 5;
  printf("%d\n",x);
  double d = 4.0;
  d = sqrt(d);
  printf("square root of d = %lf\n",d);
  int i;
  for(i = 0; i < 5; i++)
    enqueue(i);
  while(!isEmpty())
    printf("%d\n", dequeue());  
  return 0;
}
