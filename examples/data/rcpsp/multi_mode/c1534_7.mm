************************************************************************
file with basedata            : c1534_.bas
initial value random generator: 1158583562
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  121
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       24       10       24
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          1           5
   3        3          3           7   8  10
   4        3          1          16
   5        3          2           6  12
   6        3          3           7   9  11
   7        3          2          13  14
   8        3          1          14
   9        3          1          13
  10        3          1          17
  11        3          1          13
  12        3          1          16
  13        3          2          15  17
  14        3          2          15  16
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     6       0    8   10    7
         2     8       7    0    9    3
         3     8       0    7    8    6
  3      1     6       0    7    5    5
         2     6       6    0    4    5
         3    10       4    0    4    4
  4      1     1       8    0   10    8
         2     1       9    0    9   10
         3     8       0    4    8    5
  5      1     4       4    0    9    9
         2     4       0    5   10   10
         3     7       0    1    9    9
  6      1     1       5    0    4    7
         2     1       0    6    4    7
         3     3       5    0    4    5
  7      1     6       0    2    3    8
         2     6       8    0    3    8
         3     7       0    2    2    6
  8      1     3       5    0    4    9
         2     4       0    1    4    7
         3     8       1    0    3    4
  9      1     2       0    2    2    5
         2     5       7    0    2    5
         3     9       6    0    2    5
 10      1     1       5    0    9    8
         2     5       0    8    5    8
         3     5       0    7    7    8
 11      1     1       9    0    8    4
         2     2       0    9    6    3
         3     8       0    5    5    3
 12      1     4       6    0    8    5
         2     7       5    0    6    4
         3     9       0    8    4    3
 13      1     3       7    0    9    8
         2     4       5    0    5    6
         3    10       0    1    5    4
 14      1     4       0   10    8    2
         2     6       6    0    8    2
         3    10       5    0    8    1
 15      1     1       4    0    8   10
         2     4       0    9    8   10
         3     6       3    0    7   10
 16      1     3       2    0    6    8
         2     4       1    0    4    8
         3     6       1    0    1    8
 17      1     3       0   10    9    7
         2     6       0    9    6    4
         3     7       0    6    5    3
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   16   14   88   89
************************************************************************