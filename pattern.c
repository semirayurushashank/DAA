#include <stdio.h>
void printPattern(int n, int row, int col) {
    if (row > n) {
        return;
    }
    printf("%d ", col);
    if (row == col) {
        printf("\n");
        printPattern(n, row + 1, 1);
    } else {
        printPattern(n, row, col + 1);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Pattern:\n");
    printPattern(n, 1, 1);
    return 0;
}
