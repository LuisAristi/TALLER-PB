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
char convertir(int numero, char &binario, int &size);
int ordenar(char &binario, int size);
int elevar(int indice, int exponente);




//coloca desde la linea 23 a 32 tus prototipos de funcion, este texto debe estar en la linea 23








//terminan aca, este texto debe estar en la linea 32

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
                goto inicio; //el break me sacaba del programa xd
            case 2:
                while(opc == 2){
                    clear();

                    leer(numero0, numero1);
                    convertir(numero0, binarios[0], size = 0);

                    cout<<ordenar(binarios[0], size);
                    

                    cout<<endl<<endl<<"------ presione cualquier numero distinto de 2 para salir o 2 para repetir: ";
                    cin>>opc;
                }
                goto inicio;
        }

        return 0;
    }
}

//funciones gemelos
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
        return true; // Si el cuadrado del divisor es mayor al numero, es primo
    }
    if (numero % divisor == 0) {
        return false; // Si es divisible por el divisor actual, no es primo
    }

	return es_primo(numero, divisor+1);
}

//funciones malvadas

char convertir(int numero, char &binario, int &size){
    char *p;
    p = &binario;
    if(numero > 0){
      if(numero % 2 == 0){
           *p = '0';
       }
        else if(numero % 2 == 1){ 
            *p = '1';
        }
    size++;
    p++;
    return convertir(numero/ 2, *p, size);
    }
    return 0;
}

int ordenar(char &binario, int size){
    char *p;
    int numero = 0;
    p = &binario;
    for(int i = 0; i < size + 1; i++){
        if(*(p+i) == '1'){
            numero += elevar(2, i);
        }
    }
    return numero;
}

int elevar(int indice, int exponente){
    exponente--;
    if(exponente > 0){
        return elevar(indice * indice, exponente - 1);
    }
    else return indice;
}

unsigned int decimalToBinary(unsigned decimal, unsigned int binaryResult) {
    if (decimal > 0) {
        binaryResult = binaryResult * 10 + decimal % 2; // Acumula el dígito binario en la variable entera
        cout<<binaryResult<<endl;
        return decimalToBinary(decimal / 2, binaryResult); // Llama recursivamente con la parte entera de la división por 2
    }
    cout<<binaryResult<<endl;
    return binaryResult;
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




//aqui terminan funciones de luis, 199
//coloca desde la linea 200 tus funciones, este texto debe estar en la linea 200
//comienzan las de moncrieff














































































//coloca desde la linea 160 tus funciones, este texto debe estar en la linea 280