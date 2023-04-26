#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct point{
    int inte;
    struct point* next;
    struct point* pre
}point;

int main(){
    int temp = 0, n = 1;
    scanf("%d", &temp);

    point* curr;
    point head;

    curr = &head;
    curr->inte = temp;
    curr->next = NULL;
    curr->pre = NULL;

    while(scanf("%d", &temp) != EOF){
        point* tmp = malloc(sizeof(point)) ;
        tmp->inte = temp;
        tmp->pre = curr;
        tmp->next = NULL;
        curr->next = tmp;
        curr = curr->next;
        ++n;
    }

    curr->next = &head;
    curr->next->pre = curr;
    curr = curr->next;

    int tmpA = 0, m = n, arr[n];

    arr[--m] = curr->pre->inte;
    curr = curr->pre;

    do{
        tmpA += curr->inte;
        if(arr[m] > tmpA) arr[m-1] = arr[m];
        else arr[m-1] = tmpA;
        curr = curr->pre;
        --m;
    }while(curr != &head);

    int tmpB = curr->inte, tmpC = tmpA = 0, ans = 0;
    do{
        tmpC += curr->inte;
        if(tmpC <= 0) tmpC = 0;
        if(tmpC > ans) ans = tmpC;
    
        tmpA += curr->inte;
        if(m+1 < n){
            if(tmpB > (tmpA + arr[m+1])) tmpB = tmpB;
            else tmpB = tmpA + arr[m+1];
        }
        ++m;
        curr = curr->next;
    }while(curr != &head);
    
    if(ans > tmpB) ans = ans;
    else ans = tmpB;
  
    printf("%d\n" , ans);

    return 0;
}
