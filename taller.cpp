#ifdef _WIN32 
        #include<windows.h> 
    #else
        #include<unistd.h>
    #endif

#include<iostream>
#include<math.h>

using namespace std;

//prototipos de funcion primos gemelos
int leer(int &numero0, int &numero1);
int gemelos(int a, int b);
bool es_primo(int numero, int divisor);

//prototipos de funcion primos malvados



void clear();

int main() {
    //variables locales
    int opc, numero0, numero1, size;
    char binarios[64];

    //comienza el codigo || Dios libranos del espagueti :D
    for(;;){
        inicio:
        clear();
        cout<<"ingrese una de las siguientes opciones: "<<endl;
        cout<<"1. primos gemelos: "<<endl;
        cout<<"2. primos malvados: "<<endl;
        cout<<"3. aritmetica de punteros: "<<endl;
        cout<<"4. salir"<<endl;
        cin>>opc; clear();
    
        switch(opc){
            case 1:
                while(opc == 1){
                    clear();
                    leer(numero0, numero1);
                    if(gemelos(numero0, numero1) == 2){
                        cout<<endl<<"son numeros primos gemelos!!";
                    }
                    else cout<<endl<<"no son numeros primos gemelos :()";
                    cout<<endl<<endl<<"------ presione cualquier numero distinto de 1 para salir o 1 para repetir: ";
                    cin>>opc;
                }
                goto inicio;
            case 2:
                while(opc == 1){
                    clear();
                    
                    

                    cout<<endl<<endl<<"------ presione cualquier numero distinto de 1 para salir o 1 para repetir: ";
                    cin>>opc;
                }
                break;
        }

        return 0;
    }
}

//funciones
int leer(int &numero0, int &numero1){
    label1: //goto es literalmente ir a, cuando decimos goto label1; regresamos aca, si usamos break eb vez de goto sale error en el compilador.
    clear();
    cout<<"ingrese el primer numero: "; cin>>numero0;

    if(numero0 <= 1 || es_primo(numero0, 2) == false ){ 
        cout<<"recuerde ingresar un numero primo"<<endl; sleep(1); goto label1;
    }

    cout<<endl<<"ingrese el segundo numero: "; cin>>numero1;

    if(numero1 <= 1 || es_primo(numero1, 2) == false ){ 
        cout<<"recuerde ingresar un numero primo"<<endl; sleep(1); goto label1;
    }

    return 0;
}

int gemelos(int a, int b){
    b -= a;
    return b;
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


//hay que agilizar tiempo y hay gente que usa linux || platform tolerant is thhe way
void clear(){
    #ifdef _WIN32 
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

