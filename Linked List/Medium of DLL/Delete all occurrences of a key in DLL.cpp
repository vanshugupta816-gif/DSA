#include <bits/stdc++.h>
using namespace std;
// Node structure for Doubly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to delete all occurrences of key k
Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            // If the node is the head
            if (temp == head)
            {
                head = temp->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            // Connect previous node to next node
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }
            // Connect next node to previous node
            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }
            delete temp;
            // Move to next node
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Creating the doubly linked list:
    // 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10

    Node *head = new Node(10);

    Node *node2 = new Node(4);
    Node *node3 = new Node(10);
    Node *node4 = new Node(3);
    Node *node5 = new Node(5);
    Node *node6 = new Node(20);
    Node *node7 = new Node(10);

    // Connecting nodes
    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    node6->next = node7;
    node7->prev = node6;

    // Key to delete
    int k = 10;

    cout << "Original List: ";
    printList(head);

    // Delete all occurrences of 10
    head = deleteAllOccurrences(head, k);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
