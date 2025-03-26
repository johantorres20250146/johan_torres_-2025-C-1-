#include <stdio.h>
/* Incrementa salarios.
El programa incrementa el salario de los empleados de una empresa
�actualiza el archivo correspondiente� si sus ventas son superiores
al mill�n de pesos anuales. */
typedef struct /* Declaraci�n de la estructura empleado. */
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *); /* Prototipo de funci�n. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad5.dat", "r+")) != NULL)  // Corrected quotation marks
        incrementa(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}

void incrementa(FILE *ap)
/* Esta funci�n se utiliza para incrementar el salario de todos aquellos
empleados que hayan tenido ventas anuales por m�s de $1,000,000.
Actualiza adem�s el archivo correspondiente. */
{
    int j;
    float sum;
    empleado emple;

    // Read the first employee record
    while (fread(&emple, sizeof(empleado), 1, ap) == 1)
    {
        sum = 0;
        // Calculate the total annual sales
        for (j = 0; j < 12; j++)
            sum += emple.ventas[j];

        // If annual sales exceed 1 million, increase the salary by 10%
        if (sum > 1000000)
        {
            emple.salario = emple.salario * 1.10;  // Increase the salary
            fseek(ap, -sizeof(empleado), SEEK_CUR);  // Move back to the current record
            fwrite(&emple, sizeof(empleado), 1, ap);  // Write the updated record
        }
    }
}
