#include <stdio.h>
#include <string.h>

void main() {
	char str[256];
	scanf("%[^,.]", &str); 
	for(int i = strlen(str); i >= 0; i--) {
		printf("%c", str[i]);
	}

}
