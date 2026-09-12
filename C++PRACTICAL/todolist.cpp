#include <iostream>
#include <vector>
using namespace std;

struct Task {
    int id;
    string name;
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice, id;
    int nextID = 1;

    while (true) {
        cout << "\n===== To-Do List =====\n";
        cout << "1. Add  2. Mark Completed  3. View Pending\n";
        cout << "4. View Completed  5. Delete  6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            if (tasks.size() == 15) {
                cout << "Task list is full\n";
                break;
            }

            Task t;
            t.id = nextID++;

            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, t.name);

            t.completed = false;
            tasks.push_back(t);

            cout << "Task added with ID " << t.id << endl;
            break;
        }

        case 2: {
            cout << "Enter task ID: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].id == id) {
                    found = true;

                    if (tasks[i].completed) {
                        cout << "Task is already completed\n";
                    } else {
                        tasks[i].completed = true;
                        cout << "Task marked as completed.\n";
                    }
                    break;
                }
            }

            if (!found)
                cout << "Task not found\n";

            break;
        }

        case 3: {
            bool found = false;

            for (int i = 0; i < tasks.size(); i++) {
                if (!tasks[i].completed) {
                    cout << "[" << tasks[i].id << "] "
                         << tasks[i].name << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No tasks to show\n";

            break;
        }

        case 4: {
            bool found = false;

            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].completed) {
                    cout << "[" << tasks[i].id << "] "
                         << tasks[i].name << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No tasks to show\n";

            break;
        }

        case 5: {
            cout << "Enter task ID: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].id == id) {
                    tasks.erase(tasks.begin() + i);
                    found = true;
                    cout << "Task deleted.\n";
                    break;
                }
            }

            if (!found)
                cout << "Task not found\n";

            break;
        }

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}

