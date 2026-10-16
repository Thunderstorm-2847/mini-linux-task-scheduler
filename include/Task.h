#ifndef TASK_H
#define TASK_H

#include <string>

enum class Tasktype
{
    INTERNAL,
    LINUX_COMMAND
};

enum class TaskStatus
{
    WAITING,
    RUNNING,
    COMPLETED,
    FAILED
};

struct Task
{
    int id;
    std::string name;
    Tasktype type;
    TaskStatus status;
};

void addTask(std::vector<Task>& tasks, int& nextId);
void viewTasks(const std::vector<Task>& tasks);

std::string taskTypeToString(Tasktype type);
std::string taskStatusToString(TaskStatus status);

#endif