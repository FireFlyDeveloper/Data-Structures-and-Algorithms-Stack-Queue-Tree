#include <iostream>
using namespace std;

string input = "radar";
bool isPalindrome = true;

char myStack[20];
int top = -1;

bool isUnderflow() {
  if (top == -1) {
    return true;
  }
  return false;
}

void push(char val) { myStack[++top] = val; }

char pop() {
  if (isUnderflow()) {
    return '\0';
  }
  return myStack[top--];
}

void checkPalindrome() {
  int len = input.length();
  int i, mid = len / 2;

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
      isPalindrome = false;
      break;
    }
    i++;
  }
}

int main() {
  checkPalindrome();

  if (isPalindrome) {
    cout << "The word is a palindrome." << endl;
  } else {
    cout << "The word is not a palindrome." << endl;
  }

  return 0;
}
