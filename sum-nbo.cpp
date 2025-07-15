#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int avgc, char* avg[]) {
    uint32_t sum = 0;
    
    if (avgc < 2) {
        printf("syntax : sum-nbo <file1> [<file2>...]");
        return 1;
    } else {
        for (int i = 1; i < avgc; ++i) {
            uint32_t num;
            FILE *file = fopen(avg[i], "rb");
            fread(&num, 4, 1, file);
            fclose(file);

            printf("%d(0x%08x)", htonl(num), htonl(num));
            
            if (i != avgc - 1) {
                printf(" + ");
            }
            sum += htonl(num);
        }
    }

    printf("= %d(0x%08x)", sum, sum);

    return 0;
}