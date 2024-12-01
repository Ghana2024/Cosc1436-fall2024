/* Program title:Lab 5
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
/// @brief function returns an integer with detail of the choice result.
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

/// @brief Structure representing a node in a linked list
struct Node 
{
    int Value = 0;// The value stored in the node
    Node* Next = nullptr;// Pointer to the next node in the list
};

/// @brief Structure representing a linked list
struct LinkedList 
{
    Node* Head = nullptr;// Pointer to the first node in the list
};

/// @brief Adds a new value to the end of the linked list
/// @param list Reference to the linked list
/// @param value The value to be added to the list 
void AddValue(LinkedList& list, int value) 
{
    Node* newNode = new Node();// Create a new node
    newNode->Value = value;// Set the value of the new node
    if (list.Head == nullptr) 
    {
        list.Head = newNode;// If the list is empty, set the new node as the head
    } 
    else 
    {
        Node* current = list.Head;// Start at the head of the list
        while (current->Next != nullptr) 
        {
            current = current->Next;// Traverse to the end of the list
        }
        current->Next = newNode;// Link the new node at the end of the list
    }
}
/// @brief Prints all values in the linked list
/// @param list Reference to the linked list
void ListValues(const LinkedList& list) 
{
    Node* current = list.Head;// Start at the head of the list
    while (current != nullptr) 
    {
        cout << current->Value << " ";// Print the value of the current node
        current = current->Next;       // Move to the next node
    }
    cout << endl;// Print a newline at the end
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
