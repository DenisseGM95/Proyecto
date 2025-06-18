#include <stdio.h>

int main() {
    int numero, inverso, original;
    char respuesta;

    do {
        inverso = 0;

        printf("Ingrese un número (máximo 5 dígitos): ");
        scanf("%d", &numero);

        original = numero;  

        while (numero > 0) {
            int digito = numero % 10;
            inverso = inverso * 10 + digito;
            numero /= 10;     
        }

        printf("Número ingresado: %d\n", original);
        printf("Número invertido: %d\n", inverso);

        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
