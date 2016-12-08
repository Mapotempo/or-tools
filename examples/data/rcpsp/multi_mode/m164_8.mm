************************************************************************
file with basedata            : cm164_.bas
initial value random generator: 418726896
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  80
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       24        2       24
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        1          3           9  16  17
   3        1          3           8  10  15
   4        1          3           5   6   7
   5        1          3           9  13  14
   6        1          3           9  13  17
   7        1          2          11  14
   8        1          2          11  12
   9        1          1          15
  10        1          3          11  12  17
  11        1          1          13
  12        1          1          14
  13        1          1          16
  14        1          1          16
  15        1          1          18
  16        1          1          18
  17        1          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     7       4    6    6    4
  3      1     1       6    6    5    7
  4      1     3      10    5    5   10
  5      1     6       6    6    8    9
  6      1     8       2    5    4    6
  7      1     7       7    5    3    2
  8      1     7       9    3    6    2
  9      1     2       9    3    8    8
 10      1     4       7    7    3    5
 11      1     5       9    6    4    7
 12      1     4       2    4    5    7
 13      1     2       9   10    4    6
 14      1     3       8    7    6    4
 15      1     5       2    2    7    7
 16      1     7       9    2    4    3
 17      1     9       9    9    3    2
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   35   32   81   89
************************************************************************