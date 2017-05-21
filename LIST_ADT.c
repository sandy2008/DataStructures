#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "LIST.h"

typedef int Item;

link LISTempty(void){
 return NULL;
}

Item LISThead(link x){
  if (x == NULL) return 0;
  return x->item;
}

link LISTtail(link x){
   if (x == NULL) return NULL;
  return x->next;
}

link makeNew(Item item){
 link x;
 x = malloc(sizeof(*x));
 x->item = item;
 x->next = NULL;
 return x;
}

link LISTcons(Item n, link x){
  link t = makeNew(n);
  t->next = x;
  return t;
}

int LISTlength(link x){
  int c = 0;
  link t = x;
  while(t != NULL){
    c++;
    t = t->next;
  }
   return c;
}

void LISTprint(link x){
  link t = x;
  printf("[");
  while(t != NULL){
    printf("%d ", t->item);
     t = t->next;
   }
  printf("]\n");
}
