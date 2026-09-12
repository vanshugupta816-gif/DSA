#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Helper function
int addHelper(Node *temp)
{
    if (temp == NULL)
    {
        return 1;
    }

    int carry = addHelper(temp->next);

    temp->data = temp->data + carry;

    if (temp->data < 10)
        return 0;

    temp->data = 0;

    return 1;
}

// Main function for adding one
Node *addOne(Node *head)
{
    int carry = addHelper(head);

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Print Linked List
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // Input: 1 -> 5 -> 2
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);

    cout << "Before adding one: ";
    printList(head);

    head = addOne(head);

    cout << "After adding one: ";
    printList(head);

    return 0;
}
