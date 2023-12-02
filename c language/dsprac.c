#include <stdio.h>

#define SIZE 6
int queue[SIZE], front = -1, rear = -1;

void enqueue(int data)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("\n!! Queue is Full !!!\n");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        // rear++;
        rear = (rear + 1) % SIZE;

        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\n!!! Queue is Empty!!!\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // front++;
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (rear == -1)
    {
        printf("\n!!! Queue is Empty!!!\n");
    }
    else
    {
        printf("The queue has: ");
        for (int i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(99);
    enqueue(90);
    enqueue(50);
    enqueue(51);
    enqueue(55);
    enqueue(60);
    dequeue();
    enqueue(99);

    display();
    enqueue(69);
    // dequeue();
    display();
}