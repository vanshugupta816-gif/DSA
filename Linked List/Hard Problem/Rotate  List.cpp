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

Node *rotateRight(Node *head, int k)
{
    // If list is empty, has only one node,
    // or k is 0
    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    // Find the length of the list
    int length = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }
    // Since rotating length times gives the same list
    k = k % length;
    if (k == 0)
    {
        return head;
    }
    // Make the list circular
    temp->next = head;
    // Find the new last node
    int stepsToNewLast = length - k;
    Node *newLast = head;
    for (int i = 1; i < stepsToNewLast; i++)
    {
        newLast = newLast->next;
    }
    // The node after newLast becomes the new head
    Node *newHead = newLast->next;
    // Break the circular list
    newLast->next = NULL;
    return newHead;
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
    /*
        Original List:
        1 -> 2 -> 3 -> 4 -> 5
        k = 2
        Rotate right by 2:
        4 -> 5 -> 1 -> 2 -> 3
    */
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;
    cout << "Original List: ";
    printList(head);
    head = rotateRight(head, k);
    cout << "After Rotation: ";
    printList(head);
    return 0;
}
