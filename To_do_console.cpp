#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "------Task added successfully.-------" << endl;
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "-----------Task marked as completed.--------" << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    
    do {
        cout << "\nTodo List Application" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	cout << "---------------------------------" << endl;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                int index;
                cout << "---------------------------------" << endl;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index - 1);
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << "---------------------------------" << endl;
        }
    } while (choice != 4);

    return 0;
}
