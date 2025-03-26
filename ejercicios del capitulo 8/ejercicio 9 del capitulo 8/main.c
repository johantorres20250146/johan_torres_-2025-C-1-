#include <stdio.h>
#include <string.h>

/* Estructura de ubicación */
typedef struct {
    char zona[20];
    char calle[20];
    char colo[20]; /* Colonia */
} ubicacion;

/* Estructura de propiedades */
typedef struct {
    char clave[5];
    float scu; /* Superficie cubierta */
    float ste; /* Superficie terreno */
    char car[50]; /* Características */
    ubicacion ubi;
    float precio;
    char dispo; /* Disponibilidad */
} propiedades;

void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

int main(void) {
    propiedades PROPIE[100]; /* Arreglo de estructuras */
    int TAM;

    do {
        printf("Ingrese el número de propiedades (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

void Lectura(propiedades A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos de la propiedad %d\n", I + 1);
        getchar(); // Limpiar buffer antes de fgets

        printf("Clave: ");
        fgets(A[I].clave, sizeof(A[I].clave), stdin);
        strtok(A[I].clave, "\n");

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        getchar();  // Limpiar buffer antes de fgets

        printf("Características: ");
        fgets(A[I].car, sizeof(A[I].car), stdin);
        strtok(A[I].car, "\n");

        printf("\tZona: ");
        fgets(A[I].ubi.zona, sizeof(A[I].ubi.zona), stdin);
        strtok(A[I].ubi.zona, "\n");

        printf("\tCalle: ");
        fgets(A[I].ubi.calle, sizeof(A[I].ubi.calle), stdin);
        strtok(A[I].ubi.calle, "\n");

        printf("\tColonia: ");
        fgets(A[I].ubi.colo, sizeof(A[I].ubi.colo), stdin);
        strtok(A[I].ubi.colo, "\n");

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Disponibilidad (Venta-V Renta-R): ");
        getchar(); // Limpiar buffer antes de leer un char
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T) {
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores\n");

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0)) {
            if ((A[I].precio >= 450000) && (A[I].precio <= 650000)) {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);
                printf("Superficie cubierta: %.2f\n", A[I].scu);
                printf("Superficie terreno: %.2f\n", A[I].ste);
                printf("Características: ");
                puts(A[I].car);
                printf("Calle: ");
                puts(A[I].ubi.calle);
                printf("Colonia: ");
                puts(A[I].ubi.colo);
                printf("Precio: %.2f\n", A[I].precio);
            }
        }
    }
}

void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\n\t\tListado de Propiedades para Renta\n");
    printf("Ingrese zona geográfica: ");
    getchar(); // Limpiar buffer antes de fgets
    fgets(zon, sizeof(zon), stdin);
    strtok(zon, "\n");

    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);

    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0)) {
            if ((A[I].precio >= li) && (A[I].precio <= ls)) {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);
                printf("Superficie cubierta: %.2f\n", A[I].scu);
                printf("Superficie terreno: %.2f\n", A[I].ste);
                printf("Características: ");
                puts(A[I].car);
                printf("Calle: ");
                puts(A[I].ubi.calle);
                printf("Colonia: ");
                puts(A[I].ubi.colo);
                printf("Precio: %.2f\n", A[I].precio);
            }
        }
    }
}
