#include<stdio.h>
#include "BTREE.h"

int ctoi(char c){ return (c - '0'); }
int evalTree(BTlink tr){
    if (tr->label==NULL)
        return 0;
    if (BTisLeaf(tr)==1)
        return tr->label;
    if (tr->label=='+')
        return tr->l->label+tr->r->label;
    if (tr->label=='-')
        return tr->l->label-tr->r->label;
    if (tr->label=='*')
        return tr->l->label*tr->r->label;
}
void main(void){
   BTlink treeOne = BTcons('1', NULL, NULL);
   BTlink treeTwo = BTcons('2', NULL, NULL);
   BTlink treeThree = BTcons('3', NULL, NULL);
   BTlink treeFour = BTcons('4', NULL, NULL);
   BTlink treeFive = BTcons('5', NULL, NULL);
   BTlink treeRRR = BTcons('+', treeFour, treeFive);
   BTlink treeRR = BTcons('*', treeThree, treeRRR);
   BTlink treeR = BTcons('+', treeTwo, treeRR);
   BTlink tree = BTcons('+', treeOne, treeR);
   printf("result = %d\n", evalTree(tree)) ;
}
