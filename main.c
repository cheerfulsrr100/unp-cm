#include <stdio.h>
#include "sock_ntop.h"
#include <netinet/in.h>

int main() {

    struct sockaddr_in sock_test = {
            .sin_port = htons(56789),
            .sin_family = AF_INET
    };
    inet_pton(AF_INET, "127.0.0.1", &sock_test.sin_addr);

    printf("%lu\n", sizeof(char));

    char *t = sock_ntop((struct sockaddr *) &sock_test, NULL);
    printf("%s", t);

    return 0;
}
