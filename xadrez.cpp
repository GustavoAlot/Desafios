#include <bits/stdc++.h>

using namespace std;



int main(){
    int loop = 0;

    while(1){
        char tabuleiro[8][8];
        short slotReiPx = 80, slotReiBx = 80, slotReiBy = 80, slotReiPy =80;
        bool checkB = 0;
        bool checkP = 0;
        bool continua;

        //lendo do teclado
        for (int i= 0 ; i< 8 ;i++){
            for(int j= 0; j < 8 ;j++){
                cin >> tabuleiro[i][j];

                switch (tabuleiro[i][j])
                {
                case 'k':
                    slotReiPx = j;
                    slotReiPy = i;


                    break;
                
                case 'K':
                    slotReiBx = j;
                    slotReiBy = i;
                    break;
                }
            }
        }

        continua = 0;
        for (int i= 0 ; i< 8 ;i++){
            for(int j= 0; j < 8 ;j++){
                if(tabuleiro[i][j] != '.')
                    continua= 1;
            }
        }

        if(!continua){
            break;
        }    


        //check por peao branco
        if(tabuleiro[slotReiPy+1][slotReiPx+1]== 'P'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy+1][slotReiPx-1] == 'P'){
            checkP = 1;
        }

        //check por peao preto
        if(tabuleiro[slotReiBy-1][slotReiBx-1] == 'p'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy-1][slotReiBx+1]== 'p'){
            checkB = 1;
        }


        //check por cavalo preto
        if(tabuleiro[slotReiBy-2][slotReiBx-1] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy-1][slotReiBx-2] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy+1][slotReiBx-2] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy+2][slotReiBx-1] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy+2][slotReiBx+1] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy+1][slotReiBx+2] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy-1][slotReiBx+2] == 'n'){
            checkB = 1;
        }else if(tabuleiro[slotReiBy-2][slotReiBx+1] == 'n'){
            checkB = 1;
        }


        //check por cavalo branco
        if(tabuleiro[slotReiPy-2][slotReiPx-1] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy-1][slotReiPx-2] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy+1][slotReiPx-2] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy+2][slotReiPx-1] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy+2][slotReiPx+1] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy+1][slotReiPx+2] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy-1][slotReiPx+2] == 'N'){
            checkP = 1;
        }else if(tabuleiro[slotReiPy-2][slotReiPx+1] == 'N'){
            checkP = 1;
        }






        //check para horiontal vertical de pecas pretas
        for(short x = slotReiBx; x <= 7; x++){
            if(tabuleiro[slotReiBy][x] == 'q' || tabuleiro[slotReiBy][x] == 'r'){
                checkB = 1;
            }else if(tabuleiro[slotReiBy][x] != '.' && tabuleiro[slotReiBy][x] != 'K'){
                x = 8;
            }
        }

        for(short x = slotReiBx; x >=0; x--){
            
            if(tabuleiro[slotReiBy][x] == 'q' || tabuleiro[slotReiBy][x] == 'r'){
                checkB = 1;
            }else if(tabuleiro[slotReiBy][x] != '.' && tabuleiro[slotReiBy][x] != 'K'){
                x = 0;
            }
        }

        for(short y = slotReiBy; y <=7; y++){
            if(tabuleiro[y][slotReiBx] == 'q' || tabuleiro[y][slotReiBx] == 'r'){
                checkB = 1;
            }else if(tabuleiro[y][slotReiBx] != '.'&& tabuleiro[y][slotReiBx] != 'K'){
                y = 8;
            }
        }

        for(short y = slotReiBy; y >=0; y--){
            if(tabuleiro[y][slotReiBx] == 'q' || tabuleiro[y][slotReiBx] == 'r'){
                checkB = 1;
            }else if(tabuleiro[y][slotReiBx] != '.' && tabuleiro[y][slotReiBx] != 'K'){
                y = 0;
            }
        }





        //check para horizontal vertical de pecas brancas
        for(short x = slotReiPx; x <= 7; x++){
            if(tabuleiro[slotReiPy][x] == 'Q' || tabuleiro[slotReiPy][x] == 'R'){
                checkP = 1;
            }else if(tabuleiro[slotReiPy][x] != '.' && tabuleiro[slotReiPy][x] != 'k'){
                x = 8;
            }
        }

        for(short x = slotReiBx; x >=0; x--){
            if(tabuleiro[slotReiPy][x] == 'Q' || tabuleiro[slotReiPy][x] == 'R'){
                checkP = 1;
            }else if(tabuleiro[slotReiPy][x] != '.' && tabuleiro[slotReiPy][x] != 'k'){
                x = 0;
            }
        }

        for(short y = slotReiBy; y <=7; y++){
            if(tabuleiro[y][slotReiPx] == 'Q' || tabuleiro[y][slotReiPx] == 'R'){
                checkP = 1;
            }else if(tabuleiro[y][slotReiPx] != '.' && tabuleiro[y][slotReiPx] != 'k'){
                y = 8;
            }
        }

        for(short y = slotReiBy; y >=0; y--){
            if(tabuleiro[y][slotReiPx] == 'Q' || tabuleiro[y][slotReiPx] == 'R'){
                checkP = 1;
            }else if(tabuleiro[y][slotReiPx] != '.' && tabuleiro[y][slotReiPx] != 'k'){
                y = 0;
            }
        }










        for( short c = slotReiPx, cont = 0; (c >= 0 && slotReiPy - cont >=0); c--, cont++){ 
        
        if( tabuleiro[slotReiPy-cont][c] == 'B' || tabuleiro[slotReiPy-cont][c] == 'Q'){
            checkP = 1;
        } else if(tabuleiro[slotReiPy-cont][c] != '.' && tabuleiro[slotReiPy-cont][c] != 'k'){
            c = -18;
        }
        }
        for( short c = slotReiPx, cont = 0; (c <= 7 && slotReiPy - cont >= 0); c++, cont++){ 
            
            if( tabuleiro[slotReiPy-cont][c] == 'B' || tabuleiro[slotReiPy-cont][c] == 'Q'){
                checkP = 1;
            } else if(tabuleiro[slotReiPy-cont][c] != '.' && tabuleiro[slotReiPy-cont][c] != 'k'){
                c = 18;
            }
        }  
        for( short c = slotReiPy, cont = 0; c >= 0 && slotReiPy + cont <= 7; c--, cont++){ 
            
            if( tabuleiro[c][slotReiPx+cont]  == 'B' || tabuleiro[c][slotReiPx+cont] == 'Q'){
                checkP = 1;
            } else if(tabuleiro[c][slotReiPx+cont] != '.' && tabuleiro[c][slotReiPx+cont] != 'k'){
                c = -18;
            }
        }
        for( short c = slotReiPy, cont = 0; c <= 7 && slotReiPy + cont <= 7; c++, cont++){ 
            
            if( tabuleiro[c][slotReiPx+cont] == 'B' || tabuleiro[c][slotReiPx+cont] == 'Q'){
                checkP = 1;
            } else if(tabuleiro[c][slotReiPx+cont] != '.' && tabuleiro[c][slotReiPx+cont] != 'k'){
                c = 18;
            }
        }     

        // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        for( short c = slotReiBx, cont = 0; (c >= 0 && slotReiBy - cont >=0); c--, cont++){ 
            
            if( tabuleiro[slotReiBy-cont][c] == 'b' || tabuleiro[slotReiBy-cont][c] == 'q'){
                checkB = 1;
            } else if(tabuleiro[slotReiBy-cont][c] != '.' && tabuleiro[slotReiBy-cont][c] != 'K'){
                c = -18;
            }
        }
        for( short c = slotReiBx, cont = 0; (c <= 7 && slotReiBy - cont >= 0); c++, cont++){ 
            
            if( tabuleiro[slotReiBy-cont][c] == 'b' || tabuleiro[slotReiBy-cont][c] == 'q'){
                checkB = 1;
            } else if(tabuleiro[slotReiBy-cont][c] != '.' && tabuleiro[slotReiBy-cont][c] != 'K'){
                c = 18;
            }
        }  
        for( short c = slotReiBy, cont = 0; c >= 0 && slotReiBy + cont <= 7; c--, cont++){ 
            
            if( tabuleiro[c][slotReiBx+cont]  == 'b' || tabuleiro[c][slotReiBx+cont] == 'q'){
                checkB = 1;
            } else if(tabuleiro[c][slotReiBx+cont] != '.' && tabuleiro[c][slotReiBx+cont] != 'K'){
                c = -18;
            }
        }
        for( short c = slotReiBy, cont = 0; c <= 7 && slotReiBy + cont <= 7; c++, cont++){ 
            
            if( tabuleiro[c][slotReiBx+cont] == 'b' || tabuleiro[c][slotReiBx+cont] == 'q'){
                checkB = 1;
            } else if(tabuleiro[c][slotReiBx+cont] != '.' && tabuleiro[c][slotReiBx+cont] != 'K'){
                cont = 18;
            }
        }   






        

        loop++;
        if (checkP){
            cout << "Game #"<<loop<<": black king is in check.\n";
        }else if (checkB){
            cout << "Game #"<<loop<<": white king is in check.\n";
        }else{
            cout << "Game #"<<loop<<": no king is in check.\n";
        }
        
    }
}