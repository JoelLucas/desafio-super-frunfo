#include <stdio.h>
#include <string.h>

// Super Trunfo - Versão Iniciante (Tema: Cidades)
// 3 atributos inteiros para manter o projeto simples:
// [0] Populacao (em milhoes)   -> quanto maior, melhor
// [1] Area (em km^2)           -> quanto maior, melhor
// [2] PIB (indice 0..100)      -> quanto maior, melhor
//
// Dica: se quiser outros atributos (ex.: IDH, turismo, custo de vida),
// basta alterar os nomes nas impressões e os valores no vetor "baralho".

#define ATR_COUNT 3
#define MAX_NAME  32

typedef struct {
    char nome[MAX_NAME];
    int attr[ATR_COUNT]; // [0]=Populacao, [1]=Area, [2]=PIB (indice)
} Carta;

void mostra_carta(const char* dono, Carta c) {
    printf("\n[%s] %s\n", dono, c.nome);
    printf("  1) Populacao (milhoes): %d\n", c.attr[0]);
    printf("  2) Area (km^2):         %d\n", c.attr[1]);
    printf("  3) PIB (0-100):         %d\n", c.attr[2]);
}

int compara(Carta a, Carta b, int idx) {
    if (a.attr[idx] > b.attr[idx]) return 1;
    if (a.attr[idx] < b.attr[idx]) return -1;
    return 0;
}

int main(void) {
    // 8 cartas de cidades brasileiras (valores simples e aproximados/indicativos)
    // Você pode ajustar os números à vontade – o importante é serem inteiros.
    Carta baralho[8] = {
        {"Sao Paulo",     {12, 1521, 100}},
        {"Rio de Janeiro",{7,  1200,  90}},
        {"Brasilia",      {3,  5802,  85}},
        {"Salvador",      {3,   693,  70}},
        {"Belo Horizonte",{3,   331,  75}},
        {"Curitiba",      {2,   435,  80}},
        {"Recife",        {2,   218,  65}},
        {"Porto Alegre",  {2,   496,  78}}
    };

    // Distribuicao fixa: 4 primeiras para o jogador, 4 seguintes para a CPU
    Carta jogador[4] = { baralho[0], baralho[1], baralho[2], baralho[3] };
    Carta cpu[4]     = { baralho[4], baralho[5], baralho[6], baralho[7] };

    int pontos_jog = 0;
    int pontos_cpu = 0;

    printf("=============================================\n");
    printf("     SUPER TRUNFO - INICIATE (Cidades)       \n");
    printf("Atributos: Populacao (milhoes), Area (km^2), PIB (0-100)\n");
    printf("=============================================\n");
    printf("Sao 4 rodadas. Em cada uma, voce escolhe um atributo (1..3).\n");

    for (int rodada = 0; rodada < 4; rodada++) {
        printf("\n---------------------------------------------\n");
        printf("Rodada %d\n", rodada + 1);
        mostra_carta("Voce", jogador[rodada]);
        printf("\nA carta da CPU sera revelada apos a escolha.\n");

        int escolha = 0;
        printf("\nEscolha o atributo (1=Populacao, 2=Area, 3=PIB): ");
        if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 3) {
            printf("Entrada invalida. Considerando atributo 1 (Populacao).\n");
            escolha = 1;
        }
        int idx = escolha - 1;

        // Revela CPU
        mostra_carta("CPU", cpu[rodada]);

        int r = compara(jogador[rodada], cpu[rodada], idx);
        if (r > 0) {
            printf("\nVoce venceu esta rodada!\n");
            pontos_jog++;
        } else if (r < 0) {
            printf("\nCPU venceu esta rodada!\n");
            pontos_cpu++;
        } else {
            printf("\nEmpate nesta rodada!\n");
        }

        printf("Placar parcial: Voce %d x %d CPU\n", pontos_jog, pontos_cpu);

        // Limpar stdin para evitar loop de input nas proximas leituras
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Pressione ENTER para continuar...");
        getchar();
    }

    printf("\n=============================================\n");
    printf("Placar final: Voce %d x %d CPU\n", pontos_jog, pontos_cpu);
    if (pontos_jog > pontos_cpu) {
        printf("Parabens! Voce venceu o jogo.\n");
    } else if (pontos_jog < pontos_cpu) {
        printf("CPU venceu o jogo. Tente novamente!\n");
    } else {
        printf("Empate geral!\n");
    }
    printf("=============================================\n");

    return 0;
}
