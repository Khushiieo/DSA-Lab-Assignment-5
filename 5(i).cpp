#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertBefore(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->data == key)
    {
        insertBeginning(x);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int key, int x)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int key)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->data == key)
    {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void search(int key)
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Node found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Node not found\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice, x, key;

    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert Before a Node";
        cout << "\n4. Insert After a Node";
        cout << "\n5. Delete from Beginning";
        cout << "\n6. Delete from End";
        cout << "\n7. Delete Specific Node";
        cout << "\n8. Search Node";
        cout << "\n9. Display List";
        cout << "\n10. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBeginning(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter new value and existing node value: ";
                cin >> x >> key;
                insertBefore(key, x);
                break;

            case 4:
                cout << "Enter new value and existing node value: ";
                cin >> x >> key;
                insertAfter(key, x);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteSpecific(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                search(key);
                break;

            case 9:
                display();
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 10);

    return 0;
}
