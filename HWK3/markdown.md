# CSCI-340 Homework 3: Blake Mitrick
---

# 2. Simple Scheduling
## a. FIFO
| Job Name | Execution Time | T arrival | T end | T t   | T firstrun | T r   |
|----------|----------------|-----------|-------|-------|------------|-------|
| Job 1    | 10             | 0         | 10    | 10    | 0          | 0     |
| Job 2    | 15             | 0         | 25    | 25    | 10         | 10    |
| Job 3    | 5              | 0         | 30    | 30    | 25         | 25    |
| Job 4    | 22             | 0         | 52    | 52    | 30         | 30    |
| AVG      |                |           |       | 29.25 |            | 16.25 |

## b. SJF
| Job Name | Execution Time | T arrival | T end | T t   | T firstrun | T r  |
|----------|----------------|-----------|-------|-------|------------|------|
| Job 1    | 25             | 0         | 55    | 55    | 30         | 30   |
| Job 2    | 15             | 0         | 30    | 30    | 15         | 15   |
| Job 3    | 5              | 0         | 5     | 5     | 0          | 0    |
| Job 4    | 10             | 0         | 15    | 15    | 5          | 5    |
| AVG      |                |           |       | 26.25 |            | 12.5 |

## c. STCF
| Job Name | Execution Time | T arrival | T end | T t | T firstrun | T r |
|----------|----------------|-----------|-------|-----|------------|-----|
| Job 1    | 25             | 0         | 55    | 55  | 20         | 20  |
| Job 2    | 15             | 0         | 30    | 30  | 0          | 0   |
| Job 3    | 5              | 5         | 10    | 5   | 5          | 0   |
| Job 4    | 10             | 10        | 20    | 10  | 10         | 0   |
| AVG      |                |           |       | 25  |            | 5   |

## d. RR
| Job Name | Execution Time | T arrival | T end | T t   | T firstrun | T r  |
|----------|----------------|-----------|-------|-------|------------|------|
| Job 1    | 20             | 0         | 50    | 50    | 0          | 0    |
| Job 2    | 10             | 0         | 30    | 30    | 5          | 5    |
| Job 3    | 5              | 5         | 15    | 10    | 10         | 5    |
| Job 4    | 15             | 10        | 45    | 35    | 15         | 5    |
| AVG      |                |           |       | 31.25 |            | 3.75 |
