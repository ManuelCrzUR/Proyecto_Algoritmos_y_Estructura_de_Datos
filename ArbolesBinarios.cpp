//Esta parte de la librería recoge la implementación de un árbol binario y las funciones que se necesitan para su funcionamiento.

#include <iostream>

using namespace std;

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
    //Los Argumentos de la función son:
        //NodoAB *raiz = Un apuntador a un NodoAB que representa la raiz del árbol
        //int val = Una variable de tipo int, que indica el valor del nodo que se quiere insertar
    //¿Que retorna?:
        //Un apuntador a un NodoAB que representa la raiz del árbol
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

void PreOrden(NodoAB *raiz){
    if(raiz!=NULL){
        cout<<raiz->valor;
        PreOrden(raiz->sai);
        PreOrden(raiz->sad);
    }
};
void InOrden(NodoAB *raiz){
    if(raiz!=NULL){
        InOrden(raiz->sai);
        cout<<raiz->valor;
        InOrden(raiz->sad);

    }
};
void PosOrden(NodoAB *raiz){
    if(raiz!=NULL){
        PosOrden(raiz->sai);
        PosOrden(raiz->sad);
        cout<<raiz->valor;
    }
};

int buscar(NodoAB *raiz, int num){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->valor==num){
        return 1;
    }
    return(buscar(raiz->sai,num))+(buscar(raiz->sad,num));

};
int Sumar(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    return (raiz->valor)+(Sumar(raiz->sai))+(Sumar(raiz->sad));
};

int contar(NodoAB *raiz,int num){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->valor>num){
        return 1+ contar(raiz->sai,num)+ contar(raiz->sad,num);
    }
    return contar(raiz->sai,num)+ contar(raiz->sad,num);
};
NodoAB *encontrar_nodo(NodoAB *raiz,int num){
    if(raiz->valor==num){
        return raiz;
    }
    if(buscar(raiz->sai,num)){
        return encontrar_nodo(raiz->sai,num);
    }
    return encontrar_nodo(raiz->sad,num);
};
int camino(NodoAB *raiz,int num1, int num2){
    if(buscar(raiz,num1)&& buscar(raiz,num2)){
        NodoAB *p1= encontrar_nodo(raiz,num1), *p2= encontrar_nodo(raiz,num2);

        if(buscar(p1,num2)|| buscar(p2,num1)) {
            return 1;
        }
    }
    return 0;
};

int peso(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    return 1 + (peso(raiz->sai)) + (peso(raiz->sad));
};
int hojas(NodoAB *raiz){
    if (raiz==NULL){
        return 0;
    }
    if(raiz->sai==NULL&&raiz->sad==NULL){
        return 1;
    }
    return hojas(raiz->sai)+ hojas(raiz->sad);
};



int main()
{
   

    
    return 0;
}
