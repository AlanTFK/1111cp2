#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct point{
    int inte;
    bool conflict;
    struct point* next;
}point;

int main(){
    int temp = 0, n = 1;
    scanf("%d", &temp);

    point* curr;
    point head;
    
    curr = &head;
    head.inte = temp;
    head.conflict = false;
    head.next = NULL;

    while(scanf("%d", &temp) != EOF){
        point* tmp = malloc(sizeof(point)) ;
        tmp->inte = temp;
        tmp->conflict = false;
        tmp->next = NULL;
        curr->next = tmp;
        curr = curr->next;
        ++n;
    }

    curr->next = &head;
    curr = curr->next;

    /*do{
        printf("%d ", curr->inte);
        curr = curr->next;
    }while(curr != &head);
    */
    int tmpA = 0, tmpC = 0, ans = 0, m = 0;
    do{
        if(curr->inte >= 0){
            tmpA += curr->inte;
            if(tmpA > ans)
                ans = tmpA;
        }
        else tmpA = 0;

        tmpC += curr->inte;
        if(tmpC < 1) tmpC = 0;
        if(tmpC > ans) ans = tmpC;

        curr = curr->next;
        ++n;
    }while(curr != &head);
    
    do{
        if(curr->inte >= 0){
            tmpA += curr->inte;
            if(tmpA > ans)
                ans = tmpA;
        }
        else tmpA = 0;

        tmpC += curr->inte;
        if(tmpC < 1) tmpC = 0;
        if(tmpC > ans) ans = tmpC;

        curr = curr->next;
        m++;
    }while(n/2 != m);
    printf("%d" , ans);
    
    return 0; 
}
