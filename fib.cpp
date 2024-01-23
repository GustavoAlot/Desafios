#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

cpp_int fibonacci(int n) {
    if (n <= 1)
        return n;
   
    cpp_int a = 0, b = 1;
    cpp_int result = 1;
   
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
   
    return result;
}

int contarFibonacciEntre(cpp_int limiteInf, cpp_int limiteSup) {
    int contador = 0;
    cpp_int fib = 0;
    int n = 0;
   
    while (fib <= limiteSup) {
        fib = fibonacci(n);
        if (fib >= limiteInf && fib <= limiteSup) {
            contador++;
        }
        n++;
    }
   
    return contador;
}

int main() {
    cpp_int limiteInf, limiteSup;
    string linha;



    while (1)
    {
        getline(cin, linha);
        istringstream iss(linha);
        iss >> limiteInf >> limiteSup;

        if(limiteInf == 0 && limiteSup ==0){
            break;
        }

        int quantidadeFibonacci = contarFibonacciEntre(limiteInf, limiteSup);
        cout << quantidadeFibonacci << "\n";
    }
    
   
    return 0;
}