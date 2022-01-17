# CSCI-340 Homework 1: Blake Mitrick
---

## 1. Virtual Machine

>### a. From a terminal window in this VM provide the output of the following commands:
>>#### i) ```uname -a```
```
Linux CSCI-340 5.0.0-23-generic #24~18.04.1-Ubuntu SMP Mon Jul 29 16:12:28 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
```
>>#### ii) ```ps -al```
```
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
4 R     0   681   677  1  80   0 - 117648 -     tty1     00:00:28 Xorg
0 S  1000   801   677  0  80   0 - 160775 poll_s tty1    00:00:00 gnome-session-b
0 R  1000   996   801  7  80   0 - 764636 -     tty1     00:02:28 gnome-shell
0 S  1000  1061   996  0  80   0 - 94444 poll_s tty1     00:00:06 ibus-daemon
0 S  1000  1071  1061  0  80   0 - 74194 poll_s tty1     00:00:00 ibus-dconf
0 S  1000  1073     1  0  80   0 - 89068 poll_s tty1     00:00:00 ibus-x11
0 S  1000  1149   801  0  80   0 - 131848 poll_s tty1    00:00:00 gsd-power
0 S  1000  1151   801  0  80   0 - 87330 poll_s tty1     00:00:00 gsd-print-notif
0 S  1000  1154   801  0  80   0 - 105835 poll_s tty1    00:00:00 gsd-rfkill
0 S  1000  1156   801  0  80   0 - 68933 poll_s tty1     00:00:00 gsd-screensaver
0 S  1000  1157   801  0  80   0 - 117795 poll_s tty1    00:00:00 gsd-sharing
0 S  1000  1159   801  0  80   0 - 98177 poll_s tty1     00:00:00 gsd-smartcard
0 S  1000  1163   801  0  80   0 - 85771 poll_s tty1     00:00:00 gsd-sound
0 S  1000  1165   801  0  80   0 - 126172 poll_s tty1    00:00:00 gsd-xsettings
0 S  1000  1174   801  0  80   0 - 110183 poll_s tty1    00:00:00 gsd-wacom
0 S  1000  1177   801  0  80   0 - 74158 poll_s tty1     00:00:00 gsd-a11y-settin
0 S  1000  1180   801  0  80   0 - 167233 poll_s tty1    00:00:00 gsd-color
0 S  1000  1185   801  0  80   0 - 88969 poll_s tty1     00:00:00 gsd-clipboard
0 S  1000  1187   801  0  80   0 - 93669 poll_s tty1     00:00:00 gsd-housekeepin
0 S  1000  1189   801  0  80   0 - 119143 poll_s tty1    00:00:00 gsd-datetime
0 S  1000  1190   801  0  80   0 - 200790 poll_s tty1    00:00:00 gsd-media-keys
0 S  1000  1192   801  0  80   0 - 129171 poll_s tty1    00:00:00 gsd-keyboard
0 S  1000  1200   801  0  80   0 - 74160 poll_s tty1     00:00:00 gsd-mouse
0 S  1000  1209     1  0  80   0 - 127190 poll_s tty1    00:00:00 gsd-printer
0 S  1000  1251   801  0  80   0 - 67983 poll_s tty1     00:00:00 gsd-disk-utilit
0 S  1000  1255   801  0  80   0 - 203270 poll_s tty1    00:00:02 nautilus-deskto
0 S  1000  1509  1061  0  80   0 - 55232 poll_s tty1     00:00:01 ibus-engine-sim
0 S  1000  1913   801  0  80   0 - 169477 poll_s tty1    00:00:00 update-notifier
0 S  1000  3927   801  0  80   0 - 197413 poll_s tty1    00:00:00 deja-dup-monito
1 S  1000  7626   620  0  80   0 -  4997 wait   pts/1    00:00:00 atom
4 S  1000  7628  7626  2  80   0 - 1265492 poll_s pts/1  00:00:12 atom
0 S  1000  7631  7628  0  80   0 - 100356 poll_s pts/1   00:00:00 atom
4 S  1000  7632  7628  0  80   0 - 100356 wait  pts/1    00:00:00 atom
1 S  1000  7634  7632  0  80   0 - 100356 poll_s pts/1   00:00:00 atom
1 S  1000  7666  7631  1  80   0 - 120828 poll_s pts/1   00:00:05 atom
0 S  1000  7669  7628  0  80   0 - 119457 futex_ pts/1   00:00:00 atom
1 S  1000  7675  7666  0  80   0 - 104682 skb_wa pts/1   00:00:00 atom
0 S  1000  7689  7628  8  80   0 - 1230795 futex_ pts/1  00:00:33 atom
0 S  1000  7753  7628  0  80   0 - 1184056 futex_ pts/1  00:00:00 atom
4 R  1000  7925  5419  0  80   0 -  9003 -      pts/1    00:00:00 ps
```
>>#### iii) ```cat /proc/meminfo```
```
MemTotal:        4037360 kB
MemFree:          284972 kB
MemAvailable:    2273992 kB
Buffers:           84788 kB
Cached:          2099516 kB
SwapCached:            0 kB
Active:          2256996 kB
Inactive:        1270364 kB
Active(anon):    1257496 kB
Inactive(anon):   126416 kB
Active(file):     999500 kB
Inactive(file):  1143948 kB
Unevictable:          48 kB
Mlocked:              48 kB
SwapTotal:        483800 kB
SwapFree:         483800 kB
Dirty:                36 kB
Writeback:             0 kB
AnonPages:       1343128 kB
Mapped:           394524 kB
Shmem:             76072 kB
KReclaimable:      97392 kB
Slab:             128748 kB
SReclaimable:      97392 kB
SUnreclaim:        31356 kB
KernelStack:        7440 kB
PageTables:        38364 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     2502480 kB
Committed_AS:    4708632 kB
VmallocTotal:   34359738367 kB
VmallocUsed:           0 kB
VmallocChunk:          0 kB
Percpu:              280 kB
HardwareCorrupted:     0 kB
AnonHugePages:         0 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
CmaTotal:              0 kB
CmaFree:               0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
Hugetlb:               0 kB
DirectMap4k:      137152 kB
DirectMap2M:     4057088 kB
```
>>#### iv) ```cat /proc/cpuinfo```
```
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i7-8750H CPU @ 2.20GHz
stepping	: 10
cpu MHz		: 2208.000
cache size	: 9216 KB
physical id	: 0
siblings	: 1
core id		: 0
cpu cores	: 1
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq monitor ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds
bogomips	: 4416.00
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:
```
>### b. Search on the web for the ```uname``` and ```ps``` command (hint, try ```man uname```). Give a brief, one or two sentence, explanation of each command in your own words.
>>#### ```uname```
>> When you input ```uname --help``` in the terminal it gives you a decent definition of what ```uname``` does. It essentially states that the ```uname``` command is followed by some argument and it will print different system info depending on what the argument is. The research I did on the web tends to echo the same thing with a bit more information such as sample outputs for the different arguments which are defined when using ```uname --help```.
>>#### ```ps```
>> When you input ```ps --help```, you don't get too much. Attempting ```man ps``` is a lot more helpful as it essentially states that ```ps``` is used to get the information about a currently running process. Like ```uname```, it is followed by arguments which will determine what kind of info is returned.


## 2. Clone git Repository
>### a. Clone the repository (git clone command).
>> ```
blake@CSCI-340:~/Documents$ git clone "https://github.com/remzi-arpacidusseau/ostep-code"
Cloning into 'ostep-code'...
remote: Enumerating objects: 312, done.
remote: Counting objects: 100% (26/26), done.
remote: Compressing objects: 100% (16/16), done.
remote: Total 312 (delta 9), reused 22 (delta 5), pack-reused 286
Receiving objects: 100% (312/312), 54.46 KiB | 1.76 MiB/s, done.
Resolving deltas: 100% (142/142), done. ```
>### b. Change into the directory for the ostep code, run the following command and provide the output
>### ```git status```
>> ```
blake@CSCI-340:~/Documents$ cd ostep-code/
blake@CSCI-340:~/Documents/ostep-code$ git status
On branch master
Your branch is up to date with 'origin/master'.
nothing to commit, working tree clean

## 3. "C" Editing and Compiling
>### As we discussed in class you can compile and link a C program using the Gnu C compiler (gcc). Write a C program that will just print the addresses of the parameters passed from the command line. The cpu.c program we looked at in class will provide an example of accessing the parameters. You can use a while loop or a for loop. Print the addresses using the %p format code.
>### Submit:
> - a. The source file.
> - b. Either a makefile or a markdown file with instructions for building the program.
>
>### Commands used along the way, mainly for personal reference in the future.
>>#### Installing Gnu C compiler
>> ```
blake@CSCI-340:~$ sudo apt install build-essential
...
...
...
Setting up build-essential (12.4ubuntu1) ...
Processing triggers for libc-bin (2.27-3ubuntu1) ...
blake@CSCI-340:~$ gcc --version
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
