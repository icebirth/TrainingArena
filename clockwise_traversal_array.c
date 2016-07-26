#include <stdio.h>

typedef enum _dir {
	RIGHT,
	DOWN,
	LEFT,
	UP
}DIR;

void fill_array(int n, int array[][n]) {
int i, j, val = 1;
for (i=0 ; i<n; i++) {
for (j=0 ; j<n; j++) {
 array[i][j] = val;
 val++;
}
}
}

void print_array(int n, int array[][n]) {
int i,j;

for (i=0; i<n; i++) {
for (j=0; j<n; j++) {
printf("%4d ", array[i][j]);
}
printf("\n");
}
}

void print_circular_array(int n, int array[][n], int r) {
	int x,y,i;
	
	x = y = (n-r)/2;
	if (r == 0)
		return;
	else if (r == 1)
		printf("%d:%d ", r, array[x][y]);
	else {
		DIR d = RIGHT;
		printf("%d:", 4*(r-1));
		for (i=1; i<= 4*(r-1) ; i++) {
			printf("%d ", array[x][y]);
			if (d == RIGHT) y++;
			else if (d == DOWN) x++;
			else if (d == LEFT) y--;
			else if (d == UP) x--;
			
			if (i%(r-1) == 0) d++;
		}
		printf("\n");
		print_circular_array(n, array, r-2);
	}	
}
 
int main() {

int n = 15;
int array[n][n];

fill_array(n, array);

print_array(n, array);

printf("Circular Array: \n");
print_circular_array(n, array, n);
printf(" \n");
return 0;
}
