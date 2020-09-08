#include <cmath>
#include <cassert>
#include "Matriz.h++"
#include "Vector.h++"


// Construidor de copia
// Aloca memoria para uma nova matriz e
// copia as entradas para essa matriz
Matriz::Matriz(const Matriz& B) {
    linhas = B.linhas;
    colunas = B.colunas;
    A = new double* [linhas];
    
    for(int i=0; i<linhas; i++) {
        A[i] = new double [colunas];
    }

    for(int i=0; i<linhas; i++) {
        for(int j=0;; j<colunas) {
            A[i][j] = B.A[i][j];
        }
    }
}

// construidor da classe recebe o tamanho da matriz, verifica os valores
// aloca memoria para a matriz e inicializa com zeros
Matriz::Matriz(int linhas, int colunas){
    assert(linhas > 0); 
    assert(colunas> 0);

    this->linhas = linhas;
    this->colunas = colunas;
    
    A = new double* [linhas];
    for (int i=0; i<linhas; i++){
        A[i] = new double [colunas];
    }

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            A[i][j] = 0.0;
        }
    }
}

Matriz::~Matriz(){
    // desaloca memoria das colunas e 
    // depois para as linhas
    for (int i=0; i<linhas; i++){
        delete[] A[i];
    }
    delete[] A;
}

int Matriz::quantidadeLinhas() const{
    return linhas;
}

int Matriz::quantidadeColunas() const{
    return colunas;
}

// sobrecarga do operador parenteses, indexacao baseada em um
// e verifica a validade do indice
double& Matriz::operator()(int i, int j) {
    assert(i > 0);
    assert(i < linhas+1);
    assert(j > 0);
    assert(j < colunas+1);

    return A[i-1][j-1];
}

// sobrecarga do operador "="
Matriz& Matriz::operator=(const Matriz& B) {
    assert(linhas = B.linhas);
    assert(colunas = B.colunas);

    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            A[i][j] = B.A[i][j];
        }
    }

    return *this;
}

// sobrecarga operador unario +
Matriz Matriz::operator+() const {
    Matriz C(linhas, colunas);
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            C(i+1, j+1) = A[i][j];
        }
    }

    return C;
}

// sobrecarga operador unario -
Matriz Matriz::operator-() const {
    Matriz C(linhas, colunas);
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            C(i+1, j+1) = -A[i][j];
        }
    }

    return C;
}

// sobrecarga operador binario +
Matriz Matriz::operator+(const Matriz& B) const {
    assert(linhas == B.linhas);
    assert(colunas == B.colunas);

    Matriz C(linhas, colunas);

    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            C(i+1, j+1) = A[i][j] + B.A[i][j];
        }
    }

    return C;
}

// sobrecarga do operador binario -
Matriz Matriz::operator-(const Matriz& B) const {
    assert(linhas == B.linhas);
    assert(colunas == B.colunas);

    Matriz C(linhas, colunas);

    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            C(i+1, j+1) = A[i][j] - B.A[i][j];
        }
    }


    return C;
}

// sobrecarga para multiplicacao por um escalar
Matriz Matriz::operator*(double escalar) const {
    Matriz C(linhas, colunas);

    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            C(i+1, j+1) = escalar*A[i][j];
        }
    }

    return C;
}

// sobrecarga do operador "*" para multiplicacao de uma matriz por 
// um vetor
Vector operator*(const Matriz& mA, const Vector& v) {
    int tamanho_vector_original = v.obtemTamanho();
    
    assert(mA.quantidadeColunas() == tamanho_vector_original);
    
    int tamanho_novo_vetor = mA.quantidadeLinhas();

    Vector novoVetor(tamanho_vector_original);

    for(int i=0; i<tamanho_vector_original; i++) {
        for(int j=0; j<tamanho_vector_original; j++) {
            novoVetor[i] += mA.A[i][j] * v.lerVetor(j);
        }
    }

    return novoVetor;
}

// sobrecarga vector multiplicando-se pela matriz
Vector operator*(const Vector& v, const Matriz& mA) {
    int tamanho_vector_original = v.obtemTamanho();
    assert(mA.quantidadeLinhas() == tamanho_vector_original);

    int tamanho_novo_vetor = mA.quantidadeColunas();

    Vector novoVetor(tamanho_novo_vetor);

    for(int i=0; i<tamanho_novo_vetor; i++) {
        for(int j=0; j<tamanho_vector_original; j++) {
            novoVetor[i] +=  v.lerVetor(j) * mA.A[j][i];
        }
    }
}

double Matriz::calculaDeterminante() const {
    assert(linhas == colunas);
    double determinante = 0.0;

    if (linhas == 1) {
        determinante = A[0][0];
    }
    else {
    // More than one entry of matrix
        for (int i_outer=0; i_outer<linhas; i_outer++) {
            Matriz sub_matrix(linhas-1, linhas-1);
            for (int i=0; i<linhas-1; i++) {
                for (int j=0; j<i_outer; j++) {
                    sub_matrix(i+1,j+1) = A[i+1][j];
                }
                for (int j=i_outer; j<linhas-1; j++) {
                    sub_matrix(i+1,j+1) = A[i+1][j+1];
                }
            }
            double sub_matrix_determinante = sub_matrix.calculaDeterminante();

            determinante += pow(-1.0, i_outer) * A[0][i_outer] * sub_matrix_determinante;
        }
    }
    return determinante;
}


double& Matriz::gerarPesos(int quantidadeNeuronios) {


}