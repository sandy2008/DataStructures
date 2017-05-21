#include<stdio.h>
#include "LIST.h"
#include "BTREE.h"

void main(void){
BTlink treeRR = BTcons('G',NULL,NULL);
BTlink treeRL = BTcons('F',NULL,NULL);
BTlink treeLR = BTcons('E',NULL,NULL);
BTlink treeLL = BTcons('D',NULL,NULL);
BTlink treeR = BTcons('C',treeRL,treeRR); 
BTlink treeL = BTcons('B',treeLL,treeLR);
BTlink tree = BTcons('A',treeL,treeR);
link pathRL = LISTcons(1, LISTcons(0,LISTempty()));
BTprint(tree);printf("\n\n");

printf("Size : %d\n", BTsize(tree));           
printf("Lvs : %d\n", BTleaves(tree));
printf("Edgs : %d\n", BTedges(tree));
printf("Lbl : %c\n", BTlabel(tree, pathRL));

}
