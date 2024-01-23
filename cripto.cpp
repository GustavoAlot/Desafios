#include <bits/stdc++.h>

using namespace std;


int main(){
    char descripto[26];
    string mensagem[100];
    int entrada;
    string original = "the quick brown fox jumps over the lazy dog";

    cin >> entrada;

    for(int count = -1; count < entrada; count++)
    {
        string frase = "";
        int nLinhas = 0;
        bool chave = false;

        while(1){
            getline( std::cin, frase);

            string w1, w2, w3, w4, w5, w6, w7, w8, w9;
            mensagem[nLinhas] = frase;


            if (frase.empty()) {
                break;
            }
            
            nLinhas++;
          
            mensagem[nLinhas] = frase;

            istringstream iss(frase);
            iss >> w1 >> w2 >> w3 >> w4 >> w5 >> w6 >> w7 >> w8 >> w9;
            if( w1.length() == 3 && w2 .length() == 5 && w3.length() == 5 && w4.length() == 3 && w5.length() == 5 && w6.length() == 4 && w7.length() == 3 && w8.length() == 4 && w9.length() == 3)
            {
                chave = true;
                for(int i = 0; i < frase.length(); i++)
                {
                    if(frase[i] != ' ')
                        descripto[frase[i] - 97] = original[i];
                }
            }
        }

        if(chave){
            for(int i = 0; i < nLinhas; i++){
                int tamanho = mensagem[i].length();
                for(int j = 0; j < tamanho; j++){
                    if(mensagem[i][j] == ' '){
                      cout << " ";
                    }
                    cout << descripto[(int(mensagem[i][j] - 97))];
                }
                cout << "\n";
              
            }
          
            cout << "\n";
          
        } else if(count != -1) 
        {
            cout << "No solution\n\n";
        }

    }

    return 0;
}