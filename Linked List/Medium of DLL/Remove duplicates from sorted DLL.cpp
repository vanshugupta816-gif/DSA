#include <bits/stdc++.h>
using namespace std;
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

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            temp->next = nextNode;
            if (nextNode != NULL)
            {
                nextNode->prev = temp;
            }
            delete duplicate;
        }
        temp = temp->next;
    }
    return head;
}

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
    // Creating the doubly linked list:
    // 1 <-> 1 <-> 2 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4
    Node *head = new Node(1);
    Node *second = new Node(1);
    Node *third = new Node(2);
    Node *fourth = new Node(2);
    Node *fifth = new Node(2);
    Node *sixth = new Node(3);
    Node *seventh = new Node(4);
    Node *eighth = new Node(4);
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    fifth->next = sixth;
    sixth->prev = fifth;

    sixth->next = seventh;
    seventh->prev = sixth;

    seventh->next = eighth;
    eighth->prev = seventh;

    cout << "Original list: ";
    printList(head);
    head = removeDuplicates(head);
    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
