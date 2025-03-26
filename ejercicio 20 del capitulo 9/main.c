#include <stdio.h>
/* Escuela.
El programa, al recibir como dato un archivo de acceso directo que contiene
informaci�n de los alumnos de una escuela, genera informaci�n estad�stica
importante. */

typedef struct /* Declaraci�n de la estructura matcal. */
{
    char materia[20];
    int calificacion;
} matcal;

typedef struct /* Declaraci�n de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    matcal cal[5]; // Campo de estructura que contiene las calificaciones
} alumno;

void F1(FILE *);
void F2(FILE *); /* Prototipos de funciones. */
float F3(FILE *);

void main(void)
{
    float pro;
    FILE *ap;

    // Abriendo el archivo para lectura
    if ((ap = fopen("esc.dat", "r")) != NULL)
    {
        F1(ap); // Muestra matr�cula y promedio
        F2(ap); // Muestra alumnos con calificaci�n > 9 en la materia 3
        pro = F3(ap); // Obtiene el promedio de la materia 4
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f", pro);
        fclose(ap); // Cerramos el archivo despu�s de usarlo
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
}

void F1(FILE *ap)
/* La funci�n escribe la matr�cula y el promedio general de cada alumno. */
{
    alumno alu;
    int j;
    float sum, pro;

    printf("\nMATR�CULA y PROMEDIOS");

    // Leer el primer alumno
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nMatr�cula: %d", alu.matricula);
        sum = 0.0;

        // Calcular el promedio de las 5 materias
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;

        pro = sum / 5;
        printf("\tPromedio: %f", pro);
    }
}

void F2(FILE *ap)
/* La funci�n escribe la matr�cula de los alumnos cuya calificaci�n en la
tercera materia es mayor a 9. */
{
    alumno alu;

    rewind(ap); // Volver al inicio del archivo
    printf("\n\nALUMNOS CON CALIFICACI�N > 9 EN MATERIA 3");

    // Leer el primer alumno
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        if (alu.cal[2].calificacion > 9) // Materia 3 (�ndice 2)
            printf("\nMatr�cula del alumno: %d", alu.matricula);
    }
}

float F3(FILE *ap)
/* Esta funci�n obtiene el promedio general de la materia 4. */
{
    alumno alu;
    int i = 0;
    float sum = 0, pro;

    rewind(ap); // Volver al inicio del archivo

    // Leer el primer alumno
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        i++;
        sum += alu.cal[3].calificacion; // Materia 4 (�ndice 3)
    }

    // Calcular el promedio de la materia 4
    if (i > 0)
        pro = sum / i;
    else
        pro = 0; // Si no hay alumnos, evitar divisi�n por cero

    return pro;
}
