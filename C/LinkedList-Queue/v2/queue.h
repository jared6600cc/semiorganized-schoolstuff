#ifndef queue
#define queue
  #include<stdlib.h>
  #include<stdio.h>
  // the struct definition
  typedef struct queueNode
  {
    int value;
    struct queueNode * next;
  } queueStruct;

  queueStruct * head, * tail;

  // prototypes
  void enqueue(int val);
  int dequeue();
  int isEmpty();
#endif
