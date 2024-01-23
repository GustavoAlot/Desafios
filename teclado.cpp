#include <bits/stdc++.h>

using namespace std;

int main()
{

    //string realAlfa = "snvfrghjokl;,mp[wtdyibecux";
    string realAlfa2 = ";....M0,.9`12345678.L.-....VXSWDFGUHJKNBIO.EARYCQZT.P][..";
    string linha = "";

    while(1){
        getline( std::cin, linha);

        if (linha.empty()) 
        {
            // Linha em branco encontrada
            break;
        }
        else
        {
            for (int i = 0; i < linha.length(); i++)
            {
                if(linha[i] == ' ')
                    cout << linha[i];
                else{
                    cout << realAlfa2[linha[i]- 39];
                }
            }
            cout << "\n";
            
        }
    }
    return 0;
}
