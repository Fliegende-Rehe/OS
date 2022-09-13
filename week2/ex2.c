#include <stdio.h>
#include <string.h>

void main() {
	char str[256];
	printf("Enter string: ");
	scanf("%[^,.]", &str); 
	printf("Result: ");
	for(int i = strlen(str); i >= 0; i--)
		printf("%c", str[i]);
	printf("\n");	
}

