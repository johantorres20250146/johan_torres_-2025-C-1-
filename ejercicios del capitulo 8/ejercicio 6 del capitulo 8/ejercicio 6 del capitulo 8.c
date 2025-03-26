#include <stdio.h>
#include <string.h>

/* Estructura del producto */
typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

/* Prototipos de funciones */
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

int main(void) {
    producto INV[100];  // Arreglo de productos
    int TAM, OPE;

    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1); // Verificación del rango

    Lectura(INV, TAM);

    do {
        printf("\nIngrese operación a realizar: \n");
        printf("\t1 - Ventas\n");
        printf("\t2 - Reabastecimiento\n");
        printf("\t3 - Nuevos Productos\n");
        printf("\t4 - Inventario\n");
        printf("\t0 - Salir\n");
        printf("Opción: ");
        scanf("%d", &OPE);

        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (OPE != 0);

    return 0;
}

void Lectura(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese información del producto %d", I + 1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);

        while (getchar() != '\n');  // Limpiar buffer
        printf("\tNombre: ");
        fgets(A[I].nombre, 15, stdin);
        A[I].nombre[strcspn(A[I].nombre, "\n")] = 0;  // Eliminar salto de línea

        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);

        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0, PAR;

    printf("\nIngrese clave del producto (-1 para salir): ");
    scanf("%d", &CLA);

    while (CLA != -1) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);

        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;  // Búsqueda

        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto es incorrecta\n");
        } else if (A[I].existencia >= CAN) {
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            printf("\nStock insuficiente. Solo hay %d", A[I].existencia);
            printf("\n¿Lleva lo disponible? (1-Sí / 0-No): ");
            scanf("%d", &RES);

            if (RES) {
                PAR = A[I].precio * A[I].existencia;
                A[I].existencia = 0;
                TOT += PAR;
            }
        }
        printf("\nIngrese otra clave de producto (-1 para salir): ");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;

    printf("\nIngrese clave del producto (-1 para salir): ");
    scanf("%d", &CLA);

    while (CLA != -1) {
        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;

        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto ingresada es incorrecta\n");
        } else {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave del producto" (-1 para salir): );
