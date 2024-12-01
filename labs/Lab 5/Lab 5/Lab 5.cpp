/* Program title:Lab 5
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
/// @brief 
void DisplayMainMenu() 
{
    cout << "Main Menu:" << endl;
    cout << "A. Add Value" << endl;
    cout << "L. List Values" << endl;
    cout << "R. Remove Value" << endl;
    cout << "C. Clear List" << endl;
    cout << "E. Quit" << endl;
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

/// @brief Function to handle the menu choices takes the user's choice.
/// @param choice;user's menu choice which determines the action to be performed. 
/// @param numbers[];an array of integers that stores the values to be processed.
/// @param int& count;A reference to an integer representing the current number of elements in the array. 
/// This allows the function to update the count if more values are added. 
/// @param maxValuesSize;The maximum size,how many values can be stored.
int handleDisplayMenu(LinkedList& list)
{
    char choice;
    do
    {
        DisplayMainMenu();
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
            case 'A':
            {
                int value;
                cout << "Enter value to add: ";
                cin >> value;
                AddValue(list, value);
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
                break;
            }
            case 'L':
                cout << "\nThe numbers are ";
                ListValues(list);
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
                break;
            case 'R':
            {
                int value;
                cout << "Enter value to remove: ";
                cin >> value;
                RemoveValue(list, value);
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
                break;
            }
            case 'C':
            {
                char confirm;
                cout << "Are you sure you want to clear the list? (y/n): ";
                cin >> confirm;
                if (tolower(confirm) == 'y') {
                    ClearList(list);
                }
                break;
            }
            case 'E':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'E');

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

