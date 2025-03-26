#include <stdio.h>
#include <string.h>

/* Definición de la estructura domicilio */
typedef struct {
    char cal[20]; /* Calle */
    int num; /* Número */
    char col[20]; /* Colonia */
    char cp[6]; /* Código Postal */
    char ciu[20]; /* Ciudad */
} domicilio;

/* Definición de la estructura paciente */
typedef struct {
    char nom[20]; /* Nombre y apellido */
    int edad;
    char sexo;
    int con; /* Condición */
    domicilio dom;
    char tel[11]; /* Teléfono */
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el número de pacientes (1-50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\tPaciente %d\n", I + 1);
        getchar();  // Limpia el buffer antes de fgets

        printf("Nombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        strtok(A[I].nom, "\n"); // Elimina el salto de línea

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        printf("Sexo (F-M): ");
        getchar(); // Limpia el buffer antes de leer un carácter
        scanf("%c", &A[I].sexo);

        printf("Condición (1-5): ");
        scanf("%d", &A[I].con);
        getchar();  // Limpia el buffer

        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        strtok(A[I].dom.cal, "\n");

        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);
        getchar();  // Limpia el buffer

        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        strtok(A[I].dom.col, "\n");

        printf("\tCódigo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        strtok(A[I].dom.cp, "\n");

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        strtok(A[I].dom.ciu, "\n");

        printf("Teléfono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        strtok(A[I].tel, "\n");
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F': FEM++; break;
            case 'M': MAS++; break;
        }
    }

    int TOT = FEM + MAS;
    if (TOT == 0) {
        printf("\nNo hay pacientes registrados.");
        return;
    }

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%\n", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }

    printf("\nNúmero de pacientes en cada condición:");
    printf("\nCondición 1: %d", C1);
    printf("\nCondición 2: %d", C2);
    printf("\nCondición 3: %d", C3);
    printf("\nCondición 4: %d", C4);
    printf("\nCondición 5: %d\n", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes en estado de gravedad (Condición 5):");

    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("\nNombre: %s\tTeléfono: %s", A[I].nom, A[I].tel);
        }
    }
    printf("\n");
}
