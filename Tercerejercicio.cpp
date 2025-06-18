#include <stdio.h>

int main() {
    int numero, inverso, original;
    char respuesta;

    do {
        inverso = 0;

        printf("Ingrese un n�mero (m�ximo 5 d�gitos): ");
        scanf("%d", &numero);

        original = numero;  

        while (numero > 0) {
            int digito = numero % 10;
            inverso = inverso * 10 + digito;
            numero /= 10;     
        }

        printf("N�mero ingresado: %d\n", original);
        printf("N�mero invertido: %d\n", inverso);

        printf("�Desea ingresar otro n�mero? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
