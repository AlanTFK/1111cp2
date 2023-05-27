#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0, b = 0;

    scanf("%d", &a);

    int *arrA = malloc(sizeof(int) * a);
    for (int i = 0; i < a; ++i) 
        scanf("%d", &arrA[i]);

    scanf("%d", &b);

    int *arrB = malloc(sizeof(int) * b);
    for (int i = 0; i < b ; ++i)
        scanf("%d", &arrB[i]);

/*    for (int i = 0; i < a ; ++i)
        printf("%d ", arrA[i]);
    printf("\n");

    for (int i = 0; i < b ; ++i)
        printf("%d ", arrB[i]);
    printf("\n");
*/
    int tmpA = 0, tmpB = 0; 
    for (;tmpA < a && tmpB < b;) {
        if (arrA[tmpA] < arrB[tmpB])
            printf("%d ", arrA[tmpA++]);
        else printf("%d ", arrB[tmpB++]);
    }

    if (tmpA == a) for (;tmpB < b;) printf("%d ", arrB[tmpB++]);
    else for (;tmpA < a;) printf("%d ", arrA[tmpA++]);

    return 0;
}
