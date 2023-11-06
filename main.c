#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURAS///
typedef struct
{
    int nota[3];
    int promedio;
} nota;

typedef struct
{
    char nombreyApellido [20];
    int dni;
    nota notas;
    int asistencias;
} alumno;

typedef struct
{
    int numDeCurso;
    char division;
} curso;

typedef struct
{
    alumno alumnito;
    struct alumno*siguiente;

} nodoAlumno;

///PROTOTIPADO///
//MENUS
void menuPrincipal(curso cursoAMostrar);

//LISTAS
nodoAlumno* inicLista();

//ALUMNO
void mostrarAlumno(alumno aux);
void mostrarListaAlumnos(nodoAlumno* lista);

//OTRO
curso cargaCurso();

int main()
{
    //VARIABLES
    int opc = 0;
    curso cursos[10];
    cursos[0] = cargaCurso();

    menuPrincipal(cursos[0]);
    scanf("%i", &opc);

    switch(opc)
    {
    case 1://MOSTRAR Y PODER ACCEDER A LISTA DE ALUMNOS
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    default:
        break;


    }

    return 0;
}

alumno cargaAlumno()
{
    alumno aux;
    printf("\nIngrese nombre y apellido: ");
    fflush(stdin);
    gets(&aux.nombreyApellido);
    printf("\nIngrese DNI: ");
    fflush(stdin);
    scanf("%d", &aux.dni);

    return aux;
}

void mostrarAlumno(alumno aux)
{
    printf("\nNombre y Apellido: %s", aux.nombreyApellido);
    printf("\nDNI: %d", aux.dni);
}

void mostrarListaAlumnos(nodoAlumno* lista)
{
    nodoAlumno* aux = lista;
    while(aux)
    {
        mostrarAlumno(aux->alumnito);
        aux = aux->siguiente;
    }
}
void menuPrincipal(curso cursoAMostrar)
{
    printf("\n================|CURSO %i %c|================\n", cursoAMostrar.numDeCurso, cursoAMostrar.division);
    printf(" 1- Acceder Lista de Alumnos\n");
    printf(" 2- Mostrar Lista de Aprobados\n");
    printf(" 3- Tomar Asistencia\n");
    printf(" 4- Avanzar de Curso\n");
    printf(" 5- Agregar Curso/\n");
    printf("====================================");
    printf("\nIngrese una opcion: \n");

}

curso cargaCurso()
{
    curso aux;
    printf("INGRESE NUMERO DE CURSO\n");
    fflush(stdin);
    scanf("%i", &aux.numDeCurso);

    printf("INGRESE DIVISION DE CURSO\n");
    fflush(stdin);
    scanf("%c", &aux.division);

    return aux;
}

nodoAlumno* inicLista()
{
    return NULL;
}
