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
    if()
}

link LISTtail(link){

}

link LISTcons(Item,link){
}

int LISTlength(link){
}

void LISTprint(link hd){
    if(hd == NULL)
        printf("No List");
    else{
         printf("[");
         print("%d",hd->item);
         while(hd->next != NULL){
            hd = hd->next;
            printf("%,d",hd->item);
            printf("]\n");
         }
}
}
