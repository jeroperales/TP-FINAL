#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

///ESTRUCTURAS///

typedef struct
{
    char nombreyApellido [20];
    int dni;
    float notas;
    int asistencias;
    int numDeCurso;
    char division;
} registroArchivo;

typedef struct
{
    char nombreyApellido [20];
    int dni;
    float notas;
    int asistencias;

} alumno;

typedef struct
{
    alumno datos;
    struct alumno*siguiente;

} nodoAlumno;

typedef struct
{
    int numDeCurso;
    char division;
    nodoAlumno* listaDeAlumnos;
} curso;


///PROTOTIPADO///
//MENUS
void menuPrincipal(curso cursoAMostrar);

//LISTAS
nodoAlumno* inicLista();

//ALUMNO
void mostrarAlumno(alumno aux);
void mostrarListaAlumnos(nodoAlumno* lista);
void cargarArchivo(FILE* archivo);
void mostrarAlumnosARCHI(FILE* archivo);
//OTRO
curso cargaCurso();

int main()
{
    //VARIABLES
    int opc = 0;
    int i = 0;
    int dim = 20;
    curso cursos[dim];
    cursos[i] = cargaCurso();
    cursos[i].listaDeAlumnos =inicLista();
    menuPrincipal(cursos[0]);
    FILE* archivo;
    scanf("%i", &opc);

    switch(opc)
    {
    case 1://MOSTRAR Y PODER ACCEDER A LISTA DE ALUMNOS
        system("cls");
        subMenuAlumnos(cursos[i]);


        break;

    case 2:

        cargarArchivo(archivo);
        mostrarAlumnosARCHI(archivo);
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
    if (aux)
    {
        while(aux)
        {
            mostrarAlumno(lista->datos);
            aux = aux->siguiente;
        }
    }
    else
    {
        printf("DICHA LISTA ESTA VACIA!");
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

void subMenuAlumnos (curso cursoAMostrar)
{

    printf("\n================|CURSO %i %c|================\n\n", cursoAMostrar.numDeCurso, cursoAMostrar.division);
    mostrarListaAlumnos(cursoAMostrar.listaDeAlumnos);
    printf("\n\n===========================================");
    printf("\n 1- MODIFICAR NOTAS DE ALUMNO\n");
    printf(" 2- MODIFICAR ASISTENCIAS DE ALUMNO\n");
    printf(" 3- MODIFICAR CURSO\n");
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

nodoAlumno* crearNodoAlumno(alumno datosAlumno) //NODO QUE RECIBE UN ALUMNO Y CREA UN NODO CON DICHA INFORMACION
{
    nodoAlumno* aux = (nodoAlumno*)malloc(sizeof(nodoAlumno));
    aux->datos = datosAlumno;
    aux->siguiente = NULL;

}

void cargarArchivo(FILE* archivo)
{

    archivo = fopen("miArchivo.bin", "ab");
    char letra = 's';
    registroArchivo aux;

    if(archivo)
    {

        while(letra == 's')
        {

            system("cls");

            printf("Ingresa el curso: ");
            fflush(stdin);
            scanf("%i", &aux.numDeCurso);

            printf("Ingresa la division: ");
            fflush(stdin);
            scanf("%c", &aux.division);

            printf("Ingresa el nombre del alumno: ");
            fflush(stdin);
            gets(&aux.nombreyApellido);

            printf("Ingresa el DNI del alumno: ");
            fflush(stdin);
            scanf("%i", &aux.dni);

            printf("Ingresa la nota del alumno: ");
            fflush(stdin);
            scanf("%f", &aux.notas);

            printf("Ingresa la asistencia del alumno: ");
            fflush(stdin);
            scanf("%i", &aux.asistencias);

            fwrite(&aux, sizeof(registroArchivo), 1, archivo);

            printf("Ingresa s para seguir agregando: ");
            fflush(stdin);
            scanf("%c", &letra);
        }

        fclose(archivo);
    }
}

void mostrarAlumnosARCHI(FILE* archivo)
{

    archivo = fopen("miArchivo.bin", "rb");
    registroArchivo aux;

    if(archivo)
    {

        while(fread(&aux, sizeof(registroArchivo), 1, archivo) > 0)
        {

            printf("==================================\n");
            printf("Curso: %i/%c\n", aux.numDeCurso, aux.division);
            printf("Nombre y Apellido: %s\n", aux.nombreyApellido);
            printf("Documento: %i\n", aux.dni);
            printf("Nota: %.2f\n", aux.notas);
            printf("Asistencia: %i\n", aux.asistencias);
            printf("==================================\n");

        }

        fclose(archivo);
    }
}

int pasarArchivoAArreglo(curso arreglo[], FILE* archivo, int dimension) //COPIAR CODIGO Y FUNCIONES DE AVANZ
{
    archivo = fopen("miArchivo.bin", "rb");

    int cursoAlumno;
    char division;
    int validos = 0;
    alumno aux;
    registroArchivo alumnoArchivo;

    if(archivo)
    {
        while(validos < dimension && fread(&alumnoArchivo, sizeof(registroArchivo), 1, archivo) > 0)
        {

            aux.dni = alumnoArchivo.dni;
            strcpy(aux.nombreyApellido, alumnoArchivo.nombreyApellido);
            aux.notas = alumnoArchivo.notas;
            aux.asistencias = alumnoArchivo.asistencias;

            cursoAlumno = alumnoArchivo.numDeCurso;
            division = alumnoArchivo.division;

           // validos = alta(arreglo, aux, validos, materia); //FALTA HACER PASAJE DE VARIABLES CORRECTA

        }

        fclose(archivo);
    }

    return validos;
}
