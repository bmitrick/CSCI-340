# CSCI-340 Homework 5: Blake Mitrick
---

## 1. ```pmap``` Utility

```
blake@CSCI-340:~$ ps
  PID TTY          TIME CMD
  476 pts/0    00:00:00 ps
26809 pts/0    00:00:00 bash
blake@CSCI-340:~$ pmap 26809
26809:   bash
000055f40a084000   1040K r-x-- bash
000055f40a387000     16K r---- bash
000055f40a38b000     36K rw--- bash
000055f40a394000     40K rw---   [ anon ]
000055f40a448000   1496K rw---   [ anon ]
00007fbe0f5a2000     44K r-x-- libnss_files-2.27.so
00007fbe0f5ad000   2044K ----- libnss_files-2.27.so
00007fbe0f7ac000      4K r---- libnss_files-2.27.so
00007fbe0f7ad000      4K rw--- libnss_files-2.27.so
00007fbe0f7ae000     24K rw---   [ anon ]
00007fbe0f7b4000     92K r-x-- libnsl-2.27.so
00007fbe0f7cb000   2044K ----- libnsl-2.27.so
00007fbe0f9ca000      4K r---- libnsl-2.27.so
00007fbe0f9cb000      4K rw--- libnsl-2.27.so
00007fbe0f9cc000      8K rw---   [ anon ]
00007fbe0f9ce000     44K r-x-- libnss_nis-2.27.so
00007fbe0f9d9000   2044K ----- libnss_nis-2.27.so
00007fbe0fbd8000      4K r---- libnss_nis-2.27.so
00007fbe0fbd9000      4K rw--- libnss_nis-2.27.so
00007fbe0fbda000     32K r-x-- libnss_compat-2.27.so
00007fbe0fbe2000   2048K ----- libnss_compat-2.27.so
00007fbe0fde2000      4K r---- libnss_compat-2.27.so
00007fbe0fde3000      4K rw--- libnss_compat-2.27.so
00007fbe0fde4000   2936K r---- locale-archive
00007fbe100c2000   1948K r-x-- libc-2.27.so
00007fbe102a9000   2048K ----- libc-2.27.so
00007fbe104a9000     16K r---- libc-2.27.so
00007fbe104ad000      8K rw--- libc-2.27.so
00007fbe104af000     16K rw---   [ anon ]
00007fbe104b3000     12K r-x-- libdl-2.27.so
00007fbe104b6000   2044K ----- libdl-2.27.so
00007fbe106b5000      4K r---- libdl-2.27.so
00007fbe106b6000      4K rw--- libdl-2.27.so
00007fbe106b7000    148K r-x-- libtinfo.so.5.9
00007fbe106dc000   2048K ----- libtinfo.so.5.9
00007fbe108dc000     16K r---- libtinfo.so.5.9
00007fbe108e0000      4K rw--- libtinfo.so.5.9
00007fbe108e1000    164K r-x-- ld-2.27.so
00007fbe10af2000     20K rw---   [ anon ]
00007fbe10b03000     28K r--s- gconv-modules.cache
00007fbe10b0a000      4K r---- ld-2.27.so
00007fbe10b0b000      4K rw--- ld-2.27.so
00007fbe10b0c000      4K rw---   [ anon ]
00007ffc2df31000    132K rw---   [ stack ]
00007ffc2dfc3000     12K r----   [ anon ]
00007ffc2dfc6000      4K r-x--   [ anon ]
ffffffffff600000      4K r-x--   [ anon ]
 total            22712K
```
```
blake@CSCI-340:~$ ps
  PID TTY          TIME CMD
  704 pts/1    00:00:00 bash
  715 pts/1    00:00:00 ps
blake@CSCI-340:~$ pmap 704
704:   bash
000055f8a28cb000   1040K r-x-- bash
000055f8a2bce000     16K r---- bash
000055f8a2bd2000     36K rw--- bash
000055f8a2bdb000     40K rw---   [ anon ]
000055f8a40b5000   1496K rw---   [ anon ]
00007f244dfd1000     44K r-x-- libnss_files-2.27.so
00007f244dfdc000   2044K ----- libnss_files-2.27.so
00007f244e1db000      4K r---- libnss_files-2.27.so
00007f244e1dc000      4K rw--- libnss_files-2.27.so
00007f244e1dd000     24K rw---   [ anon ]
00007f244e1e3000     92K r-x-- libnsl-2.27.so
00007f244e1fa000   2044K ----- libnsl-2.27.so
00007f244e3f9000      4K r---- libnsl-2.27.so
00007f244e3fa000      4K rw--- libnsl-2.27.so
00007f244e3fb000      8K rw---   [ anon ]
00007f244e3fd000     44K r-x-- libnss_nis-2.27.so
00007f244e408000   2044K ----- libnss_nis-2.27.so
00007f244e607000      4K r---- libnss_nis-2.27.so
00007f244e608000      4K rw--- libnss_nis-2.27.so
00007f244e609000     32K r-x-- libnss_compat-2.27.so
00007f244e611000   2048K ----- libnss_compat-2.27.so
00007f244e811000      4K r---- libnss_compat-2.27.so
00007f244e812000      4K rw--- libnss_compat-2.27.so
00007f244e813000   2936K r---- locale-archive
00007f244eaf1000   1948K r-x-- libc-2.27.so
00007f244ecd8000   2048K ----- libc-2.27.so
00007f244eed8000     16K r---- libc-2.27.so
00007f244eedc000      8K rw--- libc-2.27.so
00007f244eede000     16K rw---   [ anon ]
00007f244eee2000     12K r-x-- libdl-2.27.so
00007f244eee5000   2044K ----- libdl-2.27.so
00007f244f0e4000      4K r---- libdl-2.27.so
00007f244f0e5000      4K rw--- libdl-2.27.so
00007f244f0e6000    148K r-x-- libtinfo.so.5.9
00007f244f10b000   2048K ----- libtinfo.so.5.9
00007f244f30b000     16K r---- libtinfo.so.5.9
00007f244f30f000      4K rw--- libtinfo.so.5.9
00007f244f310000    164K r-x-- ld-2.27.so
00007f244f521000     20K rw---   [ anon ]
00007f244f532000     28K r--s- gconv-modules.cache
00007f244f539000      4K r---- ld-2.27.so
00007f244f53a000      4K rw--- ld-2.27.so
00007f244f53b000      4K rw---   [ anon ]
00007ffd677bf000    132K rw---   [ stack ]
00007ffd677f3000     12K r----   [ anon ]
00007ffd677f6000      4K r-x--   [ anon ]
ffffffffff600000      4K r-x--   [ anon ]
 total            22712K
```

### a) Libraries
* bash - The command line interpreter for the operating system.
* libnss_files - A library used to look up user ids and usernames.
* libnsl - A library responsible for network services.
* libnss_nis - A NSS NIS plugin for glibc, is IPv6 capable.
* libnss_compat - A library providing support for additional entries in the ```/etc/passwd file```
* locale-archive - A local archive that contains all system-provided locales.
* libc - Provides all definitions needed to work with C code
* libdl - A library that provides support for dynamic linking.
* libtinfo - A library containing the info/data of a thread.
* ld - A library used to check for available dynamic and shared libraries.
* gconv-modules- A part of the GNU C library.


### b) They look to be the same with the exception of all the addresses. Most of the addresses listed are different, however, the address for the last entry, labeled ```[ anon ]```, is ```ffffffffff600000``` for both pmaps


## 2) Threads

### a) Processes have a single point of execution while threads have many.
### b) You could use multiple threads for a variety of reasons. The first reason given by the book is the ability of threads to be run in parallel and work on multiple CPUs rather than just one. The other reason given is to avoid blocking a program due to slow I/O.
### c)
#### a) networkd-dispat
#### b) 487
##### i) has 2 threads, 487 and 650

```
blake@CSCI-340:~/Documents/CSCI-340/PRJ1$ top -H -p 487

top - 20:06:52 up 16:37,  1 user,  load average: 0.33, 0.17, 0.11
Threads:   2 total,   0 running,   2 sleeping,   0 stopped,   0 zombie
%Cpu(s):  5.1 us,  0.9 sy,  0.0 ni, 93.9 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem :  4037172 total,   203268 free,  2166372 used,  1667532 buff/cache
KiB Swap:   483800 total,   483020 free,      780 used.  1575672 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S %CPU %MEM     TIME+ COMMAND                                                                                                                                  
  487 root      20   0  177688  13652   5720 S  0.0  0.3   0:00.13 networkd-dispat                                                                                                                          
  650 root      20   0  177688  13652   5720 S  0.0  0.3   0:00.00 gmain   
  ```

## 3) Memory and Concurrency

### a) The loop needs to get somewhere between 15000 and 20000.

### b) The computer is pretty good at keeping counter consistent to what it should actually be so we need to throw a lot of chances for error at it in order for it to fail. The textbook talks about how sometimes the program will run twice and only save the output like it was run once, leading to an incorrect saved global counter. We need to increase the number of loops in order to increase the odds of this happening.

### c) Increasing the number of cores would cause the issue to arise sooner since more threads can be run at once over all 4 cores leading to the odds of an inaccurate counter to be much higher at an even lower number of loops since there are 4 cores running simultaneously rather than the 1 that the VM utilizes.
