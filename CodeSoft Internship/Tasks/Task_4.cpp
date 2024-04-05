// Build a simple console-based to-do list

// manager that allows users to add, view, and

// delete tasks

// Task Input: Allow users to input tasks they want to add to the list.
// Add Task: Implement a function to add tasks to the list.
// View Tasks: Display the list of tasks with their status (completed or
// pending).
// Mark Task as Completed: Allow users to mark tasks as completed.
// Remove Task: Provide an option to remove tasks from the list.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class ToDoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &description)
    {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks available." << endl;
        }
        else
        {
            cout << "Tasks:" << endl;
            for (const auto &task : tasks)
            {
                cout << "- " << task.description;
                if (task.completed)
                {
                    cout << " (Completed)";
                }
                cout << endl;
            }
        }
    }

    void markAsCompleted(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].completed = true;
            cout << "Marked task as completed: " << tasks[index].description << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            cout << "Removed task: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }
};

int main()
{
    ToDoList toDoList;

    while (true)
    {
        cout << "\n===== To-Do List Manager =====" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter task description: ";
            string description;
            cin.ignore(); // Clear the input buffer
            getline(cin, description);
            toDoList.addTask(description);
            break;
        }
        case 2:
            toDoList.viewTasks();
            break;
        case 3:
        {
            cout << "Enter the index of the task to mark as completed: ";
            int index;
            cin >> index;
            toDoList.markAsCompleted(index);
            break;
        }
        case 4:
        {
            cout << "Enter the index of the task to remove: ";
            int index;
            cin >> index;
            toDoList.removeTask(index);
            break;
        }
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
