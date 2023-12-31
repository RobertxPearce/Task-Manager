/// - Robert Pearce

#include <iostream>
#include <string>

using namespace std;

class TaskNode {        // Task Node Class
public:
    string description; // Description of task.
    int priority;       // Priority of task.
    TaskNode* next;     // Pointer to next node.

    // Constructor
    TaskNode(string desc, int pri) : description(desc), priority(pri), next(nullptr) {};
};

class TaskList {                                                                        // Task List Manager Class
private:
    TaskNode* head;                                                                     // Pointer to head of linked list.
public:
    TaskList() { head = nullptr; }                                                      // Task list constructor.

    void addTask(string description, int priority) {                                    // Function to add task based on priority.
        TaskNode* newTask = new TaskNode(description, priority);                        // Create new task node.

        if (head == nullptr || priority > head->priority) {                             // Check if list is empty or head has lower priority.
            newTask->next = head;                                                       // Set next task to head.
            head = newTask;                                                             // Set head to new task.
        } else {                                                                        // If not find correct place for new task.
            TaskNode* current = head;                                                   // Temp tasknode.
            while(current->next != nullptr && priority <= current->next->priority) {    // While loop to find appropriate place for new node.
                current = current->next;                                                // Update current node pointer.
            }
            newTask->next = current->next;                                              // Set position of new task.
            current->next = newTask;                                                    // Update pointer.
        }
        cout << "Task added: " << description << endl;                                  // Print message.
    }

    void removeTask(string description) {                                               // Function to remove task by description.
        TaskNode* current = head;                                                       // Temporary task node for iteration.
        TaskNode* prev = nullptr;                                                       // Temporary task node for previous node.

        while (current != nullptr && current->description != description) {             // while Loop to iterate through list and find node.
            prev = current;                                                             // Update previous node pointer.
            current = current->next;                                                    // Update current node pointer.
        }
        if (current == nullptr) {                                                       // Check if task was not found.
            cout << "Task not found!" << endl;                                          // If so print message.
            return;                                                                     // Return.
        }
        if (prev == nullptr) {                                                          // Remove task from list.
            head = current->next;                                                       // Update head pointer.
        } else {
            prev->next = current->next;                                                 // Update next pointer of previous pointer.
        }
        cout << "Task removed: " << description << endl;                                // Display message.
        delete current;                                                                 // Deallocate current node pointer.
    }

    void displayTasks() {                                                               // Function to print the tasks in list.
        if (head == nullptr) {                                                          // Check if list is empty.
            cout << "Task list is empty!" << endl;                                      // If so print error message.
            return;
        }

        TaskNode* current = head;                                                       // Temp node pointer.

        cout << "Tasks in list:" << endl;                                               // Print title.

        while (current != nullptr) {                                                    // while Loop to iterate through list.
            cout << "Priority: " << current->priority;                                  // Print priority.
            cout << " - Description: " << current->description << endl;                 // Print description.
            current = current->next;                                                    // Update current node pointer to next.
        }
    }

    ~TaskList() {                                                                   // Destructor for task list.
        TaskNode* current = head;                                                   // Allocate node pointer.
        while (current != nullptr) {                                                // while Loop to iterate through list.
            TaskNode* temp = current;                                               // Temp node pointer.
            current = current->next;                                                // Update current node pointer.
            delete temp;                                                            // Delete temp node.
        }
        head = nullptr;                                                             // Set head to nullptr.
    }
};

// Main function or Task Manager interface
int main() {
    TaskList taskManager;   // Create a TaskList object
    int choice;             // Variable for input from user.
    string desc;            // Variable for task description.
    int priority;           // Variable for task priority.

    do {                                            // do while Loop to prompt user and display menu & tasks until user selects to exit.
        cout << "\nTask Manager Menu:" << endl;     // Print header.
        cout << "1. Add Task" << endl;              // Print choice to add task.
        cout << "2. Remove Task" << endl;           // Print choice to remove task. 
        cout << "3. Display Tasks" << endl;         // Print choice to display tasks.
        cout << "4. Exit" << endl;                  // Print choice to exit task list.
        cout << "Enter your choice: ";              // Prompt user for choice.
        cin >> choice;                              // cin User input.

        switch (choice) {
            case 1:                                                     // Add a task: Prompt user for description and priority, then add the task.
                cout << "Enter task description: ";                     // Prompt user to enter task.
                cin.ignore();                                           // Ignore newline character in the buffer.
                getline(cin, desc);                                     // cin Task description.
                cout << "Enter priority (1-5, where 5 is highest): ";   // Prompt user to enter task priority.
                cin >> priority;                                        // cin user input.
                taskManager.addTask(desc, priority);                    // Call add task function.
                break;
            case 2:                                                     // Remove a task: Prompt user for description and remove the task.
                cout << "Enter task description to remove: ";           // Prompt user to enter desc of task to remove.
                cin.ignore();                                           // Ignore newline character.
                getline(cin, desc);                                     // cin task desc.
                taskManager.removeTask(desc);                           // Call funciton to remove task.
                break;
            case 3:                                                     // Display all tasks in the task list.
                taskManager.displayTasks();                             // Call function to display task.
                break;
            case 4:                                                     // Exit the program
                cout << "Exiting the Task Manager..." << endl;          // Print message to user.
                break;
            default:                                                    // Default on invalid input.                 
                cout << "Invalid choice!" << endl;                      // Prompt user to enter correct input.
                break;
        }
    } while (choice != 4);

    return 0;
}
