#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;
    // Map original node -> copied node
    unordered_map<Node *, Node *> mp;
    Node *temp = head;
    // Step 1: Create a new node for every original node
    while (temp != NULL)
    {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }
    // Step 2: Connect next and random pointers
    temp = head;
    while (temp != NULL)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];

        temp = temp->next;
    }
    // Return copied head
    return mp[head];
}

void printList(Node *head)
{
    // Store nodes so that we can find random indexes
    vector<Node *> nodes;
    Node *temp = head;
    while (temp != NULL)
    {
        nodes.push_back(temp);
        temp = temp->next;
    }

    // Print value and random index
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << "[" << nodes[i]->val << ", ";
        if (nodes[i]->random == NULL)
        {
            cout << "null";
        }
        else
        {
            for (int j = 0; j < nodes.size(); j++)
            {
                if (nodes[i]->random == nodes[j])
                {
                    cout << j;
                    break;
                }
            }
        }
        cout << "] ";
    }
    cout << endl;
}

int main()
{
    /*
        Original list:

        Node 0: [7, null]
        Node 1: [13, 0]
        Node 2: [11, 4]
        Node 3: [10, 2]
        Node 4: [1, 0]

        next:
        7 -> 13 -> 11 -> 10 -> 1

        random:
        7  -> NULL
        13 -> 7
        11 -> 1
        10 -> 11
        1  -> 7
    */
    Node *head = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    // Connecting next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Connecting random pointers
    head->random = NULL;
    second->random = head;
    third->random = fifth;
    fourth->random = third;
    fifth->random = head;
    cout << "Original List:" << endl;
    printList(head);
    // Create deep copy
    Node *copiedHead = copyRandomList(head);
    cout << "Copied List:" << endl;
    printList(copiedHead);
    return 0;
}
