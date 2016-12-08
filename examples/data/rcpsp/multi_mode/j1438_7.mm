************************************************************************
file with basedata            : md166_.bas
initial value random generator: 421646381
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  16
horizon                       :  120
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     14      0       14        7       14
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           9  12
   3        3          1           7
   4        3          3           5   6  12
   5        3          2          13  14
   6        3          3           8  11  15
   7        3          3          10  11  12
   8        3          1          10
   9        3          3          10  11  15
  10        3          2          13  14
  11        3          2          13  14
  12        3          1          15
  13        3          1          16
  14        3          1          16
  15        3          1          16
  16        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1       4    8    8    7
         2     2       3    6    7    5
         3    10       2    5    4    3
  3      1     3       7    6    2    8
         2     6       6    5    2    7
         3    10       6    3    1    5
  4      1     4       6    2    5    9
         2     6       5    1    3    7
         3    10       3    1    2    6
  5      1     3       6    4    2    9
         2     6       4    4    2    7
         3     8       3    2    2    4
  6      1     2       7    6    8    8
         2     2       7    7    7    8
         3     8       7    5    6    8
  7      1     4       5    6    9    5
         2     6       4    3    9    5
         3    10       4    3    8    5
  8      1     1       9    6    5    8
         2     5       6    3    5    7
         3    10       4    3    4    5
  9      1     6       1    9    9    6
         2     7       1    4    8    5
         3    10       1    3    7    2
 10      1     1       6    3    5    7
         2     4       6    3    3    5
         3     4       4    2    5    4
 11      1     2       3    1    5    8
         2     5       2    1    3    6
         3     5       2    1    1    7
 12      1     1       8    7    3    8
         2     6       8    3    3    7
         3     9       8    2    2    6
 13      1     4       6   10    9    2
         2     5       6    7    8    2
         3     9       6    3    8    2
 14      1     5       7    5    6    2
         2     7       5    4    6    2
         3     9       5    3    4    2
 15      1     5       4    7    4    3
         2     6       4    6    2    2
         3     8       3    6    1    2
 16      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   15   16   60   68
************************************************************************