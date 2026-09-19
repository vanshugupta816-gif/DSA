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

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    // Find the middle of the linked list
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half
    Node *newHead = reverseLinkedList(slow->next);
    Node *first = head;
    Node *second = newHead;
    // Compare first half and reversed second half
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            // Restore the linked list
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    // Restore the linked list
    reverseLinkedList(newHead);
    return true;
}

int main()
{
    // Creating linked list:
    // 1 -> 2 -> 3 -> 2 -> 1
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
