/**
 * @file tablas_hash.cpp
 * @author Manuel Cruz Garrote (manuels.cruz@urosario.edu.co)
 * @brief Archivo, el cual implementa el funcionamiento de una tabla hash o mapa hash, usando multiples de sus funcioens y con una proxima implementación a libreria
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
 * @brief La clase "HashMap" realiza la implementacioń para un mapa hash, en el privado mantiene una longitud de 10, guarda su estructura y almacena la función hash, la cual es responsable de dividir el almacenamiento del mapa
 * 
 */
class HashMap {
    private:
        static const int tamaño = 10;
        list<pair<int, string>> tabla[tamaño];

        /**
         * @brief Función que retorna el indice de la ubicación de la información en la tabla hash.
         * 
         * Esta función recibe un entero el cual se procesa dependiendo de la funcion hash, en este caso lo divide y toma el valor entero.
         * 
         * @param pLlave Lugar, el cual almacena la información del mapa
         * @return (int) Valor que pertenece al indice en el cual se va a almacenar la información en el mapa hash
         */
        int funcionHash(int pLlave) {
            return pLlave % tamaño;
        }

    public:
        /**
         * @brief Función que añade la pareja (Llave, Valor) en el espacio perteneciente en la tabla hash.
         * 
         * Esta función, inserta información a la tabla hash, esta mantiene un formatod de parejas ordenadas como antes se describio. Si el espacio de memoria se encuentra ocupado, este realiza un pushback, para que se almacene de ultimas en los elementos correspondientes a ese indice
         * 
         * 
         * @param pLlave Lugar, el cual almacena la información del mapa
         * @param pValor Información que sera almacenada en pLlave en un formato de pareja
         */
        void insertar(int pLlave, const string& pValor) {
            int indice = funcionHash(pLlave);

            for (auto it = tabla[indice].begin(); it != tabla[indice].end(); ++it) {
                if (it->first == pLlave) {
                    it->second = pValor;
                    return;
                }
            }

            tabla[indice].push_back(make_pair(pLlave, pValor));
        }

        /**
         * @brief Función que elimina una pareja ordenada de un espacio de memoria dentro del mapa hash.
         * 
         * Esta función elimina la pareja ordenada (Llave, Valor) usando la Llave de un elemento
         * 
         * @param pLlave Lugar, el cual almacena la información del mapa
         */
        void remover(int pLlave) {
            int indice = funcionHash(pLlave);

            for (auto it = tabla[indice].begin(); it != tabla[indice].end(); ++it) {
                if (it->first == pLlave) {
                    tabla[indice].erase(it);
                    return;
                }
            }
        }

        /**
         * @brief Función que retorna la informacioń que se encuentre en una llave.
         * 
         * Esta función obtiene el Valor de la pareja (Llave, Valor) accediendo al indice en el cual se encuetra almacenado.
         * 
         * @param pLlave Lugar, el cual almacena la información del mapa
         * @return (string) Valor que pertenece a la llave de ingreso
         */
        string obtenerValor(int pLlave) {
            int indice = funcionHash(pLlave);

            for (const auto& par : tabla[indice]) {
                if (par.first == pLlave) {
                    return par.second;
                }
            }

            return "";
        }

        /**
         * @brief Función que retorna si la llave ingresada contiene algun elemento.
         * 
         * Esta función, retorna un booleano dependiendo si la existe un valor en la clave ingresada.
         * 
         * @param pLlave Lugar, el cual almacena la información del mapa
         * @return true si la llave contiene  información
         * @return false si la llave no contiene información
         */
        bool estaVacio(int pLlave) {
            int indice = funcionHash(pLlave);

            for (const auto& par : tabla[indice]) {
                if (par.first == pLlave) {
                    return false;
                }
            }

            return true;
        }

        /**
         * @brief Fucnión que retorna la cantidad de elementos que tiene el mapa hash almacenados.
         * 
         * Esta función recorre todos los indices y obtiene la longitud de cada uno y retorna la suma de todos
         * 
         * @return (int) Suma de los elementos contenidos en el mapa hash
         */
        int obtenerTamaño() {
            int contador = 0;

            for (int i = 0; i < tamaño; i++) {
                contador += tabla[i].size();
            }

            return contador;
        }

        /**
         * @brief Función la cual imprime el mapa hash
         * 
         * Esta función se encarga de recorrer todo el mapa hash e imprimirlo en la terminal. La impresión se divide entre los indices del mapa y las parejas ordenadas que se encuentren en cada uno de los indices pertenecientes al mapa hash
         * 
         */
        void mostrarMapaHash() const {
            for (int i = 0; i < tamaño; i++) {
                cout << "Índice " << i << ": ";
                for (const auto& par : tabla[i]) {
                    cout << "(" << par.first << ", " << par.second << ") ";
                }
                cout << endl;
            }
        }
};
