#ifndef UNTITLED1_ARBOLESBINARIOS_H
#define UNTITLED1_ARBOLESBINARIOS_H

#include <iostream>

using namespace std;

//Esta parte de la librería recoge la implementación de un árbol binario y las funciones que se necesitan para su funcionamiento

//La clase NodoAB, inicializa el nodo o elemento del árbol binario y posee tres atributos:
//valor: variable de tipo int, el cual representa el valor numerico de cada Nodo
//sai: Es un apuntador a un NodoAB que representa al hijo izquierdo del árbol
//sad:Es un apuntador a un NodoAB que representa al hijo derecho del árbol

class NodoAB{ //Para construir un nodoAB, se utiliza la siguiente sintaxis: NodoAB *nombredelnodo = new NodoAB
public:
    int valor;
    NodoAB *sai;
    NodoAB *sad;
};

// La función Insertar, como lo indica su nombre añade un nodoAB al árbol binario. Esta tiene una condición en particular y consiste en que los valores menores a la raíz van en el subárbol izquierdo y los otros en el derecho.
// Los Argumentos de la función son:
// NodoAB *raiz = Un apuntador a un NodoAB que representa la raiz del árbol
// int val = Una variable de tipo int, que indica el valor del nodo que se quiere insertar
// ¿Que retorna?:
// Un apuntador a un NodoAB que representa la raiz del árbol

NodoAB *insertar(NodoAB *raiz, int val){
    NodoAB *nuevo;
    if(raiz==NULL){
        nuevo=new NodoAB;
        nuevo->valor=val;
        nuevo->sai=NULL;
        nuevo->sad=NULL;
        raiz=nuevo;
        return raiz;
    }else if(raiz->valor > val){
        raiz->sai=insertar(raiz->sai, val);
    }else{
        raiz->sad=insertar(raiz->sad, val);
    }
    return raiz;
};

//La funcion PreOrden recorre el arbol e imprime el valor de sus nodos empezando por la raiz, luego aplicando PreOrden en el subarbol izquierdo y luego en el subarbol derecho.
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
//¿Que retorna?
// Como es una función de tipo void, no retorna nada.

void PreOrden(NodoAB *raiz){
    if(raiz!=NULL){
        cout<<raiz->valor;
        PreOrden(raiz->sai);
        PreOrden(raiz->sad);
    }
};

//La funcion InOrden recorre el arbol e imprime el valor de sus nodos empezando por aplicar InOrden en el subarbol izquierdo, luego la raiz y finalmente aplicar InOrden en el subarbol derecho.
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
//¿Que retorna?
// Como es una función de tipo void, no retorna nada.

void InOrden(NodoAB *raiz){
    if(raiz!=NULL){
        InOrden(raiz->sai);
        cout<<raiz->valor;
        InOrden(raiz->sad);

    }
};

//La funcion PosOrden recorre el arbol e imprime el valor de sus nodos empezando luego aplicando PosOrden en el subarbol izquierdo, luego PosOrden en el subarbol derecho y finalmente la raiz
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
//¿Que retorna?
// Como es una función de tipo void, no retorna nada.

void PosOrden(NodoAB *raiz){
    if(raiz!=NULL){
        PosOrden(raiz->sai);
        PosOrden(raiz->sad);
        cout<<raiz->valor;
    }
};

// La funcion buscar, recibe un numero y busca si ese valor corresponde a un NodoAB en el arbol.
// Los argumentos de la función son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// num: Una variable de tipo int, que corresponde al valor del número que se planea buscar.
//¿Que retorna?
// 1: Si el valor ingresado corresponde a un NodoAB que esta en el árbol
// 0: Si el valor ingresado no corresponde a un NodoAB que esta en el árbol

int buscar(NodoAB *raiz, int num){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->valor==num){
        return 1;
    }
    return(buscar(raiz->sai,num))+(buscar(raiz->sad,num));

};

// La funcion Sumar recibe la raiz de un arbol y suma todos los nodos que hay en dicho arbol.
// Los argumentos de la función son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// ¿Que retorna?
// 0: Si el arbol esta vacio
// El valor entero de la suma de los valores de todos los nodos del arbol.

int Sumar(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    return (raiz->valor)+(Sumar(raiz->sai))+(Sumar(raiz->sad));
};

// La función contar cuenta los nodos cuyos valores sean menores a el numero entero recibido como argumento de la funcion.
//Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// num: Variable de tipo int, que corresponde al numero con el que se quiere comparar el valor de los nodos
//¿Que retorna?
// 0: Si el arbol esta vacio
// El numero de nodos en el arbol cuyos valores sean mayores a num.

int contar(NodoAB *raiz,int num){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->valor>num){
        return 1+ contar(raiz->sai,num)+ contar(raiz->sad,num);
    }
    return contar(raiz->sai,num)+ contar(raiz->sad,num);
};

// La función encontrar_nodo recibe un numero y encuentra el nodo del arbol cuyo valor corresponde al numero recibido.
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// num: Variable de tipo int, que corresponde al valor del nodo que se quiere encontrar_nodo
//¿Que retorna?
// Un apuntador a un nodo de la clase NodoAB que corresponde al nodo del arbol cuyo valor corresponde a num
// Si no encuentra: Un apuntador a un nodo de la clase NodoAB que sea igual a NULL

NodoAB *encontrar_nodo(NodoAB *raiz,int num){
    if(raiz->valor==num){
        return raiz;
    }
    if(buscar(raiz->sai,num)){
        return encontrar_nodo(raiz->sai,num);
    }
    return encontrar_nodo(raiz->sad,num);
};

// La funcion camino recibe dos numeros y verifica si existe un camino para llegar del numero 1 al numero 2.
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// num1: Una variable de tipo int que corresponde al valor del nodo del arbol destinatario
// num2: Una variable de tipo int que corresponde al valor del nodo destino
//¿Que retorna?
// 0: Si no existe camino entre el nodo que corresponde a num 1 y el nodo que corresponde a num num2
// 1: Si existe camino entre el nodo que corresponde a num 1 y el nodo que corresponde a num num2

int camino(NodoAB *raiz,int num1, int num2){
    if(buscar(raiz,num1)&& buscar(raiz,num2)){
        NodoAB *p1= encontrar_nodo(raiz,num1), *p2= encontrar_nodo(raiz,num2);

        if(buscar(p1,num2)|| buscar(p2,num1)) {
            return 1;
        }
    }
    return 0;
};

// La funcion peso cuenta todos los nodos que hay en el arbol
//Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
//¿Que retorna?
// 0: Si el arbol esta vacio
// El numero de la cantidad total de nodos en el arbol

int peso(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    return 1 + (peso(raiz->sai)) + (peso(raiz->sad));
};

// La funcion hojas cuenta el total de hojas que en el arbol
// Los argumentos de la funcion son:
// NodoAB *raiz: Un apuntador a un NodoAB que representa la raiz del árbol
// ¿Que retorna?
// 0: Si el arbol esta vacio
// El numero de la cantidad total de hojas en el arbol

int hojas(NodoAB *raiz){
    if (raiz==NULL){
        return 0;
    }
    if(raiz->sai==NULL&&raiz->sad==NULL){
        return 1;
    }
    return hojas(raiz->sai)+ hojas(raiz->sad);
};

