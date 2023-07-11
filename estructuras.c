// estructuras.c

#include <stdio.h>

#define MAX_MATERIAS 10

typedef struct {
    char nombre_materia[50];
    int paralelo;
} MateriaProfesor;

typedef struct {
    char nombre_materia[50];
    int creditos;
} MateriaEstudiante;

typedef struct {
    char nombre[50];
    char carrera[50];
    int num_materias;
    MateriaProfesor materias[MAX_MATERIAS];
} Profesor;

typedef struct {
    char nombre[50];
    int nivel;
    char carrera[50];
    int num_materias;
    MateriaEstudiante materias[MAX_MATERIAS];
} Estudiante;
