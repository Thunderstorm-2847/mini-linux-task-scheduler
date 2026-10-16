#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include "Task.h"

int main() {
    std::vector<Task> tasks;
    int nextID = 1;
    int choice;

    std::cout << "This is a Mini Task Scheduler" << '\n';

    do
    {
        std::cout << "Options:" << '\n';
        std::cout << "1. Add a task" << '\n';
        std::cout << "2. View all tasks" << '\n';
        std::cout << "3. Exit" << '\n';
        std::cout << '\n';

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cout << '\n';

        if (choice == 1)
        {
            addTask(tasks, nextID);
        }
        else if (choice == 2)
        {
            viewTasks(tasks);
        }
        else if (choice == 3)
        {
            std::cout << "Exiting the scheduler..." << '\n';
        }
        else
        {
            std::cout << "Invalid choice. Try again." << '\n';
        }

        std::cout << '\n';

    } while (choice!=3);

    return 0;
}