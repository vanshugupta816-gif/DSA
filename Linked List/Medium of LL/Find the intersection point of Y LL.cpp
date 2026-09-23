#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    if (firstHead == NULL || secondHead == NULL)
        return NULL;

    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
            return temp1;

        if (temp1 == NULL)
            temp1 = secondHead;

        if (temp2 == NULL)
            temp2 = firstHead;
    }

    return temp1;
}

int main()
{
    // Common part of both linked lists
    Node *common = new Node(8);
    common->next = new Node(10);
    common->next->next = new Node(12);

    // First Linked List
    Node *firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(3);

    // Connect first list to common part
    firstHead->next->next->next = common;

    // Second Linked List
    Node *secondHead = new Node(5);
    secondHead->next = new Node(6);

    // Connect second list to common part
    secondHead->next->next = common;

    // Find intersection
    Node *intersection = findIntersection(firstHead, secondHead);

    if (intersection != NULL)
    {
        cout << "Intersection point: " << intersection->data << endl;
    }
    else
    {
        cout << "No intersection point." << endl;
    }

    return 0;
}
