// regDatosOpciones.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos.h"

int main(int argc, char *argv[]) {
    int num_personas;
    char opcion[3];
    int i;

    if (argc != 3) {
        printf("Uso: ./regDatosOpciones <cantidad_personas> <opcion>\n");
        return 1;
    }

    num_personas = atoi(argv[1]);
    strcpy(opcion, argv[2]);

    if (num_personas < 2 || (strcmp(opcion, "-p") != 0 && strcmp(opcion, "-e") != 0 && strcmp(opcion, "-a") != 0)) {
        printf("La cantidad de personas debe ser mayor o igual a 2 y la opción debe ser -p, -e o -a.\n");
        return 1;
    }

    Profesor *profesores = NULL;
    Estudiante *estudiantes = NULL;

    int num_profesores = 0;
    int num_estudiantes = 0;

    if (strcmp(opcion, "-p") == 0 || strcmp(opcion, "-a") == 0) {
        profesores = (Profesor *)malloc(num_personas * sizeof(Profesor));
        if (profesores == NULL) {
            printf("Error al asignar memoria.\n");
            return 1;
        }

        printf("\n*** Registro de profesores ***\n");
        for (i = 0; i < num_personas; i++) {
            crearProfesor(&profesores[num_profesores]);
            num_profesores++;
        }
    }

    if (strcmp(opcion, "-e") == 0 || strcmp(opcion, "-a") == 0) {
        estudiantes = (Estudiante *)malloc((num_personas - 1) * sizeof(Estudiante));
        if (estudiantes == NULL) {
            printf("Error al asignar memoria.\n");
            free(profesores);
            return 1;
        }

        printf("\n*** Registro de estudiantes ***\n");
        for (i = 0; i < num_personas - 1; i++) {
            crearEstudiante(&estudiantes[num_estudiantes]);
            num_estudiantes++;
        }
    }

    printf("\n*** Información ingresada ***\n");

    if (profesores != NULL) {
        for (i = 0; i < num_profesores; i++) {
            mostrarDatos(profesores[i], estudiantes[i]);
        }
    }

    if (estudiantes != NULL) {
        for (i = 0; i < num_estudiantes; i++) {
            mostrarDatos(profesores[0], estudiantes[i]);
        }
    }

    free(profesores);
    free(estudiantes);

    return 0;
}
