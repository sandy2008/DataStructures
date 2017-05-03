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
    else
        return hd->item;
}

link LISTtail(link hd){
    if(hd->next!=NULL)
        return hd->next;
}

link LISTcons(Item n,link hd){
    link newhd = malloc(sizeof(n));
    newhd->item = n;
    newhd->next = hd;
    return newhd;

}

int LISTlength(link hd){
    int count = 0;
    if(hd == NULL) return count;
    else{
    while(hd->next != NULL){
        count++;
        hd = hd->next;
    }
    return count;
    }
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
