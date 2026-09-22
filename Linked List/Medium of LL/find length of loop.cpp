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

int findLength(Node *slow, Node *fast)
{
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findLength(slow, fast);
        }
    }
    return 0;
}

int main()
{
    // Creating nodes
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    // Connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Creating a loop
    fifth->next = third;
    // Finding length of loop
    cout << "Length of Loop: " << lengthOfLoop(head) << endl;

    return 0;
}
