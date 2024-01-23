#include <iostream>

using namespace std;


string invertString(const string& str){
    string reversed;
    for(int i = str.length() -1 ; i >= 0; i--){
        reversed += str[i];

    }
    return reversed;
}

int main(){
    int numEntradas;
    cin >> numEntradas;
    string entradas[numEntradas];
    

    for( int i = 0; i < numEntradas; i++){
        cin >> entradas[i];
    }


    for (int i = 0; i < numEntradas; i++){
        string novaEntrada = entradas[i];
        string reversed;
        int contador = 0;

        reversed = invertString(novaEntrada);

       
        while(novaEntrada != reversed || contador == 0 ){
            int auxOrg, auxReverse;
            auxOrg = stoi(novaEntrada);
            auxReverse =stoi(reversed);

            novaEntrada = to_string(auxOrg + auxReverse);
            reversed = invertString(novaEntrada);

            contador++;

        }
        cout << contador << " " << novaEntrada << "\n";
        
    }

    return 0;

}
