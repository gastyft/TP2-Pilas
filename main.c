#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//FALTA 6 - 12
//VER 13
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();
Pila cargarPila();
float sumarPila(Pila pila);
float contarPila(Pila pila);
Pila ordenarPila(Pila pila);
Pila copiarPila(Pila pila);
Pila unir2Pilas(Pila pila1,Pila pila2);
Pila eliminarDuplicados(Pila pila);
Pila mazoRandom(int manos);
int main()
{
    int ejercicio;
    do
    {
        do
        {
            printf("EJERCICIOS                                                 INGRESAR");
            printf("\nEJERCICIO 1  ...................................................  1");
            printf("\nEJERCICIO 2  ...................................................  2");
            printf("\nEJERCICIO 3  ...................................................  3");
            printf("\nEJERCICIO 4  ...................................................  4");
            printf("\nEJERCICIO 5  ...................................................  5");
            printf("\nEJERCICIO 6  ...................................................  6");
            printf("\nEJERCICIO 7  ...................................................  7");
            printf("\nEJERCICIO 8  ...................................................  8");
            printf("\nEJERCICIO 9  ...................................................  9");
            printf("\nEJERCICIO 10 ................................................... 10");
            printf("\nEJERCICIO 11 ................................................... 11");
            printf("\nEJERCICIO 12 ................................................... 12");
            printf("\nEJERCICIO 13 ................................................... 13\n");
            printf("\nIngrese el ejercicio: ");
            scanf("%i",&ejercicio);
        }
        while(ejercicio!=1 && ejercicio!=2 && ejercicio!=3 && ejercicio!=4 && ejercicio!=5 && ejercicio!=6 && ejercicio!=7 && ejercicio!=8 && ejercicio!=9 && ejercicio!=10 && ejercicio!=11 && ejercicio!=12 && ejercicio!=13 && ejercicio!=0);
        if(ejercicio!=0)
        {
            printf("\nEJERCICIO %i\n\n",ejercicio);
        }
        switch(ejercicio)
        {
            case 1:
            {
                ejercicio1();
            }
            break;
            case 2:
            {
                ejercicio2();
            }
            break;
            case 3:
            {
                ejercicio3();
            }
            break;
            case 4:
            {
                ejercicio4();
            }
            break;
            case 5:
            {
                ejercicio5();
            }
            break;
            case 6:
            {
                ejercicio6();
            }
            break;
            case 7:
            {
                ejercicio7();
            }
            break;
            case 8:
            {
                ejercicio8();
            }
            break;
            case 9:
            {
                ejercicio9();
            }
            break;
            case 10:
            {
                ejercicio10();
            }
            break;
            case 11:
            {
                ejercicio11();
            }
            break;
            case 12:
            {
                ejercicio12();
            }
            break;
            case 13:
            {
                ejercicio13();
            }
            break;
        }
    }
    while(ejercicio!=0);
    printf("\nTP2 TERMINADO\n");
    printf("\nVersion 1.7\n");
    return 0;
}
Pila cargarPila()                                       //INICIO FUNCION CARGAR ELEMENTOS EN UNA PILA
{
    Pila pilaAux;
    char continuar;
    inicpila(&pilaAux);
    printf("Ingrese los elementos de la pila:\n\n");
    do
    {
        leer(&pilaAux);
        printf("Desea ingresar otro elemento? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    while(continuar!='n');
    return pilaAux;
}                                                       //FIN FUNCION CARGAR ELEMENTOS EN UNA PILA
float sumarPila(Pila pila)                              //INICIO FUNCIONSUMARPILA
{
    float suma=0;
    while(!pilavacia(&pila))
    {
        suma=suma+tope(&pila);
        desapilar(&pila);
    }
    return suma;
}                                                       //FIN FUNCION SUMARPILA
float contarPila(Pila pila)                             //INICIO FUNCION CONTARPILA
{
    float contador=0;
    while(!pilavacia(&pila))
    {
        contador++;
        desapilar(&pila);
    }
    return contador;
}                                                       //FIN FUNCION CONTARPILA
Pila ordenarPila(Pila pilaDesordenada)                  //INICIO FUNCION ORDENAR UNA PILA
{
    Pila ordenada,aux;
    inicpila(&ordenada);
    inicpila(&aux);
    while(!pilavacia(&pilaDesordenada))
    {
        if(tope(&pilaDesordenada)<tope(&ordenada))
        {
            apilar(&ordenada,desapilar(&pilaDesordenada));
        }
        else
        {
            while(tope(&pilaDesordenada)>tope(&ordenada))
            {
                apilar(&aux,desapilar(&ordenada));
            }
            apilar(&ordenada,desapilar(&pilaDesordenada));
            while(!pilavacia(&aux))
            {
                apilar(&ordenada,desapilar(&aux));
            }
        }
    }
    return ordenada;
}                                                       //FIN FUNCION ORDENAR UNA PILA
Pila copiarPila(Pila pila)                              //INICIO FUNCION COPIAR PILA
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        apilar(&aux,desapilar(&pila));
    }
    return aux;
}                                                       //FIN FUNCION COPIAR PILA
Pila unir2Pilas(Pila pila1,Pila pila2)                  //INICIO FUNCION UNIR2PILAS
{
    Pila aux,unionPila;
    inicpila(&aux);
    inicpila(&unionPila);
    while(!pilavacia(&pila1))
    {
        apilar(&aux,desapilar(&pila1));
    }
    while(!pilavacia(&pila2))
    {
        apilar(&aux,desapilar(&pila2));
    }
    unionPila=ordenarPila(aux);                         //FUNCION ORDENARPILA
    return unionPila;
}                                                       //FIN FUNCION UNIR2PILAS
Pila eliminarDuplicados(Pila pila)                      //INICIO FUNCION ELIMINARDUPLICADOS
{
    Pila aux,unionPila;
    inicpila(&unionPila);
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        if(tope(&pila)==tope(&unionPila))
        {
            apilar(&aux,desapilar(&pila));
        }
        else
        {
            apilar(&unionPila,desapilar(&pila));
        }
    }
    return unionPila;
}                                                       //FIN FUNCION ELIMINARDUPLICADOS
Pila mazoRandom(int manos)                              //INICIO FUNCION MAZORANDOM
{
    Pila mazoAux;
    inicpila(&mazoAux);
    int i;
    time_t t;
    srand((unsigned) time(&t));                         //INICIALIZA EL GENERADOR DE NUMEROS RANDOM
    for(i=0;i<4*manos;i++)
    {
        apilar(&mazoAux,1+rand()%4);
    }
    //mostrar(&mazoAux);
    return mazoAux;
}                                                       //FIN MAZORANDOM
void ejercicio1()
{
    //Sumar los elementos de una pila. (usar variables)
    float suma=0;
    Pila pila;
    inicpila(&pila);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("La pila es:");
    mostrar(&pila);
    suma=sumarPila(pila);                               //FUNCION SUMARPILA
    printf("La suma de los elementos de la pila es: %.0f\n\n",suma);
}
void ejercicio2()
{
    //Contar los elementos de una pila. (usar variables)
    float contador=0;
    Pila pila,aux;
    inicpila(&pila);
    inicpila(&aux);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("La pila es:");
    mostrar(&pila);
    contador=contarPila(pila);                          //FUNCION CONTARPILA
    printf("La cantidad de elementos de la pila es: %.0f\n\n",contador);
}
void ejercicio3()
{
    //Calcular el promedio de los valores de una pila. (usar variables)
    float contador=0,suma=0,promedio=0;
    Pila pila,aux;
    inicpila(&pila);
    inicpila(&aux);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("La pila es:");
    mostrar(&pila);
    suma=sumarPila(pila);                               //FUNCION SUMARPILA
    contador=contarPila(pila);                          //FUNCION CONTARPILA
    promedio=suma/contador;
    printf("El promedio de los valores de la pila es: %.2f\n\n",promedio);
}
void ejercicio4()
{
    //Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
    Pila pila,aux,menor;
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&menor);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("La pila es:");
    mostrar(&pila);
    apilar(&menor,desapilar(&pila));
    while(!pilavacia(&pila))
    {
        if(tope(&menor)>tope(&pila))
        {
            apilar(&aux,desapilar(&menor));
            apilar(&menor,desapilar(&pila));
        }
        else
        {
            apilar(&aux,desapilar(&pila));
        }
    }
    printf("El menor elemento de la pila es: %i\n\n",tope(&menor));
}
void ejercicio5()
{
    //Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas)
    Pila pila,ordenada,aux;
    inicpila(&pila);
    inicpila(&ordenada);
    inicpila(&aux);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    ordenada=ordenarPila(pila);                         //FUNCION ORDENARPILA
    printf("La pila ordenada es:");
    mostrar(&ordenada);
    printf("Ingrese un elemento que desee agregar a la pila:\n\n");
    leer(&ordenada);
    ordenada=ordenarPila(ordenada);                     //FUNCION ORDENARPILA
    printf("\nLa pila ordenada es:");
    mostrar(&ordenada);
}
void ejercicio6()
{
    //Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base).
    //Esto se llama m�todo de ordenaci�n por selecci�n.
}
void ejercicio7()
{
    //Determinar si un elemento buscado est� dentro de una pila. Al encontrarlo, finalizar la b�squeda.
    int busqueda;
    Pila pila,aux;
    inicpila(&pila);
    inicpila(&aux);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("\nLa pila es:");
    mostrar(&pila);
    printf("Ingrese el elemento que desea buscar: ");
    scanf("%i",&busqueda);
    printf("\n");
    while((busqueda!=tope(&pila))&&(!pilavacia(&pila)))
    {
        apilar(&aux,desapilar(&pila));
    }
    if(pilavacia(&pila))
    {
        printf("El elemento buscado no esta en la pila\n\n");
    }
    else
    {
        printf("El elemento buscado esta en la pila\n\n");
    }
}
void ejercicio8()
{
    //Eliminar un elemento de una pila.
    //El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
    int busqueda;
    Pila pila,aux1,aux2;
    inicpila(&pila);
    inicpila(&aux1);
    inicpila(&aux2);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    printf("\nLa pila es:");
    mostrar(&pila);
    printf("Ingrese el elemento que desea eliminar: ");
    scanf("%i",&busqueda);
    printf("\n");
    while((busqueda!=tope(&pila))&&(!pilavacia(&pila)))
    {
        apilar(&aux1,desapilar(&pila));
    }
    if(pilavacia(&pila))
    {
        printf("El elemento buscado no esta en la pila, por lo que no fue eliminado\n\n");
    }
    else
    {
        printf("El elemento buscado esta en la pila y fue eliminado una sola vez\n\n");
        apilar(&aux2,desapilar(&pila));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&pila,desapilar(&aux1));
    }
    printf("La pila final es:");
    mostrar(&pila);
}
void ejercicio9()
{
    //Verificar si una pila DADA es capic�a.
    Pila pila,aux1,aux2,aux3;
    inicpila(&pila);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);
    pila=cargarPila(pila);                              //FUNCION CARGARPILA
    aux1=copiarPila(pila);                              //FUNCION COPIARPILA
    aux2=copiarPila(aux1);                              //FUNCION COPIARPILA
    printf("La pila original es:");
    mostrar(&pila);
    while((tope(&aux1)==tope(&aux2))&&!pilavacia(&aux1)&&!pilavacia(&aux2))
    {
        apilar(&aux3,desapilar(&aux1));
        apilar(&aux3,desapilar(&aux2));
    }
    if(!pilavacia(&aux1)||!pilavacia(&aux2))
    {
        printf("La pila no es capicua\n\n");
    }
    else
    {
        printf("La pila es capicua\n\n");
    }
}
void ejercicio10()
{
    //Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre s� mismo), realizar un programa que calcule en la pila C la operaci�n de uni�n.
    Pila pilaA,pilaB,unionAB;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&unionAB);
    printf("PilaA:\n\n");
    pilaA=cargarPila(pilaA);                            //FUNCION CARGARPILA
    printf("PilaB:\n\n");
    pilaB=cargarPila(pilaB);                            //FUNCION CARGARPILA
    printf("Primer conjunto:");
    mostrar(&pilaA);
    printf("Segundo conjunto:");
    mostrar(&pilaB);
    unionAB=unir2Pilas(pilaA,pilaB);                    //FUNCION UNIR2PILAS
    unionAB=eliminarDuplicados(unionAB);                //FUNCION ELIMINARDUPLICADOS
    printf("Union de los conjuntos:");
    mostrar(&unionAB);
}
void ejercicio11()
{
    //Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila tambi�n ordenada en forma creciente (ORDENADAFINAL).
    Pila pila1,pila2,ordenada1,ordenada2,ordenadaFinal;
    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);
    pila1=cargarPila(pila1);                            //FUNCION CARGARPILA
    pila2=cargarPila(pila2);                            //FUNCION CARGARPILA
    printf("La pila1 es:");
    mostrar(&pila1);
    printf("La pila2 es:");
    mostrar(&pila2);
    ordenada1=ordenarPila(pila1);                       //FUNCION ORDENARPILA
    ordenada2=ordenarPila(pila2);                       //FUNCION ORDENARPILA
    printf("La pila1 ordenada es:");
    mostrar(&ordenada1);
    printf("La pila2 ordenada es:");
    mostrar(&ordenada2);
    ordenadaFinal=unir2Pilas(ordenada1,ordenada2);      //FUNCION UNIR2PILAS
    printf("La pila final ordenada es:");
    mostrar(&ordenadaFinal);
}
void ejercicio12()
{
    //Dada la pila ORIGEN ordenarla en forma ascendente por m�todo de inserci�n dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
}
void ejercicio13()
{
    //Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador.
    //Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas las cartas (las de �l y las de su rival) en su pila de puntos.
    //En caso de empate (y para simplificar) siempre gana el jugador1.
    //Simular la ejecuci�n del juego de tal manera que dada una pila MAZO (con un n�mero de elementos m�ltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado.
    //Utilizar las pilas auxiliares que crea conveniente.
    int i,j1,j2,m,manos,suma1=0,suma2=0,puntaje1=0,puntaje2=0;
    char continuar;
    Pila mazo,jugador1,jugador2,descarte1,descarte2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&descarte1);
    inicpila(&descarte2);
    printf("Ingrese la cantidad de manos que desea jugar: ");
    scanf("%i",&manos);
    mazo=mazoRandom(manos);
    printf("\nMazo:");
    mostrar(&mazo);
    printf("Enter para jugar la primera mano: ");
    fflush(stdin);
    scanf("%c",&continuar);
    for(m=1;m<manos+1;m++)
    {
        printf("\nMano: %i\n",m);
        for(i=0;i<2;i++)                                //INICIO REPARTO CARTAS
        {
            if(suma1<suma2)
            {
                apilar(&jugador1,desapilar(&mazo));
                apilar(&jugador2,desapilar(&mazo));
            }
            else
            {
                apilar(&jugador2,desapilar(&mazo));
                apilar(&jugador1,desapilar(&mazo));
            }
        }                                               //FIN REPARTO CARTAS
        printf("\nMano del jugador 1:");
        mostrar(&jugador1);
        suma1=0;
        suma1=sumarPila(jugador1);
        printf("Mano del jugador 2:");
        mostrar(&jugador2);
        suma2=0;
        suma2=sumarPila(jugador2);
        printf("Puntaje de esta ronda del jugador 1: %i\n",suma1);
        printf("Puntaje de esta ronda del jugador 2: %i\n",suma2);
        if(suma2>suma1)
        {
            puntaje2=puntaje2+suma1+suma2;
            printf("\nEl jugador 2 se queda con los puntos.\n");
            for(j2=0;j2<2;j2++)                         //INICIO DESCARTE CARTAS
            {
                apilar(&descarte2,desapilar(&jugador1));
                apilar(&descarte2,desapilar(&jugador2));
            }                                           //FIN DESCARTE CARTAS
        }
        else
        {
            puntaje1=puntaje1+suma1+suma2;
            printf("\nEl jugador 1 se queda con los puntos.\n");
            for(j1=0;j1<2;j1++)                         //INICIO DESCARTE CARTAS
            {
                apilar(&descarte1,desapilar(&jugador1));
                apilar(&descarte1,desapilar(&jugador2));
            }                                           //FIN DESCARTE CARTAS
        }
        printf("\nPuntaje total del jugador 1: %i",puntaje1);
        printf("\nPuntaje total del jugador 2: %i\n",puntaje2);
        if(m==manos-1)
        {
            printf("\nEnter para jugar la ultima mano: ");
            fflush(stdin);
            scanf("%c",&continuar);
        }
        if(m<manos-1)
        {
            printf("\nEnter para jugar la siguiente mano: ");
            fflush(stdin);
            scanf("%c",&continuar);
        }
    }
    if(puntaje2>puntaje1)
    {
        printf("\nFin del juego: El jugador 2 ha ganado con %i puntos contra %i puntos del jugador 1.\n\n",puntaje2,puntaje1);
    }
    else
    {
        printf("\nFin del juego: El jugador 1 ha ganado con %i puntos contra %i puntos del jugador 2.\n\n",puntaje1,puntaje2);
    }
}
