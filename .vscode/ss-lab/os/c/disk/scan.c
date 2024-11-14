#include<stdio.h>
#include<stdlib.h>

void cscan(int queue[10], int max, int n, int head, int move, int index)
{
    int seek = 0, i;
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            seek += abs(queue[i] - head);
            head = queue[i];
        }
        if (head < max - 1)
        {
            seek += abs(max - 1 - head); // Move to end of disk
        }
        head = 0; // Wrap around to start
        seek += max - 1; // Count the full disk distance once
        for (i = 0; i < index; i++)
        {
            seek += abs(queue[i] - head);
            head = queue[i];
        }
    }
    if (move == 0)
    {
        for (i = index - 1; i >= 0; i--)
        {
            seek += abs(queue[i] - head);
            head = queue[i];
        }
        if (head > 0)
        {
            seek += head; // Move to beginning of disk
        }
        seek += max - 1; // Count the full disk distance once
        head = max - 1; // Wrap around to end
        for (i = n - 1; i >= index; i--)
        {
            seek += abs(queue[i] - head);
            head = queue[i];
        }
    }
    printf("\nTotal seek time: %d", seek);
}

int main()
{
    int n, i, j, head, max, queue[20];
    printf("Enter range of the disk: ");
    scanf("%d", &max);
    printf("\nEnter no of requests in the queue: ");
    scanf("%d", &n);
    printf("\nEnter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    printf("\nEnter head: ");
    scanf("%d", &head);
    int index = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (queue[j] > queue[j + 1])
            {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        if (head < queue[i])
        {
            index = i;
            break;
        }
    }
    int move;
    printf("\nEnter direction (1 for higher, 0 for lower): ");
    scanf("%d", &move);
    
    cscan(queue, max, n, head, move, index);
    return 0;
}