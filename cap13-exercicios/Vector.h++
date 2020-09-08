#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class Vector{
    private:
        double* vA;
        int comprimento;

    public:
        Vector(const Vector& vetor);

        Vector(int tamanho);
        
        ~Vector();
        
        int obtemTamanho() const;

        double& operator[](int i);

        double lerVetor(int i) const;

        double& operator()(int i); // indexacao baseada em 1

        Vector& operator=(const Vector& vetor);

        Vector operator+() const; // unário +

        Vector operator-() const; // unário -

        Vector operator+(const Vector& v1) const; // operador binario +
        
        Vector operator-(const Vector& v1) const; // operador binario -

        Vector operator*(double escalar) const; // multiplicacao por escalar

        friend int tamanho(const Vector& vA); // permite uma classe amiga ter acesso ao metodo      
};

// Assinatura de protótipo da função Friend 
int tamanho(const Vector& v);

#endif