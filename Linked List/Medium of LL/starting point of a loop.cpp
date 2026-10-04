#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Constructor with data and next pointer
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to find the first node of the loop
Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    // Step 1: Detect whether a cycle exists
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        // Cycle detected
        if (slow == fast)
        {
            // Step 2: Find the starting point of the cycle
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    // No cycle
    return NULL;
}

int main()
{
    // Creating nodes
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    // Connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Creating a cycle:
    // 50 -> 30
    fifth->next = third;
    // Find first node of loop
    Node *result = firstNode(head);
    if (result != NULL)
    {
        cout << "First node of loop is: " << result->data;
    }
    else
    {
        cout << "No loop present";
    }
    return 0;
}
