#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor for a single node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Constructor with next and prev
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

// Function to reverse a doubly linked list
Node *reverseDLL(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *current = head;

    while (current != NULL)
    {

        // Swap next and prev
        prev = current->prev;

        current->prev = current->next;
        current->next = prev;

        // Move to the next node
        current = current->prev;
    }

    // New head
    return prev->prev;
}

// Function to print the doubly linked list
void printList(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    // Creating the doubly linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    // Connecting nodes
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;

    // Print original list
    cout << "Original Doubly Linked List: ";
    printList(head);

    // Reverse the list
    head = reverseDLL(head);

    // Print reversed list
    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}
