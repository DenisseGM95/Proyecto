#include <stdio.h> 

bool primo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0)
            return false;
    }
    return true;
}

int main() {
    char continuar;

    do {
        int n;
        printf("�Cu�ntos n�meros desea validar? ");
        scanf("%d", &n);

        int mayor = -1;
        int posicionMayor = -1;

        int sumaPrimos = 0, sumaNoPrimos = 0;
        int cuentaPrimos = 0, cuentaNoPrimos = 0;

        for (int i = 0; i < n; ++i) {
            int numero;
            printf("Ingresa el n�mero %d: ", i + 1);
            scanf("%d", &numero);

            if (primo(numero)) {
                printf("%d es un n�mero primo.\n", numero);
                sumaPrimos += numero;
                cuentaPrimos++;
            } else {
                printf("%d no es un n�mero primo.\n", numero);
                sumaNoPrimos += numero;
                cuentaNoPrimos++;
            }

            if (i == 0 || numero > mayor) {
                mayor = numero;
                posicionMayor = i + 1;
            }
        }

        printf("\n--- Resultados ---\n");
        printf("N�mero mayor: %d\n", mayor);
        printf("Posici�n en que fue ingresado: %d\n", posicionMayor);

        printf("\nCantidad de n�meros primos: %d\n", cuentaPrimos);
        printf("Suma de n�meros primos: %d\n", sumaPrimos);
        if (cuentaPrimos > 0)
            printf("Promedio de n�meros primos: %.2f\n", (float)sumaPrimos / cuentaPrimos);
        else
            printf("Promedio de n�meros primos: N/A\n");

        printf("\nCantidad de n�meros no primos: %d\n", cuentaNoPrimos);
        printf("Suma de n�meros no primos: %d\n", sumaNoPrimos);
        if (cuentaNoPrimos > 0)
            printf("Promedio de n�meros no primos: %.2f\n", (float)sumaNoPrimos / cuentaNoPrimos);
        else
            printf("Promedio de n�meros no primos: N/A\n");

        printf("\n�Deseas ingresar otra cantidad de n�meros? (s/n): ");
        scanf(" %c", &continuar); 

    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
    
