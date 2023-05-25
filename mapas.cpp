// CÓDIGO RESPECTIVO PARA LOS MAPAS

/*
Operaciones de los mapas:
    Elem:  Retorna x.val si x.key Está en s
    Insert: Inserta un elemento en S
    Remove: Remueve el elemento
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> InsertarElemento(map<char, int>S, char pKey, int pVal) {   
    map<char, int>::iterator it;
    
    for (it = S.begin(); it != S.end(); it++) {
        if (pKey == it->first) {
            S[pKey] = pVal;
            
            return S;
    }
    S[pKey] = pVal;
    
    return S;
};

int main() {
    map<char, int> mymap;
    map<char, int>::iterator it;
    
    mymap['a'] = 6;
    mymap['b'] = -1;
    mymap['c'] = 2;
    mymap['d'] = 5;
    
    for (it = mymap.begin(); it != mymap.end(); it++) {
        cout << it->first << ", " << it->second << endl; 
    }
    
    cout << mymap['e'] << endl << endl;
    
    //mymap = InsertarElemento(mymap, 'a', 10);
    
    for (it = mymap.begin(); it != mymap.end(); it++) {
        cout << it->first << ", " << it->second << endl; 
    }
    
    return 0;
}
