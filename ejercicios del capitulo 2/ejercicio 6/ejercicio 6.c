#include <stdio.h>

/* Incremento de salario.

El programa, al recibir como dato el nivel de un profesor, incrementa su salario en funci�n de la tabla 2.3.

NIV: variable de tipo entero.
SAL: variables de tipo real. */

int main(void)
{
    float SAL; // Variable para el salario
    int NIV;   // Variable para el nivel acad�mico

    // Solicitar el nivel acad�mico del profesor
    printf("Ingrese el nivel acad�mico del profesor: ");
    scanf("%d", &NIV);

    // Solicitar el salario
    printf("Ingrese el salario: ");
    scanf("%f", &SAL);

    // Incrementar el salario seg�n el nivel
    switch(NIV) {
        case 1:
            SAL = SAL * 1.0035;
            break;
        case 2:
            SAL = SAL * 1.0041;
            break;
        case 3:
            SAL = SAL * 1.0048;
            break;
        case 4:
            SAL = SAL * 1.0053;
            break;
        default:
            printf("Nivel no v�lido\n");
            return 1; // Termina el programa si el nivel no es v�lido
    }

    // Mostrar el nuevo salario
    printf("\nNivel: %d \tNuevo salario: %.2f\n", NIV, SAL);

    return 0; // Finaliza el programa exitosamente
}
