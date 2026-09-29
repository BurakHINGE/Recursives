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
        for (int i = 0; i < N; i++) {
            printf("%d ", *(table + i));
        }
    }
    else {
        printf("Çözüm bulunamadı!");
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