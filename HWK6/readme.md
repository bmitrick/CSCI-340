# CSCI-340 Homework 6: Blake Mitrick
---
## 1. Use the command ```gcc -pthread -o hwk6 hwk6.c``` to compile and ```./hwk6 num_threads len_string``` to run
## 2. Locking

### b.
```
blake@CSCI-340:~/Documents/CSCI-340/HWK6/locks$ python x86.py -c -a bx=10 -M count -i 5 -t 3 -S -p flag.s
ARG seed 0
ARG numthreads 3
ARG program flag.s
ARG interrupt frequency 5
ARG interrupt randomness False
ARG procsched
ARG argv bx=10
ARG load address 1000
ARG memsize 128
ARG memtrace count
ARG regtrace
ARG cctrace False
ARG printstats True
ARG verbose False


icount count          Thread 0                Thread 1                Thread 2         

     0     0   
     0     0   1000 mov  flag, %ax
     1     0   1001 test $0, %ax
     2     0   1002 jne  .acquire
     3     0   1003 mov  $1, flag
     4     0   1004 mov  count, %ax
     5     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
     5     0                            1000 mov  flag, %ax
     6     0                            1001 test $0, %ax
     7     0                            1002 jne  .acquire
     8     0                            1000 mov  flag, %ax
     9     0                            1001 test $0, %ax
    10     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    10     0                                                     1000 mov  flag, %ax
    11     0                                                     1001 test $0, %ax
    12     0                                                     1002 jne  .acquire
    13     0                                                     1000 mov  flag, %ax
    14     0                                                     1001 test $0, %ax
    15     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    15     0   1005 add  $1, %ax
    16     1   1006 mov  %ax, count
    17     1   1007 mov  $0, flag
    18     1   1008 sub  $1, %bx
    19     1   1009 test $0, %bx
    20     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    20     1                            1002 jne  .acquire
    21     1                            1000 mov  flag, %ax
    22     1                            1001 test $0, %ax
    23     1                            1002 jne  .acquire
    24     1                            1003 mov  $1, flag
    25     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    25     1                                                     1002 jne  .acquire
    26     1                                                     1000 mov  flag, %ax
    27     1                                                     1001 test $0, %ax
    28     1                                                     1002 jne  .acquire
    29     1                                                     1000 mov  flag, %ax
    30     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    30     1   1010 jgt .top
    31     1   1000 mov  flag, %ax
    32     1   1001 test $0, %ax
    33     1   1002 jne  .acquire
    34     1   1000 mov  flag, %ax
    35     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    35     1                            1004 mov  count, %ax
    36     1                            1005 add  $1, %ax
    37     2                            1006 mov  %ax, count
    38     2                            1007 mov  $0, flag
    39     2                            1008 sub  $1, %bx
    40     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    40     2                                                     1001 test $0, %ax
    41     2                                                     1002 jne  .acquire
    42     2                                                     1000 mov  flag, %ax
    43     2                                                     1001 test $0, %ax
    44     2                                                     1002 jne  .acquire
    45     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    45     2   1001 test $0, %ax
    46     2   1002 jne  .acquire
    47     2   1000 mov  flag, %ax
    48     2   1001 test $0, %ax
    49     2   1002 jne  .acquire
    50     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    50     2                            1009 test $0, %bx
    51     2                            1010 jgt .top
    52     2                            1000 mov  flag, %ax
    53     2                            1001 test $0, %ax
    54     2                            1002 jne  .acquire
    55     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    55     2                                                     1003 mov  $1, flag
    56     2                                                     1004 mov  count, %ax
    57     2                                                     1005 add  $1, %ax
    58     3                                                     1006 mov  %ax, count
    59     3                                                     1007 mov  $0, flag
    60     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    60     3   1003 mov  $1, flag
    61     3   1004 mov  count, %ax
    62     3   1005 add  $1, %ax
    63     4   1006 mov  %ax, count
    64     4   1007 mov  $0, flag
    65     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    65     4                            1003 mov  $1, flag
    66     4                            1004 mov  count, %ax
    67     4                            1005 add  $1, %ax
    68     5                            1006 mov  %ax, count
    69     5                            1007 mov  $0, flag
    70     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    70     5                                                     1008 sub  $1, %bx
    71     5                                                     1009 test $0, %bx
    72     5                                                     1010 jgt .top
    73     5                                                     1000 mov  flag, %ax
    74     5                                                     1001 test $0, %ax
    75     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    75     5   1008 sub  $1, %bx
    76     5   1009 test $0, %bx
    77     5   1010 jgt .top
    78     5   1000 mov  flag, %ax
    79     5   1001 test $0, %ax
    80     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    80     5                            1008 sub  $1, %bx
    81     5                            1009 test $0, %bx
    82     5                            1010 jgt .top
    83     5                            1000 mov  flag, %ax
    84     5                            1001 test $0, %ax
    85     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    85     5                                                     1002 jne  .acquire
    86     5                                                     1003 mov  $1, flag
    87     5                                                     1004 mov  count, %ax
    88     5                                                     1005 add  $1, %ax
    89     6                                                     1006 mov  %ax, count
    90     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    90     6   1002 jne  .acquire
    91     6   1003 mov  $1, flag
    92     6   1004 mov  count, %ax
    93     6   1005 add  $1, %ax
    94     7   1006 mov  %ax, count
    95     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    95     7                            1002 jne  .acquire
    96     7                            1003 mov  $1, flag
    97     7                            1004 mov  count, %ax
    98     7                            1005 add  $1, %ax
    99     8                            1006 mov  %ax, count
   100     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   100     8                                                     1007 mov  $0, flag
   101     8                                                     1008 sub  $1, %bx
   102     8                                                     1009 test $0, %bx
   103     8                                                     1010 jgt .top
   104     8                                                     1000 mov  flag, %ax
   105     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   105     8   1007 mov  $0, flag
   106     8   1008 sub  $1, %bx
   107     8   1009 test $0, %bx
   108     8   1010 jgt .top
   109     8   1000 mov  flag, %ax
   110     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   110     8                            1007 mov  $0, flag
   111     8                            1008 sub  $1, %bx
   112     8                            1009 test $0, %bx
   113     8                            1010 jgt .top
   114     8                            1000 mov  flag, %ax
   115     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   115     8                                                     1001 test $0, %ax
   116     8                                                     1002 jne  .acquire
   117     8                                                     1003 mov  $1, flag
   118     8                                                     1004 mov  count, %ax
   119     8                                                     1005 add  $1, %ax
   120     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   120     8   1001 test $0, %ax
   121     8   1002 jne  .acquire
   122     8   1003 mov  $1, flag
   123     8   1004 mov  count, %ax
   124     8   1005 add  $1, %ax
   125     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   125     8                            1001 test $0, %ax
   126     8                            1002 jne  .acquire
   127     8                            1003 mov  $1, flag
   128     8                            1004 mov  count, %ax
   129     8                            1005 add  $1, %ax
   130     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   130     9                                                     1006 mov  %ax, count
   131     9                                                     1007 mov  $0, flag
   132     9                                                     1008 sub  $1, %bx
   133     9                                                     1009 test $0, %bx
   134     9                                                     1010 jgt .top
   135     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   135     9   1006 mov  %ax, count
   136     9   1007 mov  $0, flag
   137     9   1008 sub  $1, %bx
   138     9   1009 test $0, %bx
   139     9   1010 jgt .top
   140     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   140     9                            1006 mov  %ax, count
   141     9                            1007 mov  $0, flag
   142     9                            1008 sub  $1, %bx
   143     9                            1009 test $0, %bx
   144     9                            1010 jgt .top
   145     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   145     9                                                     1000 mov  flag, %ax
   146     9                                                     1001 test $0, %ax
   147     9                                                     1002 jne  .acquire
   148     9                                                     1003 mov  $1, flag
   149     9                                                     1004 mov  count, %ax
   150     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   150     9   1000 mov  flag, %ax
   151     9   1001 test $0, %ax
   152     9   1002 jne  .acquire
   153     9   1000 mov  flag, %ax
   154     9   1001 test $0, %ax
   155     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   155     9                            1000 mov  flag, %ax
   156     9                            1001 test $0, %ax
   157     9                            1002 jne  .acquire
   158     9                            1000 mov  flag, %ax
   159     9                            1001 test $0, %ax
   160     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   160     9                                                     1005 add  $1, %ax
   161    10                                                     1006 mov  %ax, count
   162    10                                                     1007 mov  $0, flag
   163    10                                                     1008 sub  $1, %bx
   164    10                                                     1009 test $0, %bx
   165    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   165    10   1002 jne  .acquire
   166    10   1000 mov  flag, %ax
   167    10   1001 test $0, %ax
   168    10   1002 jne  .acquire
   169    10   1003 mov  $1, flag
   170    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   170    10                            1002 jne  .acquire
   171    10                            1000 mov  flag, %ax
   172    10                            1001 test $0, %ax
   173    10                            1002 jne  .acquire
   174    10                            1000 mov  flag, %ax
   175    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   175    10                                                     1010 jgt .top
   176    10                                                     1000 mov  flag, %ax
   177    10                                                     1001 test $0, %ax
   178    10                                                     1002 jne  .acquire
   179    10                                                     1000 mov  flag, %ax
   180    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   180    10   1004 mov  count, %ax
   181    10   1005 add  $1, %ax
   182    11   1006 mov  %ax, count
   183    11   1007 mov  $0, flag
   184    11   1008 sub  $1, %bx
   185    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   185    11                            1001 test $0, %ax
   186    11                            1002 jne  .acquire
   187    11                            1000 mov  flag, %ax
   188    11                            1001 test $0, %ax
   189    11                            1002 jne  .acquire
   190    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   190    11                                                     1001 test $0, %ax
   191    11                                                     1002 jne  .acquire
   192    11                                                     1000 mov  flag, %ax
   193    11                                                     1001 test $0, %ax
   194    11                                                     1002 jne  .acquire
   195    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   195    11   1009 test $0, %bx
   196    11   1010 jgt .top
   197    11   1000 mov  flag, %ax
   198    11   1001 test $0, %ax
   199    11   1002 jne  .acquire
   200    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   200    11                            1003 mov  $1, flag
   201    11                            1004 mov  count, %ax
   202    11                            1005 add  $1, %ax
   203    12                            1006 mov  %ax, count
   204    12                            1007 mov  $0, flag
   205    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   205    12                                                     1003 mov  $1, flag
   206    12                                                     1004 mov  count, %ax
   207    12                                                     1005 add  $1, %ax
   208    13                                                     1006 mov  %ax, count
   209    13                                                     1007 mov  $0, flag
   210    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   210    13   1003 mov  $1, flag
   211    13   1004 mov  count, %ax
   212    13   1005 add  $1, %ax
   213    14   1006 mov  %ax, count
   214    14   1007 mov  $0, flag
   215    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   215    14                            1008 sub  $1, %bx
   216    14                            1009 test $0, %bx
   217    14                            1010 jgt .top
   218    14                            1000 mov  flag, %ax
   219    14                            1001 test $0, %ax
   220    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   220    14                                                     1008 sub  $1, %bx
   221    14                                                     1009 test $0, %bx
   222    14                                                     1010 jgt .top
   223    14                                                     1000 mov  flag, %ax
   224    14                                                     1001 test $0, %ax
   225    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   225    14   1008 sub  $1, %bx
   226    14   1009 test $0, %bx
   227    14   1010 jgt .top
   228    14   1000 mov  flag, %ax
   229    14   1001 test $0, %ax
   230    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   230    14                            1002 jne  .acquire
   231    14                            1003 mov  $1, flag
   232    14                            1004 mov  count, %ax
   233    14                            1005 add  $1, %ax
   234    15                            1006 mov  %ax, count
   235    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   235    15                                                     1002 jne  .acquire
   236    15                                                     1003 mov  $1, flag
   237    15                                                     1004 mov  count, %ax
   238    15                                                     1005 add  $1, %ax
   239    16                                                     1006 mov  %ax, count
   240    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   240    16   1002 jne  .acquire
   241    16   1003 mov  $1, flag
   242    16   1004 mov  count, %ax
   243    16   1005 add  $1, %ax
   244    17   1006 mov  %ax, count
   245    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   245    17                            1007 mov  $0, flag
   246    17                            1008 sub  $1, %bx
   247    17                            1009 test $0, %bx
   248    17                            1010 jgt .top
   249    17                            1000 mov  flag, %ax
   250    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   250    17                                                     1007 mov  $0, flag
   251    17                                                     1008 sub  $1, %bx
   252    17                                                     1009 test $0, %bx
   253    17                                                     1010 jgt .top
   254    17                                                     1000 mov  flag, %ax
   255    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   255    17   1007 mov  $0, flag
   256    17   1008 sub  $1, %bx
   257    17   1009 test $0, %bx
   258    17   1010 jgt .top
   259    17   1000 mov  flag, %ax
   260    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   260    17                            1001 test $0, %ax
   261    17                            1002 jne  .acquire
   262    17                            1003 mov  $1, flag
   263    17                            1004 mov  count, %ax
   264    17                            1005 add  $1, %ax
   265    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   265    17                                                     1001 test $0, %ax
   266    17                                                     1002 jne  .acquire
   267    17                                                     1003 mov  $1, flag
   268    17                                                     1004 mov  count, %ax
   269    17                                                     1005 add  $1, %ax
   270    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   270    17   1001 test $0, %ax
   271    17   1002 jne  .acquire
   272    17   1003 mov  $1, flag
   273    17   1004 mov  count, %ax
   274    17   1005 add  $1, %ax
   275    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   275    18                            1006 mov  %ax, count
   276    18                            1007 mov  $0, flag
   277    18                            1008 sub  $1, %bx
   278    18                            1009 test $0, %bx
   279    18                            1010 jgt .top
   280    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   280    18                                                     1006 mov  %ax, count
   281    18                                                     1007 mov  $0, flag
   282    18                                                     1008 sub  $1, %bx
   283    18                                                     1009 test $0, %bx
   284    18                                                     1010 jgt .top
   285    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   285    18   1006 mov  %ax, count
   286    18   1007 mov  $0, flag
   287    18   1008 sub  $1, %bx
   288    18   1009 test $0, %bx
   289    18   1010 jgt .top
   290    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   290    18                            1000 mov  flag, %ax
   291    18                            1001 test $0, %ax
   292    18                            1002 jne  .acquire
   293    18                            1003 mov  $1, flag
   294    18                            1004 mov  count, %ax
   295    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   295    18                                                     1000 mov  flag, %ax
   296    18                                                     1001 test $0, %ax
   297    18                                                     1002 jne  .acquire
   298    18                                                     1000 mov  flag, %ax
   299    18                                                     1001 test $0, %ax
   300    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   300    18   1000 mov  flag, %ax
   301    18   1001 test $0, %ax
   302    18   1002 jne  .acquire
   303    18   1000 mov  flag, %ax
   304    18   1001 test $0, %ax
   305    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   305    18                            1005 add  $1, %ax
   306    19                            1006 mov  %ax, count
   307    19                            1007 mov  $0, flag
   308    19                            1008 sub  $1, %bx
   309    19                            1009 test $0, %bx
   310    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   310    19                                                     1002 jne  .acquire
   311    19                                                     1000 mov  flag, %ax
   312    19                                                     1001 test $0, %ax
   313    19                                                     1002 jne  .acquire
   314    19                                                     1003 mov  $1, flag
   315    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   315    19   1002 jne  .acquire
   316    19   1000 mov  flag, %ax
   317    19   1001 test $0, %ax
   318    19   1002 jne  .acquire
   319    19   1000 mov  flag, %ax
   320    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   320    19                            1010 jgt .top
   321    19                            1000 mov  flag, %ax
   322    19                            1001 test $0, %ax
   323    19                            1002 jne  .acquire
   324    19                            1000 mov  flag, %ax
   325    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   325    19                                                     1004 mov  count, %ax
   326    19                                                     1005 add  $1, %ax
   327    20                                                     1006 mov  %ax, count
   328    20                                                     1007 mov  $0, flag
   329    20                                                     1008 sub  $1, %bx
   330    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   330    20   1001 test $0, %ax
   331    20   1002 jne  .acquire
   332    20   1000 mov  flag, %ax
   333    20   1001 test $0, %ax
   334    20   1002 jne  .acquire
   335    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   335    20                            1001 test $0, %ax
   336    20                            1002 jne  .acquire
   337    20                            1000 mov  flag, %ax
   338    20                            1001 test $0, %ax
   339    20                            1002 jne  .acquire
   340    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   340    20                                                     1009 test $0, %bx
   341    20                                                     1010 jgt .top
   342    20                                                     1000 mov  flag, %ax
   343    20                                                     1001 test $0, %ax
   344    20                                                     1002 jne  .acquire
   345    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   345    20   1003 mov  $1, flag
   346    20   1004 mov  count, %ax
   347    20   1005 add  $1, %ax
   348    21   1006 mov  %ax, count
   349    21   1007 mov  $0, flag
   350    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   350    21                            1003 mov  $1, flag
   351    21                            1004 mov  count, %ax
   352    21                            1005 add  $1, %ax
   353    22                            1006 mov  %ax, count
   354    22                            1007 mov  $0, flag
   355    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   355    22                                                     1003 mov  $1, flag
   356    22                                                     1004 mov  count, %ax
   357    22                                                     1005 add  $1, %ax
   358    23                                                     1006 mov  %ax, count
   359    23                                                     1007 mov  $0, flag
   360    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   360    23   1008 sub  $1, %bx
   361    23   1009 test $0, %bx
   362    23   1010 jgt .top
   363    23   1000 mov  flag, %ax
   364    23   1001 test $0, %ax
   365    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   365    23                            1008 sub  $1, %bx
   366    23                            1009 test $0, %bx
   367    23                            1010 jgt .top
   368    23                            1000 mov  flag, %ax
   369    23                            1001 test $0, %ax
   370    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   370    23                                                     1008 sub  $1, %bx
   371    23                                                     1009 test $0, %bx
   372    23                                                     1010 jgt .top
   373    23                                                     1000 mov  flag, %ax
   374    23                                                     1001 test $0, %ax
   375    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   375    23   1002 jne  .acquire
   376    23   1003 mov  $1, flag
   377    23   1004 mov  count, %ax
   378    23   1005 add  $1, %ax
   379    24   1006 mov  %ax, count
   380    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   380    24                            1002 jne  .acquire
   381    24                            1003 mov  $1, flag
   382    24                            1004 mov  count, %ax
   383    24                            1005 add  $1, %ax
   384    25                            1006 mov  %ax, count
   385    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   385    25                                                     1002 jne  .acquire
   386    25                                                     1003 mov  $1, flag
   387    25                                                     1004 mov  count, %ax
   388    25                                                     1005 add  $1, %ax
   389    26                                                     1006 mov  %ax, count
   390    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   390    26   1007 mov  $0, flag
   391    26   1008 sub  $1, %bx
   392    26   1009 test $0, %bx
   393    26   1010 jgt .top
   394    26   1011 halt
   395    26   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   395    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   395    26                                                     1007 mov  $0, flag
   396    26                                                     1008 sub  $1, %bx
   397    26                                                     1009 test $0, %bx
   398    26                                                     1010 jgt .top
   399    26                                                     1011 halt
   400    26   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   400    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   400    26                            1007 mov  $0, flag
   401    26                            1008 sub  $1, %bx
   402    26                            1009 test $0, %bx
   403    26                            1010 jgt .top
   404    26                            1011 halt

STATS:: Instructions    405
STATS:: Emulation Rate  15.08 kinst/sec
blake@CSCI-340:~/Documents/CSCI-340/HWK6/locks$ python x86.py -c -a bx=10 -M count -i 5 -t 3 -S -p test-and-set.s
ARG seed 0
ARG numthreads 3
ARG program test-and-set.s
ARG interrupt frequency 5
ARG interrupt randomness False
ARG procsched
ARG argv bx=10
ARG load address 1000
ARG memsize 128
ARG memtrace count
ARG regtrace
ARG cctrace False
ARG printstats True
ARG verbose False


icount count          Thread 0                Thread 1                Thread 2         

     0     0   
     0     0   1000 mov  $1, %ax
     1     0   1001 xchg %ax, mutex
     2     0   1002 test $0, %ax
     3     0   1003 jne  .acquire
     4     0   1004 mov  count, %ax
     5     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
     5     0                            1000 mov  $1, %ax
     6     0                            1001 xchg %ax, mutex
     7     0                            1002 test $0, %ax
     8     0                            1003 jne  .acquire
     9     0                            1000 mov  $1, %ax
    10     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    10     0                                                     1000 mov  $1, %ax
    11     0                                                     1001 xchg %ax, mutex
    12     0                                                     1002 test $0, %ax
    13     0                                                     1003 jne  .acquire
    14     0                                                     1000 mov  $1, %ax
    15     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    15     0   1005 add  $1, %ax
    16     1   1006 mov  %ax, count
    17     1   1007 mov  $0, mutex
    18     1   1008 sub  $1, %bx
    19     1   1009 test $0, %bx
    20     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    20     1                            1001 xchg %ax, mutex
    21     1                            1002 test $0, %ax
    22     1                            1003 jne  .acquire
    23     1                            1004 mov  count, %ax
    24     1                            1005 add  $1, %ax
    25     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    25     1                                                     1001 xchg %ax, mutex
    26     1                                                     1002 test $0, %ax
    27     1                                                     1003 jne  .acquire
    28     1                                                     1000 mov  $1, %ax
    29     1                                                     1001 xchg %ax, mutex
    30     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    30     1   1010 jgt .top
    31     1   1000 mov  $1, %ax
    32     1   1001 xchg %ax, mutex
    33     1   1002 test $0, %ax
    34     1   1003 jne  .acquire
    35     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    35     2                            1006 mov  %ax, count
    36     2                            1007 mov  $0, mutex
    37     2                            1008 sub  $1, %bx
    38     2                            1009 test $0, %bx
    39     2                            1010 jgt .top
    40     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    40     2                                                     1002 test $0, %ax
    41     2                                                     1003 jne  .acquire
    42     2                                                     1000 mov  $1, %ax
    43     2                                                     1001 xchg %ax, mutex
    44     2                                                     1002 test $0, %ax
    45     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    45     2   1000 mov  $1, %ax
    46     2   1001 xchg %ax, mutex
    47     2   1002 test $0, %ax
    48     2   1003 jne  .acquire
    49     2   1000 mov  $1, %ax
    50     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    50     2                            1000 mov  $1, %ax
    51     2                            1001 xchg %ax, mutex
    52     2                            1002 test $0, %ax
    53     2                            1003 jne  .acquire
    54     2                            1000 mov  $1, %ax
    55     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    55     2                                                     1003 jne  .acquire
    56     2                                                     1004 mov  count, %ax
    57     2                                                     1005 add  $1, %ax
    58     3                                                     1006 mov  %ax, count
    59     3                                                     1007 mov  $0, mutex
    60     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    60     3   1001 xchg %ax, mutex
    61     3   1002 test $0, %ax
    62     3   1003 jne  .acquire
    63     3   1004 mov  count, %ax
    64     3   1005 add  $1, %ax
    65     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    65     3                            1001 xchg %ax, mutex
    66     3                            1002 test $0, %ax
    67     3                            1003 jne  .acquire
    68     3                            1000 mov  $1, %ax
    69     3                            1001 xchg %ax, mutex
    70     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    70     3                                                     1008 sub  $1, %bx
    71     3                                                     1009 test $0, %bx
    72     3                                                     1010 jgt .top
    73     3                                                     1000 mov  $1, %ax
    74     3                                                     1001 xchg %ax, mutex
    75     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    75     4   1006 mov  %ax, count
    76     4   1007 mov  $0, mutex
    77     4   1008 sub  $1, %bx
    78     4   1009 test $0, %bx
    79     4   1010 jgt .top
    80     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    80     4                            1002 test $0, %ax
    81     4                            1003 jne  .acquire
    82     4                            1000 mov  $1, %ax
    83     4                            1001 xchg %ax, mutex
    84     4                            1002 test $0, %ax
    85     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    85     4                                                     1002 test $0, %ax
    86     4                                                     1003 jne  .acquire
    87     4                                                     1000 mov  $1, %ax
    88     4                                                     1001 xchg %ax, mutex
    89     4                                                     1002 test $0, %ax
    90     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    90     4   1000 mov  $1, %ax
    91     4   1001 xchg %ax, mutex
    92     4   1002 test $0, %ax
    93     4   1003 jne  .acquire
    94     4   1000 mov  $1, %ax
    95     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    95     4                            1003 jne  .acquire
    96     4                            1004 mov  count, %ax
    97     4                            1005 add  $1, %ax
    98     5                            1006 mov  %ax, count
    99     5                            1007 mov  $0, mutex
   100     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   100     5                                                     1003 jne  .acquire
   101     5                                                     1000 mov  $1, %ax
   102     5                                                     1001 xchg %ax, mutex
   103     5                                                     1002 test $0, %ax
   104     5                                                     1003 jne  .acquire
   105     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   105     5   1001 xchg %ax, mutex
   106     5   1002 test $0, %ax
   107     5   1003 jne  .acquire
   108     5   1000 mov  $1, %ax
   109     5   1001 xchg %ax, mutex
   110     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   110     5                            1008 sub  $1, %bx
   111     5                            1009 test $0, %bx
   112     5                            1010 jgt .top
   113     5                            1000 mov  $1, %ax
   114     5                            1001 xchg %ax, mutex
   115     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   115     5                                                     1004 mov  count, %ax
   116     5                                                     1005 add  $1, %ax
   117     6                                                     1006 mov  %ax, count
   118     6                                                     1007 mov  $0, mutex
   119     6                                                     1008 sub  $1, %bx
   120     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   120     6   1002 test $0, %ax
   121     6   1003 jne  .acquire
   122     6   1000 mov  $1, %ax
   123     6   1001 xchg %ax, mutex
   124     6   1002 test $0, %ax
   125     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   125     6                            1002 test $0, %ax
   126     6                            1003 jne  .acquire
   127     6                            1000 mov  $1, %ax
   128     6                            1001 xchg %ax, mutex
   129     6                            1002 test $0, %ax
   130     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   130     6                                                     1009 test $0, %bx
   131     6                                                     1010 jgt .top
   132     6                                                     1000 mov  $1, %ax
   133     6                                                     1001 xchg %ax, mutex
   134     6                                                     1002 test $0, %ax
   135     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   135     6   1003 jne  .acquire
   136     6   1004 mov  count, %ax
   137     6   1005 add  $1, %ax
   138     7   1006 mov  %ax, count
   139     7   1007 mov  $0, mutex
   140     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   140     7                            1003 jne  .acquire
   141     7                            1000 mov  $1, %ax
   142     7                            1001 xchg %ax, mutex
   143     7                            1002 test $0, %ax
   144     7                            1003 jne  .acquire
   145     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   145     7                                                     1003 jne  .acquire
   146     7                                                     1000 mov  $1, %ax
   147     7                                                     1001 xchg %ax, mutex
   148     7                                                     1002 test $0, %ax
   149     7                                                     1003 jne  .acquire
   150     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   150     7   1008 sub  $1, %bx
   151     7   1009 test $0, %bx
   152     7   1010 jgt .top
   153     7   1000 mov  $1, %ax
   154     7   1001 xchg %ax, mutex
   155     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   155     7                            1004 mov  count, %ax
   156     7                            1005 add  $1, %ax
   157     8                            1006 mov  %ax, count
   158     8                            1007 mov  $0, mutex
   159     8                            1008 sub  $1, %bx
   160     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   160     8                                                     1000 mov  $1, %ax
   161     8                                                     1001 xchg %ax, mutex
   162     8                                                     1002 test $0, %ax
   163     8                                                     1003 jne  .acquire
   164     8                                                     1004 mov  count, %ax
   165     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   165     8   1002 test $0, %ax
   166     8   1003 jne  .acquire
   167     8   1000 mov  $1, %ax
   168     8   1001 xchg %ax, mutex
   169     8   1002 test $0, %ax
   170     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   170     8                            1009 test $0, %bx
   171     8                            1010 jgt .top
   172     8                            1000 mov  $1, %ax
   173     8                            1001 xchg %ax, mutex
   174     8                            1002 test $0, %ax
   175     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   175     8                                                     1005 add  $1, %ax
   176     9                                                     1006 mov  %ax, count
   177     9                                                     1007 mov  $0, mutex
   178     9                                                     1008 sub  $1, %bx
   179     9                                                     1009 test $0, %bx
   180     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   180     9   1003 jne  .acquire
   181     9   1000 mov  $1, %ax
   182     9   1001 xchg %ax, mutex
   183     9   1002 test $0, %ax
   184     9   1003 jne  .acquire
   185     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   185     9                            1003 jne  .acquire
   186     9                            1000 mov  $1, %ax
   187     9                            1001 xchg %ax, mutex
   188     9                            1002 test $0, %ax
   189     9                            1003 jne  .acquire
   190     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   190     9                                                     1010 jgt .top
   191     9                                                     1000 mov  $1, %ax
   192     9                                                     1001 xchg %ax, mutex
   193     9                                                     1002 test $0, %ax
   194     9                                                     1003 jne  .acquire
   195     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   195     9   1004 mov  count, %ax
   196     9   1005 add  $1, %ax
   197    10   1006 mov  %ax, count
   198    10   1007 mov  $0, mutex
   199    10   1008 sub  $1, %bx
   200    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   200    10                            1000 mov  $1, %ax
   201    10                            1001 xchg %ax, mutex
   202    10                            1002 test $0, %ax
   203    10                            1003 jne  .acquire
   204    10                            1004 mov  count, %ax
   205    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   205    10                                                     1000 mov  $1, %ax
   206    10                                                     1001 xchg %ax, mutex
   207    10                                                     1002 test $0, %ax
   208    10                                                     1003 jne  .acquire
   209    10                                                     1000 mov  $1, %ax
   210    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   210    10   1009 test $0, %bx
   211    10   1010 jgt .top
   212    10   1000 mov  $1, %ax
   213    10   1001 xchg %ax, mutex
   214    10   1002 test $0, %ax
   215    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   215    10                            1005 add  $1, %ax
   216    11                            1006 mov  %ax, count
   217    11                            1007 mov  $0, mutex
   218    11                            1008 sub  $1, %bx
   219    11                            1009 test $0, %bx
   220    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   220    11                                                     1001 xchg %ax, mutex
   221    11                                                     1002 test $0, %ax
   222    11                                                     1003 jne  .acquire
   223    11                                                     1004 mov  count, %ax
   224    11                                                     1005 add  $1, %ax
   225    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   225    11   1003 jne  .acquire
   226    11   1000 mov  $1, %ax
   227    11   1001 xchg %ax, mutex
   228    11   1002 test $0, %ax
   229    11   1003 jne  .acquire
   230    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   230    11                            1010 jgt .top
   231    11                            1000 mov  $1, %ax
   232    11                            1001 xchg %ax, mutex
   233    11                            1002 test $0, %ax
   234    11                            1003 jne  .acquire
   235    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   235    12                                                     1006 mov  %ax, count
   236    12                                                     1007 mov  $0, mutex
   237    12                                                     1008 sub  $1, %bx
   238    12                                                     1009 test $0, %bx
   239    12                                                     1010 jgt .top
   240    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   240    12   1000 mov  $1, %ax
   241    12   1001 xchg %ax, mutex
   242    12   1002 test $0, %ax
   243    12   1003 jne  .acquire
   244    12   1004 mov  count, %ax
   245    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   245    12                            1000 mov  $1, %ax
   246    12                            1001 xchg %ax, mutex
   247    12                            1002 test $0, %ax
   248    12                            1003 jne  .acquire
   249    12                            1000 mov  $1, %ax
   250    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   250    12                                                     1000 mov  $1, %ax
   251    12                                                     1001 xchg %ax, mutex
   252    12                                                     1002 test $0, %ax
   253    12                                                     1003 jne  .acquire
   254    12                                                     1000 mov  $1, %ax
   255    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   255    12   1005 add  $1, %ax
   256    13   1006 mov  %ax, count
   257    13   1007 mov  $0, mutex
   258    13   1008 sub  $1, %bx
   259    13   1009 test $0, %bx
   260    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   260    13                            1001 xchg %ax, mutex
   261    13                            1002 test $0, %ax
   262    13                            1003 jne  .acquire
   263    13                            1004 mov  count, %ax
   264    13                            1005 add  $1, %ax
   265    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   265    13                                                     1001 xchg %ax, mutex
   266    13                                                     1002 test $0, %ax
   267    13                                                     1003 jne  .acquire
   268    13                                                     1000 mov  $1, %ax
   269    13                                                     1001 xchg %ax, mutex
   270    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   270    13   1010 jgt .top
   271    13   1000 mov  $1, %ax
   272    13   1001 xchg %ax, mutex
   273    13   1002 test $0, %ax
   274    13   1003 jne  .acquire
   275    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   275    14                            1006 mov  %ax, count
   276    14                            1007 mov  $0, mutex
   277    14                            1008 sub  $1, %bx
   278    14                            1009 test $0, %bx
   279    14                            1010 jgt .top
   280    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   280    14                                                     1002 test $0, %ax
   281    14                                                     1003 jne  .acquire
   282    14                                                     1000 mov  $1, %ax
   283    14                                                     1001 xchg %ax, mutex
   284    14                                                     1002 test $0, %ax
   285    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   285    14   1000 mov  $1, %ax
   286    14   1001 xchg %ax, mutex
   287    14   1002 test $0, %ax
   288    14   1003 jne  .acquire
   289    14   1000 mov  $1, %ax
   290    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   290    14                            1000 mov  $1, %ax
   291    14                            1001 xchg %ax, mutex
   292    14                            1002 test $0, %ax
   293    14                            1003 jne  .acquire
   294    14                            1000 mov  $1, %ax
   295    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   295    14                                                     1003 jne  .acquire
   296    14                                                     1004 mov  count, %ax
   297    14                                                     1005 add  $1, %ax
   298    15                                                     1006 mov  %ax, count
   299    15                                                     1007 mov  $0, mutex
   300    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   300    15   1001 xchg %ax, mutex
   301    15   1002 test $0, %ax
   302    15   1003 jne  .acquire
   303    15   1004 mov  count, %ax
   304    15   1005 add  $1, %ax
   305    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   305    15                            1001 xchg %ax, mutex
   306    15                            1002 test $0, %ax
   307    15                            1003 jne  .acquire
   308    15                            1000 mov  $1, %ax
   309    15                            1001 xchg %ax, mutex
   310    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   310    15                                                     1008 sub  $1, %bx
   311    15                                                     1009 test $0, %bx
   312    15                                                     1010 jgt .top
   313    15                                                     1000 mov  $1, %ax
   314    15                                                     1001 xchg %ax, mutex
   315    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   315    16   1006 mov  %ax, count
   316    16   1007 mov  $0, mutex
   317    16   1008 sub  $1, %bx
   318    16   1009 test $0, %bx
   319    16   1010 jgt .top
   320    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   320    16                            1002 test $0, %ax
   321    16                            1003 jne  .acquire
   322    16                            1000 mov  $1, %ax
   323    16                            1001 xchg %ax, mutex
   324    16                            1002 test $0, %ax
   325    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   325    16                                                     1002 test $0, %ax
   326    16                                                     1003 jne  .acquire
   327    16                                                     1000 mov  $1, %ax
   328    16                                                     1001 xchg %ax, mutex
   329    16                                                     1002 test $0, %ax
   330    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   330    16   1000 mov  $1, %ax
   331    16   1001 xchg %ax, mutex
   332    16   1002 test $0, %ax
   333    16   1003 jne  .acquire
   334    16   1000 mov  $1, %ax
   335    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   335    16                            1003 jne  .acquire
   336    16                            1004 mov  count, %ax
   337    16                            1005 add  $1, %ax
   338    17                            1006 mov  %ax, count
   339    17                            1007 mov  $0, mutex
   340    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   340    17                                                     1003 jne  .acquire
   341    17                                                     1000 mov  $1, %ax
   342    17                                                     1001 xchg %ax, mutex
   343    17                                                     1002 test $0, %ax
   344    17                                                     1003 jne  .acquire
   345    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   345    17   1001 xchg %ax, mutex
   346    17   1002 test $0, %ax
   347    17   1003 jne  .acquire
   348    17   1000 mov  $1, %ax
   349    17   1001 xchg %ax, mutex
   350    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   350    17                            1008 sub  $1, %bx
   351    17                            1009 test $0, %bx
   352    17                            1010 jgt .top
   353    17                            1000 mov  $1, %ax
   354    17                            1001 xchg %ax, mutex
   355    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   355    17                                                     1004 mov  count, %ax
   356    17                                                     1005 add  $1, %ax
   357    18                                                     1006 mov  %ax, count
   358    18                                                     1007 mov  $0, mutex
   359    18                                                     1008 sub  $1, %bx
   360    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   360    18   1002 test $0, %ax
   361    18   1003 jne  .acquire
   362    18   1000 mov  $1, %ax
   363    18   1001 xchg %ax, mutex
   364    18   1002 test $0, %ax
   365    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   365    18                            1002 test $0, %ax
   366    18                            1003 jne  .acquire
   367    18                            1000 mov  $1, %ax
   368    18                            1001 xchg %ax, mutex
   369    18                            1002 test $0, %ax
   370    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   370    18                                                     1009 test $0, %bx
   371    18                                                     1010 jgt .top
   372    18                                                     1000 mov  $1, %ax
   373    18                                                     1001 xchg %ax, mutex
   374    18                                                     1002 test $0, %ax
   375    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   375    18   1003 jne  .acquire
   376    18   1004 mov  count, %ax
   377    18   1005 add  $1, %ax
   378    19   1006 mov  %ax, count
   379    19   1007 mov  $0, mutex
   380    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   380    19                            1003 jne  .acquire
   381    19                            1000 mov  $1, %ax
   382    19                            1001 xchg %ax, mutex
   383    19                            1002 test $0, %ax
   384    19                            1003 jne  .acquire
   385    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   385    19                                                     1003 jne  .acquire
   386    19                                                     1000 mov  $1, %ax
   387    19                                                     1001 xchg %ax, mutex
   388    19                                                     1002 test $0, %ax
   389    19                                                     1003 jne  .acquire
   390    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   390    19   1008 sub  $1, %bx
   391    19   1009 test $0, %bx
   392    19   1010 jgt .top
   393    19   1000 mov  $1, %ax
   394    19   1001 xchg %ax, mutex
   395    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   395    19                            1004 mov  count, %ax
   396    19                            1005 add  $1, %ax
   397    20                            1006 mov  %ax, count
   398    20                            1007 mov  $0, mutex
   399    20                            1008 sub  $1, %bx
   400    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   400    20                                                     1000 mov  $1, %ax
   401    20                                                     1001 xchg %ax, mutex
   402    20                                                     1002 test $0, %ax
   403    20                                                     1003 jne  .acquire
   404    20                                                     1004 mov  count, %ax
   405    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   405    20   1002 test $0, %ax
   406    20   1003 jne  .acquire
   407    20   1000 mov  $1, %ax
   408    20   1001 xchg %ax, mutex
   409    20   1002 test $0, %ax
   410    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   410    20                            1009 test $0, %bx
   411    20                            1010 jgt .top
   412    20                            1000 mov  $1, %ax
   413    20                            1001 xchg %ax, mutex
   414    20                            1002 test $0, %ax
   415    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   415    20                                                     1005 add  $1, %ax
   416    21                                                     1006 mov  %ax, count
   417    21                                                     1007 mov  $0, mutex
   418    21                                                     1008 sub  $1, %bx
   419    21                                                     1009 test $0, %bx
   420    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   420    21   1003 jne  .acquire
   421    21   1000 mov  $1, %ax
   422    21   1001 xchg %ax, mutex
   423    21   1002 test $0, %ax
   424    21   1003 jne  .acquire
   425    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   425    21                            1003 jne  .acquire
   426    21                            1000 mov  $1, %ax
   427    21                            1001 xchg %ax, mutex
   428    21                            1002 test $0, %ax
   429    21                            1003 jne  .acquire
   430    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   430    21                                                     1010 jgt .top
   431    21                                                     1000 mov  $1, %ax
   432    21                                                     1001 xchg %ax, mutex
   433    21                                                     1002 test $0, %ax
   434    21                                                     1003 jne  .acquire
   435    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   435    21   1004 mov  count, %ax
   436    21   1005 add  $1, %ax
   437    22   1006 mov  %ax, count
   438    22   1007 mov  $0, mutex
   439    22   1008 sub  $1, %bx
   440    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   440    22                            1000 mov  $1, %ax
   441    22                            1001 xchg %ax, mutex
   442    22                            1002 test $0, %ax
   443    22                            1003 jne  .acquire
   444    22                            1004 mov  count, %ax
   445    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   445    22                                                     1000 mov  $1, %ax
   446    22                                                     1001 xchg %ax, mutex
   447    22                                                     1002 test $0, %ax
   448    22                                                     1003 jne  .acquire
   449    22                                                     1000 mov  $1, %ax
   450    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   450    22   1009 test $0, %bx
   451    22   1010 jgt .top
   452    22   1000 mov  $1, %ax
   453    22   1001 xchg %ax, mutex
   454    22   1002 test $0, %ax
   455    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   455    22                            1005 add  $1, %ax
   456    23                            1006 mov  %ax, count
   457    23                            1007 mov  $0, mutex
   458    23                            1008 sub  $1, %bx
   459    23                            1009 test $0, %bx
   460    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   460    23                                                     1001 xchg %ax, mutex
   461    23                                                     1002 test $0, %ax
   462    23                                                     1003 jne  .acquire
   463    23                                                     1004 mov  count, %ax
   464    23                                                     1005 add  $1, %ax
   465    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   465    23   1003 jne  .acquire
   466    23   1000 mov  $1, %ax
   467    23   1001 xchg %ax, mutex
   468    23   1002 test $0, %ax
   469    23   1003 jne  .acquire
   470    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   470    23                            1010 jgt .top
   471    23                            1000 mov  $1, %ax
   472    23                            1001 xchg %ax, mutex
   473    23                            1002 test $0, %ax
   474    23                            1003 jne  .acquire
   475    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   475    24                                                     1006 mov  %ax, count
   476    24                                                     1007 mov  $0, mutex
   477    24                                                     1008 sub  $1, %bx
   478    24                                                     1009 test $0, %bx
   479    24                                                     1010 jgt .top
   480    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   480    24   1000 mov  $1, %ax
   481    24   1001 xchg %ax, mutex
   482    24   1002 test $0, %ax
   483    24   1003 jne  .acquire
   484    24   1004 mov  count, %ax
   485    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   485    24                            1000 mov  $1, %ax
   486    24                            1001 xchg %ax, mutex
   487    24                            1002 test $0, %ax
   488    24                            1003 jne  .acquire
   489    24                            1000 mov  $1, %ax
   490    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   490    24                                                     1000 mov  $1, %ax
   491    24                                                     1001 xchg %ax, mutex
   492    24                                                     1002 test $0, %ax
   493    24                                                     1003 jne  .acquire
   494    24                                                     1000 mov  $1, %ax
   495    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   495    24   1005 add  $1, %ax
   496    25   1006 mov  %ax, count
   497    25   1007 mov  $0, mutex
   498    25   1008 sub  $1, %bx
   499    25   1009 test $0, %bx
   500    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   500    25                            1001 xchg %ax, mutex
   501    25                            1002 test $0, %ax
   502    25                            1003 jne  .acquire
   503    25                            1004 mov  count, %ax
   504    25                            1005 add  $1, %ax
   505    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   505    25                                                     1001 xchg %ax, mutex
   506    25                                                     1002 test $0, %ax
   507    25                                                     1003 jne  .acquire
   508    25                                                     1000 mov  $1, %ax
   509    25                                                     1001 xchg %ax, mutex
   510    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   510    25   1010 jgt .top
   511    25   1000 mov  $1, %ax
   512    25   1001 xchg %ax, mutex
   513    25   1002 test $0, %ax
   514    25   1003 jne  .acquire
   515    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   515    26                            1006 mov  %ax, count
   516    26                            1007 mov  $0, mutex
   517    26                            1008 sub  $1, %bx
   518    26                            1009 test $0, %bx
   519    26                            1010 jgt .top
   520    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   520    26                                                     1002 test $0, %ax
   521    26                                                     1003 jne  .acquire
   522    26                                                     1000 mov  $1, %ax
   523    26                                                     1001 xchg %ax, mutex
   524    26                                                     1002 test $0, %ax
   525    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   525    26   1000 mov  $1, %ax
   526    26   1001 xchg %ax, mutex
   527    26   1002 test $0, %ax
   528    26   1003 jne  .acquire
   529    26   1000 mov  $1, %ax
   530    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   530    26                            1000 mov  $1, %ax
   531    26                            1001 xchg %ax, mutex
   532    26                            1002 test $0, %ax
   533    26                            1003 jne  .acquire
   534    26                            1000 mov  $1, %ax
   535    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   535    26                                                     1003 jne  .acquire
   536    26                                                     1004 mov  count, %ax
   537    26                                                     1005 add  $1, %ax
   538    27                                                     1006 mov  %ax, count
   539    27                                                     1007 mov  $0, mutex
   540    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   540    27   1001 xchg %ax, mutex
   541    27   1002 test $0, %ax
   542    27   1003 jne  .acquire
   543    27   1004 mov  count, %ax
   544    27   1005 add  $1, %ax
   545    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   545    27                            1001 xchg %ax, mutex
   546    27                            1002 test $0, %ax
   547    27                            1003 jne  .acquire
   548    27                            1000 mov  $1, %ax
   549    27                            1001 xchg %ax, mutex
   550    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   550    27                                                     1008 sub  $1, %bx
   551    27                                                     1009 test $0, %bx
   552    27                                                     1010 jgt .top
   553    27                                                     1000 mov  $1, %ax
   554    27                                                     1001 xchg %ax, mutex
   555    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   555    28   1006 mov  %ax, count
   556    28   1007 mov  $0, mutex
   557    28   1008 sub  $1, %bx
   558    28   1009 test $0, %bx
   559    28   1010 jgt .top
   560    28   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   560    28                            1002 test $0, %ax
   561    28                            1003 jne  .acquire
   562    28                            1000 mov  $1, %ax
   563    28                            1001 xchg %ax, mutex
   564    28                            1002 test $0, %ax
   565    28   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   565    28                                                     1002 test $0, %ax
   566    28                                                     1003 jne  .acquire
   567    28                                                     1000 mov  $1, %ax
   568    28                                                     1001 xchg %ax, mutex
   569    28                                                     1002 test $0, %ax
   570    28   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   570    28   1011 halt
   571    28   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   571    28                            1003 jne  .acquire
   572    28                            1004 mov  count, %ax
   573    28                            1005 add  $1, %ax
   574    29                            1006 mov  %ax, count
   575    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   575    29                                                     1003 jne  .acquire
   576    29                                                     1000 mov  $1, %ax
   577    29                                                     1001 xchg %ax, mutex
   578    29                                                     1002 test $0, %ax
   579    29                                                     1003 jne  .acquire
   580    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   580    29                            1007 mov  $0, mutex
   581    29                            1008 sub  $1, %bx
   582    29                            1009 test $0, %bx
   583    29                            1010 jgt .top
   584    29                            1011 halt
   585    29   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   585    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   585    29                                                     1000 mov  $1, %ax
   586    29                                                     1001 xchg %ax, mutex
   587    29                                                     1002 test $0, %ax
   588    29                                                     1003 jne  .acquire
   589    29                                                     1004 mov  count, %ax
   590    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   590    29                                                     1005 add  $1, %ax
   591    30                                                     1006 mov  %ax, count
   592    30                                                     1007 mov  $0, mutex
   593    30                                                     1008 sub  $1, %bx
   594    30                                                     1009 test $0, %bx
   595    30   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   595    30                                                     1010 jgt .top
   596    30                                                     1011 halt

STATS:: Instructions    597
STATS:: Emulation Rate  19.83 kinst/sec
blake@CSCI-340:~/Documents/CSCI-340/HWK6/locks$ python x86.py -c -a bx=10 -M count -i 5 -t 3 -S -p yield.s
ARG seed 0
ARG numthreads 3
ARG program yield.s
ARG interrupt frequency 5
ARG interrupt randomness False
ARG procsched
ARG argv bx=10
ARG load address 1000
ARG memsize 128
ARG memtrace count
ARG regtrace
ARG cctrace False
ARG printstats True
ARG verbose False


icount count          Thread 0                Thread 1                Thread 2         

     0     0   
     0     0   1000 mov  $1, %ax
     1     0   1001 xchg %ax, mutex
     2     0   1002 test $0, %ax
     3     0   1003 je .acquire_done
     4     0   1006 mov  count, %ax
     5     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
     5     0                            1000 mov  $1, %ax
     6     0                            1001 xchg %ax, mutex
     7     0                            1002 test $0, %ax
     8     0                            1003 je .acquire_done
     9     0                            1004 yield
    10     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    10     0                                                     1000 mov  $1, %ax
    11     0                                                     1001 xchg %ax, mutex
    12     0                                                     1002 test $0, %ax
    13     0                                                     1003 je .acquire_done
    14     0                                                     1004 yield
    15     0   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    15     0   1007 add  $1, %ax
    16     1   1008 mov  %ax, count
    17     1   1009 mov  $0, mutex
    18     1   1010 sub  $1, %bx
    19     1   1011 test $0, %bx
    20     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    20     1                            1005 j .acquire
    21     1                            1000 mov  $1, %ax
    22     1                            1001 xchg %ax, mutex
    23     1                            1002 test $0, %ax
    24     1                            1003 je .acquire_done
    25     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    25     1                                                     1005 j .acquire
    26     1                                                     1000 mov  $1, %ax
    27     1                                                     1001 xchg %ax, mutex
    28     1                                                     1002 test $0, %ax
    29     1                                                     1003 je .acquire_done
    30     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    30     1   1012 jgt .top
    31     1   1000 mov  $1, %ax
    32     1   1001 xchg %ax, mutex
    33     1   1002 test $0, %ax
    34     1   1003 je .acquire_done
    35     1   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    35     1                            1006 mov  count, %ax
    36     1                            1007 add  $1, %ax
    37     2                            1008 mov  %ax, count
    38     2                            1009 mov  $0, mutex
    39     2                            1010 sub  $1, %bx
    40     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    40     2                                                     1004 yield
    41     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    41     2   1004 yield
    42     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    42     2                            1011 test $0, %bx
    43     2                            1012 jgt .top
    44     2                            1000 mov  $1, %ax
    45     2                            1001 xchg %ax, mutex
    46     2                            1002 test $0, %ax
    47     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    47     2                                                     1005 j .acquire
    48     2                                                     1000 mov  $1, %ax
    49     2                                                     1001 xchg %ax, mutex
    50     2                                                     1002 test $0, %ax
    51     2                                                     1003 je .acquire_done
    52     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    52     2   1005 j .acquire
    53     2   1000 mov  $1, %ax
    54     2   1001 xchg %ax, mutex
    55     2   1002 test $0, %ax
    56     2   1003 je .acquire_done
    57     2   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    57     2                            1003 je .acquire_done
    58     2                            1006 mov  count, %ax
    59     2                            1007 add  $1, %ax
    60     3                            1008 mov  %ax, count
    61     3                            1009 mov  $0, mutex
    62     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    62     3                                                     1004 yield
    63     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    63     3   1004 yield
    64     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    64     3                            1010 sub  $1, %bx
    65     3                            1011 test $0, %bx
    66     3                            1012 jgt .top
    67     3                            1000 mov  $1, %ax
    68     3                            1001 xchg %ax, mutex
    69     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    69     3                                                     1005 j .acquire
    70     3                                                     1000 mov  $1, %ax
    71     3                                                     1001 xchg %ax, mutex
    72     3                                                     1002 test $0, %ax
    73     3                                                     1003 je .acquire_done
    74     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    74     3   1005 j .acquire
    75     3   1000 mov  $1, %ax
    76     3   1001 xchg %ax, mutex
    77     3   1002 test $0, %ax
    78     3   1003 je .acquire_done
    79     3   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    79     3                            1002 test $0, %ax
    80     3                            1003 je .acquire_done
    81     3                            1006 mov  count, %ax
    82     3                            1007 add  $1, %ax
    83     4                            1008 mov  %ax, count
    84     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    84     4                                                     1004 yield
    85     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    85     4   1004 yield
    86     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    86     4                            1009 mov  $0, mutex
    87     4                            1010 sub  $1, %bx
    88     4                            1011 test $0, %bx
    89     4                            1012 jgt .top
    90     4                            1000 mov  $1, %ax
    91     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    91     4                                                     1005 j .acquire
    92     4                                                     1000 mov  $1, %ax
    93     4                                                     1001 xchg %ax, mutex
    94     4                                                     1002 test $0, %ax
    95     4                                                     1003 je .acquire_done
    96     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
    96     4   1005 j .acquire
    97     4   1000 mov  $1, %ax
    98     4   1001 xchg %ax, mutex
    99     4   1002 test $0, %ax
   100     4   1003 je .acquire_done
   101     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   101     4                            1001 xchg %ax, mutex
   102     4                            1002 test $0, %ax
   103     4                            1003 je .acquire_done
   104     4                            1004 yield
   105     4   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   105     4                                                     1006 mov  count, %ax
   106     4                                                     1007 add  $1, %ax
   107     5                                                     1008 mov  %ax, count
   108     5                                                     1009 mov  $0, mutex
   109     5                                                     1010 sub  $1, %bx
   110     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   110     5   1004 yield
   111     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   111     5                            1005 j .acquire
   112     5                            1000 mov  $1, %ax
   113     5                            1001 xchg %ax, mutex
   114     5                            1002 test $0, %ax
   115     5                            1003 je .acquire_done
   116     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   116     5                                                     1011 test $0, %bx
   117     5                                                     1012 jgt .top
   118     5                                                     1000 mov  $1, %ax
   119     5                                                     1001 xchg %ax, mutex
   120     5                                                     1002 test $0, %ax
   121     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   121     5   1005 j .acquire
   122     5   1000 mov  $1, %ax
   123     5   1001 xchg %ax, mutex
   124     5   1002 test $0, %ax
   125     5   1003 je .acquire_done
   126     5   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   126     5                            1006 mov  count, %ax
   127     5                            1007 add  $1, %ax
   128     6                            1008 mov  %ax, count
   129     6                            1009 mov  $0, mutex
   130     6                            1010 sub  $1, %bx
   131     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   131     6                                                     1003 je .acquire_done
   132     6                                                     1004 yield
   133     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   133     6   1004 yield
   134     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   134     6                            1011 test $0, %bx
   135     6                            1012 jgt .top
   136     6                            1000 mov  $1, %ax
   137     6                            1001 xchg %ax, mutex
   138     6                            1002 test $0, %ax
   139     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   139     6                                                     1005 j .acquire
   140     6                                                     1000 mov  $1, %ax
   141     6                                                     1001 xchg %ax, mutex
   142     6                                                     1002 test $0, %ax
   143     6                                                     1003 je .acquire_done
   144     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   144     6   1005 j .acquire
   145     6   1000 mov  $1, %ax
   146     6   1001 xchg %ax, mutex
   147     6   1002 test $0, %ax
   148     6   1003 je .acquire_done
   149     6   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   149     6                            1003 je .acquire_done
   150     6                            1006 mov  count, %ax
   151     6                            1007 add  $1, %ax
   152     7                            1008 mov  %ax, count
   153     7                            1009 mov  $0, mutex
   154     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   154     7                                                     1004 yield
   155     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   155     7   1004 yield
   156     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   156     7                            1010 sub  $1, %bx
   157     7                            1011 test $0, %bx
   158     7                            1012 jgt .top
   159     7                            1000 mov  $1, %ax
   160     7                            1001 xchg %ax, mutex
   161     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   161     7                                                     1005 j .acquire
   162     7                                                     1000 mov  $1, %ax
   163     7                                                     1001 xchg %ax, mutex
   164     7                                                     1002 test $0, %ax
   165     7                                                     1003 je .acquire_done
   166     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   166     7   1005 j .acquire
   167     7   1000 mov  $1, %ax
   168     7   1001 xchg %ax, mutex
   169     7   1002 test $0, %ax
   170     7   1003 je .acquire_done
   171     7   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   171     7                            1002 test $0, %ax
   172     7                            1003 je .acquire_done
   173     7                            1006 mov  count, %ax
   174     7                            1007 add  $1, %ax
   175     8                            1008 mov  %ax, count
   176     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   176     8                                                     1004 yield
   177     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   177     8   1004 yield
   178     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   178     8                            1009 mov  $0, mutex
   179     8                            1010 sub  $1, %bx
   180     8                            1011 test $0, %bx
   181     8                            1012 jgt .top
   182     8                            1000 mov  $1, %ax
   183     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   183     8                                                     1005 j .acquire
   184     8                                                     1000 mov  $1, %ax
   185     8                                                     1001 xchg %ax, mutex
   186     8                                                     1002 test $0, %ax
   187     8                                                     1003 je .acquire_done
   188     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   188     8   1005 j .acquire
   189     8   1000 mov  $1, %ax
   190     8   1001 xchg %ax, mutex
   191     8   1002 test $0, %ax
   192     8   1003 je .acquire_done
   193     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   193     8                            1001 xchg %ax, mutex
   194     8                            1002 test $0, %ax
   195     8                            1003 je .acquire_done
   196     8                            1004 yield
   197     8   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   197     8                                                     1006 mov  count, %ax
   198     8                                                     1007 add  $1, %ax
   199     9                                                     1008 mov  %ax, count
   200     9                                                     1009 mov  $0, mutex
   201     9                                                     1010 sub  $1, %bx
   202     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   202     9   1004 yield
   203     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   203     9                            1005 j .acquire
   204     9                            1000 mov  $1, %ax
   205     9                            1001 xchg %ax, mutex
   206     9                            1002 test $0, %ax
   207     9                            1003 je .acquire_done
   208     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   208     9                                                     1011 test $0, %bx
   209     9                                                     1012 jgt .top
   210     9                                                     1000 mov  $1, %ax
   211     9                                                     1001 xchg %ax, mutex
   212     9                                                     1002 test $0, %ax
   213     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   213     9   1005 j .acquire
   214     9   1000 mov  $1, %ax
   215     9   1001 xchg %ax, mutex
   216     9   1002 test $0, %ax
   217     9   1003 je .acquire_done
   218     9   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   218     9                            1006 mov  count, %ax
   219     9                            1007 add  $1, %ax
   220    10                            1008 mov  %ax, count
   221    10                            1009 mov  $0, mutex
   222    10                            1010 sub  $1, %bx
   223    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   223    10                                                     1003 je .acquire_done
   224    10                                                     1004 yield
   225    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   225    10   1004 yield
   226    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   226    10                            1011 test $0, %bx
   227    10                            1012 jgt .top
   228    10                            1000 mov  $1, %ax
   229    10                            1001 xchg %ax, mutex
   230    10                            1002 test $0, %ax
   231    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   231    10                                                     1005 j .acquire
   232    10                                                     1000 mov  $1, %ax
   233    10                                                     1001 xchg %ax, mutex
   234    10                                                     1002 test $0, %ax
   235    10                                                     1003 je .acquire_done
   236    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   236    10   1005 j .acquire
   237    10   1000 mov  $1, %ax
   238    10   1001 xchg %ax, mutex
   239    10   1002 test $0, %ax
   240    10   1003 je .acquire_done
   241    10   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   241    10                            1003 je .acquire_done
   242    10                            1006 mov  count, %ax
   243    10                            1007 add  $1, %ax
   244    11                            1008 mov  %ax, count
   245    11                            1009 mov  $0, mutex
   246    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   246    11                                                     1004 yield
   247    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   247    11   1004 yield
   248    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   248    11                            1010 sub  $1, %bx
   249    11                            1011 test $0, %bx
   250    11                            1012 jgt .top
   251    11                            1000 mov  $1, %ax
   252    11                            1001 xchg %ax, mutex
   253    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   253    11                                                     1005 j .acquire
   254    11                                                     1000 mov  $1, %ax
   255    11                                                     1001 xchg %ax, mutex
   256    11                                                     1002 test $0, %ax
   257    11                                                     1003 je .acquire_done
   258    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   258    11   1005 j .acquire
   259    11   1000 mov  $1, %ax
   260    11   1001 xchg %ax, mutex
   261    11   1002 test $0, %ax
   262    11   1003 je .acquire_done
   263    11   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   263    11                            1002 test $0, %ax
   264    11                            1003 je .acquire_done
   265    11                            1006 mov  count, %ax
   266    11                            1007 add  $1, %ax
   267    12                            1008 mov  %ax, count
   268    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   268    12                                                     1004 yield
   269    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   269    12   1004 yield
   270    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   270    12                            1009 mov  $0, mutex
   271    12                            1010 sub  $1, %bx
   272    12                            1011 test $0, %bx
   273    12                            1012 jgt .top
   274    12                            1000 mov  $1, %ax
   275    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   275    12                                                     1005 j .acquire
   276    12                                                     1000 mov  $1, %ax
   277    12                                                     1001 xchg %ax, mutex
   278    12                                                     1002 test $0, %ax
   279    12                                                     1003 je .acquire_done
   280    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   280    12   1005 j .acquire
   281    12   1000 mov  $1, %ax
   282    12   1001 xchg %ax, mutex
   283    12   1002 test $0, %ax
   284    12   1003 je .acquire_done
   285    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   285    12                            1001 xchg %ax, mutex
   286    12                            1002 test $0, %ax
   287    12                            1003 je .acquire_done
   288    12                            1004 yield
   289    12   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   289    12                                                     1006 mov  count, %ax
   290    12                                                     1007 add  $1, %ax
   291    13                                                     1008 mov  %ax, count
   292    13                                                     1009 mov  $0, mutex
   293    13                                                     1010 sub  $1, %bx
   294    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   294    13   1004 yield
   295    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   295    13                            1005 j .acquire
   296    13                            1000 mov  $1, %ax
   297    13                            1001 xchg %ax, mutex
   298    13                            1002 test $0, %ax
   299    13                            1003 je .acquire_done
   300    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   300    13                                                     1011 test $0, %bx
   301    13                                                     1012 jgt .top
   302    13                                                     1000 mov  $1, %ax
   303    13                                                     1001 xchg %ax, mutex
   304    13                                                     1002 test $0, %ax
   305    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   305    13   1005 j .acquire
   306    13   1000 mov  $1, %ax
   307    13   1001 xchg %ax, mutex
   308    13   1002 test $0, %ax
   309    13   1003 je .acquire_done
   310    13   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   310    13                            1006 mov  count, %ax
   311    13                            1007 add  $1, %ax
   312    14                            1008 mov  %ax, count
   313    14                            1009 mov  $0, mutex
   314    14                            1010 sub  $1, %bx
   315    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   315    14                                                     1003 je .acquire_done
   316    14                                                     1004 yield
   317    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   317    14   1004 yield
   318    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   318    14                            1011 test $0, %bx
   319    14                            1012 jgt .top
   320    14                            1013 halt
   321    14   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   321    14                                                     1005 j .acquire
   322    14                                                     1000 mov  $1, %ax
   323    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   323    14   1005 j .acquire
   324    14   1000 mov  $1, %ax
   325    14   1001 xchg %ax, mutex
   326    14   1002 test $0, %ax
   327    14   1003 je .acquire_done
   328    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   328    14                                                     1001 xchg %ax, mutex
   329    14                                                     1002 test $0, %ax
   330    14                                                     1003 je .acquire_done
   331    14                                                     1004 yield
   332    14   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   332    14   1006 mov  count, %ax
   333    14   1007 add  $1, %ax
   334    15   1008 mov  %ax, count
   335    15   1009 mov  $0, mutex
   336    15   1010 sub  $1, %bx
   337    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   337    15                                                     1005 j .acquire
   338    15                                                     1000 mov  $1, %ax
   339    15                                                     1001 xchg %ax, mutex
   340    15                                                     1002 test $0, %ax
   341    15                                                     1003 je .acquire_done
   342    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   342    15   1011 test $0, %bx
   343    15   1012 jgt .top
   344    15   1000 mov  $1, %ax
   345    15   1001 xchg %ax, mutex
   346    15   1002 test $0, %ax
   347    15   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   347    15                                                     1006 mov  count, %ax
   348    15                                                     1007 add  $1, %ax
   349    16                                                     1008 mov  %ax, count
   350    16                                                     1009 mov  $0, mutex
   351    16                                                     1010 sub  $1, %bx
   352    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   352    16   1003 je .acquire_done
   353    16   1004 yield
   354    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   354    16                                                     1011 test $0, %bx
   355    16                                                     1012 jgt .top
   356    16                                                     1000 mov  $1, %ax
   357    16                                                     1001 xchg %ax, mutex
   358    16                                                     1002 test $0, %ax
   359    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   359    16   1005 j .acquire
   360    16   1000 mov  $1, %ax
   361    16   1001 xchg %ax, mutex
   362    16   1002 test $0, %ax
   363    16   1003 je .acquire_done
   364    16   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   364    16                                                     1003 je .acquire_done
   365    16                                                     1006 mov  count, %ax
   366    16                                                     1007 add  $1, %ax
   367    17                                                     1008 mov  %ax, count
   368    17                                                     1009 mov  $0, mutex
   369    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   369    17   1004 yield
   370    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   370    17                                                     1010 sub  $1, %bx
   371    17                                                     1011 test $0, %bx
   372    17                                                     1012 jgt .top
   373    17                                                     1000 mov  $1, %ax
   374    17                                                     1001 xchg %ax, mutex
   375    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   375    17   1005 j .acquire
   376    17   1000 mov  $1, %ax
   377    17   1001 xchg %ax, mutex
   378    17   1002 test $0, %ax
   379    17   1003 je .acquire_done
   380    17   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   380    17                                                     1002 test $0, %ax
   381    17                                                     1003 je .acquire_done
   382    17                                                     1006 mov  count, %ax
   383    17                                                     1007 add  $1, %ax
   384    18                                                     1008 mov  %ax, count
   385    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   385    18   1004 yield
   386    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   386    18                                                     1009 mov  $0, mutex
   387    18                                                     1010 sub  $1, %bx
   388    18                                                     1011 test $0, %bx
   389    18                                                     1012 jgt .top
   390    18                                                     1000 mov  $1, %ax
   391    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   391    18   1005 j .acquire
   392    18   1000 mov  $1, %ax
   393    18   1001 xchg %ax, mutex
   394    18   1002 test $0, %ax
   395    18   1003 je .acquire_done
   396    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   396    18                                                     1001 xchg %ax, mutex
   397    18                                                     1002 test $0, %ax
   398    18                                                     1003 je .acquire_done
   399    18                                                     1004 yield
   400    18   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   400    18   1006 mov  count, %ax
   401    18   1007 add  $1, %ax
   402    19   1008 mov  %ax, count
   403    19   1009 mov  $0, mutex
   404    19   1010 sub  $1, %bx
   405    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   405    19                                                     1005 j .acquire
   406    19                                                     1000 mov  $1, %ax
   407    19                                                     1001 xchg %ax, mutex
   408    19                                                     1002 test $0, %ax
   409    19                                                     1003 je .acquire_done
   410    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   410    19   1011 test $0, %bx
   411    19   1012 jgt .top
   412    19   1000 mov  $1, %ax
   413    19   1001 xchg %ax, mutex
   414    19   1002 test $0, %ax
   415    19   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   415    19                                                     1006 mov  count, %ax
   416    19                                                     1007 add  $1, %ax
   417    20                                                     1008 mov  %ax, count
   418    20                                                     1009 mov  $0, mutex
   419    20                                                     1010 sub  $1, %bx
   420    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   420    20   1003 je .acquire_done
   421    20   1004 yield
   422    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   422    20                                                     1011 test $0, %bx
   423    20                                                     1012 jgt .top
   424    20                                                     1000 mov  $1, %ax
   425    20                                                     1001 xchg %ax, mutex
   426    20                                                     1002 test $0, %ax
   427    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   427    20   1005 j .acquire
   428    20   1000 mov  $1, %ax
   429    20   1001 xchg %ax, mutex
   430    20   1002 test $0, %ax
   431    20   1003 je .acquire_done
   432    20   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   432    20                                                     1003 je .acquire_done
   433    20                                                     1006 mov  count, %ax
   434    20                                                     1007 add  $1, %ax
   435    21                                                     1008 mov  %ax, count
   436    21                                                     1009 mov  $0, mutex
   437    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   437    21   1004 yield
   438    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   438    21                                                     1010 sub  $1, %bx
   439    21                                                     1011 test $0, %bx
   440    21                                                     1012 jgt .top
   441    21                                                     1000 mov  $1, %ax
   442    21                                                     1001 xchg %ax, mutex
   443    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   443    21   1005 j .acquire
   444    21   1000 mov  $1, %ax
   445    21   1001 xchg %ax, mutex
   446    21   1002 test $0, %ax
   447    21   1003 je .acquire_done
   448    21   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   448    21                                                     1002 test $0, %ax
   449    21                                                     1003 je .acquire_done
   450    21                                                     1006 mov  count, %ax
   451    21                                                     1007 add  $1, %ax
   452    22                                                     1008 mov  %ax, count
   453    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   453    22   1004 yield
   454    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   454    22                                                     1009 mov  $0, mutex
   455    22                                                     1010 sub  $1, %bx
   456    22                                                     1011 test $0, %bx
   457    22                                                     1012 jgt .top
   458    22                                                     1000 mov  $1, %ax
   459    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   459    22   1005 j .acquire
   460    22   1000 mov  $1, %ax
   461    22   1001 xchg %ax, mutex
   462    22   1002 test $0, %ax
   463    22   1003 je .acquire_done
   464    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   464    22                                                     1001 xchg %ax, mutex
   465    22                                                     1002 test $0, %ax
   466    22                                                     1003 je .acquire_done
   467    22                                                     1004 yield
   468    22   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   468    22   1006 mov  count, %ax
   469    22   1007 add  $1, %ax
   470    23   1008 mov  %ax, count
   471    23   1009 mov  $0, mutex
   472    23   1010 sub  $1, %bx
   473    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   473    23                                                     1005 j .acquire
   474    23                                                     1000 mov  $1, %ax
   475    23                                                     1001 xchg %ax, mutex
   476    23                                                     1002 test $0, %ax
   477    23                                                     1003 je .acquire_done
   478    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   478    23   1011 test $0, %bx
   479    23   1012 jgt .top
   480    23   1000 mov  $1, %ax
   481    23   1001 xchg %ax, mutex
   482    23   1002 test $0, %ax
   483    23   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   483    23                                                     1006 mov  count, %ax
   484    23                                                     1007 add  $1, %ax
   485    24                                                     1008 mov  %ax, count
   486    24                                                     1009 mov  $0, mutex
   487    24                                                     1010 sub  $1, %bx
   488    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   488    24   1003 je .acquire_done
   489    24   1004 yield
   490    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   490    24                                                     1011 test $0, %bx
   491    24                                                     1012 jgt .top
   492    24                                                     1013 halt
   493    24   ----- Halt;Switch -----  ----- Halt;Switch -----  ----- Halt;Switch -----  
   493    24   1005 j .acquire
   494    24   1000 mov  $1, %ax
   495    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   495    24   1001 xchg %ax, mutex
   496    24   1002 test $0, %ax
   497    24   1003 je .acquire_done
   498    24   1006 mov  count, %ax
   499    24   1007 add  $1, %ax
   500    24   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   500    25   1008 mov  %ax, count
   501    25   1009 mov  $0, mutex
   502    25   1010 sub  $1, %bx
   503    25   1011 test $0, %bx
   504    25   1012 jgt .top
   505    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   505    25   1000 mov  $1, %ax
   506    25   1001 xchg %ax, mutex
   507    25   1002 test $0, %ax
   508    25   1003 je .acquire_done
   509    25   1006 mov  count, %ax
   510    25   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   510    25   1007 add  $1, %ax
   511    26   1008 mov  %ax, count
   512    26   1009 mov  $0, mutex
   513    26   1010 sub  $1, %bx
   514    26   1011 test $0, %bx
   515    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   515    26   1012 jgt .top
   516    26   1000 mov  $1, %ax
   517    26   1001 xchg %ax, mutex
   518    26   1002 test $0, %ax
   519    26   1003 je .acquire_done
   520    26   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   520    26   1006 mov  count, %ax
   521    26   1007 add  $1, %ax
   522    27   1008 mov  %ax, count
   523    27   1009 mov  $0, mutex
   524    27   1010 sub  $1, %bx
   525    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   525    27   1011 test $0, %bx
   526    27   1012 jgt .top
   527    27   1000 mov  $1, %ax
   528    27   1001 xchg %ax, mutex
   529    27   1002 test $0, %ax
   530    27   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   530    27   1003 je .acquire_done
   531    27   1006 mov  count, %ax
   532    27   1007 add  $1, %ax
   533    28   1008 mov  %ax, count
   534    28   1009 mov  $0, mutex
   535    28   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   535    28   1010 sub  $1, %bx
   536    28   1011 test $0, %bx
   537    28   1012 jgt .top
   538    28   1000 mov  $1, %ax
   539    28   1001 xchg %ax, mutex
   540    28   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   540    28   1002 test $0, %ax
   541    28   1003 je .acquire_done
   542    28   1006 mov  count, %ax
   543    28   1007 add  $1, %ax
   544    29   1008 mov  %ax, count
   545    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   545    29   1009 mov  $0, mutex
   546    29   1010 sub  $1, %bx
   547    29   1011 test $0, %bx
   548    29   1012 jgt .top
   549    29   1000 mov  $1, %ax
   550    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   550    29   1001 xchg %ax, mutex
   551    29   1002 test $0, %ax
   552    29   1003 je .acquire_done
   553    29   1006 mov  count, %ax
   554    29   1007 add  $1, %ax
   555    29   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   555    30   1008 mov  %ax, count
   556    30   1009 mov  $0, mutex
   557    30   1010 sub  $1, %bx
   558    30   1011 test $0, %bx
   559    30   1012 jgt .top
   560    30   ------ Interrupt ------  ------ Interrupt ------  ------ Interrupt ------  
   560    30   1013 halt

STATS:: Instructions    561
STATS:: Emulation Rate  17.33 kinst/sec
```

### c.
#### ```flag.s```
This program only ends with count 26, this is because the flag system is not atomic and some of the threads may incorrectly add to count due to a thread preemptively executing.
#### ```test-and-set.s``` and ```yield.s```
These programs end with count 30, this is because they are atomic and work as intended.

### d.
The different programs handle the process of checking if a thread is good to run in different ways (ie mutex and flags) and they take more or fewer instructions based on the checking mechanism.

### e.
#### i.
For flag, the count value changes but it appears to be inconsistent and does not necessarily go up or down with the increase or decrease of -I. For the other 2 programs, count stays the same.
#### ii.
The number of instructions for each change and they do not really appear to have a consistent trend with regards to -I. Similar to the count for flag, the number of instructions will increase and decrease seemingly independently of -I.
