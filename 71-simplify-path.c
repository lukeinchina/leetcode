#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * simplifyPath(char * path){
    int len = strlen(path);
    char *stack = (char *)malloc(len+1);
    const char *p   = NULL;
    int top = 0;
    if (len > 0) {
        stack[top++] = *path++;
    }
    while ('\0' != *path) {
        while ('/' == *path) {
            path++;
        }
        p = path;
        while ('\0' != *path && '/' != *path) {
            path++;
        }
        if (path - p == 2 && strncmp(p, "..", 2) == 0) {
            /* pop one path */
            top--;
            while (top > 0 && '/' != stack[top-1]) {
                top--;
            }
            top += (top == 0 ? 1 : 0);
            continue;
        } else if ((path - p == 1) && ('.' == *p)) {
            /* skip */
            continue;
        }
            /* push */
        if ('/' == *path) {
            path++;
        }
        while (p < path) {
            stack[top++] = *p++;
        }
    }
    stack[top] = '\0';
    if (top > 1 && stack[top-1] == '/') {
        stack[top-1] = '\0';
    }
    return stack;
}

int
main(int argc, char *argv[]) {
    char *path;
    if (argc < 2) {
        printf("usage:%s path\n", argv[0]);
        return 1;
    }
    path = simplifyPath(argv[1]);
    printf("%s\n", path);
    return 0;
}
