#include <stdio.h>
#include "sort.h"
#include "LIST.h"

link mergeListAB(link fst, link snd){
    link head;
    link headstart;
    if(fst->item <= snd->item){
        head = fst;
        fst = fst->next;
        headstart = head;
    }
    else if(fst->item > snd->item){
        head = snd;
        snd = snd->next;
        headstart = head;
    }
    while((fst!=NULL)||(snd!=NULL)){

        if(fst==NULL){
            head -> next = snd;
            snd = snd->next;
        }
        else if(snd==NULL){
            head -> next = fst;
            fst = fst->next;
        }
        else if(fst->item <= snd->item){
            head -> next = fst;
            fst = fst -> next;
        }
        else if(fst->item > snd->item){
            head -> next = snd;
            snd = snd -> next;
        }
        head = head -> next;
    }
    return headstart;
}
link splitList(link a, int len){
    int i;
    link b;
    b = a;
    for(i = 0;i < len-1; i++){
        b = b->next;
    }
    link c = b->next;
    b -> next = NULL;
    return c;
}

link mergesortList(link a){
    int N = LISTlength(a);
    if(N <= 1) return a;
    link fst = a;
    link snd = splitList(a, N/2);
    fst = mergesortList(fst);
    snd = mergesortList(snd);
    return mergeListAB(fst, snd);
}

void main(void){
    link lst = LISTcons(6,NULL);
    lst = LISTcons(4,lst); lst = LISTcons(2,lst); lst = LISTcons(5,lst);
    lst = LISTcons(7,lst); lst = LISTcons(3,lst); lst = LISTcons(1,lst);
    LISTprint(lst);
    lst = mergesortList(lst);
    LISTprint(lst);
}
