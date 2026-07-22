#include <stdio.h>
int main(){
    int size,i;
    printf("enter size of array:");
    scanf("%d",&size);

    int arr[size];

    printf("enter %d array elements:\n",size);

    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("array elements are:\n");

    for(i=size-1;i>=0;i--){
        printf("%d ",arr[i]);
}
return 0;
}