/*
Point Update In Square Root Decomposition

venice 90 

https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/range-queries/point-update-in-square-root-decomposition-official/ojquestion

You are given a list of N numbers and Q queries. There are two types of queries:

1. f l r : In a line, the first character would be f, and 2 index l and r, you
have to find the sum of numbers between l and r.
2. u i d : In a line, the first character would be u, and we have to change the
value at index i in the original array by d. Input Format The first line
contains N. The next line holds N numbers. Following the list is a number Q. The
next Q lines each contain one of the 2 queries. Output Format Output the sum
from l to r for type 1 query and update the value at index i for type 2 query.
Question Video

  COMMENTConstraints
1 <= N <= 10^6
1 <= Q <= 10^5
1 <= arr[i] <= 10^9
Sample Input
5
1 5 3 9 -2
3
f 0 4
u 2 3
f 0 4
Sample Output
16
19
 */