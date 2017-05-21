#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "LIST.h"


void main(void){
  link hd;

  hd = LISTempty();

  printf("Cons of 10 and ");
  LISTprint(hd);
  hd = LISTcons(10,hd);
  LISTprint(hd);

  printf("Cons of 20 and ");
  LISTprint(hd);
  hd = LISTcons(20,hd);
  LISTprint(hd);

  printf("Taking the head of ");
  LISTprint(hd);
  printf("%d\n", LISThead(hd));

  printf("Taking the tail of ");
  LISTprint(hd);
  hd = LISTtail(hd);
  LISTprint(hd);

  printf("The length of ");
  LISTprint(hd);
  printf("length = %d\n", LISTlength(hd));
}
