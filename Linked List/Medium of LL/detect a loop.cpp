#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor 1
    Node()
    {
        data = 0;
        next = NULL;
    }
    // Constructor 2
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Constructor 3
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to detect cycle
bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Creating nodes
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    // Connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    // Creating a cycle:
    // 40 -> 20
    fourth->next = second;
    // Calling function
    if (detectCycle(head))
    {
        cout << "Cycle is present in the linked list";
    }
    else
    {
        cout << "Cycle is not present in the linked list";
    }
    return 0;
}
