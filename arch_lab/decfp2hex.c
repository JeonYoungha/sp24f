#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char* pointer;

bool is64bit() {
    return sizeof(double) == 8;  
}

bool isBigEndian(){
    unsigned int x = 1;
    return (*(char*)&x) == 0;  
}

void show_bytes(double num) {
    unsigned long long int_rep; // double이 64 비트이므로 unsigned long long 을 이용하여 64비트 그대로 데이터 손실 없이 가져온다.
    memcpy(&int_rep, &num, sizeof(double));

    char hexDigits[] = "0123456789ABCDEF";
    char hex[17];
    hex[16] = '\0';

    for (int i = 0; i < 16; ++i) {
        hex[i] = hexDigits[(int_rep >> (60 - i * 4)) & 0xF];
    }

    printf("%s\n", hex);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out number\n");
        exit(0);
    }

    double a = atof(argv[1]);

    printf("ARCH=%d\n", is64bit()? 64 : 32);
    printf("ORDERING=%s\n", isBigEndian()? "BIG_ENDIAN": "LITTLE_ENDIAN");

    printf("MYANS: DEC=%.10g HEX=", a);  // 10자리까지 표시
    show_bytes(a);  // double 값을 16진수로 변환

    return 0;
}