#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include "Scheduler.h"

void runScheduler(std::vector<Task>& tasks)
{
    std::cout << "========================" << '\n';
    std::cout << "Starting Scheduler..." << '\n';
    std::cout << '\n';
    
    if(tasks.size()==0)
    {
        std::cout << "No tasks to schedule." << '\n';
        std::cout << '\n';
        return;
    }
    else
    {
        for(Task& task : tasks)
        {
            if(task.status != TaskStatus::WAITING)
                continue;
            else
            {
                std::cout << "Task " << task.id << ": " << task.name << '\n';
                std::cout << taskStatusToString(task.status) << " -> ";

                task.status = TaskStatus::RUNNING;
                std::cout << taskStatusToString(task.status) << " -> ";

                task.status = TaskStatus::COMPLETED;
                std::cout << taskStatusToString(task.status) << '\n';

                std::cout << '\n';
            }
        }

        std::cout << "All tasks are Completed." << '\n';
        std::cout << "========================" << '\n';
    }
}