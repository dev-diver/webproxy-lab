#include "csapp.h"

void echo(int connfd) {
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE) != 0)) {
        printf("%d byte를 받았습니다\n", (int)n);
        Rio_written(connfd, buf, n);
    }
}