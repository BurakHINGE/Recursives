#include <stdio.h>

double calculateWeightBackR(int, int);
double calculateWeightBackI(int, int);

int main() {

    int row, col;

    printf("Enter id: \n");
    scanf("%d %d", &row, &col);

    printf("%f\n", calculateWeightBackR(row, col));
    printf("%f\n", calculateWeightBackI(row, col));

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

double calculateWeightBackI(int row, int col) {
    if (row == 0) return 0.0; 

    double weights[31][31] = {0.0};
    
    weights[0][0] = 80.0;

    for (int r = 1; r <= row; r++) {
        for (int c = 0; c <= r; c++) {
            if (c > 0) {
                weights[r][c] += weights[r-1][c-1] / 2.0;
            }
            if (c < r) {
                weights[r][c] += weights[r-1][c] / 2.0;
            }
            
            if (r < row) {
                weights[r][c] += 80.0;
            }
        }
    }
    return weights[row][col];
}