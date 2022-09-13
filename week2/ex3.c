#include <stdio.h>

int convert(int n, int src, int trgt);

int main() {
    int n, src, trgt;
    scanf("%d %i %i", &n, &src, &trgt);
    if(!convert(n, src, trgt))
    	printf("cannot convert!");
    printf("\n"); 	
}

int convert(int n, int src, int trgt) {
    if (src < 2 || src > 10 || trgt < 2 || trgt > 10)
    	return 0;
    
    char result[64];
    int d = 0, len = 0;
    
    for (int pwr = 1; n > 0; ) {
        d += (n % 10) * pwr;
        pwr *= src;
        n /= 10;
    }
   
    n = d;
    
    for (int i = 0; n != 0; i++) {
        result[i] = n % trgt + '0';
        n /= trgt;
        ++len;
    }
    
    for (int i = len ; i > 0; i--) 
    	printf("%c", result[i - 1]);
    
    return 1;
}
