#include <stdio.h>
#include <string.h>

int main() {
    char path[3333] = {0};
    char* stack[3333];
    int k = 0, l = 0;

    while (scanf("%c", &path[k++]) != EOF);      //接收字串

//    for (int i = 0; i < k; ++i)       //檢查字串，會多出\n和\0
//        printf("%c", path[i]);
    
    char *tmp = strtok(path, "/");      //用‘/’分割字串，tmp是分割出來的字串

    while (tmp != NULL) {

        if (!strcmp(tmp, ".") || !strcmp(tmp, ".\n") || !strcmp(tmp, "\n"));
        else if (!strcmp(tmp, "..") || !strcmp(tmp, "..\n")) {
            if (l - 1 < 0) l = 0;       //如果減一小於0就不要減一
            else --l;
        }
        else stack[l++] = tmp;
        tmp = strtok(NULL, "/");        //NULL表示繼續分割上一次分割的字串
    }
    if (!l) printf("/");
    for (int i = 0; i < l; ++i)
        printf("/%s", stack[i]);
}
