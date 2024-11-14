#include<stdio.h>
#include<stdlib.h>
void main()
{
    int queue[20],i,j,n,head,seek=0,diff;
    int max;
    printf("enter range of the disk\t");
    scanf("%d",&max);
    printf("\nenter no of requests in the queue\t");
    scanf("%d",&n);
    printf("\nenter the requests\t");
    for(i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    printf("\nENetr head\t");
    scanf("%d",&head);
    for(j=0;j<n;j++)
    {
        diff=abs(head-queue[j]);
        seek+=diff;
        printf("\ndisk moves from %d to %d in seek time %d\t",head,queue[j],seek);
        head=queue[j];
    }
    printf("\ntotal seek time:%d\t",seek);
    
}