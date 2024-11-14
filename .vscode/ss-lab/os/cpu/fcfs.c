#include<stdio.h>
#include<stdlib.h>
void findwt(int n,int pid[],int at[],int bt[],int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=(at[i-1]+bt[i-1]+wt[i-1])-at[i];
    }
}
void findtat(int n,int pid[],int at[],int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
         tat[i]=wt[i]+bt[i];
    }
   
}
 
 void findct(int n,int pid[],int at[],int bt[],int wt[],int tat[],int ct[])
{
    for(int i=0;i<n;i++)
    {
         ct[i]=tat[i]+at[i];
    }
   
}
void gant(int pid[],int n,int ct[])
{
    int i;
    for( i=0;i<n;i++)
    {
        printf("|P%d\t",pid[i]);
    }
    printf("|\n");
    printf("0\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",ct[i]);
    }
}
void main()
{
    int n,i,j,wt[10],tat[10],ct[10];
    printf("enter no of processes:\t");
    scanf("%d",&n);
    int at[10],bt[10],pid[10];
    printf("\nenter pid,at,bt\t\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
    }
    findwt(n,pid,at,bt,wt);
    findtat(n,pid,at,bt,wt,tat);
    findct(n,pid,at,bt,wt,tat,ct);
    printf("pid\tat\tbt\tct\ttat\twt\n");

        for(int j=0;j<n;j++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[j],at[j],bt[j],ct[j],tat[j],wt[j]);

    }
    printf("gant\n");
    gant(pid,n,ct);

}