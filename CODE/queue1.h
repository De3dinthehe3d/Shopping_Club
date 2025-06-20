#include <iostream>
#include <string>
using namespace std;

// Structure of Node
struct Node
{
    string cname; // Customer name
    Node *link;   // Pointer to the next node
};

// Global variables for the queue
Node *front = NULL;
Node *rear = NULL;

// Function to check if the queue is empty
bool isempty()
{
    return (front == NULL && rear == NULL);
}

// Function to add a customer to the queue
void enqueue(string name)
{
    Node *ptr = new Node();
    ptr->cname = name;
    ptr->link = NULL;

    if (isempty())
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

// Function to remove a customer from the queue
void dequeue()
{
    if (isempty())
    {
        cout << "Queue is empty\n";
    }
    else if (front == rear)
    { // Only one element in the queue
        delete front;
        front = rear = NULL;
    }
    else
    {
        Node *temp = front;
        front = front->link;
        delete temp;
    }
}

// Function to display the customer at the front
void showfront()
{
    if (isempty())
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Customer at the front: " << front->cname << "\n";
    }
}

// Function to display the entire queue
void displayQueue()
{
    if (isempty())
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node *ptr = front;
        cout << "Customers in the queue:\n";
        while (ptr != NULL)
        {
            cout << "\t" << ptr->cname << endl;
            ptr = ptr->link;
        }
    }
}

