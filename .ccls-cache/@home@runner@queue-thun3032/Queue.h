#include <stdio.h>
#include "Node.h"
#define PRICE_1 100
#define PRICE_2 20
#define PRICE_3 50



typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;



void enqueue_struct(Queue* q, int order, int qt){
  Node *new_node=(Node*) malloc(sizeof(Node));
  if(new_node){ 
      new_node->order_number=order;
      //printf("[%d] ",order);
      new_node->qty=qt;
      //printf("{%d} ",qt);
    new_node->nextPtr=NULL;
    if(q->headPtr==NULL) q->headPtr=new_node;
    else q->tailPtr->nextPtr=new_node;
    q->tailPtr=new_node;
    q->size++;
    /* Finish queue*/
 }
}


int dequeue_struct(Queue *q){
  NodePtr t=q->headPtr;
  if(t){
    int cost=0;
    {
      switch(t->order_number){
        case 1: 
          printf("My order is 1\n");
          //printf("\nRamen");
          cost=cost+(PRICE_1*t->qty);
          //printf("(%dx, %d)",t->qty,cost);
          break;
        case 2: 
          printf("My order is 2\n");
          //printf("\nSomtum");
          cost=cost+(PRICE_2*t->qty);
          //printf("(%dx, %d)",t->qty,cost);
          break;
        case 3: 
          printf("My order is 3\n");
          //printf("\nFried Chicken");
          cost=cost+(PRICE_3*t->qty);
          //printf("(%dx, %d)",t->qty,cost);
          break;
        default: printf("No food\n"); break;
      }
    }
    q->headPtr=t->nextPtr;
    if(q->headPtr==NULL) 
      q->tailPtr=NULL;
    q->size--;
    free(t);
      return cost;
  }
  else{
    printf("The queue is empty");
    return 0;
  }
}

void printqueue(Queue *q){
  printf("\n");
  NodePtr t=q->headPtr;
  while(t){
    printf("%d %d ",t->order_number,t->qty);
    t=t->nextPtr;
  }
  printf("\n");
}