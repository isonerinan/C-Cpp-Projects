#include <iostream>
#include <math.h>
using namespace std;


double f(double x);
void CentralDifference(double x, double h);
void ForwardDifference(double x, double h);
void BackwardDifference(double x, double h);


double a, b;
int n;

int main()
{

    // Take input from user
    cout << "Please enter an interval [a, b] for f(x) = x^3 - 6x - 3.\na = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nPlease enter the number of points you wish to take derivative in [a, b]: ";
    cin >> n;

    // Interval between every point from a to b
    double length = (b - a) / n;

    // Use Central Difference Method to get derivative; but if the point is a, use Forward Difference Method and if the point is b, use Backward Difference Method 
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ForwardDifference(a, length);
        }

        else if (i == n - 1) {
            BackwardDifference(b, length);
        }

        else {
            CentralDifference(a + i * length, length);
        }
    }

}

// Function to be derived
double f(double x) {
    return pow(x, 3) - 6 * x - 3;
}

// f'(x) = [f(x + h) - f(x - h)] / 2h
void CentralDifference(double x, double h) {
    printf("\nf'(%f) = %f", x, (f(x + h) - f(x - h)) / (2*h));
}

// f'(x) = [f(x + h) - f(x)] / h
void ForwardDifference(double x, double h) {
    printf("\nf'(%f) = %f", x, (f(x + h) - f(x)) / h);
}

// f'(x) = [f(x) - f(x - h)] / h
void BackwardDifference(double x, double h) {
    printf("\nf'(%f) = %f", x, (f(x) - f(x - h)) / h);
}
