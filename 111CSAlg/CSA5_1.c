#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct city{
    int SN;
    int neighbourNum;
    struct city* neighbour[1000];
    bool marked;
}city ;

void mark(city* const thisCity, const city* const preCity, bool* circle) {
    thisCity->marked = true;
//    printf("%d is marked! %d\n", thisCity->SN, thisCity->neighbourNum);
    for (int i = 0; i < thisCity->neighbourNum; ++i) {
        if (!thisCity->neighbour[i]->marked) 
            mark(thisCity->neighbour[i], thisCity, circle);
        else if (thisCity->neighbour[i] != preCity) {
            *circle = true;
        }
    }
}

int main() {

    int cityNum = 0;
    scanf("%d", &cityNum);
    city* vertexArr = malloc(sizeof(city) * cityNum);
    for (int i = 0; i < cityNum; ++i) {
        vertexArr[i].SN = i+1;
        vertexArr[i].neighbourNum = 0;
        vertexArr->marked = false;
    }

    int currCity, connectedCity;
    char tmpC = ' ';

    for (int i = 0; i < cityNum; ++i) {
        scanf("%d%c", &currCity, &tmpC);
        if(i != cityNum-1)
            while (tmpC != '\n') {
                scanf("%d%c", &connectedCity, &tmpC);
                vertexArr[currCity-1].neighbour[(vertexArr[currCity-1].neighbourNum)++] = &vertexArr[connectedCity-1];
            }
        else if(i == cityNum-1)
            while (scanf("%d", &connectedCity) != EOF) 
                vertexArr[currCity-1].neighbour[(vertexArr[currCity-1].neighbourNum)++] = &vertexArr[connectedCity-1];
    }

    int lonelyCityNum = 0;
    bool circle = false;
    for (int i = 0; i < cityNum; ++i) {
        if (!vertexArr[i].marked) {
            mark(&vertexArr[i], &vertexArr[i], &circle);
            ++lonelyCityNum;
        }
    }

/*    for(int i = 0; i < cityNum; ++i) {
        printf("%d ", vertexArr[i].SN);
        for (int j = 0; j < vertexArr[i].neighbourNum; ++j) 
            printf("%d ", vertexArr[i].neighbour[j]->SN);
        printf("%d", vertexArr[i].neighbourNum);
        printf("\n");
    }
*/
    if (circle) printf("%d %d\n", lonelyCityNum-1, 1);
    else printf("%d %d\n", lonelyCityNum-1, 0);
    return 0;
}

