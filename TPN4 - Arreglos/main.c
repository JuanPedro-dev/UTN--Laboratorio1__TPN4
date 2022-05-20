#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"
#include <string.h>

void menu();
int cargarArreglo(int arreglo[]);
void mostrarVector(int arreglo[],int DIM);
void sumatoriaVector(int arreglo[],int validos);
void copiarVectorAPila(int arreglo[], int validos, Pila* pila);
void copiarVectorAPila(int arreglo[], int validos, Pila* pila);
void cargarFloatVector(float arreglo[]);
void randomFloatVector(float arreglo[]);
void mostrarFloatVector(float arreglo[]);
void mostrarFloatVector(float arreglo[]);
void sumatoriaFloatVector(float arreglo[]);
int seEncuentra(int arreglo[],int validos,int buscar );
void insetarLetra(char arreglo[],char letra);
char maximoChar(char arreglo[]);
int esCapicua(char arreglo[]);
void invertirArregloChar(char arreglo[]);
int menor(const int arreglo[], const int validos);
void ordenar_seleccion(int arreglo[], const int validos);



void sumarAnteriores(int arreglo[], const int DIM);

int main()
{
    char option;
    setlocale(LC_ALL,"");
    srand(time(NULL));
    system("color 1F");
    char letras[20] = {'b','c','e'};
    int num[] = {3,2,1,4};

    // ordenar_seleccion(num, 4);
    ordenar_insercion(num, 4);

    mostrarVector(num, 4);



    system("pause");
    return 0;
}

/** 1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
    el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
    elementos cargados en el arreglo (o pueden utilizar como puntero válidos). */
int cargarArreglo(int arreglo[])
{
    char option;
    int i = 0;
    do
    {
        printf("Ingrese un valor: ");
        scanf("%d", &arreglo[i]);
        printf("¿Continuar cargando? s/n: ");
        fflush(stdin);
        scanf("%c", &option);
        i++;
    } while(option!= 'n' && option!='N');
    return i;
}
/** 2.Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos
    (válidos) cargados en él y los muestre por pantalla. */
void mostrarVector(int arreglo[],int DIM)
{
    printf ("-> [");
    for(int i = 0; i < DIM -1 ; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf ("%d]\n", arreglo[DIM-1]);
}
/** 3. Hacer una función que reciba como parámetro un arreglo y la cantidad de
    elementos (válidos) cargados en él y calcule la suma de sus elementos. */

void sumatoriaVector(int arreglo[],int validos)
{
    int acumulador = 0;
    for(int i = 0; i < validos; i++)
    {
        acumulador += arreglo[i];
    }
    printf("La suma de todos los elementos del vector es: %i", acumulador);
}
/** 4.Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos
    (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila. */

void copiarVectorAPila(int arreglo[], int validos, Pila* pila)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(pila, arreglo[i]);
    }
}
/** 5.Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
    (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)*/

void cargarFloatVector(float arreglo[])
{
    int DIM = 100;
    printf("\n");
    for(int i = 0; i < DIM; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%f", &arreglo[i]);
    }
}
void randomFloatVector(float arreglo[])
{
    int DIM = 100;
    printf("\n");
    for(int i = 0; i < DIM; i++)
    {
       arreglo[i] = rand();     ///////////////////////////////////////////// ACAAAAAA generar numeros random decimales.
    }
}

void mostrarFloatVector(float arreglo[])
{
    int DIM = 100;
    printf ("-> [");
    for(int i = 0; i < DIM -1 ; i++)
    {
        printf("%.2f, ", arreglo[i]);
    }
    printf ("%.2f]\n", arreglo[DIM-1]);
}

void sumatoriaFloatVector(float arreglo[])
{
    int DIM = 5;
    float acumulador = 0;
    for(int i = 0; i < DIM ; i++)
    {
        acumulador += arreglo[i];
    }
    printf ("%.2f \n", acumulador);
}

/** 6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.*/
    // si return = 0, no se encuentra en el arreglo, 1 si se encuentra...
int seEncuentra(int arreglo[],int validos,int buscar )
{
    int encontrado = 0;
    for(int i = 0; i < validos; i++)
    {
        if(arreglo[i] == buscar)
        {
            encontrado = 1;
            break;
        }
    }
    return encontrado;
}

/** 7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden. */

void insetarLetra(char arreglo[],char letra)
{
    int insertado = 0;
    for(int i = strlen(arreglo)-1; i >= 0 ; i--)
    {
        if(arreglo[i] < letra)
        {
            arreglo[i+1] = letra;
            insertado = 1;
            break;
        } else
        {
            arreglo[i+1] = arreglo[i];
        }
    }
    if(insertado == 0)
    {
        arreglo[0] = letra;
    }
}
 /** 8.Realizar una función que obtenga el máximo carácter de un arreglo dado. */
char maximoChar(char arreglo[])
{
    char max;
    max = arreglo[0];
    for (int i = 1 ; i < strlen(arreglo); i++)
    {
        if(max < arreglo[i])
        {
            max = arreglo[i];
        }
    }
    return max;
}

/** 9.Realizar una función que determine si un arreglo es capicúa. */
// 0 para es capicua / 1 NO es capicua
int esCapicua(char arreglo[])
{
    int i = 0;
    int j = strlen(arreglo);
    int capicua = 0;
    while (i-j <= 0 && capicua == 0)
    {
        if(arreglo[i] != arreglo[j-1])
        {
            capicua = 1;
        }
        i++;
        j--;
    }
    return capicua;
}
/** 10. Realizar una función que invierta los elementos de un arreglo.
    (sin utilizar un arreglo auxiliar)*/

void invertirArregloChar(char arreglo[])
{
    char auxiliar;
    int i = 0;
    int j = strlen(arreglo);
    while (i-j < 0)
    {
        auxiliar = arreglo[j-1];
        arreglo[j-1] = arreglo[i];
        arreglo[i] = auxiliar;
        i++;
        j--;
        printf("%c", auxiliar);
    }

}

/** 11. Ordenar un arreglo según los siguientes métodos:
        a. Selección
        b. Inserción*/
int menor(const int arreglo[], const int validos)
{
    if(validos > 0)
    {
        int posicionMenor = 0;
        int menor = arreglo[posicionMenor];

        for(int i = 0; i < validos;i++)
        {
            if(menor > arreglo[i])
            {
                menor = arreglo[i];
                posicionMenor = i;
            }
        }
        return posicionMenor;
    }
    return -1;
}
void ordenar_seleccion(int arreglo[], const int validos)
{
    for(int i=0; i< validos;i++)
    {
        // El menor a partir de la posicion i
        int posicionMenor = i;
        int menor = arreglo[posicionMenor];

        for(int j = i ; j < validos; j++)
        {
            if(menor > arreglo[j])
            {
                menor = arreglo[j];
                posicionMenor = j;
            }
        }
        // Ya se cual es el menor ahora debo intercambiarlo.
        int auxiliar = arreglo[i];
        arreglo[i] = arreglo[posicionMenor];
        arreglo[posicionMenor] = auxiliar;
    }
}

/////////////////////////////////////////////////// terminar
//
void ordenar_insercion(int arreglo[], const int  validos)
{
    for (int i = 1; i < validos; i++)
    {
        int flag = 0;
        int elemento = arreglo[i];
        mostrarVector(arreglo,4);
        for(int j = i-1; j >=0 && flag == 0; j-- )
        {
            if(arreglo[j] > elemento)
            {
                int aux = arreglo[j];
                arreglo[j] = elemento;
                arreglo[i] = aux;
            }
            else
            {
                flag = 1;
            }
            mostrarVector(arreglo,4);
        }
    }
}


/** 12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo
        con los elementos de los dos primeros intercalados, de manera que quede un
        arreglo también ordenado alfabéticamente.         */
// Aca si entendi bien concateno dos arreglos y los ordeno.

void sumaOrdenadaArreglos (char arreglo[], char arreglo2[])
{

}

/** 13. (ejercicio extra Com 8) Dado un el vector {1,5,6,7,8} escribir un programa
    que genere otro vector con la suma del contenido de todo los elementos anteriores
    al índice actual: {1,6,12,19,27}.*/

void sumarAnteriores(int arreglo[], const int DIM)
{
    int acumulador = 0;
    for (int i = 0; i < DIM ; i++)
    {
        acumulador += arreglo[i];
        arreglo[i] = acumulador;
    }
}

void menu()
{
    system("color 3f");
    system("cls");
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("//                                     TPN 3 - Funciones Con pilas                                            //\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("//  int main (ejercicio)                                                                                      //\n");
    Sleep(50);
    printf("//  {                                                                                                         //\n");
    Sleep(50);
    printf("//      int opción A = 'Cargar un arreglo y retornar la cantidad de elementos cargado.';                      //\n");
    Sleep(50);
    printf("//      int opción B = 'Mostrar en pantalla un arreglo (indicar los válidos).';                               //\n");
    Sleep(50);
    printf("//      int opción C = ' ';       //\n");
    Sleep(50);
    printf("//      int opción D = ' ';                                                                //\n");
    Sleep(50);
    printf("//      int opción E = ' ';                                  //\n");
    Sleep(50);
    printf("//      int opción F = ' ';                                               //\n");
    Sleep(50);
    printf("//      int opción G = ' ';                                          //\n");
    Sleep(50);
    printf("//      int opción H = ' ';                                   //\n");
    Sleep(50);
    printf("//      int opción I = ' ';                                                                                                      //\n");
    Sleep(50);
    printf("//      int opción J = ' ';    //\n");
    Sleep(50);
    printf("//      int opción K = ' ';     //\n");
    Sleep(50);
    printf("//      int opción L = ' ';        //\n");
    Sleep(50);
    printf("//      int opción M = ' ';      //\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("//      }                                                                                                     //\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("//                                                                       Created By Juan Pedro...             //\n");
    Sleep(50);
    printf("//                                                                                                            //\n");
    Sleep(50);
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    Sleep(50);
    printf("\n                                Tu entrada (Terminar Programa: s o S): ");
}
