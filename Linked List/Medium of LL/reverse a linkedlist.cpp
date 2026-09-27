#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    // Default constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Constructor with data and next
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to reverse the linked list
// Node *reverseLinkedList(Node *head)
// {
//     Node *temp = head;
//     Node *prev = NULL;
//     while (temp != NULL)
//     {
//         Node *front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }
// Function to print linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Recursive function to reverse linked list
Node *reverseLinkedList(Node *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// Main function
int main()
{
    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original Linked List: ";
    printLinkedList(head);
    // Reverse the linked list
    head = reverseLinkedList(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);
    return 0;
}
