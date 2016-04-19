#include <stdio.h>
#include <stdlib.h>
int buscarLibre(int[]);
int main()
{


    int vector[10];
    int i;
    int pos;
    int num;
    for(i=0;i<10;i++)
    {
        vector[i]=-1;

    }


    do
    {


       pos=buscarLibre(vector);
       if(pos!=-1)
       {
           printf("ingrese un numero en posicion %d", pos);
           scanf("%d", &vector[pos]);
       }
       else
       {
            printf("No hay lugar");
       }



    }while(pos!=-1);


    vector[6]=-1;
     vector[9]=-1;
      vector[3]=-1;
      system("pause");
      system("cls");
printf("Aca doy de baja y vuelvo a cargar\n");

    do
    {


       pos=buscarLibre(vector);
       if(pos!=-1)
       {
           printf("ingrese un numero en posicion %d", pos);
           scanf("%d", &vector[pos]);
       }
       else
       {
            printf("No hay lugar");
       }



    }while(pos!=-1);





    return 0;
}

int buscarLibre(int vec[])
{
    int index=-1;
    int i;
    for(i=0;i<10;i++)
    {
        if(vec[i]==-1)
        {
            //Esta vacio
            index=i;
             break;

        }
    }


    return index;
}
