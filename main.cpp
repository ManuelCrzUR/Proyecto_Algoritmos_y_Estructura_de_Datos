#include "../PrFinal/Librerias/ArbolesBinarios.cpp"
#include "../PrFinal/Librerias/mapas.cpp"

using namespace std;

int main() {
    Mapa mapa1;

    mapa1.Insertar("A", 100);
    mapa1.Insertar("B", 10);

    mapa1.MostrarElementos();

    mapa1.EliminarElemento("B");
    mapa1.MostrarElementos();

    return 0;
}