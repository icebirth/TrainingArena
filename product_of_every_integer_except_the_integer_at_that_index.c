#include <stdio.h>

int result[4];
int array[4] = {2, 7, 0, 6};
int count = 0;

int find_product(int i, int n, int prev)
{
 count++;

 if (i==n) return 1;

 int np;

 np = find_product(i+1, n, prev*array[i]);

 result[i] = np * prev;

 printf("prev %d np %d result[%d] = %d\n", prev, np, i, result[i]);

 return np*array[i];
}

int main()
{
 find_product(0,4,1);
 printf("count %d\n", count);
 return 0;
}

