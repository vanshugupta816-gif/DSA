#include<bits/stdc++.h>
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
// Function to merge two sorted linked lists
Node* sortTwoLists(Node* list1, Node* list2)
{
    Node* t1 = list1;
    Node* t2 = list2;

    // Dummy node
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // Attach remaining nodes
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    Node* head = dummyNode->next;

    // Important: don't delete dummyNode using destructor
    dummyNode->next = NULL;
    delete dummyNode;

    return head;
}

// Function to print linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // First sorted linked list:
    // 1 -> 3 -> 5
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    // Second sorted linked list:
    // 2 -> 4 -> 6
    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    // Display original lists
    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge both lists
    Node* result = sortTwoLists(list1, list2);

    // Display result
    cout << "Merged List: ";
    printList(result);
    // Delete the final list
    delete result;

    return 0;
}
