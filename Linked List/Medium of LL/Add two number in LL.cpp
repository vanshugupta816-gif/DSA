#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
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
  Node *addTwoNumbers(Node *l1, Node *l2)
    {
        // Dummy node
        Node *dummy = new Node();
        Node *temp = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;

            // Take value from first linked list
            if (l1 != NULL)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            // Take value from second linked list
            if (l2 != NULL)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            // Add carry
            sum += carry;

            // Calculate carry
            carry = sum / 10;

            // Create new node
            Node *node = new Node(sum % 10);

            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }


// Function to print linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;

        if (head->next != NULL)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // First number: 2 -> 4 -> 3
    // Represents 342
    Node *l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // Second number: 5 -> 6 -> 4
    // Represents 465
    Node *l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    // Add both numbers
    Node *result = addTwoNumbers(l1, l2);

    // Print result
    cout << "First Number: ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
