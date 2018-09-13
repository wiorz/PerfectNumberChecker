//ko, ivan
//Feb 06th, 2017
//input: userNum, userChar
//output: sumFac, cycle
//purpose: sum all possible dividers of a number and see if the sum equals to the number. The divider cannot be
//to the number itself, however, 1 is counted and should be added.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int userNum, factor = 2, divider = 1, sumFac= 0, cycle = 0;
	char userChar = 'y';

	printf("Enter a perfect number:");
	scanf("%d", &userNum);

	///Outer loop is for checking if user wants to continue.
	while (userChar != 'n') {
		///The max range of a number'sfactor is the square root of itself, i.e. 100/10 = 10. 
		///Therefore, we only need to find factors up to the value of the squareroot of the userNum.
		///factor starts at 2 because we always skips 1 (added back below).
		while (factor <= sqrt(userNum)) {
			if (userNum % factor == 0) {
				divider = userNum / factor;
				sumFac += factor + divider;
			}
			factor += 1;
			cycle += 1;
		}
		///Add 1 to the sum because we skipped it.
		sumFac += 1;
		if ((sumFac == userNum) && (userNum != 1)) {
			printf("Number %d is perfect\n", userNum);
		}
		else {
			printf("Number %d is not perfect\n", userNum);
		}

		printf("Number of iterations: %d\n", cycle);

		printf("Do you want to continue (y/n)?");
		scanf(" %c", &userChar);
	}

	//printf("Sum is %d", sumFac);
	printf("Goodbye\n");

	return(0);
}