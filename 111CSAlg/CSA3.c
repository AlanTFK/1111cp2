#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ans = 0;
int count = 0;      //目前的面積編號

typedef struct mine{
    int num;        //面積編號
    int isIron;     //是否鉄
    bool marked;    //是否走過
}mine;

mine** create2DArray(int x, int y){
    mine **arr = (mine **)malloc(y * sizeof(mine*) + x * y * sizeof(mine));
    mine *tmp = (mine*) (arr + y);

    for (int i = 0; i < y; ++i, tmp += x)
        arr[i] = tmp;

    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j){
            arr[i][j].isIron = -1;
            arr[i][j].marked = false;
            arr[i][j].num = -1;
        }

    return arr;
}

void print2DArray(mine** arr, int x, int y){
    for (int i = 0; i < y; ++i){
        for (int j = 0; j < x; ++j)
            printf("%d ", arr[i][j].isIron);
        printf("\n");
    }
}

void marked(mine** arr, int i, int j){
    arr[i][j].marked = true;                    //先marked
    arr[i][j].num = count;                      //給予面積編號
    
    //如果沒有marked且是同種礦
    if (arr[i][j+1].marked == false && arr[i][j+1].isIron == arr[i][j].isIron)      //右 
        marked(arr, i, j+1);

    if (arr[i+1][j].marked == false && arr[i+1][j].isIron == arr[i][j].isIron)      //下
        marked(arr, i+1, j);

    if (arr[i][j-1].marked == false && arr[i][j-1].isIron == arr[i][j].isIron)      //左
        marked(arr, i, j-1);

    if (arr[i-1][j].marked == false && arr[i-1][j].isIron == arr[i][j].isIron)      //上
        marked(arr, i-1, j);
}

void calculate(mine** arr, int x, int y){       //計算答案

    for (int i = 1; i < y - 1; ++i)
        for (int j = 1; j < x - 1; ++j)
            if(arr[i][j].marked == false){
                marked(arr, i, j);              //開始marked，這一列就會把一塊面積做完了
                ++count;                        //一塊面積做完，面積編號+1
            }

    int* bucket = malloc(count * sizeof(int));  //水桶的大小是 面積編號的大小+1
    
    for (int i = 0;i < count; ++i)
        bucket[i] = 0;

    for (int i = 1; i < y - 1; ++i)
        for (int j = 1; j < x - 1; ++j)
            if (arr[i][j].num != -1)
                ++bucket[arr[i][j].num];

    for (int i = 0;i < count; ++i)
        if (bucket[i] > ans)
            ans = bucket[i];
}

int main(){         //主程式
    int x = 0, y = 0;
    scanf_s("%d%d", &y, &x);

    mine **arr = create2DArray(x + 2, y + 2);   //新增一個有外圍的陣列
    
    for (int i = 1; i < y + 1; ++i)
        for (int j = 1; j < x + 1; ++j)
            scanf_s("%d", &arr[i][j].isIron);   //scanf看不懂我也是不懂了

    calculate(arr, x + 2, y + 2);               //計算答案

    //print2DArray(arr, x + 2, y + 2);          //檢查陣列

    free(arr);                                  //malloc就要free

    printf("%d\n", ans);

    return 0;
}
