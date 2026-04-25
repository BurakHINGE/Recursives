#include <stdio.h>

int sumOfDigits(int, int); //prototype 

int main() {
    int number;

    printf("Enter your number: \n");
    scanf("%d", &number);

    printf("Sum of digits of your number is: %d\n", sumOfDigits(number, 0));

}

int sumOfDigits(int num, int sum) { //recursive function

    if (num == 0) {
        return num + sum;
    } 
    else {
        sum += num % 10;
        return sumOfDigits(num / 10, sum);
    }
}