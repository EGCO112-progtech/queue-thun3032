#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
   NodePtr tailPtr=NULL;
   Queue  q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;
   int i,price;
   
  int count=1,first_order=0;
  for(i=1;i<argc;i++){
        price=0;
        if(strcmp(argv[i],"x")==0){
          //printqueue(&q);
          while(q.size!=0){
            price=price+dequeue_struct(&q);
          }
          switch(first_order){
            case 1:{
              printf("Ramen\n");
              break;
            }
            case 2:{
              printf("Somtum\n");
              break;
            }
            case 3:{
              printf("Fried Chicken\n");
              break;
            }
            default: break;
          }  
          printf("You have to pay: %d\n",price);
          int input=0;
          do{
            printf("Cash: ");
            scanf("%d",&input);
          }
          while(input<price);
          printf("Thank you\n");
          if(input>price) printf("Change is: %d\n",input-price); 
          printf("\n");
          count=1;
        }
        else{
          enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
          if(count==1) first_order=atoi(argv[i]);
          i++;
          count++;
        }
  }
  printf("=======================================\n");
  if(q.size>=1){
    if(q.size==1) printf("There is 1 person left in the queue.");
    else printf("There are %d people left in the queue.",q.size);
  }
  return 0;
}
