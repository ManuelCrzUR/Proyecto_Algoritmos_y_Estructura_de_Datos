#include "Librerias/mapas.h"
#include "Librerias/hash.h"
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

    cout << "Prueba e implementacioń de libreria (hash.h)" << endl;
    cout << "\n";
    HashMap tablita;

    tablita.insertar(0, "karen");
    tablita.insertar(1, "manu");
    tablita.insertar(2, "sanny");
    tablita.insertar(3, "joseph");
    tablita.insertar(4, "danielito");
    tablita.insertar(5, "gofrecito");
    tablita.insertar(6, "laurita");
    tablita.insertar(7, "polito");
    tablita.insertar(8, "the police");
    tablita.insertar(9, "rosarista inicial");

    cout << "   Se remueve el elemento 1: " << tablita.obtenerValor(1) << endl;
    tablita.remover(1);

    cout << "   Se obtiene el valor de 3: " << tablita.obtenerValor(3) << endl;

    cout << "   Se comprueba si la tabla esta vacia: " << tablita.estaVacio(2) << endl;

    cout << "   Se obtiene el tamaño de la tabla :" << tablita.obtenerTamaño() << endl;

    cout << "   Se añade el elemento (12, dalicito)" << endl;
    tablita.insertar(12, "dalicito");

    cout<<"\n";

    cout << "   Se muestra la tabla hash" << endl;
    cout << "\n";
    tablita.mostrarMapaHash();
    cout << "\n";


    cout << "Prueba e Implementación de libreria (arbolesbinarios.h)" << endl;
    cout << "\n";
    NodoAB *raiz_arbol = NULL;

    raiz_arbol = insertar(raiz_arbol, 69);
    raiz_arbol = insertar(raiz_arbol, 13);
    raiz_arbol = insertar(raiz_arbol, 4);
    raiz_arbol = insertar(raiz_arbol, 28);

    cout << "   " <<"Elementos en PreOrden: " << endl;
    PreOrden(raiz_arbol);
    cout<<"\n"<<"\n";

    cout << "Elementos en Inorden: " << endl;
    InOrden(raiz_arbol);
    cout<<"\n"<<"\n";

    cout << "   " << "Elementos en PosOrden: " << endl;
    PosOrden(raiz_arbol);
    cout<<"\n"<<"\n";

    cout << "   " << "Buscar el elemento 13: " << endl;
    cout<< "   " <<buscar(raiz_arbol, 13) << endl;
    cout<<"\n";

    cout << "   " << "Buscar el elemento 14: " << endl;
    cout<< "   " <<buscar(raiz_arbol, 14) << endl;
    cout<<"\n";

    cout << "   " << "Sumar los elementos del arbol: " << endl;
    cout<< "   " <<Sumar(raiz_arbol) <<  endl;
    cout<<"\n";

    cout << "   " << "Contar los nodos mayores que 14" << endl;
    cout<< "   " <<contar(raiz_arbol, 14) << endl;
    cout<<"\n";

    cout << "   " << "Encontrar el nodo del número 69" << endl;
    cout << "   " << encontrar_nodo(raiz_arbol, 69) << endl;
    cout << "\n";

    cout << "   " << "Encontrar el camino entre el elemnto 13 y 69" << endl;
    cout<< "   " <<camino(raiz_arbol, 13, 69) << endl;
    cout<<"\n";

    cout << "   " << "Encontrar el peso del arbol" << endl;
    cout<< "   " <<peso(raiz_arbol) << endl;
    cout<<"\n";

    cout << "   " << "Contar las hojas del arbol" << endl;
    cout<< "   " <<hojas(raiz_arbol) << endl;
}