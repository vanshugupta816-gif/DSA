#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *back;
    Node(string url)
    {
        data = url;
        next = nullptr;
        back = nullptr;
    }
};

class Browser
{
    Node *currentPage;

public:
    // Constructor - sets homepage
    Browser(string homepage)
    {
        currentPage = new Node(homepage);
    }

    // Visit a new URL
    void visit(string url)
    {
        Node *newNode = new Node(url);
        // Connect current page to new page
        currentPage->next = newNode;
        newNode->back = currentPage;
        // Move current page
        currentPage = newNode;
    }

    // Move backward
    string back(int steps)
    {
        while (steps)
        {
            if (currentPage->back)
            {
                currentPage = currentPage->back;
            }
            else
            {
                break;
            }
            steps--;
        }
        return currentPage->data;
    }

    // Move forward
    string forward(int steps)
    {
        while (steps)
        {
            if (currentPage->next)
            {
                currentPage = currentPage->next;
            }
            else
            {
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};

int main()
{
    // Create browser with homepage
    Browser browser("google.com");

    // Visit pages
    browser.visit("youtube.com");
    browser.visit("github.com");
    browser.visit("leetcode.com");

    // Current page: leetcode.com
    cout << "Current Page: leetcode.com" << endl;

    // Go back 2 pages
    cout << "After back(2): "
         << browser.back(2) << endl;

    // Go forward 1 page
    cout << "After forward(1): "
         << browser.forward(1) << endl;

    // Visit another page
    browser.visit("geeksforgeeks.org");

    // Go back 2 pages
    cout << "After back(2): "
         << browser.back(2) << endl;

    // Go forward 1 page
    cout << "After forward(1): "
         << browser.forward(1) << endl;

    return 0;
}
