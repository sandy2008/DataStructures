#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "BTREE.h"
#define max(x,y) ((x) > (y) ? (x) : (y))

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
   if(tr == NULL){
	printf("Null");
	return;
   }
   printf("Node(%c, ",tr->label);
   BTprint(tr->l);
   printf(", ");
   BTprint(tr->r);
   printf(")");
   return;
}

int BTsize(BTlink tr){
    if (tr!=NULL){
        if(tr->l==NULL&&tr->r==NULL){
            return 1;
	 }
        else
            return BTsize(tr->l) + BTsize(tr->r);
   }
   else
	return 0;
}

int BTisLeaf(BTlink tr, link path){
   if(path == NULL)
	return 0;
   switch(LISThead(path)){
   case 0:
   if(tr->l == NULL)
	return 0;
   if(tr->l->l == NULL&& tr->l->r == NULL)
    return 1;
   return BTisLeaf(tr->l, LISTtail(path));
   break;
   case 1:
   if(tr->r == NULL)
	return 0;
   if(tr->r->l == NULL&& tr->r->r == NULL)
    return 1;
   return BTisLeaf(tr->r, LISTtail(path));
   break;
   default:
   return 0;
   break;
  }
}

int BTleaves(BTlink tr) {
    int result = 0;
    if (tr->l == NULL && tr->r == NULL)
        result += 1;
    if (tr->l != NULL)
        result += BTleaves(tr->l);
    if (tr->r != NULL)
        result += BTleaves(tr->r);
    return result;
}

int BTedges(BTlink tr) {
    int result = 0;
    if (tr->l != NULL)
        result += BTleaves(tr->l)+1;
    if (tr->r != NULL)
        result += BTleaves(tr->r)+1;
    return result;
}

char BTlabel(BTlink tr, link path){
   if(path == NULL)
	return tr->label;
   switch(LISThead(path)){
   case 0:
   if(tr->l == NULL)
	return '\0';
   return BTlabel(tr->l, LISTtail(path));
   break;
   case 1:
   if(tr->r == NULL)
	return '\0';
   return BTlabel(tr->r, LISTtail(path));
   break;
   default:
   return '\0';
   break;
  }
}

link BTlongestPath(BTlink tr){
    if(tr->l != NULL||tr->r != NULL){
            link leftPath = BTlongestPath(tr->l);
            link rightPath = BTlongestPath(tr->r);
            if(LISTlength(leftPath)>=LISTlength(rightPath))
                return LISTcons(0, leftPath);
            else
                return LISTcons(1, rightPath);
    }
    else
        return LISTempty();

}

int BTheight(BTlink tr){
    if (tr == NULL)
        return -1;
    else
        return 1 + max(BTheight(tr->l),BTheight(tr->r));
}

int BTcheckComplete(BTlink tr){
    if(tr->l==NULL&&tr->r==NULL)
        return 1;
    else if(tr->l!=NULL&&tr->r!=NULL)
        return BTcheckComplete(tr->l)&&BTcheckComplete(tr->r);
    else
	return 0;
}

int BTcheckBalanced(BTlink tr){
    if(tr == NULL)
        return 1;
    else if(abs(BTheight(tr->l)-BTheight(tr->r))<=1)
        return BTcheckBalanced(tr->l)&&BTcheckBalanced(tr->r);
    else
	return 0;
}
