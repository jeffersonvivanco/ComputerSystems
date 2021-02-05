#include <arpa/inet.h>

struct in_addr {
    uint32_t s_addr; // address in network byte order (big-endian)
};

// converts an unsigned 32-bit integer from host byte order to network byte order
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort); // returns value in network byte order

uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort); // returns value in host byte order

// "n" stands for network, "p" stands for presentation
// they can manipulate either 32-bit IPv4 addresses AF_INET or
// 128-bit IPv6 addresses AF_INET6
// converts a dotted-decimal string (src) to a binary IP address in network byte order (dst)
int inet_pton(AF_INET, const char *src, void *dst); // returns 1 if OK, 0 if src is invalid, -1 on error
// converts a binary IP addresss in network byte order (src) to the corresponding dotted
// decimal representation and copies the most size bytes of the resulting null-terminated string to dst
const char *inet_ntop(AF_INET, const void *src, char *dst), socklen_t size);
// returns pointer to a dotted-decimal string if OK, NULL on error