#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse_str(const char *str)
{
	int size = strlen(str) - 1;
	int k = size;
	int i;
	char *revstr = malloc(size + 1); //memory leak

	for (i=0; i <= size; i++, k--) {
		revstr[i] = str[k];
	}

	return revstr;
}

int main(void)
{
	char *str = "hello";

	printf("*str = %s\n", str);
	printf("*str reversed = %s\n", reverse_str(str));	

	return 0;
}
