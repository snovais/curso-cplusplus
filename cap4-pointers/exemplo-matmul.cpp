#include <iostream>

int main(int argc, char *argv[]){ 
    int linha, coluna, i, somaprod;

    int mat1[2][2]={{1,2,3},{4,5,6},{7,8,9}};
    int mat2[2][2]={{1,0,0},{0,1,0},{0,0,1}};
    int mat3[3][3];
    
    int M1L=3, M1C=3, M2L=3, M2C=3;
    for(linha=0; linha<M1L; linha++){
        for(coluna=0; coluna<M2C; coluna++){
            somaprod=0;
            for(i=0; i<M1L; i++) somaprod+=mat1[linha][i]*mat2[i][coluna];
                mat3[linha][coluna]=somaprod;
        }
    }
    //
    //imprime mat3
    //
    for(linha=0; linha<M1L; linha++){
        for(coluna=0; coluna<M2C; coluna++)
            printf("%d ", mat3[linha][coluna]);
        printf("\n");
    }
    system("PAUSE");     
    return 0;
}