#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char *str, char sym);
void countAll(char * str);

int main() {
	char str[256];
	scanf("%[^\n]%*c", str); 
	countAll(str);
 	return 0;
}

int count(char *str, char c) {
    	int sum = 0;
    	for (int i = 0; i < strlen(str); i++) {
		if (toupper(str[i]) == toupper(c)) 
			sum++;
	}
	return sum;
}

void countAll(char *str) {
	for (int i = 0; i < strlen(str); ++i) {
		printf("%c:%d", toupper(str[i]), count(str, str[i]));
		if (i != strlen(str) - 1) printf(", ");
		else printf("\n");
	}	
}

