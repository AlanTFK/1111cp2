#include<stdio.h>
#include<stdlib.h>

#define int long long
typedef struct mine{
    int u;
    int zn;
}mine;

typedef struct product{
    int uNum;
    int znNum;
    int price;
}product;

int main(){
    int mineNum = 0, productNum = 0;
    scanf_s("%d%d", &mineNum, &productNum);
    
    mine* ms = malloc(sizeof(mine) * mineNum);
    product* ps = malloc(sizeof(product) * productNum);
    
    for (int i = 0; i < mineNum; ++i)
        scanf_s("%lld%lld", &ms[i].u, &ms[i].zn);
        
    for (int i = 0; i < productNum; ++i)
        scanf_s("%lld%lld%lld", &ps[i].uNum, &ps[i].znNum, &ps[i].price);
/*
    for (int i = 0; i < mineNum; ++i)
        printf("%lld %lld\n", ms[i].u, ms[i].zn);
     
    for (int i = 0; i < productNum; ++i)
        printf("%lld%lld%lld", ps[i].uNum, ps[i].znNum, ps[i].price);
*/

    int maxPrice = 0, tmpPrice = 0, productionNum = 0, tmpAPNum = 0, tmpBPNum = 0;

    for (int i = 0; i < mineNum - 1; ++i) 
        for (int j = i + 1; j < mineNum; ++j)
            for (int k = 0; k < productNum; ++k) {

                tmpAPNum = (ms[i].u/ps[k].uNum > ms[j].zn/ps[k].znNum ? ms[j].zn/ps[k].znNum : ms[i].u/ps[k].uNum);
                tmpBPNum = (ms[i].zn/ps[k].znNum > ms[j].u/ps[k].uNum ? ms[j].u/ps[k].uNum : ms[i].zn/ps[k].znNum);
                productionNum = (tmpAPNum > tmpBPNum ? tmpAPNum : tmpBPNum);

                tmpPrice = productionNum * ps[k].price * (92 * ps[k].uNum + 30 * ps[k].znNum);

                /*printf("tmpAPNum: %lld %lld === ", ms[i].u/ps[k].uNum, ms[j].zn/ps[k].znNum);
                printf("tmpBPNum: %lld %lld ", ms[j].u/ps[k].uNum, ms[i].zn/ps[k].znNum);
                printf("production: %lld %lld %lld\n", ps[k].uNum, ps[k].znNum, ps[k].price);
                printf("===%lld %lld %lld %lld\n\n", tmpAPNum, tmpBPNum, productionNum, tmpPrice);
                */
                if (tmpPrice > maxPrice) maxPrice = tmpPrice;

            }

    printf("%lld\n", maxPrice);
    return 0;
}
