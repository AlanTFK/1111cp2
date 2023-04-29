#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    int* c = (int*) a;
    int* d = (int*) b;
    if (*c > *d) return 1;
    else if (*c < *d) return -1;
    return 0;
}

int main(){
    int t = 0;
    scanf_s("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n = 0;
        scanf_s("%d", &n);

        int* arr = malloc(sizeof(int) * n);

        for (int j = 0; j < n; ++j)
            scanf_s("%d", &arr[j]);

        qsort(arr, n, sizeof(int), cmp);  //排小到大

        //calloc是一樣陣列但裏面的數字都是0，malloc不一定是0
        int* dpSample = calloc(200000,sizeof(int));     
        bool flag = true;
        int z = 0, sum = 0;

        for (int j = 0; j < n && flag; ++j) {       //只要一false就跳出來

            int tmp = arr[j];                       //從最小的開始
            flag = false;                           
            
            if (tmp == 1) {                         //只要為1都可以加進來
                dpSample[z++] = tmp;
                sum += tmp;                         //目前dpSample[]全部加起來能達到的數字
                flag = true;                        //有加東西就是OK的
            }
            else {
                int tmpSum = sum;                   
                for (int k = 0; k < z; ++k) {
                    if (tmpSum < tmp) break;        //如果arr[j]大於我全部加起來的數字就錯了
                    else if (tmpSum == tmp) {       //如果arr[j]剛好等於我全部加起來就可以加進來
                        dpSample[z++] = tmp;
                        sum += tmp;
                        flag = true;
                        break;
                    } else if (tmpSum -= dpSample[k] == tmp) {  //如果arr[j]小於我全部加起來的數字，就從dpSample最小的開始減
                            dpSample[z++] = tmp;
                            sum += tmp;
                            flag = true;
                            break;
                            }
                }
            }
        }

        if (flag) printf("YES\n");
        else printf("NO\n");
        free(dpSample);
        free(arr);
    }
    return 0;
}
