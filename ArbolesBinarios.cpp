#include <iostream>

using namespace std;

class NodoAB{
public:
    int valor;
    NodoAB *sai;
    NodoAB *sad;
};

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

int contar(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->valor > 10){
        return 1+(contar(raiz->sai))+(contar(raiz->sad));
    }
};
int peso(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    return 1 + (peso(raiz->sai)) + (peso(raiz->sad));
};

int hojas(NodoAB *raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz!=NULL){
        if(raiz->sai == NULL && raiz->sad==NULL){
            return 1;
        }else{
            return 0;
        }
    }
    return (hojas(raiz)+(hojas(raiz->sai))+(hojas(raiz->sad)));
}



int menu(){
    int opc;
    cout<<"1-Insertar\n";
    cout<<"2-PreOrden\n";
    cout<<"3-InOrden\n";
    cout<<"4-PostOrden\n";
    cout<<"5-Buscar\n";
    cout<<"6.SumarNodoAB\n";
    cout<<"7.Contar\n";
    cout<<"8.Peso\n";
    cout<<"9.Camino\n";
    cout<<"10.Contar hojas\n";
    
    cin>>opc;
    
    return opc;
}

int main()
{
    int opc=0;
    NodoAB *raiz;
    while(opc!=10){
        opc=menu();
        switch(opc){
            case 1:
            int n;
            cout<<"Ingrese el valor que quiere insertar";
            cin>>n;
            raiz=insertar(raiz, n);
            break;
            case 2:
            PreOrden(raiz);
            break;
            case 3:
            InOrden(raiz);
            break;
            case 4:
            PosOrden(raiz);
            break;
            case 5:
            int x;
            cout<<"Ingrese el valor que quiere buscar";
            cin>>x;
            buscar(raiz, x);
            break;
            case 6:
            Sumar(raiz);
            break;
            case 7:
            contar(raiz);
            break;
            case 8:
            peso(raiz);
            break;
            case 9:
            //camino(raiz);
            break;
            case 10:
            hojas(raiz);
            break;
        }
        
    }
    return 0;
}
