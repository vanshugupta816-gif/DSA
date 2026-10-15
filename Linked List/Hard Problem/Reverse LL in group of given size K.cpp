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

// Reverse a linked list
Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Get the kth node from temp
Node *getKthNode(Node *temp, int k)
{
    k = k - 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
// Reverse nodes in groups of k
Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        // Find kth node
        Node *kthNode = getKthNode(temp, k);
        // If fewer than k nodes remain
        if (kthNode == NULL)
        {
            if (prevLast != NULL)
            {
                prevLast->next = temp;
            }
            break;
        }
        // Store the first node of next group
        Node *nextNode = kthNode->next;
        // Disconnect current group
        kthNode->next = NULL;
        // Reverse current group
        reverseLinkedList(temp);
        // First group
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }
        // temp is now the last node of reversed group
        prevLast = temp;
        // Move to next group
        temp = nextNode;
    }
    return head;
}
// Print linked list
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
    /*
        Original list:

        1 -> 2 -> 3 -> 4 -> 5

        k = 3

        After reversing in groups of 3:

        3 -> 2 -> 1 -> 4 -> 5
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;
    cout << "Original List: ";
    printList(head);
    head = kReverse(head, k);
    cout << "After K-Group Reversal: ";
    printList(head);
    return 0;
}
