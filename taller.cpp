#ifdef _WIN32 
        #include<windows.h> 
    #else
        #include<unistd.h>
    #endif

#include<iostream>
#include<math.h>

using namespace std;

//prototipos de funcion
int leer();
bool es_primo(int x, int y, int divisores);


void gemelos(int a, int b);
void clear();

int main() {
    //variables locales
    int opc;

    //comienza el codigo || Dios libranos del espagueti :D
    cout<<"ingrese una de las siguientes opciones: "<<endl;
    cout<<"1. primos gemelos: "<<endl;
    cout<<"2. primos malvados: "<<endl;
    cout<<"3. aritmetica de punteros: "<<endl;
    cout<<"4. salir"<<endl;
    cin>>opc; clear();
    
    switch(opc){
        case 1:
            
            break;
    }

    return 0;
}

//funciones
int leer(){
    int numero0, numero1;
    cout<<"ingrese el primer numero: "<<endl; cin>>numero0;

    if(numero0 <= 1){ 
        cout<<"recuerde ingresar un numero primo"<<endl; sleep(1); return 0;
    }

    cout<<"ingrese el segundo numero: "<<endl; cin>>numero1;

    if(numero1 <= 1){ 
        cout<<"recuerde ingresar un numero primo"<<endl; sleep(1); return 0;
    }

    return 0;

}

bool es_primo(int numero, int divisor = 2){
	if (divisor * divisor > numero) {
        return true; // Si no se encontraron divisores hasta la raíz cuadrada, es primo
    }
    if (numero % divisor == 0) {
        return false; // Si es divisible por el divisor actual, no es primo
    }

	return es_primo(numero, divisor+1);
}


//metodos
void gemelos(int a, int b){
    b -= a;
    if(b == 2){
        cout<<"son primos gemelos!!"<<endl;
    }
    else cout<<"no son primos gemelos"<<endl;
}

//hay que agilizar tiempo y hay gente que usa linux || platform tolerant is thhe way
void clear(){
    #ifdef _WIN32 
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

