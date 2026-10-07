#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// Function to find the last node of the doubly linked list
Node *findTail(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}

// Function to find all pairs whose sum is equal to k
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL)
    {
        return ans;
    }
    Node *left = head;
    Node *right = findTail(head);
    while (left != right && left->data < right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {

            left = left->next;
        }
        else
        {

            right = right->prev;
        }
    }
    return ans;
}

int main()
{

    // Creating the sorted doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 9

    Node *head = new Node(1);

    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(9);

    // Connecting nodes

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    // Required sum
    int k = 5;

    // Finding pairs
    vector<pair<int, int>> result = findPairs(head, k);

    // Printing result
    cout << "Pairs with sum " << k << " are:" << endl;

    for (auto p : result)
    {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
