/*for(int i = 0; i < n; i++){
    cout<<codigo[i]<<", "<<sueldo_hora[i]<<", "<<horas_trabajadas[i]<<endl;
  }*/
#ifdef _WIN32 
        #include<windows.h> 
    #else
        #include<unistd.h>
    #endif

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//prototipos de funcion primos gemelos
int leer(int &numero0, int &numero1);
int gemelos(int a, int b);
bool es_primo(int numero, int divisor);

//prototipos de funcion primos malvados
char convertir(int numero, char &binario, int &size);
int malvada(char &binario, int size);

//prototipos de punteros
void ingresar_datos_chofer(int &codigo, int &sueldo_hora, int &horas_trabajadas, int n);
void nomina(int &codigo, int &sueldo_hora, int &horas_trabajadas, int &sueldo_semanal, int n);
void consulta(int* codigo, int* sueldo_hora, int* horas_trabajadas, int* sueldo_semanal, int n);

//generales
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

                    label1: //goto es literalmente ir a, cuando decimos goto label1; regresamos aca, si usamos break en vez de goto sale error en el compilador.
                    cout<<"ingrese el primer numero: "; cin>>numero0;
                    if(numero0 <= 1 || es_primo(numero0, 2) == false ){ 
                        cout<<"recuerde ingresar un numero primo"<<endl; sleep(1); goto label1; //el goto es muchisimo mejor que implementar ciclos
                    }

                    convertir(numero0, binarios[0], size = 0); //como dato curioso el binario se lee al reves, esto tiene que ver con el orden de la funcion recursiva
                    if(malvada(binarios[0], size) % 2 == 0){   //(no importa) lo importante poder contar cuantos 1 hay y por consiguiente saber si el numero es malvado
                        cout<<"es un numero malvado !!!"<<endl;
                    }
                    else cout<<"no es un numero malvado :()"<<endl;
                    
                    cout<<endl<<endl<<"------ presione cualquier numero distinto de 2 para salir o 2 para repetir: "; //no se me ocurre otro metodo mejor (los hay)
                    cin>>opc; 
                }
                goto inicio;

            case 3: 
                //variables locales pa no tener que subir a mirar pa arriba
                int n;
                cout<<"ingrese la cantidad de choferes: "; cin>>n;

                int codigo[n], sueldo_hora[n], horas_trabajadas[n], sueldo_semanal[n];

                while(true){
                    clear();
                    int opc1;
                    menu3:
                    cout<<"TRANSPORTES RAPIDOS Y FURIOSOS"<<endl;
                    cout<<"1. ingresar datos del chofer: "<<endl; //codigo, sueldo por horas, horas trabajadas a la semana -> leer horas por dia; L M M J V S D (7);
                    cout<<"2. Generar nómina choferes: "<<endl;
                    cout<<"3. Consultar un chofer: "<<endl;
                    cout<<"4. reporte: "<<endl;
                    cout<<"5. salir: "<<endl;
                    cin>>opc1;

                    switch(opc1){
                        case 1:
                            ingresar_datos_chofer(codigo[0], sueldo_hora[0], horas_trabajadas[0], n); //como trabajamos con punteros podemos acceder a esos datos :)
                            sleep(2);
                            goto menu3;
                        case 2:
                            nomina(codigo[0], sueldo_hora[0], horas_trabajadas[0], sueldo_semanal[0], n);
                            goto menu3;
                        case 3:
                            consulta(codigo, sueldo_hora, horas_trabajadas, sueldo_semanal, n);
                            sleep(2);
                            goto menu3;
                        case 4:
                            cout<<"we'll be right back";
                            sleep(2);
                            goto menu3;
                        case 5:
                            goto inicio;
                        default:
                            cout<<"ingrese una opcion valida";
                            sleep(2);
                            break;
                    }
                }
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

int malvada(char &binario, int size){
    int numero = 0;
    char *p;
    p = &binario;
    for(int i = 0; i < size; i++){
        if(*p == '1'){
            numero++;
        }
        p++;
    }
    return numero;
}

//funciones punteros
void ingresar_datos_chofer(int &codigo, int &sueldo_hora, int &horas_trabajadas, int n){ //n = cantidad de choferes
    int *p, *q, *r, numero = 0, numero1 = 0;
    p = &codigo;
    q = &sueldo_hora;
    r = &horas_trabajadas;

    for (int i = 0; i < n; ++i) {
        cout << "ingrese los datos para el chofer " << (i + 1) << ":" << endl;
        cout << "Código del chofer: ";
        cin >>*p;

        cout << "Sueldo por hora del chofer: ";
        cin >>*q;

        for (int dia = 0; dia < 7; ++dia) {
            cout << "Ingrese las horas trabajadas del día " << (dia + 1) << ": ";
            cin >>numero;
            numero1 += numero;
        }
        *r = numero1;
        p++; q++; r++; numero = 0; numero1 = 0;
    }
}

void nomina(int &codigo, int &sueldo_hora, int &horas_trabajadas, int &sueldo_semanal, int n){ 
    int *p, *q, *r, *s;
    p = &codigo;
    q = &sueldo_hora;
    r = &horas_trabajadas;
    s = &sueldo_semanal;

    for (int i = 0; i < n; ++i) {
        cout<<"chofer #"<<*p<<":"<<endl;
        cout<<"horas trabajadas: "<<*r;
        cout<<"      sueldo semanal: "<<*r * *q<<endl<<endl;
        *s = *r * *q;
        p++; q++; r++; s++;
    }
}

void consulta(int* codigo, int* sueldo_hora, int* horas_trabajadas, int* sueldo_semanal, int n) {
    int consulta;
    cout<<"ingrese el codigo a consultar: ";
    cin>>consulta;
    
    bool codigo_encontrado = false; //  para saber si se encontró el código
    
    for (int i = 0; i < n; ++i) {
        if (codigo[i] == consulta) {
            codigo_encontrado = true;
            cout << "Código encontrado en la base de datos:" << endl;
            cout << "Horas trabajadas: " << horas_trabajadas[i] << " horas" << endl;
            cout << "Sueldo por hora: " << sueldo_hora[i] << " unidades monetarias por hora" << endl;
            cout << "Sueldo semanal: " << sueldo_semanal[i] << " unidades monetarias" << endl;
            break; // Salir del bucle ya que se encontró el código
        }
    }

    if (!codigo_encontrado) {
        cout << "El código no fue encontrado en la base de datos" << endl;
    }
}

//hay que agilizar tiempo y hay que tener la posibilidad de linux cubierta || platform tolerant is the way
void clear(){
    #ifdef _WIN32 
        system("cls"); 
    #else
        system("clear"); 
    #endif
}