#include <iostream>
#include <string>
#include <vector>
#include "Task.h"

void addTask(std::vector<Task>& tasks, int& nextID)
{
    Task newTask;
    newTask.id = nextID;
    nextID++;

    std::string taskName;

    do
    {
        std::cout << "Enter task name: ";
        
        std::cin.ignore();
        std::getline(std::cin, taskName);

        if(taskName=="")
            std::cout << "Invalid name. Enter name again." << '\n';

        std::cout << '\n';
    } while (taskName == "");


    newTask.name = taskName;

    std::cout << "Select task type:" << '\n';
    std::cout << "1. Internal Task" << '\n';
    std::cout << "2. Linux Command" << '\n';

    int t;

    do
    {
        std::cout << "Enter type: ";
        std::cin >> t;

        if(t<1 || t>2)
            std::cout << "Invalid Type. Try again." << '\n';

        std::cout << '\n';
    } while (t<1 || t>2);
    
    if(t==1)
    {
        newTask.type = Tasktype::INTERNAL;

        std::string str;

        do
        {
            std::cout << "Enter message to print: ";

            std::cin.ignore();
            std::getline(std::cin, str);

            if (str == "")
                std::cout << "Invalid message. Enter message again." << '\n';

            std::cout << '\n';
        } while (str == "");

        newTask.message = str;
    }

    if(t==2)
    {
        newTask.type = Tasktype::LINUX_COMMAND;
        newTask.message = "";
    }

    newTask.status = TaskStatus::WAITING;

    tasks.push_back(newTask);

    std::cout << "Task has been created successfully. Task ID: " << newTask.id << '\n';

}

std::string taskTypeToString(Tasktype type)
{
    if(type==Tasktype::INTERNAL)    return "INTERNAL";
    if(type==Tasktype::LINUX_COMMAND)    return "LINUX_COMMAND";
    else    return " ";
}

std::string taskStatusToString(TaskStatus status)
{
    if(status==TaskStatus::WAITING)    return "WAITING";
    if(status==TaskStatus::RUNNING)    return "RUNNING";
    if(status==TaskStatus::COMPLETED)    return "COMPLETED";
    if(status==TaskStatus::FAILED)    return "FAILED";
    else    return " ";
}

void viewTasks(const std::vector<Task>& tasks)
{
    std::cout << '\n';
    std::cout << "========ALL TASKS========" << '\n';
    std::cout << '\n';
    
    if(tasks.size()==0)
    {
        std::cout << "No tasks available." << '\n';
        std::cout << '\n';
    }
    else
    {
        int n = tasks.size();

        for(int i=0; i<n; i++)
        {
            std::cout << "TaskID: " << tasks[i].id << '\n';
            std::cout << "Name: " << tasks[i].name << '\n';
            std::cout << "Task Type: " << taskTypeToString(tasks[i].type) << '\n';
            std::cout << "Task Status: " << taskStatusToString(tasks[i].status) << '\n';
            std::cout << '\n';
        }
    }
    std::cout << "=========================" << '\n';
    std::cout << '\n';
}

bool executeTask(const Task& task)
{
    if(task.type != Tasktype::INTERNAL)
    {
        std::cout << "Unsupported Task Type." << '\n';
        return false;
    }

    std::cout << "Task Output: " << task.message << '\n';

    return true;
}