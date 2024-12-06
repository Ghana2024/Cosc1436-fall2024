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

/// @brief AddValue();Adds a new value to the end of the linked list
/// @param LinkedList& list; Reference to the linked list
/// @param value; The value to be added to the list 
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
/// @brief ListValues(); Prints all values in the linked list
/// @param LinkedList& ; Reference to the linked list
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
 
/// @brief RemoveValue();Removes the first occurrence of a value from the linked list
/// @param LinkedList& list; Reference to the linked list
/// @param value; The value to be removed from the list
void RemoveValue(LinkedList& list, int value) 
{
    Node* current = list.Head;//The value to be removed from the list
    Node* previous = nullptr; // Pointer to the previous node
    while (current != nullptr) 
    {
        if (current->Value == value) 
        {
            if (previous == nullptr) 
            {
                list.Head = current->Next;// If the node to be removed is the head
            } 
            else 
            {
                previous->Next = current->Next;// Link the previous node to the next node
            }
            delete current;// Delete the node
            return;
        }
        previous = current;// Move to the next node
        current = current->Next;
    }
}

/// @brief ClearList(); Clears all nodes from the linked list
/// @param LinkedList& list;list Reference to the linked list
void ClearList(LinkedList& list) 
{
    Node* current = list.Head;// Start at the head of the list
    while (current != nullptr) 
    {
        Node* next = current->Next;// Store the next node
        delete current; // Delete the current node
        current = next; // Move to the next node
    }
    list.Head = nullptr; // Set the head to nullptr after clearing the list
}

/// @brief handleDisplayMenu(); Handles the display menu and user input for the linked list operations
/// @param LinkedList& list; list Reference to the linked list
/// @return Returns 0 upon exiting the menu
int handleDisplayMenu(LinkedList& list)
{
    char choice;// Variable to store user's menu choice
    do
    {
        DisplayMainMenu();// Display the main menu
        cin >> choice;// Get the user's choice
        choice = toupper(choice);// Convert choice to uppercase for consistency
        switch (choice)
        {
            case 'A':
            {
                int value;
                char addMoreValue;
                do {
                    cout << "Enter value to add: ";
                    cin >> value;
                      while (!(cin >> value))
                      {
                        cout << "Invalid input. Please enter an integer: ";
                        cin.clear();
                        break;
                      }
                      //else
                      //{
                      //    AddValue(list, value); // Add the value to the list
                      //    cout << "Do you want to add another number enter 'y'/'Y', otherwise enter any other character: ";
                      //    cin >> addMoreValue;
                      //}
                    cout << "Do you want to add another number enter 'y'/'Y', otherwise enter any other character: ";
                    cin >> addMoreValue;
                } while (tolower(addMoreValue) == 'y');
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
               // break;
            }
            break;
            case 'L':
                if (list.Head == nullptr) 
                {
                    cout << "No numbers in the list." << endl;
                } else 
                {
                    cout << "\nThe numbers are ";
                    ListValues(list); // List all values in the list
                }
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
                break;
            case 'R':
            {
                if (list.Head == nullptr) 
                {
                    cout << "No numbers in the list to remove." << endl;
                } 
                else 
                {
                    int value;
                    cout << "Enter value to remove: ";
                    cin >> value;
                    Node* current = list.Head;
                    bool found = false;
                    while (current != nullptr) 
                    {
                        if (current->Value == value) 
                        {
                            found = true;
                            break;
                        }
                        current = current->Next;
                    }
                    if (found) 
                    {
                        RemoveValue(list, value); // Remove the specified value from the list
                    } 
                    else 
                    {
                        cout << "Value not found in the list." << endl;
                    }
                }
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
                break;
            }
            case 'C':
            {
                char confirm;
                cout << "Are you sure you want to clear the list? Enter 'y'/'Y', otherwise enter any other character: ";
                cin >> confirm;
                if (list.Head == nullptr)
                {
                    cout << "No numbers found to clear in the List." << endl;

                    if (tolower(confirm) == 'y')
                    {
                        ClearList(list);// Clear the entire list if confirmed
                    }
                }
                break;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;

            }
            case 'E':
                cout << "Exiting program." << endl;// Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;// Handle invalid choices
        }
    } while (choice != 'E');// Continue until the user chooses to exit

    return 0;// Return 0 upon exiting the menu

}

int main() 
{
    //Display Basic Program Title,Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 5 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    //Diplaying message for program starting point
    LinkedList list;
    handleDisplayMenu(list);
    return 0;
}

