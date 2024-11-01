#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    system("cls");
    printf("\nCampo Minado\n\n");

    int campo_minas[10][10];
    int dificuldade, valor, x, y;
    char posicoes[10][10];
    int jogo = 1;
    int estado = 1;
    time_t t;

    while(estado){
        printf("Digite o nivel de dificuldade, sendo 1 o mais dificil (1-3): ");
        scanf("%d", &dificuldade);
        system("cls");

        while(dificuldade < 1 || dificuldade > 3){
            printf("Digite uma dificuldade entre 1 e 3: ");
            scanf("%d", &dificuldade);
        }
        system("cls");

        dificuldade += 6;
        printf("\n");
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                valor = ((rand()*t) % 11);
                if(i == 0 || j == 0){
                    campo_minas[i][j] = 1;
                    posicoes[i][j] = '.';
                }
                else if(i == 9 || j == 9){
                    campo_minas[i][j] = 1;
                    posicoes[i][j] = '.';
                }
                else if(valor > dificuldade){
                    campo_minas[i][j] = 9;
                    posicoes[i][j] = '#';
                }
                else{
                    campo_minas[i][j] = 0;
                    posicoes[i][j] = '#';
                }
            }
        }

        /* // TESTES
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                printf("%d  ", campo_minas[i][j]); //print do campo minado antes das alterações
            }
            printf("\n");
        }
        printf("\n");

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                printf("%c  ", posicoes[i][j]); //print da situação atual do campo minado, questão de posições abertas(a) ou fechadas(#)
            }
            printf("\n");
        }
        printf("\n");
        */

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i > 0 && j > 0 && i < 9 && j < 9){
                    for(int k = 0; k < 3; k++){
                        for(int n = 0; n < 3; n++){  
                                if(campo_minas[i][j] != 9 && campo_minas[i-1+k][j-1+n] == 9) //Edição dos numeros do campo minado
                                    campo_minas[i][j] += 1;
                        }
                    }
                }    
            }
        }

        /* MAIS TESTE
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                printf("%d  ", campo_minas[i][j]); //print do campo minado depois das alterações
            }
            printf("\n"); 
        }
        printf("\n");
        */

        while(jogo){
            /*
            printf("\n");
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(posicoes[i][j] == 'a'){
                        printf("%d  ", campo_minas[i][j]); //print do tabuleiro baseado nas posicoes abertas
                    }
                    else{
                        printf("%c  ", posicoes[i][j]);
                    }
                }
                printf("\n");
            }
            printf("\n");
            */
           printf("\n");
        
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(posicoes[i][j] == 'a'){
                        printf(" %d  | ", campo_minas[i][j]); //print do tabuleiro com as bombas
                    }
                    else if(((j == 0 && i == 0) || (i == 0 && j == 9) || (j == 0 && i == 9)) && j != 9){
                        printf("    | ");
                    }
                    else if(j == 0 && i != 9){
                        printf(" %d  | ", i);
                    }
                    else if(j == 9 && i != 9 && i > 0){
                        printf(" %d   ", i);
                    }
                    else if(i == 0 && j < 9){
                        printf(" %d  | ", j);
                    }
                    else if(i == 9 && j != 9){
                        printf(" %d  | ", j);
                    }
                    else{
                        if(j != 9)
                        printf("    | ");
                    }
                }
            
                printf("\n");
                if(i != 9){
                    for(int w = 0; w < 10; w++){
                        printf("---");
                        if(i == 0 || i == 8){
                            printf("---");
                        }
                        else if(w > 0 && w < 8 && i < 9){
                            printf(" + ");
                        }
                        else if(w < 9){
                            printf(" | ");
                        }
                    }
                printf("\n");
                }
            }
            printf("\nDigite a linha e a coluna onde quer jogar separado por espaco (1-8): ");
            scanf("%d %d", &x, &y);

            while(posicoes[x][y] == 'a'){
                printf("Posicao invalida, digite uma posicao que esteja fechada: ");
                scanf("%d %d", &x, &y);
            }
            system("cls");

            if(campo_minas[x][y] == 9){
                
                printf("\n");
        
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 10; j++){
                        if(campo_minas[i][j] == 9)
                            printf(" @  | ");
                        else if(posicoes[i][j] == 'a'){
                            printf(" %d  | ", campo_minas[i][j]); //print do tabuleiro com as bombas
                        }
                        else if(((j == 0 && i == 0) || (i == 0 && j == 9) || (j == 0 && i == 9)) && j != 9){
                            printf("    | ");
                        }
                        else if(j == 0 && i != 9){
                            printf(" %d  | ", i);
                        }
                        else if(j == 9 && i != 9 && i > 0){
                            printf(" %d   ", i);
                        }
                        else if(i == 0 && j < 9){
                            printf(" %d  | ", j);
                        }
                        else if(i == 9 && j != 9){
                            printf(" %d  | ", j);
                        }
                        else{
                            if(j != 9)
                            printf("    | ");
                        }
                    }

                    printf("\n");
                    if(i != 9){
                        for(int w = 0; w < 10; w++){
                            printf("---");
                            if(i == 0 || i == 8){
                                printf("---");
                            }
                            else if(w > 0 && w < 8 && i < 9){
                                printf(" + ");
                            }
                            else if(w < 9){
                                printf(" | ");
                            }
                        }
                    printf("\n");
                    }
                }
                printf("\nGame Over!\n");
                printf("\n");
                
                break;
            }
            else{
                for(int k = 0; k < 3; k++){
                    for(int n = 0; n < 3; n++){  
                        if(campo_minas[x-1+k][y-1+n] != 9 && posicoes[x-1+k][y-1+n] != '.'){
                            posicoes[x-1+k][y-1+n] = 'a';
                        }
                    }
                }
            }

            /* // TESTE DE NOVO
            printf("\n");
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    printf("%c  ", posicoes[i][j]); //print da situação atual do campo minado, questão de posições abertas(a) ou fechadas(#)
                }
                printf("\n");
            }
            printf("\n");
            */
            /*
            printf("\n");
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(posicoes[i][j] == 'a'){
                        printf("%d  ", campo_minas[i][j]); //print do tabuleiro baseado nas posicoes abertas
                    }
                    else{
                        printf("%c  ", posicoes[i][j]);
                    }
                }
                printf("\n");
            }
            printf("\n");
            */


            system("cls");
        }
        printf("Digite 1 para jogar novamente ou 0 para sair: ");
        scanf("%d", &estado);
        system("cls");
    }
    return 0;
}
