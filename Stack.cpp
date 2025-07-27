#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int x) //insertion
    {
        if (isFull())
        {
            cout << "Stack is full." << endl;
        }
        else
        {
            top++;
            arr[top] = x;
            cout << "pushed " << arr[top] << endl;
        }
    }
    void pop() //deletion
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "popped " << arr[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack is : ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout <<endl;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
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
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack stack(5);

    stack.pop();
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.display();
    stack.pop();
    stack.display();
}