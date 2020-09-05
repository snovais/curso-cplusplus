
// duas linhas abaixo servem para garantir que seja declarado apenas uma vez
#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class Vector{
    private:
        double* mData; // vetor que armazena os dados
        int mSize; // tamanho do vetor

    public:
        // nao contem construidor base
        Vector(const Vector& otherVector); // construidor
        Vector(int size); // construidor
        ~Vector(); // destruidor

        int GetSize() const;

        double& operator[](int i); // indexacao baseada em 0

        // read-only zero-based indexing
        double Read(int i) const;

        double& operator()(int i); // indexacao baseada em 1 (sobrecarga)
        
        // tarefa
        Vector& operator=(const Vector& otherVector); // sobrecarga
        Vector operator+() const; // unary + // sobrecarga
        Vector operator-() const; // unary - // sobrecarga
        Vector operator+(const Vector& v1) const; // binary + // sobrecarga
        Vector operator-(const Vector& v1) const; // binary - // sobrecarga

        // scalar multiplication
        Vector operator*(double a) const;

        // p-norm method
        double CalculateNorm(int p=2) const;

        // declara função para que uma classe amiga possa acessar
        friend int length(const Vector& v);
};

// Prototype signature of length() friend function
int length(const Vector& v);

#endif