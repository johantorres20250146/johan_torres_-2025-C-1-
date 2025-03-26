#include <stdio.h>

int main(void) {
    int i, j, n, mat;
    float cal;
    FILE *ar;

    printf("\nIngrese el n�mero de alumnos: ");
    scanf("%d", &n);

    /* Se asume que el valor que ingresa el usuario est� comprendido entre 1 y 35. */
    if ((ar = fopen("arc8.txt", "w")) != NULL) {
        fprintf(ar, "%d ", n); /* Se escribe el n�mero de alumnos en el archivo */

        for (i = 0; i < n; i++) {
            printf("\nIngrese la matr�cula del alumno %d: ", i + 1);
            scanf("%d", &mat);
            fprintf(ar, "\n%d ", mat); /* Se escribe la matr�cula en el archivo */

            for (j = 0; j < 5; j++) {
                printf("\nCalificaci�n %d: ", j + 1);
                scanf("%f", &cal);
                fprintf(ar, "%.2f ", cal); /* Se escriben las calificaciones en el archivo */
            }
            fprintf(ar, "\n"); /* Agregar un salto de l�nea despu�s de las calificaciones de cada alumno */
        }
        fclose(ar);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
