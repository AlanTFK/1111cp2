#include <stdio.h>
#include <stdlib.h>

typedef struct workTime{
    int times;
    int start;
    int end;
    int timeRecord;
}workTime;

int cmp(const void *c, const void *d){
    workTime* a = (workTime*)c;
    workTime* b = (workTime*)d;
    if (a->start > b->start) return 1;
    else if (a->start < b->start) return -1;
    else if (a->start == b->start) {
        if(a->end > b->end) return 1;
        else if (a->end < b->end) return -1;
    }
    return 0;
};

int main (){
    int N = 0;
    scanf_s ("%d", &N);
    workTime *workSpace;
    workSpace = malloc (sizeof(workTime) * N);
    for (int i = 0; i < N; ++i){
        int st, et;
        scanf_s ("%d%d", &st, &et);
        workSpace[i].times = et - st;
        workSpace[i].start = st;
        workSpace[i].end = et;
        workSpace[i].timeRecord = 0;
    }

    int startTime, endTime;
    scanf_s ("%d%d", &startTime, &endTime);
    qsort (workSpace, N, sizeof(workTime), cmp);
    
    int startWorkSpace = 0;
    for (int i = 0; i < N; ++i) 
        if (workSpace[i].start < startTime)
            ++startWorkSpace;

    workSpace[startWorkSpace].timeRecord = workSpace[startWorkSpace].times;

    for (int i = startWorkSpace + 1; i < N; ++i) {
        for (int j = i - 1; j >= startWorkSpace; --j) {
            if (workSpace[j].end <= workSpace[i].start) {
                if (workSpace[i].timeRecord < workSpace[j].timeRecord + workSpace[i].times)
                    workSpace[i].timeRecord = workSpace[j].timeRecord + workSpace[i].times;
            }
            else {
                if (workSpace[i].times > workSpace[i].timeRecord)
                    workSpace[i].timeRecord = workSpace[i].times;
            }
        }
    }

    int ans = 0;
    for (int i = startWorkSpace; i < N; ++i) 
        if(workSpace[i].timeRecord > ans && workSpace[i].end <= endTime)
            ans = workSpace[i].timeRecord;

/*    for (int i = startWorkSpace; i < N; ++i) {
        printf ("%d %d %d\n", workSpace[i].start, workSpace[i].end, workSpace[i].timeRecord);
    }*/
    printf ("%d\n", ans);
}
