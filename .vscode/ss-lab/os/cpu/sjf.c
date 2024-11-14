


#include<stdio.h>
#include<stdlib.h>
struct processes
{
    int pid;
    int ct;
    int at;
    int bt;
    int wt;
    int tat;
};
void main()
{
    int i,j,n,ttat,twt,ct=0;
   
    printf("enter no of requests\t");
    scanf("%d",&n);
     struct processes proc[n],temp;
     printf("\nenter pid at bt of each\t:\n");
     for(i=0;i<n;i++)
     {
        scanf("%d%d%d",&proc[i].pid,&proc[i].at,&proc[i].bt);
     }
     for(i=0;i<n;i++)
     {
        for(j=0;j<n-i-1;j++)
        {
            if(proc[j].at>proc[j+1].at)
            {
                
                
                 temp=proc[j];
                proc[j]=proc[j+1];
                proc[j+1]=temp;
            }
        }
     }
     for(i=0;i<n;i++)
     {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(proc[j].at<=ct && proc[j].bt<proc[min].bt )
            {
                min=j;
            }
        }
         temp =proc[i];
        proc[i] = proc[min];
        proc[min]= temp;
        if(ct<=proc[i].at)
        {
            ct=proc[i].at;
        }
        ct+=proc[i].bt;
        proc[i].ct=ct;
        proc[i].tat=proc[i].ct-proc[i].at;
        proc[i].wt=proc[i].tat-proc[i].bt;

     }
    
  printf("SJF algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time\tCompletion Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].tat, proc[i].wt, proc[i].ct);
    }
}


