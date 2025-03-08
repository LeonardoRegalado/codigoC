#include <stdio.h>
int main(void) {
	char letra = 0;
    unsigned char contador = 0, i= 0;
	printf("Ingrese un número: ");
    scanf("%c", &letra);

    for (i = 0; i < 8; i++)
    {
        if ((letra >> i) & 1)
        {
            contador++;
        }
        
    }
    printf("Hay %u bits encendidos",contador);
    
}