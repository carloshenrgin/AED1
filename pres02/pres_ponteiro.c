#include <stdio.h>
#include <stdlib.h>

int main(){
    double *p, *q, *r, A[5];
    p = A;
    q = p + 1;
    r = q + 2;
    printf("&A[0] = %lu, p = &%lu", &A[0], *p); // p = &A[0] = 1234600
    printf("*r = %lf, A[3] = %lf", *r, A[3]); // *r = A[3] = 1234624
    printf("*(A+1) = %lf, *q =  %lf", A[1], *q); // *q = *(p + 1) = *(A+1) = *(1234608)
    r = p + 4;
    p = q;
    printf("p+1 = %lu, 1 ")



    return 0;
}