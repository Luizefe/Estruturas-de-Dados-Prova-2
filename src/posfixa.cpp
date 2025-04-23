#include "../include/posfixa.hpp"

int posfixa(Fila<char> &entrada) {
    Pilha<int> pilha(entrada.capacidade);
    int resultado = 0;
    char token;
    
    while (!entrada.esta_vazia()) {
        token = entrada.desenfileirar();
        
        if (isdigit(token)) {
        pilha.empilhar(token - '0');
        } else {
        if (pilha.esta_vazia()) {
            throw std::runtime_error("operador sem operandos.");
        }
        int b = pilha.desempilhar();
        
        if (pilha.esta_vazia()) {
            throw std::runtime_error(" operador sem operandos.");
        }
        int a = pilha.desempilhar();
        
        switch (token) {
            case '+':
            resultado = a + b;
            break;

            case '-':
            resultado = a - b;
            break;

            case '*':
            resultado = a * b;
            break;

            case '/':
            if (b==0){
                throw std:: runtime_error("nao pode haver divisão por zero");
                break;
            }
            resultado = a / b;
            break;
            
            default:
            throw std::runtime_error("Operador inválido.");
        }
        
        pilha.empilhar(resultado);
        }
    }
    
    if (pilha.esta_vazia()) {
        throw std::runtime_error("falta de operandos.");
    }
    
    return pilha.desempilhar(); 
}