#include <stdio.h>

unsigned long long Trib(unsigned short n);
void printTrib(unsigned short n);

void main() {
	printTrib(4);
	printTrib(36);
}

unsigned long long Trib(unsigned short n) {
	if (n == 0) return 0;
	if (1 <= n && n <= 2) return 1;
	return Trib(n - 1) + Trib(n - 2) + Trib(n - 3);
}

void printTrib(unsigned short n) {
    for (int i = 0; i < n; i++) {
    	printf("%lld", Trib(i));
    	if (i != n - 1) printf(", ");
    	else printf("\n");
    }
    
}

