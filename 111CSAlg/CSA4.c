#include <stdio.h>
#include <stdlib.h>

typedef struct mood{
    int head;
    int tail;
}mood;

int cmp (const void *a, const void *b){
    mood c = *(mood*)a;
    mood d = *(mood*)b;
    if (c.head > d.head) return 1;
    else if (c.head < d.head) return -1;
    else if (c.tail > d.tail) return -1;
    else if (c.tail < d.tail) return 1;
    return 0;
}

int main(){
    int n = 0; scanf_s("%d", &n);
    mood *arr = malloc(sizeof(mood) * n);
    mood start, end, tmp;

    for (int i = 0; i < n; ++i) {
        scanf_s("%d%d", &arr[i].head, &arr[i].tail);
        if (i == 0) tmp = start = arr[i];
        if (i == n-1) end = arr[i];
    }

    qsort(arr, n, sizeof(mood), cmp);
//    for (int i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].head, arr[i].tail);

    int tmpMaxTail = start.tail, count = 0;
    for (int i = 0; i < n; ++i) {
//        printf(" || %d", count);
        if (arr[i].head >= tmp.tail) {
            tmp.head = tmp.tail;
            tmp.tail = tmpMaxTail;
            ++count;
        }
        if (arr[i].head >= tmp.head && arr[i].head < tmp.tail)
            if (arr[i].tail > tmpMaxTail) tmpMaxTail = arr[i].tail;
        if (tmpMaxTail > end.head) {
            if (i==0) {
                count++;
                break;
            }
            count+=2;
            break;
        }
    }
    printf("%d", count);
}
