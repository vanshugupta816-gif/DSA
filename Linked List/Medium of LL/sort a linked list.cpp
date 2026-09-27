#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Find the middle node of the linked list
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted linked lists
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;
    return dummyNode->next;
}

// Merge Sort on Linked List
Node *sortList(Node *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return head;
    // Find middle
    Node *middle = findMiddle(head);
    // Divide the list into two halves
    Node *right = middle->next;
    middle->next = NULL;
    Node *left = head;
    // Sort both halves
    left = sortList(left);
    right = sortList(right);
    // Merge both sorted halves
    return mergeTwoLists(left, right);
}

// Print linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    // Creating linked list manually
    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(8);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);
    cout << "Original List: ";
    printList(head);
    // Sort the linked list
    head = sortList(head);
    cout << "Sorted List: ";
    printList(head);

    return 0;
}
