#include <stdio.h>

double calculateWeightBackR(int, int);

int main() {

    int row, col;

    printf("Enter id: \n");
    scanf("%d %d", &row, &col);

    printf("%f\n", calculateWeightBackR(row, col));

}

double calculateWeightBackR(int row, int col) {

    double weight = 80.0;

    if (col < 0 || col > row) {
        return 0.0;
    }

    if (row == 0) {
        return 0.0;
    }

    double from_left = 0;
    if (col > 0) {
        from_left = (calculateWeightBackR(row-1, col-1) + weight) / 2.0;
    }

    double from_right = 0;
    if (col < row) {
        from_right = (calculateWeightBackR(row-1, col) + weight) / 2.0;
    }

    return from_left + from_right;
}