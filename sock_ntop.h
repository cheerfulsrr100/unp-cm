#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

/**
 * 网络字节序数据转换, 返回一个用户可读的格式
 *
 * @param sockaddr
 * @param addrlen
 * @return ip:port
 */
char *sock_ntop(const struct sockaddr *sockaddr, socklen_t addrlen) {
    char portstr[8];
    static char str[128];
    switch (sockaddr->sa_family) {
        case AF_INET: {
            struct sockaddr_in *sin = (struct sockaddr_in *) sockaddr;

            if (inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL) {
                return NULL;
            }
            if (ntohs(sin->sin_port) != 0) {
                snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
                strcat(str, portstr);
            }
            return str;
        }
        default:
            return NULL;
    }
}