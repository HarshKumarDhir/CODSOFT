#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int taskId = 1, userChoice, continueAdding, taskToDelete, taskToEdit;
    string taskDescription;
    map<int, string> tasks;
    map<int, int> taskStatus;

    while (true) {
        cout << "===========================" << endl;
        cout << "-TO-DO-LIST-" << endl;
        cout << "===========================" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Remove a Task" << endl;
        cout << "4. Mark a Task as Done" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                cout << endl;
                do {
                    cin.ignore();
                    cout << "Enter task details: ";
                    getline(cin, taskDescription);
                    tasks[taskId] = taskDescription;
                    taskStatus[taskId] = 0;
                    taskId++;
                    cout << "Add another task? (1=Yes / 0=No): ";
                    cin >> continueAdding;
                } while (continueAdding);
                break;
            }

            case 2: {
                cout << endl;
                for (const auto& task : tasks) {
                    if (taskStatus.at(task.first) == 1) {
                        cout << "Task-" << task.first << ": " << task.second << " [Completed]" << endl;
                    } else {
                        cout << "Task-" << task.first << ": " << task.second << " [Pending]" << endl;
                    }
                }
                break;
            }

            case 3: {
                cout << "\nEnter the task number to delete: ";
                cin >> taskToDelete;
                if (tasks.erase(taskToDelete) && taskStatus.erase(taskToDelete)) {
                    cout << "\nTask-" << taskToDelete << " has been successfully deleted." << endl;
                } else {
                    cout << "\nTask-" << taskToDelete << " not found." << endl;
                }
                break;
            }

            case 4: {
                cout << "\nEnter the task number to mark as completed: ";
                cin >> taskToEdit;
                try {
                    taskStatus.at(taskToEdit) = 1;
                    tasks[taskToEdit] += " [Completed]";
                    cout << "\nTask-" << taskToEdit << " has been marked as completed." << endl;
                } catch (const out_of_range&) {
                    cout << "\nTask number is invalid." << endl;
                }
                break;
            }

            case 5: {
                cout << "\nThank you for using the Task Manager. Goodbye!" << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
