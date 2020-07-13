#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void add(uint8_t buf1[], uint8_t buf2[]) {
    uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
    uint32_t n1 = ntohl(*p1);

    uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
    uint32_t n2 = ntohl(*p2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

int main(int argc, char *argv[]) {
    if(argc <= 2){
        printf("syntax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin c.bin \n");
        return 0;
    }
    uint8_t buffer1[32], buffer2[32]; 
    FILE *f1, *f2;
    f1 = fopen(argv[1], "rb"); f2 = fopen(argv[2], "rb");
    fread(buffer1, 1, 32, f1); fread(buffer2, 1, 32, f2);

    add(buffer1, buffer2);
    fclose(f1); fclose(f2);
}
