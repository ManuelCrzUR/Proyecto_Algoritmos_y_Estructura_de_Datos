/**
 * @file mapas.cpp
 * @author Manuel Cruz Garrote (manuels.cruz@urosario.edu.co)
 * @brief Ejemplo de implementación de libreria de funciones de los mapas
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Mapa {
    private:
        map<string, int> mapa_;

    public:
        Mapa() {}

        /**
         * @brief Fucnión que inserta el par (clave, valor) en un mapa.
         * 
         * Esta funcion recibe un string y un entero como parametro, siendo el string la clave del valor entero. Esta funcion añade esta pareja al mapa respectivo
         * 
         * @param pClave Lugar que almacena un valor en el mapa
         * @param pValor Valor que pertenece a la clave que se asigna en el mapa
         */
        void Insertar(string pClave, int pValor) {
            mapa_[pClave] = pValor;
        }

        /**
         * @brief Función que devuelve un valor de tipo entero, que se encuentra en una clave del mapa.
         * 
         * Esta función recibe un string que pertenece a una clave del mapa. Cuando encuentra la clave, accede al valor a esta y lo retorna.
         * 
         * @param pClave Lugar que almacena un valor en el mapa.
         * @return (int) Valor que pertenece a la clave que se ingreso.
         */
        int ObtenerValor(string pClave) {
            return mapa_.at(pClave);
        }

        /**
         * @brief Función que comprueba si una clave existe en un mapa.
         * 
         * Esta función recibe un string que pertenece a la clave, comprueba en el mapa si la clave esta contenida en el mapa.
         * 
         * 
         * @param pClave Lugar que almacena un valor en el mapa.
         * @return true si la clave pertenece al mapa
         * @return false si la clave no pertenece al mapa
         */
        bool ExisteClave(string pClave) {
            return mapa_.count(pClave) > 0;
        }

        /**
         * @brief Función que elimina los elementos en una clave.
         * 
         * Esta función recibe un string que pertenece a una clave dentro del mapa y elimina la informacioń que se encuentre contenida en la clave.
         * 
         * @param pClave Lugar que almacena un valor en el mapa.
         */
        void EliminarElemento(string pClave) {
            mapa_.erase(pClave);
        }

        /**
         * @brief Función que comprueba si un mapa esta vacio.
         * 
         * Esta Función evalua si el mapa tiene información alamacenada en si.
         * 
         * @return true si el mapa cuenta con información en su interior
         * @return false si el mapa no cuenta con información en su interior
         */
        bool EstaVacio() {
            return mapa_.empty();
        }

        /**
         * @brief Función que identifica la cantidad de elementos en un mapa.
         * 
         * Esta función identifica la cantidad de elementos que se encuentran en un arbol binario y las retorna en un entero
         * 
         * @return int Numero de elementos que se encuentran en el mapa
         * 
         */
        int ObtenerTamaño() {
            return mapa_.size();
        }

        /**
         * @brief Función que imprime en la consola el contenido del mapa.
         * 
         * Esta función recorre todos los elementos que existen y pertenecen al mapa, usa un ciclo for con un iterador el cual imprime en la consola el contenido de los mapas en el formato "llave - valor"
         * 
         */
        void MostrarElementos() {
            for (auto& entry : mapa_) {
                cout << entry.first << ": " << entry.second << endl;
            }
        }
};

int main() {
    return 0;
}