#include <stdio.h>

/*
 * Your given the function prototype below. 
 * The function yields the following assembly code.
 * param xp in %rdi, yp in %rsi, zp in %rdx
 * decode:
 * 	movq (%rdi), %r8
 * 	movq (%rsi), %rcx
 * 	movq (%rdx), %rax
 * 	movq %r8, (%rsi)
 * 	movq %rcx, (%rdx)
 * 	movq %rax, (%rdi)
 * 	ret 
 *
 * Objective: Write C code for decode function that will have an effect equivalent to the assembly code above.
 */

void decode(long *xp, long *yp, long *zp);

int main() {
	long long_num = 5;
	long long_num2 = 7;
	long long_num3 = 9;
	long *xp = &long_num;
	long *yp = &long_num2;
	long *zp = &long_num3;

	decode(xp, yp, zp);
	printf("xp after decode is %d\n", *xp);
	printf("yp after decode is %d\n", *yp);
	printf("zp after decode is %d\n", *zp);
}

void decode(long *xp, long *yp, long *zp) {
	long xp_temp = *xp;
	long yp_temp = *yp;
	long zp_temp = *zp;

	*yp = xp_temp;
	*zp = yp_temp;
	*xp = zp_temp;
}
