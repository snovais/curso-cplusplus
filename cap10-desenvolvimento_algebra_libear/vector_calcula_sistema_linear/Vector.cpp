#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp" // inclusao da classe

// Construtor de cópia substituída 
//Aloca memória para o novo vetor e 
//copia entradas de outro vetor para ele
Vector::Vector(const Vector& otherVector){
    mSize = otherVector.GetSize(); 
    mData = new double [mSize]; // aloca memoria

    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];
    }
}

// Construtor para vetor de um determinado tamanho 
// Aloca memória e inicializa entradas para zero
Vector::Vector(int size){
    assert(size > 0);
    mSize = size;
    mData = new double [mSize];
    
    for (int i=0; i<mSize; i++){
        mData[i] = 0.0;
    }
}

// sobrecarga do destruidor para desalocar memoria corretamente
Vector::~Vector() {
    delete[] mData;
}

// obtem o tamanho do vetor
int Vector::GetSize() const{
    return mSize;
}

// sobrecarga do operador colchetes
// observe que a indexaçao é baseada em 0
// e checa a validade do indice
double& Vector::operator[](int i){
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

// variante somente leitura para []
// indexacao baseada em 0
// e verifica os indices
double Vector::Read(int i) const{
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

// sobrecarga dos parenteses
// indexacao baseada em 1, o que permite declarar vetor como v = -w e a = b+c
// e verifica a validade dos indices
double& Vector::operator()(int i){
    assert(i > 0);
    assert(i < mSize+1);
    return mData[i-1];
}

// sobrecarga do operador de atribuicao
Vector& Vector::operator=(const Vector& otherVector){
    assert(mSize == otherVector.mSize); // verifica se ambos possuem o mesmo tamanho
    
    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];
    }
    
    return *this;
}

// sobrecarga do operador unario de soma
Vector Vector::operator+() const{
    Vector v(mSize);
    
    for (int i=0; i<mSize; i++){
        v[i] = mData[i];
    }

    return v;
}

// sobrecarga do operador unario de subtracao
Vector Vector::operator-() const{
    Vector v(mSize);
    
    for (int i=0; i<mSize; i++){
        v[i] = -mData[i];
    }

    return v;
}

// sobrecarga do operador binario de soma, permite declarar vetor como v = -w e a = b+c
Vector Vector::operator+(const Vector& v1) const{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] + v1.mData[i];
    }

    return v;
}

// sobrecarga do operador binario de subtracao, permite declarar vetor como v = -w e a = b-c
Vector Vector::operator-(const Vector& v1) const{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] - v1.mData[i];
    }

    return v;
}

// sobrecarga que permite multiplicacao de vetor por um escalar
Vector Vector::operator*(double a) const{
    Vector v(mSize);
    
    for (int i=0; i<mSize; i++){
        v[i] = a*mData[i];
    }

    return v;
}

// calcula norma euclidiana
// p=2 padrao
double Vector::CalculateNorm(int p) const{
    double norm_val, sum = 0.0;

    for (int i=0; i<mSize; i++){
        sum += pow(fabs(mData[i]), p);
    }
    
    norm_val = pow(sum, 1.0/((double)(p)));
    
    return norm_val;
}

// Friend estilo MATLAB para obter o tamanho de um vetor
int length(const Vector& v){
    return v.mSize;
}