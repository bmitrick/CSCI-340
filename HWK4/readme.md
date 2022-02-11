# CSCI-340 Homework 4: Blake Mitrick
---

## 1. Complex Scheduling

### a) MLFQ Scheduling
i) What are the turnaround and response times?

```
blake@CSCI-340:~/Documents/CSCI-340/HWK4/MLFQ$ python mlfq.py -j 4 -s 13 -c
...
...
...
Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  84
  Job  1: startTime   0 - response   7 - turnaround 153
  Job  2: startTime   0 - response  15 - turnaround  81
  Job  3: startTime   0 - response  18 - turnaround  70

  Avg  3: startTime n/a - response 10.00 - turnaround 97.00
```
Response time = 10.00 \
Turnaround Time = 97.00

ii) What happens to the turnaround time and responses as you increase the boost time?
```
blake@CSCI-340:~/Documents/CSCI-340/HWK4/MLFQ$ python mlfq.py -j 4 -s 13 -B 1 -c
...
...
...
Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  82
  Job  1: startTime   0 - response   2 - turnaround 153
  Job  2: startTime   0 - response   3 - turnaround  90
  Job  3: startTime   0 - response   4 - turnaround  74

  Avg  3: startTime n/a - response 2.25 - turnaround 99.75

blake@CSCI-340:~/Documents/CSCI-340/HWK4/MLFQ$ python mlfq.py -j 4 -s 13 -B 2 -c
...
...
...
  Final statistics:
    Job  0: startTime   0 - response   0 - turnaround  82
    Job  1: startTime   0 - response   3 - turnaround 153
    Job  2: startTime   0 - response   4 - turnaround  90
    Job  3: startTime   0 - response   5 - turnaround  74

    Avg  3: startTime n/a - response 3.00 - turnaround 99.75

blake@CSCI-340:~/Documents/CSCI-340/HWK4/MLFQ$ python mlfq.py -j 4 -s 13 -B 4 -c
...
...
...
    Final statistics:
      Job  0: startTime   0 - response   0 - turnaround  82
      Job  1: startTime   0 - response   5 - turnaround 157
      Job  2: startTime   0 - response   6 - turnaround  85
      Job  3: startTime   0 - response   7 - turnaround  74

      Avg  3: startTime n/a - response 4.50 - turnaround 99.50

```
For a boost of 1, the turnaround time increased but the response time went down. However, for a boost of 2, the response time increased from 2.25 to 3.00 and the turnaround time stayed the same. When the boost was increased to 4, the response time once again increased to 4.5, however, this time the turnaround time decreased to 99.50.

### b) Lottery Scheduling
i) What are the turnaround and response times? You will need to work through the output to compute the times.
```
blake@CSCI-340:~/Documents/CSCI-340/HWK4/Lottery$ python lottery.py -j 4 -s 17 -c
...
...
...
Jobs:  (  job:0 timeleft:0 tix:--- )   (  job:1 timeleft:0 tix:--- )   (  job:2 timeleft:0 tix:--- )   (* job:3 timeleft:1 tix:11 )  
--> JOB 3 DONE at time 27
```

Turnaround Time = 81 total, 20.25 avg \
Response Time = 7 total, 1.75 avg

ii) What happens when to the turnaround and response times as you increase the boost time?

-q = 1: Turnaround Time = 81 total, 20.25 avg, Response Time = 7 total, 1.75 avg \
-q = 2: Turnaround Time = 94 total, 23.5 avg, Response Time = 14 total, 3.5 avg \
-q = 4; Turnaround Time = 104 total, 26 avg, Response Time = 36 total, 9 avg

As -q increases, both turnaround time and response time seem to increase

## 2. Freespace

See pdf titled freespace.pdf

## 3. Segmentation

```
blake@CSCI-340:~/Documents/CSCI-340/HWK4/HW-Segmentation/HW-Segmentation$ ./segmentation.py -s 27 -A -1 -n 20
ARG seed 27
ARG address space size 1k
ARG phys mem size 16k

Segment register information:

  Segment 0 base  (grows positive) : 0x00003d40 (decimal 15680)
  Segment 0 limit                  : 422

  Segment 1 base  (grows negative) : 0x00000e44 (decimal 3652)
  Segment 1 limit                  : 435

Virtual Address Trace
  VA  0: 0x00000042 (decimal:   66) --> 0x00003d82
  VA  1: 0x0000034c (decimal:  844) --> 0x00000d90
  VA  2: 0x00000155 (decimal:  341) --> 0x00003e95
  VA  3: 0x0000017d (decimal:  381) --> 0x00003ebd
  VA  4: 0x00000342 (decimal:  834) --> 0x00000d86
  VA  5: 0x000000bb (decimal:  187) --> 0x00003dfb
  VA  6: 0x000003a3 (decimal:  931) --> 0x00000de7
  VA  7: 0x000001f6 (decimal:  502) --> segmentation fault
  VA  8: 0x00000049 (decimal:   73) --> 0x00003d89
  VA  9: 0x000003ab (decimal:  939) --> 0x00000def
  VA 10: 0x0000024a (decimal:  586) --> segmentation fault
  VA 11: 0x00000050 (decimal:   80) --> 0x00003d90
  VA 12: 0x0000035a (decimal:  858) --> 0x00000d9e
  VA 13: 0x00000319 (decimal:  793) --> 0x00000d5d
  VA 14: 0x000002f5 (decimal:  757) --> 0x00000d39
  VA 15: 0x000002a1 (decimal:  673) --> 0x00000ce5
  VA 16: 0x000003f8 (decimal: 1016) --> 0x00000e3c
  VA 17: 0x0000000c (decimal:   12) --> 0x00003d4c
  VA 18: 0x000003e5 (decimal:  997) --> 0x00000e29
  VA 19: 0x00000292 (decimal:  658) --> 0x00000cd6

For each virtual address, either write down the physical address it translates to
OR write down that it is an out-of-bounds address (a segmentation violation). For
this problem, you should assume a simple address space with two segments: the top
bit of the virtual address can thus be used to check whether the virtual address
is in segment 0 (topbit=0) or segment 1 (topbit=1). Note that the base/limit pairs
given to you grow in different directions, depending on the segment, i.e., segment 0
grows in the positive direction, whereas segment 1 in the negative.
```

See output above for answers, I rewrote the portions that were "PA or segmentation violation?"
