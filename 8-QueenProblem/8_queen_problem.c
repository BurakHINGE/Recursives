#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isSafe(int*, int, int);
int placeQueens(int *, int, int);

int main() {
    
    int N;

    printf("Enter the size of table: \n");
    scanf("%d", &N);

    int *table = (int*)(malloc(N * sizeof(int)));

    if (placeQueens(table, 0, N)) {

        printf("\n1D Array View:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", *(table + i));
        }
        printf("\n\n");

        printf("2D Table View:\n");
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (table[col] == row) {
                    printf("Q ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
    }
    else {
        printf("Cozum bulunamadi!\n");
    }

    printf("\n");
    free(table);

    return 0;
}

int isSafe(int* queens, int row, int col) {

    for (int i = 0; i < col; i++) {
        if (queens[i] == row) {
            return 0;
        }
        if (abs(queens[i] - row) == abs(i - col)) {
            return 0;
        }
    }

    return 1;
}

int placeQueens(int *queens, int col, int N) {

    if (col == N) {
        return 1;
    }
    else {
        for (int i = 0; i < N; i++) {
            if (isSafe(queens, i, col)) {
                queens[col] = i;
            
                if (placeQueens(queens, col + 1, N) == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }
}