#include <iostream>
using namespace std;


//funcion para que ingresen los datos de las ganacias y recibe un entero n y el arreglo A
void getGain(int n, float* A){
    
    //Variable donde se almacena la ganancia temporalmente
    float gain;
    cout << "Digitar ganancias de entre -100 y 100\n\n";
    
    //for para pedir las n ganacias  
    for(int i = 0; i < n; i++){
    cout << "Ingrese la Ganancia: "; cin >> gain;
    
    //se valida que este en el rango permitido
    if(gain >= -100 && gain <= 100){
        // se almacena la ganacia en el arreglo
        A[i] = gain;
    }
    else {
        cout << "La cantidad digitada no es valida";
        return;
    }
  } 
}


//funcion para calcular la ganancia maxima
int max_gain(float* A, int n){
    //M -> arreglo para hacer la memoization y S variable alamacenar las sumas y valor maximo inicializado con cero
    int M[n+1], S = 0;
    
    //Inicalizando el primer valor de la matriz M con cero para poder hacer uso corrcto de la memoization
    M[0] = 0;
    
    // for para recorrer el arreglo con n datos y calcular  su maximo 
    for(int i = 1; i <= n; i++){0
        S = max( S + A[i-1], A[i-1] );
        M[i] = max( S, M[i-1] );
    }
    // se retorna el ultimo valor de M siendo este el maximo 
    return M[n];
}


int main(){
    // declaracion de la variable n 
int n;
// texto de salida para ayudar al usario 
cout << "******* EJERCICIO 1 TALLER 3 *******\n\n";
// pidiendo y alamcenando el valor de n 
cout << "Digite la catidad de ventas a ingresar de la tienda: ";
cin >> n;
// declarando el arreglo A de tamaño n 
float A[n];
//validado que n este en el rango de 1 a 1000
if(n >= 1 && n <= 1000){
    //llamdo la funcion getGain
    getGain(n, A);
   
}else {
    cout << "Solo se pueden ingresar en un intervalo de 1 a 1000 ventas";
    return 0;
}
// llamdo y mostrando los resultado maximo de la funcion max_gain
cout << "El gancia maxima es: " << max_gain(A, n) << ".\n";
    return 0;
}