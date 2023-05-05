#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool calculate(int *arr, int n, int target) {
//    printf("%d ", target);
    if (n == -1) return false;
    else if (target == arr[n]) return true;
    else if (arr[n] > target) return calculate(arr, n - 1, target);
    else return (calculate(arr, n - 1, target - arr[n]) || calculate(arr, n - 1, target));
}

int cmp(const void* a, const void* b)
{
    int c = *(int *)a;
    int d = *(int *)b;
    if (c > d) return 1;
    else if(c < d) return -1;
    return 0;
}

int main() {
    int t = 0;
    scanf_s("%d", &t);
    for (int i = 0; i < t; ++i) {

        int target = 0, n = 0, sum = 0;
        scanf_s("%d%d", &target, &n);
        
        int* arr = malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j) {
            scanf_s("%d", &arr[j]);
            sum += arr[j];
        }
        if (sum < target) {
            printf("NO\n");
            continue;
        }
        qsort(arr, n, sizeof(int), cmp);

//        for (int j = 0; j < n; ++j) 
//            printf("%d ", arr[j]);

//        printf("===%d %d===", target ,n-1);

        if (calculate(arr, n - 1, target)) printf("YES\n");
        else printf("NO\n");
    }
}
