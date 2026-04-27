#include <stdio.h>

void clearMatrix();
void drawTriangle(int, int, int);
void generateSierpinski(int, int, int, int);
void printMatrix();

#define ROWS 32
#define COLS 63

char matrix[ROWS][COLS];

int main() {

    int iteration;
    printf("Iterasyon sayisini giriniz (0-4): ");
    scanf("%d", &iteration);

    clearMatrix();
    
    generateSierpinski(iteration, 0, 31, 32);
    
    printMatrix();

    return 0;
}


void clearMatrix() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = '_';
        }
    }
}

void drawTriangle(int r, int c, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = -i; j <= i; j++) {
            matrix[r + i][c + j] = '1';
        }
    }
}

void generateSierpinski(int n, int r, int c, int h) {

    if (n == 0) {
        drawTriangle(r, c, h);
    }
    else {

        int newH = h / 2;

        generateSierpinski(n - 1, r, c, newH);
        generateSierpinski(n - 1, r + newH, c - newH, newH);
        generateSierpinski(n - 1, r + newH, c + newH, newH);
    }
}

void printMatrix() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}