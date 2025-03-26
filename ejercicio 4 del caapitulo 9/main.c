#include <stdio.h>

int main(void) {
    char cad[50];
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL) {
        // Se abre el archivo para lectura
        while (fgets(cad, sizeof(cad), ap) != NULL) {
            // Mientras se lea correctamente una l�nea
            puts(cad); // Despliega la cadena le�da
        }
        fclose(ap); // Cierra el archivo
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
