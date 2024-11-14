
#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAMES 3 
#define MAX_PAGES 20

int frames[MAX_FRAMES]; 
int count[MAX_FRAMES];
int freq[MAX_FRAMES];
int rear = -1; 
void initialize()
{
    int i;
    for(int i=0;i<MAX_FRAMES;i++)
    {
        frames[i]=-1;
        count[i]=0;
        freq[i]=0;
    }
}
void display()
{
    int i;
    for(i=0;i<MAX_FRAMES;i++)
    {
        if(frames[i]!=-1)
        {
            printf("%d\t",frames[i]);
        }
        else{
            printf("_\t");

        }
    }
    printf("\n");
}
void fifo(int pages[],int n)
{
    int i,j,page,found,front,pagefault=0;
    
    
    for(i=0;i<n;i++)
    {
        found=0;
        page=pages[i];
        for(j=0;j<MAX_FRAMES;j++)
        {
            if(frames[j]==page)
            {
                printf("page %d already found at frame %d\n",pages,j);
                found=1;
                break;
            }
            
        }
        if(!found)
        {
            pagefault++;
            if(rear<MAX_FRAMES-1)
            {
                rear++;
            }
            else{
                rear=0;
            }
            frames[rear]=page;
             printf("page %d loaded in frame %d \n",page,rear);

        }
        display();
    }
    printf("\n total page fault :%d\n",pagefault);
}
int find_lru()
{
    int max=count[0],lru_index=0;
    for(int i=1;i<MAX_FRAMES;i++)
    {
        if(max<count[i])
        {
            max=count[i];
            lru_index=i;
            
        }
    }
    return lru_index;
}
void lru(int pages[],int n)
{
    int i,found,page,pagefault=0;
    for(i=0;i<n;i++)
    {
        page=pages[i];
        found=0;
        for(int j=0;j<MAX_FRAMES;j++)
        {
            if(frames[j]==page)
            {
                found=1;
                printf("page %d found at frame %d\n",page,j);
                
                break;
                
            }
        }

            if(!found)
            {
               int  lru_index=find_lru();
               frames[lru_index]=page;
               count[lru_index]=0;
               pagefault++;
               printf("page %d loaded at frame %d\n",page,lru_index);

            }
              for(int j=0;j<MAX_FRAMES;j++ )
        {
            count[j]++;
        }
        for(int j=0;j<MAX_FRAMES;j++ )
        {
            if(frames[j]==page)
            {
                count[j]=0;
                break;
            }
        }
    
        
        display();
    }
    printf("no of page_fault %d\t:",pagefault);

}




int find_lfu()
{
    int min=freq[0],lfu_index=0;
    for(int i=1;i<MAX_FRAMES;i++)
    {
        if(min>freq[i])
        {
            min=freq[i];
            lfu_index=i;
            
        }
    }
    return lfu_index;
}
void lfu(int pages[],int n)
{
    int i,found,page,pagefault=0;
    for(i=0;i<n;i++)
    {
        page=pages[i];
        found=0;
        for(int j=0;j<MAX_FRAMES;j++)
        {
            if(frames[j]==page)
            {
                found=1;
                printf("page %d found at frame %d\n",page,j);
                freq[i]++;
                
                break;
                
            }
        }

            if(!found)
            {
               int  lfu_index=find_lfu();
               frames[lfu_index]=page;
               freq[lfu_index]=1;
               pagefault++;
               printf("page %d loaded at frame %d\n",page,lfu_index);

            }
              
    
        
        display();
    }
    printf("no of page_fault %d\t:",pagefault);

}

void main()
{
    int pages[MAX_PAGES];
    int n,i;
    printf("\nenter no of pages\t:");
    scanf("%d",&n);
    printf("\n enter the sequence\t:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    initialize();
    
    lfu(pages,n);
}