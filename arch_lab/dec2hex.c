#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char* pointer;

bool is64bit()
{
    return true;
}

bool isBigEndian(){
    return true;
}

void le_show_bytes(unsigned int num)
{
    char hexDigits[] = "0123456789ABCDEF";
    char hex[9];
    hex[8] = '\0';  

    for (int i = 0; i < 8; ++i) {
        hex[i] = hexDigits[(num >> (28 - i * 4)) & 0xF];
    }
    printf("%s\n", hex);  
}

void be_show_bytes(unsigned int num)
{
    char hexDigits[] = "0123456789ABCDEF";
    char hex[9];
    hex[8] = '\0'; 

    for (int i = 0; i < 8; ++i) {
        hex[i] = hexDigits[(num >> (28 - i * 4)) & 0xF];
    }
    printf("%s\n", hex);  
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: ./a.out number\n");
        exit(0);
    }
    unsigned int a = atoi(argv[1]);

    printf("ARCH=%d\n", is64bit()? 64 : 32);
    printf("ORDERING=%s\n", isBigEndian()? "BIG_ENDIAN": "LITTLE_ENDIAN");

    printf("MYANS: DEC=%d HEX=", a);
    isBigEndian() ? be_show_bytes(a) : le_show_bytes(a);

    printf("CHECK: DEC=%d HEX=%.8X\n", a, a); 
    return 0;
}