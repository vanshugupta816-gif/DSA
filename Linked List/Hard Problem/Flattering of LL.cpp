#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node(int x)
    {
        data = x;
        next = nullptr;
        child = nullptr;
    }
};

// Merge two sorted linked lists
Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }
    if (list1 != nullptr)
        res->child = list1;
    else
        res->child = list2;
    if (dummyNode->child != nullptr)
        dummyNode->child->next = nullptr;
    return dummyNode->child;
}

// Flatten the linked list
Node *flattenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    // Recursively flatten the remaining lists
    Node *mergedHead = flattenLinkedList(head->next);
    // Merge current list with already flattened list
    head = merge(head, mergedHead);
    return head;
}

// Print flattened linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main()
{
    /*
             4 -> 7 -> 9 -> 20
             |    |    |
             5    8    12
             |
             6
       Each vertical list is sorted.
    */

    // First list
    Node *head = new Node(4);
    head->child = new Node(5);
    head->child->child = new Node(6);
    // Second list
    head->next = new Node(7);
    head->next->child = new Node(8);
    // Third list
    head->next->next = new Node(9);
    head->next->next->child = new Node(12);
    // Fourth list
    head->next->next->next = new Node(20);
    // Flatten the linked list
    Node *flattenedHead = flattenLinkedList(head);
    // Print result
    cout << "Flattened Linked List: ";
    printList(flattenedHead);
    return 0;
}
