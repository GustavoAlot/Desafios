#include <iostream>

using namespace std;


int main(){

    int num1, num2;
    while(cin >> num1 >> num2){
        int numeroInicial = 0;
    
        long maior , menor;
        int maiorCiclo = 0 ;


        if (num2 > num1){
            maior = num2;
            menor = num1;

        }else{
            maior = num1;
            menor = num2;
        }



        for(int i = menor; i <= maior; i++){
            int cont = 1;
            numeroInicial = i;

            while (numeroInicial != 1){

                if (numeroInicial %2 == 0 ){
                    numeroInicial = numeroInicial/2;

                }else{
                    numeroInicial = (numeroInicial*3)+1;
                    
                }
                cont ++;
            
            }
            if(cont > maiorCiclo){
                maiorCiclo = cont;
            }   

        }

        cout << num1 <<" " << num2 << " " << maiorCiclo << "\n";
    }
}