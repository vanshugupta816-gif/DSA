#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *oddEvenList(Node *head)
{
    // If linked list has 0 or 1 node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    // Connect odd list with even list
    odd->next = evenHead;
    return head;
}
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
    // Example:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = oddEvenList(head);
    printList(head);

    return 0;
}
