//Alunos:Lucas Ramos Amaral, Leidiane Santos dos Santos
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct Cliente {
    bool temDocumentacao; // true se o cliente tem a documentação, false caso contrário
};

Cliente fila[100]; // vetor para representar a fila de clientes
int tamanhoFila = 0; // tamanho atual da fila

void adicionaCliente(Cliente novoCliente) {
    fila[tamanhoFila] = novoCliente;
    tamanhoFila++;
}

void atendeCliente() {
    if (tamanhoFila > 0 && fila[0].temDocumentacao) {
        // remove o cliente atendido da fila
        for (int j = 0; j < tamanhoFila - 1; j++) {
            fila[j] = fila[j + 1];
        }
        tamanhoFila--;
    }
}

int main() {
    srand(time(0)); // inicializa o gerador de números aleatórios

    int minutos = 10; // número de minutos a serem simulados
    int clientesAtendidos = 0;

    for (int i = 0; i < minutos; i++) {
        // chega um novo cliente a cada minuto
        Cliente novoCliente;
        novoCliente.temDocumentacao = (rand() % 4 != 0); // 1 em 4 chance de não ter documentação

        adicionaCliente(novoCliente);

        // atendimento do caixa
        while (tamanhoFila > 0 && fila[0].temDocumentacao) {
            atendeCliente();
            clientesAtendidos++;
        }

        cout << "Minuto " << i + 1 << ": ";
        cout << "Clientes na fila: " << tamanhoFila << endl;
    }

    cout << "Clientes atendidos: " << clientesAtendidos << endl;

    return 0;
}