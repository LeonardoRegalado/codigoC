#include<stdio.h>
int main(){
    int numero = 0;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    if (numero & 1)
    {
        printf("El numero %d es impar",numero);
    }else
    {
        printf("El numero %d es par",numero);
    }
    return 0;
}