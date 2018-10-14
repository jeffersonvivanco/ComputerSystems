#include <stdio.h>

/*
 * The code below is for the following assembly instructions
 * x in %rdi, y in %rsi, z in %rdx
 * scale2:
 *  leaq (%rdi, %rdi, 4), %rax
 *  leaq (%rax, %rsi, 2), %rax
 *  leaq (%rax, %rdx, 8), %rax
 */

long scale2(long x, long y, long z){
	long t = 5*x + 2*y + 8*z;
	return t;
}

int main(){
	long t = scale2(1, 1, 1);
	printf("%d\n", t);
}

