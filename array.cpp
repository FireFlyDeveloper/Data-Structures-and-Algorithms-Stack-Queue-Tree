#include <iostream>
using namespace std;

int myArray[30]; // Array to store elements
int numElem = 0; // Current number of elements in the array
int maxElem = 20; // Maximum number of elements allowed in the array

// Function to insert an element after a given element
string insertAtTheGivenPosition(int num, int ElemAfter)
{
    if (numElem != maxElem) // Check if the array is not full
    {
        int position;
        for (int i = 0; i < numElem; i++) // Find the position of the given element
        {
            if (myArray[i] == ElemAfter)
            {
                position = i;
                break;
            }
        }

        for (int i = numElem; i > position; i--) // Shift elements to the right
        {
            myArray[i] = myArray[i - 1];
        }
        myArray[position + 1] = num; // Insert the new element
        numElem++; // Increase the element count
        return "An element is successfully inserted at the specified location! \n";
    }

    return "The array is full. Please remove elements before inserting a new one. \n";
}

// Function to insert an element at the beginning of the array
string insertAtTheBeginning(int num)
{
    if (numElem != maxElem) // Check if the array is not full
    {
        for (int i = numElem; i > 0; i--) // Shift elements to the right
        {
            myArray[i] = myArray[i - 1];
        }

        myArray[0] = num; // Insert the new element at the beginning
        numElem++; // Increase the element count
        return "An element is successfully inserted at the beginning! \n";
    }

    return "The array is full. Please remove elements before inserting a new one. \n";
}

// Function to insert an element at the end of the array
string insertAtTheEnd(int num)
{
    if (numElem != maxElem) // Check if the array is not full
    {
        myArray[numElem] = num; // Insert the new element at the end
        numElem++; // Increase the element count
        return "An element is successfully inserted at the end! \n";
    }

    return "The array is full. Please remove elements before inserting a new one. \n";
}

// Function to delete an element from the end of the array
string deleteFromTheEnd()
{
    if (numElem != 0) // Check if the array is not empty
    {
        numElem--; // Decrease the element count
        return "An element has been deleted from the end! \n";
    }
    return "The array is underflow! Delete is not possible. \n";
}

// Function to delete an element from the beginning of the array
string deleteFromTheBeginning()
{
    if (numElem != 0) // Check if the array is not empty
    {
        for (int i = 0; i < numElem - 1; i++) // Shift elements to the left
        {
            myArray[i] = myArray[i + 1];
        }
        numElem--; // Decrease the element count
        return "An element has been deleted from the beginning! \n";
    }

    return "The array is underflow! Delete is not possible. \n";
}

// Function to delete a specific element from the array
string deleteFromGivenElement(int element)
{
    if (numElem != 0) // Check if the array is not empty
    {
        int index = -1; // Variable to store the index of the element to be deleted
        for (int i = 0; i < numElem; i++) // Find the index of the element
        {
            if (myArray[i] == element)
            {
                index = i;
                break;
            }
        }

        if (index != -1) // Check if the element was found
        {
            for (int i = index; i < numElem - 1; i++) // Shift elements to the left
            {
                myArray[i] = myArray[i + 1];
            }
            numElem--; // Decrease the element count
            return to_string(element) + " has been deleted! \n";
        }
        else
        {
            return "Element not found! Delete is not possible. \n";
        }
    }

    return "The array is underflow! Delete is not possible. \n";
}

// Function to traverse and display elements in the array
void traverseArray()
{
    cout << "Showing elements in my array \n";
    for (int i = 0; i < numElem; i++) // Loop through each element
    {
        cout << myArray[i] << " | ";
    }
    cout << "\n";
}

int main()
{
    // Test insertions
    cout << insertAtTheEnd(3); // Insert 3 at the end
    cout << insertAtTheEnd(7); // Insert 7 at the end
    cout << insertAtTheEnd(9); // Insert 9 at the end
    cout << insertAtTheEnd(11); // Insert 11 at the end
    cout << insertAtTheEnd(15); // Insert 15 at the end

    traverseArray(); // Display the array

    cout << insertAtTheBeginning(3); // Insert 3 at the beginning
    cout << insertAtTheEnd(7); // Insert 7 at the end
    cout << insertAtTheEnd(9); // Insert 9 at the end
    cout << insertAtTheBeginning(20); // Insert 20 at the beginning
    cout << insertAtTheGivenPosition(37, 7); // Insert 37 after the element 7
    cout << insertAtTheBeginning(256); // Insert 256 at the beginning
    cout << insertAtTheGivenPosition(128, 9); // Insert 128 after the element 9
    cout << insertAtTheBeginning(19); // Insert 19 at the beginning
    traverseArray(); // Display the array
    
    // Test deletions
    cout << deleteFromTheBeginning(); // Delete from the beginning
    cout << deleteFromTheBeginning(); // Delete from the beginning again

    cout << deleteFromTheEnd(); // Delete from the end
    cout << deleteFromTheEnd(); // Delete from the end again

    cout << deleteFromGivenElement(7); // Delete the element 7
    cout << deleteFromGivenElement(8); // Try to delete the element 8 (not in array)

    traverseArray(); // Display the array

    return 0;
}

// The output will be:
// An element is successfully inserted at the end! 
// An element is successfully inserted at the end! 
// An element is successfully inserted at the end! 
// An element is successfully inserted at the end! 
// An element is successfully inserted at the end! 
// Showing elements in my array 
// 3 | 7 | 9 | 11 | 15 | 
// An element is successfully inserted at the beginning! 
// An element is successfully inserted at the end! 
// An element is successfully inserted at the end! 
// An element is successfully inserted at the beginning! 
// An element is successfully inserted at the specified location! 
// An element is successfully inserted at the beginning! 
// An element is successfully inserted at the specified location! 
// An element is successfully inserted at the beginning! 
// Showing elements in my array 
// 19 | 256 | 20 | 3 | 3 | 7 | 37 | 9 | 128 | 11 | 15 | 7 | 9 | 
// An element has been deleted from the beginning! 
// An element has been deleted from the beginning! 
// An element has been deleted from the end! 
// An element has been deleted from the end! 
// 7 has been deleted! 
// Element not found! Delete is not possible. 
// Showing elements in my array 
// 20 | 3 | 3 | 37 | 9 | 128 | 11 | 15 | 
