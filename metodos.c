// metodos.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos.h"

void crearProfesor(Profesor *profesor) {
    printf("Ingrese el nombre del profesor: ");
    scanf("%s", profesor->nombre);

    printf("Ingrese la carrera del profesor: ");
    scanf("%s", profesor->carrera);

    printf("Ingrese la cantidad de materias que dicta (2-3): ");
    scanf("%d", &profesor->num_materias);

    for (int i = 0; i < profesor->num_materias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        scanf("%s", profesor->materias[i].nombre_materia);

        printf("Ingrese el paralelo de la materia %d: ", i + 1);
        scanf("%d", &profesor->materias[i].paralelo);
    }
}

void crearEstudiante(Estudiante *estudiante) {
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", estudiante->nombre);

    printf("Ingrese el nivel del estudiante: ");
    scanf("%d", &estudiante->nivel);

    printf("Ingrese la carrera del estudiante: ");
    scanf("%s", estudiante->carrera);

    printf("Ingrese la cantidad de materias que toma (3-7): ");
    scanf("%d", &estudiante->num_materias);

    for (int i = 0; i < estudiante->num_materias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        scanf("%s", estudiante->materias[i].nombre_materia);

        printf("Ingrese los créditos de la materia %d: ", i + 1);
        scanf("%d", &estudiante->materias[i].creditos);
    }
}

void mostrarDatos(Profesor profesor, Estudiante estudiante) {
    printf("\n--- Profesor ---\n");
    printf("Nombre: %s\n", profesor.nombre);
    printf("Carrera: %s\n", profesor.carrera);
    printf("Materias dictando:\n");
    for (int i = 0; i < profesor.num_materias; i++) {
        printf("  - Materia %d: %s (Paralelo %d)\n", i + 1, profesor.materias[i].nombre_materia, profesor.materias[i].paralelo);
    }

    printf("\n--- Estudiante ---\n");
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Nivel: %d\n", estudiante.nivel);
    printf("Carrera: %s\n", estudiante.carrera);
    printf("Materias tomando:\n");
    for (int i = 0; i < estudiante.num_materias; i++) {
        printf("  - Materia %d: %s (Créditos %d)\n", i + 1, estudiante.materias[i].nombre_materia, estudiante.materias[i].creditos);
    }
}

void eliminarMateria(Estudiante *estudiante) {
    int num_materia;
    printf("Ingrese el número de la materia a eliminar: ");
    scanf("%d", &num_materia);

    if (num_materia >= 1 && num_materia <= estudiante->num_materias) {
        // Mover las materias hacia adelante para llenar el espacio eliminado
        for (int i = num_materia - 1; i < estudiante->num_materias - 1; i++) {
            strcpy(estudiante->materias[i].nombre_materia, estudiante->materias[i + 1].nombre_materia);
            estudiante->materias[i].creditos = estudiante->materias[i + 1].creditos;
        }
        estudiante->num_materias--;

        printf("Materia eliminada con éxito.\n");
    } else {
        printf("Número de materia inválido.\n");
    }
}

void cambiarNivel(Estudiante *estudiante) {
    printf("Ingrese el nuevo nivel del estudiante: ");
    scanf("%d", &estudiante->nivel);

    printf("Nivel cambiado con éxito.\n");
}
