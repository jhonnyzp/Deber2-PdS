// regDatos.c

#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"

int main() {
    int num_personas;
    int i;

    printf("Ingrese la cantidad de personas a registrar (debe ser mayor o igual a 2): ");
    scanf("%d", &num_personas);

    if (num_personas < 2) {
        printf("La cantidad de personas debe ser mayor o igual a 2.\n");
        return 1;
    }

    Profesor *profesores = (Profesor *)malloc(sizeof(Profesor));
    Estudiante *estudiantes = (Estudiante *)malloc((num_personas - 1) * sizeof(Estudiante));

    if (profesores == NULL || estudiantes == NULL) {
        printf("Error al asignar memoria.\n");
        free(profesores);
        free(estudiantes);
        return 1;
    }

    printf("\n*** Registro de profesor ***\n");
    crearProfesor(&profesores[0]);

    printf("\n*** Registro de estudiantes ***\n");
    for (i = 0; i < num_personas - 1; i++) {
        crearEstudiante(&estudiantes[i]);
    }

    printf("\n*** Información ingresada ***\n");

    for (i = 0; i < num_personas - 1; i++) {
        mostrarDatos(profesores[0], estudiantes[i]);
    }

    free(profesores);
    free(estudiantes);

    return 0;
}
