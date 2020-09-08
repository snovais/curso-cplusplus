#include "Vector.h++"
#include <cmath>
#include <iostream>
#include <cassert>

// sobrecarga do construidor
// aloca memoria para um novo vetor, copia
// as entradas para um outro vetor
Vector::Vector(const Vector& vetor) {
    comprimento = vetor.obtemTamanho();
    vA = new double [comprimento];
    
    for(int i=0; i<comprimento; i++) {
        vA[i] = vetor.vA[i];
    }
}

// construidor para vetor obtendo tamanho a partir da entrada
// aloca memoria e inicializa com zeros
Vector::Vector(int comprimento) {
    assert(comprimento > 0);

    comprimento = comprimento;
    vA = new double [comprimento];

    for(int i=0; i<comprimento; i++) {
        vA[i] = 0.0;
    }
}

// sobrecarga do destruidor para desalocar memoria corretamente
Vector::~Vector() {
    delete[] vA;
}

int Vector::obtemTamanho() const {
    return comprimento;
}

// sobrecarga do operador colchetes, indexacao baseada em zero
// verifica a validade dos indices. É o que ajudara nas operacoes
// com objeto vetor
double& Vector::operator[](int i) {
    assert( i > -1);
    assert(i < comprimento);

    return vA[i]; // retorna ponteiro p/ a posicao 
}

// ler apenas variantes com colchetes
// observar que usa indexacao baseada em zero
// e verifica a validade do indice
double Vector::lerVetor(int i) const {
    assert(i > -1);
    assert(i < comprimento);

    return vA[i]; 
}

// ler apenas variantes com parenteses
// observar que usa indexacao baseada em um
// e verifica a validade do indice
double& Vector::operator()(int i) { // indexacao baseada em 1
    assert(i > 0);
    assert(i < comprimento+1);

    return vA[i-1]; 
} 

// sobrecarga do operador de atribuicao
Vector& Vector::operator=(const Vector& vetor) {
    assert(comprimento == vetor.comprimento);

    for(int i=0; i<comprimento; i++) {
        vA[i] = vetor.vA[i];
    }

    return *this;
}

// sobrecarga do unário +
Vector Vector::operator+() const {
    Vector v(comprimento);

    for(int i=0; i<comprimento; i++) {
        v[i] = vA[i];
    }

    return v;
}

// sobrecarga do unário -
Vector Vector::operator-() const {
    Vector v(comprimento);

    for(int i=0; i<comprimento; i++) {
        v[i] = -vA[i];
    }

    return v;
}

// sobrecarga operador binario + para somar dois vetores
Vector Vector::operator+(const Vector& v1) const {
    assert(comprimento == v1.comprimento);

    Vector v(comprimento);

    for(int i=0; i<comprimento; i++) {
        v[i] = vA[i] + v1.vA[i];
    }

    return v;
}

// sobrecarga do operador binario -
Vector Vector::operator-(const Vector& v1) const {
    assert(comprimento == v1.comprimento);

    Vector v(comprimento);

    for(int i=0; i<comprimento; i++) {
        v[i] = vA[i] - v1.vA[i];
    }

    return v;
}

// multiplicacao por escalar
Vector Vector::operator*(double escalar) const {
    Vector v(comprimento);

    for(int i=0; i<comprimento; i++) {
        v[i] = escalar*vA[i];
    }

    return v;
}

// Amigo do estilo MATLAB para obter o tamanho de um vetor
// permite uma classe amiga ter acesso ao metodo
int tamanho(const Vector& vA) {
    return vA.comprimento;
} 