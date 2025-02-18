## Shceduling

#### Problem: We don't know that much about processes

We want to know which jobs are short for the best average completion time.

Different strategies for learning job runtimes.

- measure! Use past to predict the future

There may be many queues a job is on one queue at any given time. 


### MLFQ

Assign a priority to each job with higher priority jobs running first. Equal priority jobs run in rr mode. MLFQ observes processes as they run and adjusts priority. Jobs which frequently wait for I/O end up with higher priority. CPU intensive jobs end up with lower priority.

Each job is given an allotment, which is the amount of time a job can use up before the scheduler will reduce its priority.

**Rule 1** If Priority(A) > Priority(B), A runs B doesn't
**Rule 2** If Priority(A) == Priority(B), A & B run in round robin
**Rule 3** When a job enters the system it is placed at the highest priority.
**Rule 4a** If a job uses up its allotment while running it's priority is reduced.
**Rule 4b** If a job gives up the CPU before it's allotment it stays at the same priority level.


A major goal of the algorithm is to approximate SJF (Shortest job first). When a new job enters the system it is given high priority because the system doesn't know how long the job will take to run. It might be a short job. If it's long it will quickly move down the queue.

#### Problems

- **Starvation** Too many interactive jobs consume all cpu and long running jobs never get cpu time.

- **Gaming the scheduler** A smart or nefarious user could game the scheduler. Issuing io requests to maintain high priority in the queue.

* **Rule 5** Periodically boost the priority of all jobs in the system

* **Rule 4** Once a job uses up its allotment time at a given level (regardless of how many times it has given up the cpu), its priority is lowered.

This is an further optimization to prevent gaming the system. 


### Proportional Share

We can use randomness to try to increase fairness in cpu scheduling. Such as by allocating tickets and holding a lottery to determine which process gets the cpu. This will probabalistically approach the lottery share of each process. There are also deterministic ways of accomplishing the same result but these have the downside of having to store state about each running process.



### CFS (Completely Fair Scheduler)

* **The** Linux scheduler

It turns out scheduler efficiency is important. A study of Google datacenters found that the scheduler was using 5% of all cpu time. (Which seems like alot)

CFS works by keeping track of a **virtual-runtime** for each process (essentially the amount of CPU time any given process has taken). When a scheduling decision is made CFS picks the process with the lowest virtual runtime.

CFS determines how long to run reach process by using a sched_latency value for example 43 ms. CFS divides this value by the number of running processes to get the amount of time between checks of the virtual runtime. If another process has a lower virtual runtime CFS runs that process instead

Users or system administrators can weight processes to give them higher or lower priority

All running processes are stored in a red-black tree. Meaning processes can be found in O(log n) time.

If a process has been sleeping frequently or for a long time CFS sets the vruntime of that job to the minimum value found in the running process tree.
