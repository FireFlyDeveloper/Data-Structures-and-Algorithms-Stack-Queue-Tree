#include <iostream>
using namespace std;

// Define a structure for storing task information
struct Task {
  string description; // Description of the task
  int priority;       // Priority of the task
};

Task taskQueue[10]; // Array to store tasks
int rear = -1;      // Variable to keep track of the rear end of the queue

// Function to add a task to the priority queue
void enqueue(Task t) {
    if (rear == 9) {
        cout << "Queue is full" << endl; // Display a message if the queue is full
    } else {
        if (rear == -1 || taskQueue[rear].priority <= t.priority) {
            // If the queue is empty or the new task has equal or higher priority,
            // add it directly at the end
            rear++;
            taskQueue[rear] = t;
        } else {
            // If the new task has higher priority, find its position
            // based on priority and insert it accordingly
            int i = rear;
            while (i >= 0 && taskQueue[i].priority > t.priority) {
                taskQueue[i + 1] = taskQueue[i];
                i--;
            }
            taskQueue[i + 1] = t;
            rear++;
        }
    }
}

// Function to remove a task from the priority queue
void dequeue() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display a message if the queue is empty
  } else {
    cout << "Dequeued task: " << taskQueue[0].description << " with priority " << taskQueue[0].priority << endl; // Display the dequeued task
    // Shift all tasks one position to the front
    for (int i = 0; i < rear; i++) {
        taskQueue[i] = taskQueue[i + 1];
    }
    rear--; // Update the rear index
  }
}

// Function to peek at the task with the highest priority
void peek() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display a message if the queue is empty
  } else {
    cout << "Peeked task: " << taskQueue[0].description << " with priority " << taskQueue[0].priority << endl; // Display the peeked task
  }
}

int main() {
  Task t;

  t = {"Complete assignment", 3};
  enqueue(t);

  t = {"Go to the gym", 1};
  enqueue(t);

  t = {"Pay bills", 2};
  enqueue(t);

  t = {"Prepare dinner", 4};
  enqueue(t);

  t = {"Read a book", 5};
  enqueue(t);

  peek(); // Peek at the task with the highest priority

  dequeue(); // Remove a task from the queue
  peek(); // Peek again to see the next highest priority task

  return 0;
}
