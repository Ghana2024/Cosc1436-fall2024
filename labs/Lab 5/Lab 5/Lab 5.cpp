/* Program title:Lab 5
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <cctype>
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

void AddValue(LinkedList& list, int value) 
{
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
int handleDisplayMenu(LinkedList& list)
{
    char choice;
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

int main() 
{
    //Display Basic Program Title,Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 4 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    //Diplaying message for program starting point
    LinkedList list;
    handleDisplayMenu(list);
    return 0;
}

