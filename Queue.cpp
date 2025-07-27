#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rear;
public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[size];
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "The queue is full." << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    bool isEmpty()
    {
        if (rear == -1 && front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    queue.display();
    
    queue.dequeue();
    queue.dequeue();
    
    queue.display();
    
    queue.enqueue(60);
    queue.enqueue(70);
    
    queue.display();
}