// Lab 5
// Your Name
// Course and Semester

#include <iostream>
using namespace std;

void DisplayMainMenu() 
{
    cout << "Main Menu:" << endl;
    cout << "1. Add Value" << endl;
    cout << "2. List Values" << endl;
    cout << "3. Remove Value" << endl;
    cout << "4. Clear List" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}

struct Node 
{
    int Value = 0;
    Node* Next = nullptr;
};

struct LinkedList 
{
    Node* Head = nullptr;
};

void AddValue(LinkedList& list, int value) {
    Node* newNode = new Node();
    newNode->Value = value;

    if (list.Head == nullptr) 
    {
        list.Head = newNode;
    } 
    else 
    {
        Node* current = list.Head;
        while (current->Next != nullptr) 
        {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void ListValues(const LinkedList& list) 
{
    Node* current = list.Head;
    while (current != nullptr) 
    {
        cout << current->Value << " ";
        current = current->Next;
    }
    cout << endl;
}

void RemoveValue(LinkedList& list, int value) 
{
    Node* current = list.Head;
    Node* previous = nullptr;

    while (current != nullptr) 
    {
        if (current->Value == value) 
        {
            if (previous == nullptr) 
            {
                list.Head = current->Next;
            } 
            else 
            {
                previous->Next = current->Next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->Next;
    }
}

void ClearList(LinkedList& list) 
{
    Node* current = list.Head;
    while (current != nullptr) 
    {
        Node* next = current->Next;
        delete current;
        current = next;
    }
    list.Head = nullptr;
}

int main() 
{
    LinkedList list;
    char choice;

    cout << "Program Title: Lab 5" << endl;
    cout << "Your Name" << endl;
    cout << "Course and Semester" << endl;

    do 
    {
        DisplayMainMenu();
        cin >> choice;
        choice = tolower(choice);

        switch (choice) 
        {
            case '1':
            {
                int value;
                cout << "Enter value to add: ";
                cin >> value;
                AddValue(list, value);
                break;
            }
            case '2':
                ListValues(list);
                break;
            case '3':
            {
                int value;
                cout << "Enter value to remove: ";
                cin >> value;
                RemoveValue(list, value);
                break;
            }
            case '4':
            {
                char confirm;
                cout << "Are you sure you want to clear the list? (y/n): ";
                cin >> confirm;
                if (tolower(confirm) == 'y') {
                    ClearList(list);
                }
                break;
            }
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

