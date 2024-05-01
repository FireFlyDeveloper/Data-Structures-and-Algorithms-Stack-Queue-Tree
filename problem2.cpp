#include <iostream>
using namespace std;

string input = "radar";  // Word to check for palindrome
bool isPalindrome = true; // Flag to indicate if the word is a palindrome

char myStack[20]; // Stack to store characters
int top = -1;     // Variable to keep track of the top of the stack

// Function to check if stack is empty
bool isUnderflow() {
  if (top == -1) {
    return true;
  }
  return false;
}

// Function to push a character onto the stack
void push(char val) { myStack[++top] = val; }

// Function to pop a character from the stack
char pop() {
  if (isUnderflow()) {
    return '\0';
  }
  return myStack[top--];
}

// Function to check if the word is a palindrome
void checkPalindrome() {
  int len = input.length(); // Length of the word
  int i, mid = len / 2;     // Index for iterating through the word and finding the midpoint

  // Push the first half of the characters onto the stack
  for (i = 0; i < mid; i++) {
    push(input[i]);
  }

  // Check if the word is odd or even
  if (len % 2 != 0) {
    // Skip the middle character if the length is odd
    i++;
  }

  // Compare the remaining characters with the characters popped from the stack
  while (input[i] != '\0') {
    if (input[i] != pop()) {
      isPalindrome = false; // If characters don't match, set palindrome flag to false
      break;
    }
    i++;
  }
}

int main() {
  checkPalindrome(); // Check if the word is a palindrome

  // Output the result based on whether the word is a palindrome or not
  if (isPalindrome) {
    cout << "The word is a palindrome." << endl;
  } else {
    cout << "The word is not a palindrome." << endl;
  }

  return 0;
}
