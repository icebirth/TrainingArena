#include <stdio.h>

int array1[6] = { 8, 5, 3, 6, 4, 7};		//8*6*7 =  336
int array2[6] = { -8, 5, 3, -6, 4, -7};		//-8*-7*5 = 280
int array3[6] = { -8, -5, -3, -6, -4, -7};	//-8*-7*-3 = -168
int array4[6] = { -8, -5, 0, -6, -4, -7};	//-8*-7*0 = 0
int array5[6] = { -8, -5, 3, 3, -4, -8};	//-8*-8*3 = 192
int array6[6] = { 8, -5, 3, 6, 8, 8};		//8*8*8 =  512

int top3[3] = {0,0,0};

void arrange_top3(int a, int b, int c)
{
	top3[2] = (a>b)?((a>c)?a:c):((b>c)?b:c);
	top3[1] = (a>b)?((a>c)?((b>c)?b:c):a):((b>c)?((a>c)?a:c):b);
	top3[0] = (a>b)?((a>c)?((b>c)?c:b):b):((b>c)?((a>c)?c:a):a);

}

//
//Find lowest 2 negitive numbers.
//If you find 2 -ve numbers, make them positive.
//Now we don't have to worry about negitive numbers. Just find top three.
//

int hightest_product(int array[], int n)
{
	int i;
	int lowneg_index1 = -1;
	int lowneg_index2 = -1;

#define PUT_IN_BACK(i) lowneg_index2=i;
#define PUT_IN_FRONT(i) lowneg_index2=lowneg_index1; lowneg_index1 = i;

	//Find lowest 2 negitive numbers.
	for (i = 0; i < n; i++) {
		if (array[i] < 0) {
			if (array[i] < array[lowneg_index1]) {
				PUT_IN_FRONT(i);
			} else if (array[i] < array[lowneg_index2])
				PUT_IN_BACK(i);
		}

		//printf("Handled: array[%d]=%d ==>> Current Low Negitives %d %d \n", i,array[i], lowneg_index1, lowneg_index2);
	}

	//If you find them, make them positive.
	if (lowneg_index1 != -1 && lowneg_index2 != -1) {
		array[lowneg_index1] = -1*array[lowneg_index1];
		array[lowneg_index2] = -1*array[lowneg_index2];
	}

	//Now we don't have to worry about negitive numbers. Just find top three.
	arrange_top3(array[0], array[1], array[2]);
	for (i = 3; i < n; i++) {
		if (array[i] > top3[0])
			arrange_top3(array[i], top3[1], top3[2]);		

		//printf("Handled: %d ==>> Current Top3 %d %d %d\n", array[i], top3[0], top3[1], top3[2]);
	}

	printf("Highest Product %d\n", top3[0]*top3[1]*top3[2]);
	return 0;
}

int main() {
	hightest_product(array1, 6);
	hightest_product(array2, 6);
	hightest_product(array3, 6);
	hightest_product(array4, 6);
	hightest_product(array5, 6);
	hightest_product(array6, 6);
	return 0;
}
