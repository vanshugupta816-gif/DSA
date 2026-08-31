#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1; // Initialize data with the provided value
        next = next1; // Initialize next with the provided
    }

public:
    Node(int data1)
    {
        data = data1;   // Initialize data with the provided value
        next = nullptr; // Initialize next as null since it's the end of the list
    }
};
Node *convrt_arr2LL(vector<int> &a)
{
    Node *head = new Node(a[0]); // head node of our LL
    Node *mover = head;          // starting mover ptr from head node ptr
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]); // creating temp. node for every a[i]..
        mover->next = temp;          // updating the mover ptr
        // implement mover_ptr for creating a LL...
        mover = temp; // OR (mover = mover->next)
    }
    // returning the head Node of our LL...
    return head;
}
int lngth_of_LL(Node *head)
{
    int cnt = 0; // this will help in counting the nodes till temp is valid...
    Node *temp = head;
    while (temp)
    { // this will run till temp is not equal to null_ptr...
        // cout<<temp->data<<" ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
bool check_if_present(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true; // this will check if the element is present or not...
        temp = temp->next;
    }
    return false;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    // creates a new object and y ptr is pointing to this new node memory address..
    // Node* y = new Node(a[0],nullptr);
    // cout<<y->data; //we need to return the return the data value like this when we cretae new node like this..
    // cout<<y; // returns the memory value

    // Node y1 = Node(a[0],nullptr); // creates a new object y1....
    // cout<<y1; // this will throw an error becauz you cant't just print the entire object
    // cout<<y1.data; // this will not throw an error becauz we r printing only the data of the object...
    // cout<<y1.next; // this will not throw an error becauz we r printing only the memory address of the object...

    // by creating the 2nd constructor we dont need to initialize null_ptr again and again...
    // Node* y = new Node(a[0]);
    // cout<<y->data;

    // converting arr to a linked list...
    vector<int> a1 = {12, 5, 8, 7};
    Node *head = convrt_arr2LL(a1);
    // cout<<head->data; // this will print the data of the head node in LL..

    // printing (traversing) our linked list...
    // Node* temp = head;
    // while(temp){ // this will run till temp is not equal to null_ptr...
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }

    // printing the length of LL..
    // cout<<lngth_of_LL(head);

    // checking if the x element is present in LL or not..
    int n;
    cout << "enter element you want to find in LL:" << endl;
    cin >> n;
    cout << check_if_present(head, n);
    return 0;
}
