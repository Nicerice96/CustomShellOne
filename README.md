# CustomShellOne

# Shell workflow:
prompt -> read -> parse -> fork -> exec -> wait -> repeat

# Processes
## What is a process 
When a process is executed on a computer system, the operating system allocates system resources such as central processing unit (CPU) time, memory, and input/output (I/O) devices to the process. The process then runs in its own virtual address space and performs the instructions specified in its program code.

A process is created when you launch a program or execute a command on your computer. When you initiate the execution of a program, the operating system creates a new process for that program, assigns it a unique process identifier (PID), and sets up the necessary resources for the process to run.

## What is process scheduling?
Process scheduling is how the operating system determines the order in which processes are executed. It involves selecting processes from the ready queue and allocating central processing unit (CPU) time to them. The goal of process scheduling is to maximize the utilization of system resources, ensure fairness, and maintain responsiveness.

## What is the difference between preemptive and non-preemptive scheduling?
Preemptive scheduling is a type of scheduling where the operating system can interrupt a running process and allocate the central processing unit (CPU) to another process. The operating system decides when to preempt a process based on predefined rules, such as priority levels or time quantum. In contrast, non-preemptive scheduling does not allow the operating system to interrupt a process before it completes its execution or voluntarily yields the CPU.


## What is context switching?
Context switching is the process of saving the current state of a process and restoring the state of another process. When a context switch occurs, the operating system saves the program counter, registers, and other relevant information of the currently running process, and then loads the saved state of another process. This allows the operating system to switch execution between multiple processes seamlessly.

## Why is context switching an expensive operation?
Context switching is an expensive operation because it involves saving and restoring a large amount of process state. The operating system needs to store and reload the program counter, registers, memory mappings, and other context information. Additionally, a context switch may also involve updating various data structures and performing housekeeping tasks, which adds to the overhead.

# Communication between Processes
## What is interprocess communication (IPC)?
Interprocess communication refers to the mechanisms and techniques used by processes to exchange data and information with each other. IPC allows processes to cooperate, synchronize their actions, and share resources. Common IPC mechanisms include shared memory, message passing, pipes, sockets, and remote procedure calls.

## How does interprocess communication (IPC) facilitate communication between processes?
Interprocess communication provides a set of standardized methods and protocols for processes to exchange data and coordinate their activities. Processes can use IPC mechanisms like shared memory to share data directly, or they can use message passing to send and receive messages between each other. These communication channels enable processes to work together, even if they are running independently.

## What is a daemon process?
A daemon process, often referred to as a background process, is a type of process that runs in the background without any direct user interaction. Daemons are typically started when the system boots up and provides specific services or performs certain tasks. They often operate silently, handling system maintenance, network services, or other background operations.

## What is a process tree?
A process tree represents the hierarchical relationship between processes in a system. The parent-child relationship forms a tree-like structure, where each process except the root (init process) has a single parent but can have multiple child processes. This structure allows for the organization and management of processes, where child processes inherit certain characteristics from their parent processes.

## What is a zombie process?
A zombie process, also known as a defunct process, is a terminated process that has completed its execution but still has an entry in the process table. A zombie process exists until its parent process acknowledges the termination by reading an exit status from the child process. Zombie processes consume minimal system resources and are typically cleaned up automatically by the operating system.

## What is process synchronization?
Process synchronization refers to the techniques and mechanisms used to coordinate the execution of multiple processes and ensure they access shared resources in a mutually exclusive and orderly manner. Synchronization prevents race conditions, deadlocks, and other concurrency issues that can arise when multiple processes or threads access shared data simultaneously.