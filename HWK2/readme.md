# CSCI-340 Homework 2: Blake Mitrick
---

## 2. C Pointers and References

>### Sample Input/Output for my code
```
blake@CSCI-340:~/Documents/CSCI-340/HWK2$ make
gcc -Wall -g -o hwk2 hwk2.c
blake@CSCI-340:~/Documents/CSCI-340/HWK2$ ./hwk2 3
address of memory block: <0x55ffeb4f2260>
value at address 0x55ffeb4f2260: 0
value at address 0x55ffeb4f2264: 0
value at address 0x55ffeb4f2268: 0
blake@CSCI-340:~/Documents/CSCI-340/HWK2$ ./hwk2 5
address of memory block: <0x55ec8f7be260>
value at address 0x55ec8f7be260: 0
value at address 0x55ec8f7be264: 0
value at address 0x55ec8f7be268: 0
value at address 0x55ec8f7be26c: 0
value at address 0x55ec8f7be270: 0
blake@CSCI-340:~/Documents/CSCI-340/HWK2$ ./hwk2 10
address of memory block: <0x5570761e3260>
value at address 0x5570761e3260: 0
value at address 0x5570761e3264: 0
value at address 0x5570761e3268: 0
value at address 0x5570761e326c: 0
value at address 0x5570761e3270: 0
value at address 0x5570761e3274: 0
value at address 0x5570761e3278: 0
value at address 0x5570761e327c: 0
value at address 0x5570761e3280: 0
value at address 0x5570761e3284: 0
blake@CSCI-340:~/Documents/CSCI-340/HWK2$ ./hwk2 15
address of memory block: <0x55b4fb642260>
value at address 0x55b4fb642260: 0
value at address 0x55b4fb642264: 0
value at address 0x55b4fb642268: 0
value at address 0x55b4fb64226c: 0
value at address 0x55b4fb642270: 0
value at address 0x55b4fb642274: 0
value at address 0x55b4fb642278: 0
value at address 0x55b4fb64227c: 0
value at address 0x55b4fb642280: 0
value at address 0x55b4fb642284: 0
value at address 0x55b4fb642288: 0
value at address 0x55b4fb64228c: 0
value at address 0x55b4fb642290: 0
value at address 0x55b4fb642294: 0
value at address 0x55b4fb642298: 0
```

## 3. C Pointers and References

>### For a process in each of the states below, list each other state the process could transition into and give at least one reason why it might transition into that state:
> * Ready
> * Suspended
> * Running
> ## Ready
>> A ready process can transition into running if it is run by the scheduler.
> ## Suspended
>> A suspended process can transition to ready once it has completed it's IO or action is completed
> # Running
>> A running process can transition to either suspended, terminated, or ready. It will transition to suspended if it contains a wait or a call for IO. It will transition to ready if some interrupt occurs.It will transition to terminated once it is completed.

## 4. Scheduling Policies

> ### Over the years Linux has used a number of different processing scheduling algorithms. Two current ones are the CFS and BFS schedulers. For each of these algorithms describe, in a paragraph, the main features of the algorithm (are they priority based, time sliced, etc.)
>## CFS
>> CFS (Completely Fair Scheduler) is the default scheduler for vanilla Linux. CFS is priority based with each task having a weighted priority. CFS has 3 scheduling policies: SCHED_NORMAL, SCHED_BATCH, and SCHED_IDLE. CFS does not have traditional time slices but rather, according to kernal.org, "The virtual runtime of a task specifies when its next timeslice would start execution". CFS all modeled around the idea of the "ideal, precise multi-tasking CPU".
>## BFS
>> BFS (Brain Fuck Scheduler) is a priority based scheduler built on a modified version of a weighted round robin scheduler. BFS has 103 different priority queues and 4 scheduling tiers. The scheduling tiers are also known as polices and are as follows: Realtime Policy, Isochronous Policy, Normal Policy, and Idle priority Policy. The time slice of BFS is 6ms. BFS is also capable of working with multiple CPU cores. BFS has been shown to consistently outperform CFS on vanilla Linux.
