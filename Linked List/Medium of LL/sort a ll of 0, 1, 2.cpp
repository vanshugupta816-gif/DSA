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

// Sort linked list containing 0s, 1s and 2s
Node *sortList(Node *head)
{
    // If list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;
    // Dummy nodes for 0s, 1s and 2s
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;
    // Separate nodes into three lists
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    // Connect 0s list with 1s or 2s list
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    // Connect 1s list with 2s list
    one->next = twoHead->next;
    // Last node should point to NULL
    two->next = NULL;
    // New head
    Node *newHead = zeroHead->next;
    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
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
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);
    cout << "Original List: ";
    printList(head);
    // Sort the list
    head = sortList(head);
    cout << "Sorted List: ";
    printList(head);
    return 0;
}
