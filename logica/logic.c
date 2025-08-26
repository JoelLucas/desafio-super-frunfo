#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Primeiro precisamos de uma estrutura para representar uma carta
typedef struct {
    char nome[50];     // Nome da carta
    int forca;         // Atributo 1
    int velocidade;    // Atributo 2
    int inteligencia;  // Atributo 3
    int superTrunfo;   // 1 = é Super Trunfo, 0 = não é
} Carta;

// Estrutura para o jogador
typedef struct {
    char nome[30];
    Carta cartas[30];  // Baralho do jogador
    int numCartas;     // Quantidade atual de cartas
} Jogador;

// Funções que vamos precisar:
// - Mostrar uma carta
// - Comparar duas cartas por atributo
// - Remover carta do topo do baralho
// - Colocar carta no final do baralho

// Função principal
int main() {
    // 1. Criar jogadores
    // 2. Criar algumas cartas (exemplo inicial)
    // 3. Distribuir cartas entre os jogadores
    // 4. Fazer loop de rodadas
    //    - Mostrar carta de cada jogador
    //    - Jogador humano escolhe atributo
    //    - Comparar as cartas
    //    - Quem vencer, leva as duas cartas pro fim do baralho
    //    - Empate: cada um guarda a própria carta no fim do baralho
    // 5. O jogo acaba quando um jogador fica sem cartas

    printf("===== SUPER TRUNFO =====\n");

    return 0;
}
