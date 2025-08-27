#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
    int superTrunfo; // 1 = sim, 0 = não
} Carta;

// Estrutura do jogador
typedef struct {
    char nome[30];
    Carta cartas[30];
    int numCartas;
} Jogador;

// Função para mostrar carta
void mostrarCarta(Carta c) {
    printf("\n--- Carta: %s ---\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
    if (c.superTrunfo) {
        printf(">>> SUPER TRUNFO <<<\n");
    }
}

// Função para comparar cartas
int compararCartas(Carta c1, Carta c2, int atributo) {
    if (atributo == 1) return c1.forca - c2.forca;
    if (atributo == 2) return c1.velocidade - c2.velocidade;
    if (atributo == 3) return c1.inteligencia - c2.inteligencia;
    return 0;
}

int main() {
    Jogador j1 = {"Lucas", {}, 0};
    Jogador j2 = {"Computador", {}, 0};

    // Criando cartas
    Carta c1 = {"Dragão", 90, 70, 60, 0};
    Carta c2 = {"Fênix", 80, 85, 75, 1};

    j1.cartas[0] = c1;
    j1.numCartas = 1;

    j2.cartas[0] = c2;
    j2.numCartas = 1;

    printf("===== SUPER TRUNFO =====\n");

    mostrarCarta(j1.cartas[0]);
    mostrarCarta(j2.cartas[0]);

    int atributo;
    printf("\nEscolha atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
    scanf("%d", &atributo);

    int resultado = compararCartas(j1.cartas[0], j2.cartas[0], atributo);

    if (resultado > 0) {
        printf("\n%s venceu!\n", j1.nome);
    } else if (resultado < 0) {
        printf("\n%s venceu!\n", j2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
