#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_str(const char *str, int size, char *revstr)
{
        int k = size;
        int i;

        for (i=0; i <= size; i++, k--) {
                revstr[i] = str[k];
        }
}

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("usage: ./reversestr string\n");
                exit(1);
        }

        char *str1 = argv[1];
        int size = strlen(str1) - 1;
        char *str2 = malloc(size + 1);

        reverse_str(str1, size, str2);

        printf("str1 = %s\n", str1);
        printf("str1 reversed = %s\n", str2);

        free(str2);

        return 0;
}

