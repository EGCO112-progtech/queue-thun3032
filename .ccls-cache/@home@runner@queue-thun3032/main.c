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
   
  int count=0;
 for(i=1;i<argc;i++){
        price=0;
        if(strcmp(argv[i],"x")==0){
            printqueue(&q);
            while(q.size!=0){
              price=price+dequeue_struct(&q);
            }
            printf("\nTotal Price: %d\n",price);
        }
        else {
          enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
          i++;
        }
 }
  return 0;
}
