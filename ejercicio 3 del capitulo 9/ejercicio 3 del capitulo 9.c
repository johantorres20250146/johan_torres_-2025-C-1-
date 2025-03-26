#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[50];
    int res;
    FILE *ar;

    if ((ar = fopen("arc.txt", "w")) != NULL) {
        printf("\n�Desea ingresar una cadena de caracteres? S�-1 No-0: ");
        scanf("%d", &res);
        getchar(); // Consumir el salto de l�nea pendiente

        while (res) {
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);

            // Eliminar el salto de l�nea que deja fgets
            cad[strcspn(cad, "\n")] = 0;

            fputs(cad, ar);

            printf("\n�Desea ingresar otra cadena de caracteres? Si-1 No-0: ");
            scanf("%d", &res);
            getchar(); // Consumir el salto de l�nea pendiente

            if (res) {
                fputs("\n", ar); // Agregar salto de l�nea entre cadenas
            }
        }
        fclose(ar);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
