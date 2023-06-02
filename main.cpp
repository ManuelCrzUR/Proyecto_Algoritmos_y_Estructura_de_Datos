#include "Librerias/mapas.h"
#include "Librerias/arbolesbinarios.h"
#include <iostream>

using namespace std;

int main() {
    Mapa mapa= Mapa();

    cout << "\n";

    cout << "Prueba e Implementación de libreria (mapas.h)" << endl;
    cout << "\n";
    mapa.Insertar("manu", 1);
    mapa.Insertar("sanny", 2);
    mapa.Insertar("marisando", 3);

    cout << "   Valor de manu: " << mapa.ObtenerValor("manu");
    cout<<"\n";

    cout << "   Existencia de sanny: " << mapa.ExisteClave("sanny");
    cout<<"\n";

    mapa.EliminarElemento("sanny");

    cout << "   El mapa esta viacio?: " << mapa.EstaVacio();
    cout<<"\n";

    cout << "   El tamaño del mapa es: " << mapa.ObtenerTamaño();
    cout<<"\n";

    cout << "   Los elementos del mapa son:" << endl;
    mapa.MostrarElementos();
    cout << "\n";

    cout << "Prueba e Implementación de la libreria (arbolesbinarios.h)" << endl;

        //Nota: Usar un cout<<"\n" en intermedio para separar

    //Para declarar un apuntador para un NodoAB que incluya la raiz es:
    //NodoAB *nombredelaraiz
    NodoAB *raiz_arbol;

    //Para usar la función insertar se utiliza la siguiente sintaxis:
    //nombredelaraiz=insertar(nombredelaraiz, val)

    raiz_arbol = insertar(raiz_arbol, 69);

    raiz_arbol = insertar(raiz_arbol, 13);

    raiz_arbol = insertar(raiz_arbol, 4);

    raiz_arbol = insertar(raiz_arbol, 28);


    //Para usar las funciones PreOrden, InOrden, PosOrden, la sintaxis es:
        //PreOrden(nombredelaraiz)
        //InOrden(nombredelaraiz)
        //PosOrden(nombredelaraiz)

    PreOrden(raiz_arbol);
    cout<<"\n";
    InOrden(raiz_arbol);
    cout<<"\n";
    PosOrden(raiz_arbol);
    cout<<"\n";

    //Para la funcion buscar, se utiliza la siguiente la siguiente sintaxis:
        //buscar(nombredelaraiz, num)
        //Par ver el resultado: cout<<buscar(nombredelaraiz, num)
    cout<<buscar(raiz_arbol, 13);
    cout<<"\n";
    cout<<buscar(raiz_arbol, 14);
    cout<<"\n";

    //Para la funcion Sumar, se utiliza la siguiente la siguiente sintaxis:
    //Sumar(nombredelaraiz)
    //Par ver el resultado: cout<<Sumar(nombredelaraiz)

    cout<<Sumar(raiz_arbol);
    cout<<"\n";

    //Para la funcion contar, se utiliza la siguiente la siguiente sintaxis:
    //contar(nombredelaraiz, num)
    //Par ver el resultado: cout<<buscar(nombredelaraiz, num)

    cout<<contar(raiz_arbol, 14);
    cout<<"\n";

    //Para usar la función encontrar_nodo se utiliza la siguiente sintaxis:
    //encontrar_nodo(nombredelaraiz, val)

    encontrar_nodo(raiz_arbol, 69);

    //Para la funcion camino, se utiliza la siguiente la siguiente sintaxis:
    //camino(nombredelaraiz, num1, num2)
    //Para ver el resultado: cout<<buscar(nombredelaraiz, num1, num2)

    cout<<camino(raiz_arbol, 13, 69);
    cout<<"\n";

    //Para la funcion peso, se utiliza la siguiente la siguiente sintaxis:
    //peso(nombredelaraiz)
    //Para ver el resultado: cout<<peso(nombredelaraiz)

    cout<<peso(raiz_arbol);
    cout<<"\n";

    //Para la funcion hojas, se utiliza la siguiente la siguiente sintaxis:
    //hojas(nombredelaraiz)
    //Para ver el resultado: cout<<hojas(nombredelaraiz)

    cout<<hojas(raiz_arbol);
}