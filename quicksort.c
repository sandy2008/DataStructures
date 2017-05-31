void quicksort(Item a[],int left,int right){
    int i;
    if (right <= left) return;
    i = partition(a,left,right);
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
