#include <stdio.h>
#include <time.h>

// Interval Search Method
float intervalRoot(float a);
// Newton-Raphson Formula
float newtonRoot(float a);

// This is just an easier way for me to implement f(x)
float f(float a, float x) {
	return x * x - a;
}

// This is just an easier way for me to implement f'(x)
float f_derived(float x) {
	return 2*x;
}

// Declare 4 clock variables to flag the start and finish points for our 2 different square root algorithms
clock_t t1_interval, t2_interval, t1_newton, t2_newton;

// Declare 2 variables to store the time differences between clock start-finish points
int execTimeInterval, execTimeNewton;



int main() {

	// PART 1 - USER INPUTS A NUMBER TO FIND ITS SQUARE ROOT BY THE INTERVAL METHOD
	float a = 0;
	printf("------PART1------\nPlease enter the number you want to find its square root: ");
	scanf("%f", &a);
	
	// Check if a is positive; if yes, print the result
	if (a >= 0) {

		printf("The square root of %f is: %f\n\n", a, intervalRoot(a));
		
	}

	else {
		printf("Please enter a positive number.\n");
	}

	// PART 2 - USER INPUTS A NUMBER TO FIND ITS SQUARE ROOT BY THE NEWTON-RAPHSON FORMULA
	printf("------PART1------\nPlease enter the number you want to find its square root: ");
	scanf("%f", &a);

	// Check if a is positive; if yes, print the result
	if (a >= 0) {

		printf("The square root of %f is: %f\n\n", a, newtonRoot(a));

	}

	else {
		printf("Please enter a positive number.\n");
	}

	// PART 3 - FINDING THE SQUAREROOTS OF THE FIRST 100000 INTEGERS AND COMPARING THE EXECUTION TIMES OF ALGORITHMS


	t1_interval = clock();	// Start flag for interval method
	for (int i = 1; i <= 100000; i++) {
		a = i;
		intervalRoot(a);
	}

	t2_interval = clock();	// Finish flag for interval method
	execTimeInterval = (int)(t2_interval - t1_interval);	// Interval method execution time

	t1_newton = clock();	// Start flag for Newton-Raphson method
	for (int i = 1; i <= 100000; i++) {
		a = i;
		newtonRoot(a);
	}

	t2_newton = clock();	// Finish flag for Newton-Raphson method
	execTimeNewton = (int)(t2_newton - t1_newton);	// Newton-Raphson method execution time

	// Print the execution time comparison
	printf("Interval Method time: %d\nNewton-Raphson Method time: %d\n", execTimeInterval, execTimeNewton);
}


float intervalRoot(float a) {
	// define x1, x2 and f(x)
	float x1 = 0, x2 = a;	// our first interval is (x1, x2) = (0, a). It is the greatest interval we can choose!
	float result = -1;

	while (result == -1) {
		// Divide the interval into 10 pieces
		float piece = (x2 - x1) / 10;
		
		// Add a counter for the loops
		int i = 0;

		// This is going to be the leftmost value in the interval for every loop.
		// It will start from x1 = 0, then will save x1's last value before x1 resets.
		float leftmost = x1;

		// look into the ith piece of interval (from leftmost to rightmost)
		while (i < 10) {
			x1 = leftmost + i * piece;
			x2 = x1 + piece;

			// Check if the root is in the interval
			if ((x1 * x1 - a < 0) && (x2 * x2 - a > 0)) {
				break;
			}

			// Check if the root is exactly x1
			if (x1 * x1 - a == 0) {
				result = x1;
				break;
			}

			// Check if the root is exactly x2
			if (x2 * x2 - a == 0) {
				result = x2;
				break;
			}

			// Check if the interval is smaller than 0.0001
			if (x2 - x1 <= 0.0001) {
				result = x1;
				break;
			}

			i++; // Increase the counter to move to the next piece
		}

		
	}

	return result;
}

float newtonRoot(float a) {
	float x = a;	// First estimation is a
	float lastEstimation = 0.0;
	float currentEstimation = x;

	while (1) {
		x = x - f(a, x) / f_derived(x);	// Newton-Raphson Formula is applied in a never-ending loop

		// Check if we have found the exact root; if yes, break out of the loop
		if (x * x - a == 0) {
			currentEstimation = x;
			break;
		}

		// Check if the absolute value of the difference between current and last estimations are less than 0.0001
		else if (currentEstimation - lastEstimation >= -0.0001 && currentEstimation - lastEstimation <= 0.0001) {

			// If the estimation interval is small enough, break out of the loop
			break;
		}

		// If we have not found the root and our interval is not small enough, formula's x is our current estimation
		else {
			lastEstimation = currentEstimation;
			currentEstimation = x;
		}
		
	}

	// Return the value of the current estimation
	return currentEstimation;
}