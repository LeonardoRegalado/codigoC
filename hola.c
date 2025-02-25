#include <stdio.h>



int main() {
    char num= 1;
    
    unsigned char num_unsigned = 1;  
    int num_int = 1;
    int arreglo[] =  {10, 20, 30, 40, 50};
    
    printf("%p , %p, %p \n",&num, &num_unsigned,&num_int);
    printf("%p",&arreglo);
}