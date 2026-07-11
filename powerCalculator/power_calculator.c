#include <stdio.h>

long calcPower(int, int);

int main() {

    int number, power;

    printf("Enter the base number: \n");
    scanf("%d", &number);
    printf("Enter the power: \n");
    scanf("%d", &power);

    if (power == 0) {
        printf("%d power %d = 1\n", number, power);
    }
    else {
        printf("%d power %d = %ld\n", number, power, calcPower(number, power));
    }

    return 0;
}

long calcPower(int base, int power) {

    if (power == 1) {
        return base;
    }
    else {
        return base * calcPower(base, power - 1);
    }
}