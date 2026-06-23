#include <stdio.h>

int fibonacciFunc(int, int, int, int);

int main() {

    int numberOfCounts;

    printf("Enter your digit amount: \n");
    scanf("%d", &numberOfCounts);

    int result = fibonacciFunc(numberOfCounts, 0, 1, 1);

    printf("Fibonacci sum is: %d\n", result);
}

int fibonacciFunc(int numberCounts, int pre, int current, int count) {

    if (count == numberCounts) {
        return current;
    }
    else {
        return fibonacciFunc(numberCounts, current, pre + current, count + 1);
    }
}