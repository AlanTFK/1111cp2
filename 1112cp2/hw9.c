#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int weight;
    char name[1000];
    struct node *next;
} node;

node* createNode(char t_name[1000], int t_weight) {
    node* newNode =  malloc(sizeof(node));
    strcpy(newNode->name, t_name);
    newNode->weight = t_weight;
    newNode->next = NULL;
    return newNode;
}

void useLift(node *head) {
    node *stack[8];         //電梯上限為8
    node *queue;            //排隊人數為8
    queue = head;           //第一個人先排隊
    int queNum = 1, staNum = 0, liftKG = 0;     //排隊人數，電梯人數，電梯重量
    while (head) {      //如果head不是NULL

        for (; queNum < 8 && queue->next != NULL; ++queNum) //排隊直到8個人或者沒有需要排隊的人
            queue = queue->next;

        while (queNum > 0) {        //排隊人數大於0
            liftKG += head->weight;     //隊伍的第一人上電梯
            if (liftKG <= 400) {        //如果沒超過400KG
                stack[staNum++] = head;     //確實進入電梯
                head = head->next;          //隊伍的第一人換人，如果為list(不是queue)的最後一人，此時會head=NULL
                --queNum;                   //隊伍減少一人
            }
            else  {                         //如果超過400KG
                if(head->next == NULL) break;   //如果head是最後一人，還繼續做下面那一套動作的話，他就會這樣https://reurl.cc/eDE2z7
                node *tmp = head;           //此人去隊伍的最後一位
                head = head->next;
                tmp->next = queue->next;
                queue->next = tmp;
                queue = queue->next;
                break;                  //到達上限，不再讓人進入電梯
            }
        }
        while (staNum > 0) {    //電梯人數大於0
            --staNum;           //電梯人數減1
            printf("%s ", stack[staNum]->name);     //印出名字
            free(stack[staNum]);                    //此人沒用了
            stack[staNum] = NULL;                   //初始化
        }
        liftKG = 0;
        printf("\n");       //電梯出完人就換行
    }
    printf("\n");
}
int main() {
    char a[1000];
    int tmpWeight = 0;
    node *listHead = NULL, *listCurr = NULL;

    while(scanf("%s", a) != EOF){       //輸入字串直到EndOfFile
        if(strcmp(a, "-1")){            //如果不是-1
            scanf("%d", &tmpWeight);    //輸入體重

            node *tmp = createNode(a, tmpWeight);       //增加點

            if(listHead == NULL) listCurr = listHead = tmp;  //一開始head為NULL，初始化
            else {
                listCurr->next = tmp;           //最後的點連接新的點
                listCurr = listCurr->next;      //新的點變成最後的點
            }
        }
        else {  //如果是-1
            useLift(listHead);  //執行電梯
            listHead = listCurr = NULL;    //初始化
        }
    }
    return 0;
}
