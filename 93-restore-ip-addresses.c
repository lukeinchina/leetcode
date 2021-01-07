#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ResultHead {
    char **iplist;
    int size;
};

void print_ip_addr(const int *ip, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", ip[i], i+1 == 4 ? '\n' : '.');
    }
}

void append_ip_addr(const int *ip, int size, struct ResultHead *head) {
    head->iplist = (char **)realloc(head->iplist, sizeof(char *) * (1+head->size));
    head->iplist[head->size] = (char *)malloc(16);
    snprintf(head->iplist[head->size], 16, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    head->size += 1;
    return ;
}


void find_ip_addr(const char *s, int ip[], int count, struct ResultHead *head) {
    int val = 0;
    if (count >= 4) {
        if ('\0' == *s) {
            append_ip_addr(ip, count, head);
        }
        return;
    }
    for (; '\0' != *s; s++) {
        val *= 10;
        val += (*s - '0');
        if (val == 0) {
            ip[count] = val;
            return find_ip_addr(s+1, ip, count+1, head);
        } else if (val > 255) {
            break;
        }
        ip[count] = val;
        find_ip_addr(s+1, ip, count+1, head);
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int ip[4];
    struct ResultHead  head = {NULL, 0};
    int len = strlen(s);
    if (len >= 4 && len <= 12) {
        find_ip_addr(s, ip, 0, &head);
        *returnSize = head.size;
    }
    return head.iplist;
}

int
main(int argc, char *argv[]) {
    int i, size = 0;
    char **pp;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    pp = restoreIpAddresses(argv[1], &size);
    for (i = 0; i < size; i++) {
        printf("%s\n", pp[i]);
    }
    return 0;
}
