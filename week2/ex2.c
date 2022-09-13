#include <stdio.h>
#include <string.h>

void main() {
	char str[256];
	scanf("%[^.]%*c", str); 
	for(int i = strlen(str); i >= 0; i--)
		printf("%c", str[i]);
	printf("\n");	
	return 0;
}

