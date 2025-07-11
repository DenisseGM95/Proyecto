#include <stdio.h>

void menu() {
    printf("\n--- MEN� DE OPCIONES ---\n");
    printf("1 - Registrar nueva venta\n");
    printf("2 - Cantidad vendida por tipo de tiquete\n");
    printf("3 - Monto recaudado por tipo de tiquete\n");
    printf("4 - Salir\n");
}

int main() {
    char cedula[20], nombre[50];
    int tipoCliente, tipoTiquete, cantidad;
    int facturaNumero = 1;
    int opcion;
    const int maximoTiquetes = 10;

    int precioGaleria = 6000, precioPalco = 12000;

    int cantidadVendidaGaleria = 0, cantidadVendidaPalco = 0;
    float montoRecaudadoGaleria = 0.0, montoRecaudadoPalco = 0.0;

    do {
        menu();
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                do {
                    printf("\nIngrese la c�dula del cliente:\n");
                    printf("? Nacional (9 d�gitos) o Extranjera (12 d�gitos): ");
                    scanf("%s", cedula);

                    int longitud = 0;
                    for (longitud = 0; cedula[longitud] != '\0'; longitud++);

                    if (longitud != 9 && longitud != 12) {
                        printf("? C�dula inv�lida. Debe tener 9 (nacional) o 12 (extranjera) d�gitos.\n");
                    } else {
                        break;
                    }
                } while (1);

                printf("Ingrese el nombre del cliente (sin espacios): ");
                scanf("%s", nombre);

                printf("Tipo de cliente (1 = Ni�o o Adulto Mayor, 2 = Adulto): ");
                scanf("%d", &tipoCliente);

                if (tipoCliente != 1 && tipoCliente != 2) {
                    printf("Tipo de cliente inv�lido.\n");
                    break;
                }

                printf("Tipo de tiquete (1 = Galer�a, 2 = Palco): ");
                scanf("%d", &tipoTiquete);

                if (tipoTiquete != 1 && tipoTiquete != 2) {
                    printf("Tipo de tiquete inv�lido.\n");
                    break;
                }

                printf("Ingrese la cantidad de tiquetes (m�ximo %d): ", maximoTiquetes);
                scanf("%d", &cantidad);

                if (cantidad < 1 || cantidad > maximoTiquetes) {
                    printf("Cantidad no v�lida.\n");
                    break;
                }

                int precioUnitario = (tipoTiquete == 1) ? precioGaleria : precioPalco;
                float montoVenta = precioUnitario * cantidad;
                float descuento = (tipoCliente == 1) ? montoVenta * 0.30f : 0.0f;
                float subtotal = montoVenta - descuento;
                float impuesto = subtotal * 0.13f;
                float totalPagar = subtotal + impuesto;

                if (tipoTiquete == 1) {
                    cantidadVendidaGaleria += cantidad;
                    montoRecaudadoGaleria += totalPagar;
                } else {
                    cantidadVendidaPalco += cantidad;
                    montoRecaudadoPalco += totalPagar;
                }

                printf("\n--- FACTURA #%d ---\n", facturaNumero++);
                printf("C�dula: %s\n", cedula);
                printf("Nombre: %s\n", nombre);
                printf("Tipo de cliente: %s\n", (tipoCliente == 1) ? "Ni�o o Adulto Mayor" : "Adulto");
                printf("Tipo de tiquete: %s\n", (tipoTiquete == 1) ? "Galer�a" : "Palco");
                printf("Cantidad de tiquetes: %d\n", cantidad);
                printf("Precio unitario: �%d\n", precioUnitario);
                printf("Monto de venta: �%.2f\n", montoVenta);
                printf("Descuento: �%.2f\n", descuento);
                printf("Subtotal: �%.2f\n", subtotal);
                printf("Impuesto (13%%): �%.2f\n", impuesto);
                printf("Total a pagar: �%.2f\n", totalPagar);
                break;
            }

            case 2:
                printf("\n--- Cantidad de tiquetes vendidos ---\n");
                printf("Galer�a: %d\n", cantidadVendidaGaleria);
                printf("Palco: %d\n", cantidadVendidaPalco);
                break;

            case 3:
                printf("\n--- Monto recaudado por tipo de tiquete ---\n");
                printf("Galer�a: �%.2f\n", montoRecaudadoGaleria);
                printf("Palco: �%.2f\n", montoRecaudadoPalco);
                break;

            case 4:
                printf("Gracias por su visita. Programa finalizado.\n");
                break;

            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
