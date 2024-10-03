#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <thread>

int result;
int tasknumbers {0}; 
int completedtasknumbers {0};
int selectedtask;
bool candeletetask;
std::string listname;
std::vector<std::string> tasks; // Vector to store tasks
std::vector<std::string> completedtasks; // Vector to store completed tasks
std::string task;

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux, macOS
    #endif
}

void uncompletedtask() {
    if (selectedtask > 0 && selectedtask <= completedtasks.size()) {
        // Move completed task back to pending tasks
        tasks.push_back(completedtasks[selectedtask - 1]);
        completedtasks.erase(completedtasks.begin() + (selectedtask - 1));
        std::cout << "Task marked as not done!\n";
    } else {
        std::cout << "Invalid selection!\n";
    }
}

void completedtask() {
    if (selectedtask > 0 && selectedtask <= tasks.size()) {
        // Move task to completed tasks
        completedtasks.push_back(tasks[selectedtask - 1]);
        tasks.erase(tasks.begin() + (selectedtask - 1));
        std::cout << "Task marked as done!\n";
    } else {
        std::cout << "Invalid selection!\n";
    }
}

void deletetask() {
    clearConsole();
    if (candeletetask) {
        if (selectedtask > 0 && selectedtask <= completedtasks.size()) {
            completedtasks.erase(completedtasks.begin() + (selectedtask - 1)); // Delete completed task
            std::cout << "Completed task " << selectedtask << " deleted!\n";
        } else {
            std::cout << "Invalid selection. Task not found.\n";
        }
    } else {
        if (selectedtask > 0 && selectedtask <= tasks.size()) {
            tasks.erase(tasks.begin() + (selectedtask - 1)); // Delete task
            std::cout << "Task " << selectedtask << " deleted!\n";
        } else {
            std::cout << "Invalid selection. Task not found.\n";
        }
    }
}

void deletelist() {
    tasks.clear(); // Clear all tasks
    completedtasks.clear(); // Clear all completed tasks
    std::cout << "List deleted!\n";
}

void selectcompletedtask() {
    if (completedtasks.empty()) {
        std::cout << "No completed tasks available to select.\n";
        return;
    }

    // Display completed tasks
    std::cout << "\nSelect a completed task by number: ";
    std::cin >> selectedtask;

    if (selectedtask > 0 && selectedtask <= completedtasks.size()) {
        std::cout << "Selected task: " << completedtasks[selectedtask - 1] << "\n";
        std::cout << "\n1- Unmark as Done\n";
        std::cout << "2- Delete Task\n";
        std::cout << "\nEnter Here: ";
        std::cin >> result;
        candeletetask = true;

        switch (result) {
            case 1: uncompletedtask(); break;
            case 2: deletetask(); break;
            default: std::cout << "Invalid option.\n"; break;
        }
    } else {
        std::cout << "Invalid selection.\n";
    }
}

void selecttask() {
    if (tasks.empty()) {
        std::cout << "No tasks available to select.\n";
        return;
    }

    // Display tasks
    std::cout << "\nSelect a task by number: ";
    std::cin >> selectedtask;

    if (selectedtask > 0 && selectedtask <= tasks.size()) {
        std::cout << "Selected task: " << tasks[selectedtask - 1] << "\n";
        std::cout << "\n1- Mark as Done\n";
        std::cout << "2- Delete Task\n";
        std::cout << "\nEnter Here: ";
        std::cin >> result;
        candeletetask = false;

        switch (result) {
            case 1: completedtask(); break;
            case 2: deletetask(); break;
            default: std::cout << "Invalid option.\n"; break;
        }
    } else {
        std::cout << "Invalid selection.\n";
    }
}

void addtask() {
    std::cout << "\nEnter the task to add: ";
    std::cin.ignore();
    std::getline(std::cin, task); // Capture task name including spaces
    tasks.push_back(task);
    std::cout << "Task added!\n";
}

void displayList() {
    std::cout << "List name: " << listname << "\n";
    std::cout << "\nTasks:\n";
    tasknumbers = 0; // Reset task count

    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
    } else {
        for (const auto& task : tasks) {
            tasknumbers++;
            std::cout << tasknumbers << "- " << task << '\n'; // Display task number and name
        }
    }

    std::cout << "\nCompleted Tasks:\n";
    completedtasknumbers = 0; // Reset completed task count
    if (completedtasks.empty()) {
        std::cout << "No completed tasks in the list.\n";
    } else {
        for (const auto& completedtask : completedtasks) {
            completedtasknumbers++;
            std::cout << completedtasknumbers << "- " << completedtask << '\n'; // Display completed task number
        }
    }
}

void lista() {
    while (true) {
        displayList(); // Display current tasks and completed tasks

        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1- Add Task\n";
        std::cout << "2- Select Task\n";
        std::cout << "3- Select Completed Task\n";
        std::cout << "4- Delete List\n";
        std::cout << "\nEnter Here: ";
        std::cin >> result;

        switch (result) {
            case 1: addtask(); break;
            case 2: selecttask(); break;
            case 3: selectcompletedtask(); break;
            case 4: deletelist(); return;
            default: std::cout << "Invalid option.\n"; break;
        }

        clearConsole();
    }
}   

void create() {
    // Creating Task List
    for (int print = 0; print <= 100; print++) {
        std::cout << "Creating..." << print << "%\r"; 
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(30)); // Simulate time taken to create
    } 
    std::cout << "\nCreated Successfully!\n";

    std::cout << "\nEnter a name for your task list: ";
    std::cin.ignore();
    std::getline(std::cin, listname);  // Capture list name including spaces
    clearConsole();
    lista();
}

void menu() {
    clearConsole();
    std::cout << "\nWelcome to your task list!\n";
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1- Create a new task list\n";
    std::cout << "2- Exit\n";
    std::cout << "\nEnter here: ";
    std::cin >> result;

    switch (result) {
        case 1: create(); break;
        default: std::cout << "Exiting...\n"; break;
    }
}

int main() {
    menu();
}
