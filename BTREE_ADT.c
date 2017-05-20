#include <stdlib.h>
#include <stdio.h>
#include <BTREE.h>
#include <LIST.h>

BTlink newNode(char c){
   BTlink head = malloc(sizeof(*head));
   head->label = c;
   head->l = NULL;
   head->r = NULL;
   return head;
}

BTlink BTcons(char c, BTlink left, BTlink right){
   BTlink head = newNode(c);
   head->l = left;
   head->r = right;
   return head;
}

BTlink BTsubtree(BTlink tr, link path){
   if(path == NULL)
	return tr;
   switch(LISThead(path)){
   case 0:
   if(tr->l == NULL)
	return NULL;
   return BTsubtree(tr->l, LISTtail(path));
   break;
   case 1:
   if(tr->r == NULL)
	return NULL;
   return BTsubtree(tr->r, LISTtail(path));
   break;
   default:
   return NULL;
   break;
  }
}

void BTprint(BTlink tr){
   if(tr = NULL){
	printf("Null");
	return;
   }
   printf("Node(%c, ",tr->item);
   BTprint(tr->l);
   printf(", ");
   BTprint(tr->r);
   printf(")");
   return;
}