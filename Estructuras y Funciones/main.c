#include <stdio.h>
#include <stdlib.h>
#define E 3

typedef struct
{
    int dia, mes, anio;
} eFecha;


typedef struct
{
  int legajo;
  char nombre[50];
  float sueldo;
  eFecha fechaIngreso;

} eEmpleado;


//Funcion que reciba 2 empleados y determine cual es el empleado que gana mas dinero y devuelve ese empleados
eEmpleado cargarEmpleado(int, char[], float);
void mostrarNomina(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
void ordenarPorSueldo(eEmpleado[], int);
int comparaSueldo(eEmpleado, eEmpleado);

int main()
{

    eEmpleado misEmpleados[E];
    int legajo;
    char nombre[50];
    float sueldo;
    int i;

    for(i=0; i<E; i++)
    {
         printf("Ingrese Legajo: ");
         scanf("%d", &legajo);
         printf("Ingrese nombre: ");
         fflush(stdin);
         gets(nombre);
         printf("Ingrese sueldo: ");
         scanf("%f", &sueldo);
         printf("\n");

         misEmpleados[i]=cargarEmpleado(legajo,nombre,sueldo);
    }

    mostrarNomina(misEmpleados, E);
    ordenarPorSueldo(misEmpleados, E);
    mostrarNomina(misEmpleados, E);

    return 0;
}
eEmpleado cargarEmpleado(int legajo, char nombre[], float sueldo)
{
    eEmpleado e;
    eFecha fecha;

    fecha.dia=18;
    fecha.mes=4;
    fecha.anio=2016;

    e.legajo=legajo;
    strcpy(e.nombre,nombre);
    e.sueldo=sueldo;
    e.fechaIngreso=fecha;

    /*e.fechaIngreso.dia=18;
    e.fechaIngreso.mes=4;
    e.fechaIngreso.anio=2016;*/


    return e;
}

void mostrarNomina(eEmpleado empleados[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
         mostrarEmpleado(empleados[i]);
    }
}

void mostrarEmpleado(eEmpleado empleado)
{
    printf("%d--%s--%f\n", empleado.legajo, empleado.nombre, empleado.sueldo);

}

void ordenarPorSueldo(eEmpleado empleados[], int tam)
{
    int i,j;
    eEmpleado aux;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(comparaSueldo(empleados[i],empleados[j])==-1)
            {
                aux=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=aux;
            }
            else if(comparaSueldo(empleados[i],empleados[j])==0)
            {
                if(strcmp(empleados[i].nombre,empleados[j].nombre)<0)
                {
                    aux=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=aux;
                }
            }
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return 1 si E1 gana mas -1 si E2 gana mas y 0 si ganan lo mismo
 *
 */

int comparaSueldo(eEmpleado empleado1, eEmpleado empleado2)
{
    int ganaMas=0;
    if(empleado1.sueldo<empleado2.sueldo)
    {
        ganaMas=-1;
    }
    else if(empleado1.sueldo>empleado2.sueldo)
    {
        ganaMas=1;
    }


    return ganaMas;
}
