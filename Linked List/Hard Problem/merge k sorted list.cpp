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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<
        pair<int, Node *>,
        vector<pair<int, Node *>>,
        greater<pair<int, Node *>>>
        pq;
    // Put the first node of every linked list into priority queue
    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i])
        {
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    // Dummy node
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        // Attach smallest node to result
        if (it.second->next)
            pq.push({it.second->next->data,
                     it.second->next});
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}

// Function to print linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    // List 1: 1 -> 4 -> 5
    Node *list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    // List 2: 1 -> 3 -> 4
    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    // List 3: 2 -> 6
    Node *list3 = new Node(2);
    list3->next = new Node(6);

    // Store all linked lists
    vector<Node *> listArray = {
        list1,
        list2,
        list3};

    // Merge K sorted lists
    Node *result = mergeKLists(listArray);

    // Print result
    printList(result);

    return 0;
}
