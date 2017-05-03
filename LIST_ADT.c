#include <stdlib.h>
#include "Item.h"
#include "LIST.h"

static link head;

link LISTempty(void){
    return NULL;
}

Item LISThead(link hd){
    if (hd == NULL)
        return 0;

}

link LISTtail(link hd){

}

link LISTcons(Item n,link hd){
    link newhd = malloc(sizeof(n));
    newhd->item = n;
    newhd->next = hd;
    return newhd;
    
}

int LISTlength(link hd){

}

void LISTprint(link hd){
    if(hd == NULL)
        printf("No List");
    else{
         printf("[");
         printf("%d",hd->item);
         while(hd->next != NULL){
            hd = hd->next;
            printf(",%d",hd->item);
         }
         printf("]\n");
}
}
