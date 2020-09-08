#ifndef MATRIZHEADERDEF
#define MATRIZHEADERDEF
#include "Vector.h++"

class Matriz {
    private:
        double** A; //matriz que armazena os dados
        int linhas, colunas;

    public:
        Matriz(const Matriz& B);
        Matriz(int linhas, int colunas);
        ~Matriz();
        
        int quantidadeLinhas() const;

        int quantidadeColunas() const;
        
        double& operator()(int i, int j); // indexacao baseada em 1

        Matriz& operator=(const Matriz& B);

        Matriz operator+() const; //  operador unario +

        Matriz operator-() const; //  operador unario -

        Matriz operator+(const Matriz& m1) const; // operador binario +

        Matriz operator-(const Matriz& m1) const; //  operador binario -

        // multiplicacao por escalar
        Matriz operator*(double escalar) const;

        double calculaDeterminante() const;

        // declara amizade com vector de multiplicacao
        friend Vector operator*(const Matriz& m, const Vector& v);
        friend Vector operator*(const Vector& v, const Matriz& m);
        
        double& gerarPesos(int quantidadeNeuronios);
};

// Assinatura de protótipo da função Friend 
Vector operator*(const Matriz& m, const Vector& v);
Vector operator*(const Vector& v, const Matriz& m);

#endif