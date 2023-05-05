#include <stdio.h>
#include <stdlib.h>
int minN(int a,int b) {
    return (a < b ? a : b);
}
int initSquareArr(int *squareArr, int n) {
    int maxNum = 3;
    for (int i = 0; i < n; ++i) {
        squareArr[i] = i * i;
        if (i * i > n) {
            if (i > maxNum)
                maxNum = i;
            break;
        }
    }
    return maxNum;
}

int* createDP(int n) {
    int *DP = malloc(sizeof(int) * (n + 1));
    for (int j = 0; j < (n+1); ++j)
        DP[j] = 10000000;
    DP[0] = 0;
    return DP;
}

void printArr(int* DP, int n) {
    for (int j = 0; j < (n+1); ++j)
        printf("%d ", DP[j]);
    printf("\n");   
}

int main() {
    int n = 0;
    scanf_s("%d", &n);
    
    int squareArr[1000 + 1] = {};
    int maxNum = initSquareArr(squareArr, n);

    int *DP = createDP(n);

    for (int i = 1; i < maxNum; ++i) {
        for (int j = squareArr[i]; j < n + 1; ++j) {
            DP[j] = minN(DP[j - squareArr[i]] + 1 , DP[j]);
        }
    }
    printf("%d\n", DP[n]);
    free(DP);
    return 0;
}
