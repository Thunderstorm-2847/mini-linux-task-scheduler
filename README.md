# Mini Linux Task Scheduler

A simple C++ project that demonstrates the basic concepts of task management and CPU scheduling on Linux. The project starts with a command-line interface (CLI) where users can add tasks, view them, and schedule them using the First-Come, First-Served (FCFS) scheduling algorithm.

This project is being developed step by step to understand C++, data structures, scheduling algorithms, and Linux system calls.

## Project Objectives

- Understand how to create and manage tasks in C++.
- Learn how to organize a project using header and source files.
- Implement a basic task scheduler.
- Understand the First-Come, First-Served (FCFS) scheduling algorithm.
- Learn how task status changes during scheduling.
- Build a foundation for future Linux process management and system calls.

## Features Implemented

### Day 1: Task Management and CLI

- **Add tasks:** Create tasks by entering a task name and selecting its type.
- **Unique task IDs:** Assign a unique ID to every task.
- **Two task types:** Support `INTERNAL` and `LINUX_COMMAND` tasks.
- **Task status tracking:** Each new task starts with the `WAITING` status.
- **View tasks:** Display the list of tasks with their IDs, names, types, and statuses.
- **Menu-driven interface:** Use a command-line menu to perform different operations.
- **Persistent runtime state:** Store tasks in a vector so they remain available while the program is running.
- **Modular code structure:** Separate task-related declarations and implementations into header and source files.

### Day 2: FCFS Task Scheduling

- **FCFS scheduling:** Process waiting tasks in the order they were added.
- **Task selection:** Select only tasks whose status is `WAITING`.
- **Status transitions:** Change task status from `WAITING` to `RUNNING`, then to `COMPLETED` after simulated execution.
- **Skip completed tasks:** Avoid processing tasks that have already been completed.
- **Empty queue handling:** Display a message when there are no tasks to schedule.
- **Scheduler integration:** Provide an option to run the scheduler from the command-line menu.

> **Note:** Task execution is currently simulated. The program does not yet execute actual Linux commands or create operating-system processes.

## Technologies Used

- **Language:** C++
- **C++ Standard:** C++17
- **Data Structure:** `std::vector`
- **Concepts:** Structures, enumerations, functions, references, loops, conditional statements, and modular programming
- **Scheduling Algorithm:** First-Come, First-Served (FCFS)
- **Development Environment:** Linux-compatible terminal and a C++ compiler such as `g++`
- **Version Control:** Git and GitHub

## Project Structure

```text
mini-linux-task-scheduler/
├── include/
│   ├── Task.h
│   └── Scheduler.h
├── src/
│   ├── main.cpp
│   ├── Task.cpp
│   └── Scheduler.cpp
└── README.md
```

### File Description

| File | Purpose |
|---|---|
| `include/Task.h` | Defines the task structure, task types, task statuses, and task-related function declarations. |
| `include/Scheduler.h` | Declares the scheduler function. |
| `src/main.cpp` | Contains the main program and command-line menu. |
| `src/Task.cpp` | Implements task creation, task viewing, and helper functions for displaying task types and statuses. |
| `src/Scheduler.cpp` | Implements the FCFS scheduling logic. |
| `README.md` | Documents the project, features, and instructions. |

## Task Model

Each task contains the following information:

| Field | Description |
|---|---|
| `id` | A unique integer assigned to the task. |
| `name` | The name given to the task by the user. |
| `type` | The category of task. |
| `status` | The current state of the task. |

### Task Types

- `INTERNAL`: A task handled internally by the program.
- `LINUX_COMMAND`: A task intended to represent a Linux command.

At the current stage, both types are managed by the program, but actual Linux command execution has not been implemented.

### Task Statuses

- `WAITING`: The task is waiting to be scheduled.
- `RUNNING`: The scheduler is currently processing the task.
- `COMPLETED`: The task has finished its simulated execution.
- `FAILED`: Represents a task that fails during execution. Failure handling is planned for a future stage.

## Scheduling Algorithm: FCFS

First-Come, First-Served (FCFS) is a scheduling algorithm in which tasks are processed in the order they arrive.

The scheduler follows these steps:

1. Check whether the task list is empty.
2. Traverse the task vector from beginning to end.
3. Skip tasks that are not in the `WAITING` state.
4. Change the selected task's status to `RUNNING`.
5. Simulate task processing.
6. Change the task's status to `COMPLETED`.
7. Continue until all waiting tasks have been processed.

### Example

Suppose the user adds three tasks in this order:

| Task ID | Task Name | Initial Status |
|---|---|---|
| 1 | Task A | `WAITING` |
| 2 | Task B | `WAITING` |
| 3 | Task C | `WAITING` |

When the scheduler runs, the processing order is:

`Task A → Task B → Task C`

After successful simulated processing, all three tasks have the status `COMPLETED`.

If the scheduler runs again, these completed tasks are skipped. If a new task is added, only that new waiting task needs to be processed.

## Prerequisites

Before running the project, make sure you have:

- A Linux environment or another environment with a compatible C++ compiler.
- `g++` installed.
- Basic familiarity with using a terminal.
- Git installed if you want to clone and contribute to the project.

Check whether the compiler is installed:

```bash
g++ --version
```

## How to Compile and Run

### 1. Clone the repository

Replace `<your-github-username>` with your GitHub username.

```bash
git clone https://github.com/<your-github-username>/mini-linux-task-scheduler.git
```

### 2. Navigate to the project directory

```bash
cd mini-linux-task-scheduler
```

### 3. Compile the project

Run the following command from the project root:

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/Task.cpp src/Scheduler.cpp -o scheduler
```

Explanation:

- `-std=c++17`: Compile using the C++17 standard.
- `-Wall -Wextra`: Enable additional compiler warnings.
- `-Iinclude`: Tell the compiler where to find the header files.
- `src/main.cpp src/Task.cpp src/Scheduler.cpp`: Compile all source files.
- `-o scheduler`: Name the resulting executable `scheduler`.

### 4. Run the program

```bash
./scheduler
```

Follow the on-screen menu to add tasks, view tasks, run the scheduler, or exit the program.

## Testing

The following scenarios should be tested:

- **Empty task list:** Running the scheduler without adding tasks should display an appropriate message.
- **Task creation:** Adding multiple tasks should assign unique IDs and set their initial status to `WAITING`.
- **Task viewing:** The task list should display the correct task information.
- **FCFS order:** Waiting tasks should be processed in insertion order.
- **Status updates:** Processed tasks should change to `COMPLETED`.
- **Repeated scheduling:** Running the scheduler again should skip previously completed tasks.
- **New task after scheduling:** A newly added task should be scheduled without reprocessing completed tasks.
- **Menu navigation:** The program should continue accepting choices until the user selects the exit option.

## Current Limitations

- Task processing is simulated rather than performed by the operating system.
- Linux commands are not actually executed.
- Operating-system processes are not created using `fork()`.
- Program execution using `exec()` and process synchronization using `wait()` have not been implemented.
- Multithreading, execution-time measurement, and advanced error handling are not yet implemented.
- Task data is stored in memory and is lost when the program exits.

These limitations are intentional at the current stage of development.

## Future Improvements

The following features are planned for future development:

- Execute internal tasks.
- Execute real Linux commands using process-related system calls.
- Introduce process creation with `fork()`.
- Execute commands using an appropriate `exec()` function.
- Wait for child processes using `wait()` or `waitpid()`.
- Improve error handling and task failure management.
- Add execution-time tracking and scheduling statistics.
- Explore multithreading and more advanced scheduling algorithms.
- Improve testing and documentation.

## Learning Progress

| Day | Work Completed |
|---|---|
| Day 1 | Created the task model, implemented task creation and viewing, added a menu-driven interface, and separated task-related code into header and source files. |
| Day 2 | Implemented FCFS scheduling, task selection, simulated execution, status transitions, and handling of empty or already-processed task lists. |

## Learning Outcomes

Through this project, I aim to develop a practical understanding of:

- C++ program organization and modular design.
- Task representation using structures and enumerations.
- Managing collections with `std::vector`.
- Implementing scheduling algorithms.
- Tracking task states throughout execution.
- Linux process management and system calls in later stages.
- Using Git and GitHub to manage project development.

## License

This project is intended for educational and learning purposes. A formal license can be added if the project is distributed or reused by others.
