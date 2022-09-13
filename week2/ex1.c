#include <stdio.h>
#include <limits.h>
#include <float.h>

void main() {
	int i = INT_MAX;
	unsigned short us = USHRT_MAX;
	long l = LONG_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	
	printf("%zu	%d\n", sizeof(i), i);
	printf("%zu	%d\n", sizeof(us), us);
	printf("%zu	%ld\n", sizeof(l), l);
	printf("%zu	%f\n", sizeof(f), f);
	printf("%zu	%f\n", sizeof(d), d);
}

