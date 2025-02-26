#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// Macro para printar uma string com uma quebra de linha.
#define printl(x) printf("%s\n", x)

// Esta struct representa uma carta do jogo Super Trunfo.
struct Carta{
    uint8_t estado, pontuacao;
    uint8_t nome[50];
    uint32_t codigo, populacao, pontos_turisticos;
    float area, pib, densidade_populacional, pib_per_capita;
};// uma struct serve para agrupar variáveis de tipos diferentes

struct Carta teste1 = { // CARTA TOTALMENTE PARA TESTES
    'A', 1, "Acre", 1, 881935, 1, 164123.040, 13.2, 0.18, 0.18
};
struct Carta teste2 = { // CARTA TOTALMENTE PARA TESTES
    'B', 1, "Alagoas", 2, 3337357, 1, 27778.506, 63.9, 0.08, 0.08
};

void loadCard(struct Carta *carta); // carrega os dados da carta
void showCard(struct Carta *carta); // exibe os dados da carta
void mostrarCaracteristicas(float v0, float v1);
void pedirCaracteristicas(uint8_t *caracteristica); // pede as caracteristicas
// void comparacao(uint8_t caracteristica); // compara as cartas
char* getLine(uint8_t size); // pega a linha

int main(){
    struct Carta cartas[2]; // Declaração das duas cartas.
    cartas[0] = teste1;
    cartas[1] = teste2;

    printl("Carta 1");
    // loadCard(&cartas[0]); // carrega os dados da carta 1
    showCard(&cartas[0]); // exibe os dados da carta 1

    // while (getchar() != '\n'); // apenas limpa o buffer do stdin

    printl("Carta 2");
    // loadCard(&cartas[1]); // carrega os dados da carta 2
    showCard(&cartas[1]); // exibe os dados da carta 2

    uint8_t caracteristicas[2]; // variavel para armazenar as escolhas do usuario

    pedirCaracteristicas(caracteristicas); // pede as caracteristicas para o usuario

    char vencedor;
    float soma1, soma2; // armazenará as somas das caracteristicas das cartas

    for (uint8_t i = 0; i < 2; i++) { // faz um looping de 0 a 1
        switch (caracteristicas[i]) {
            case '1': printl("\n1 - População"); // Analisa e mostra o vencedor dessa caractequistica
                printf("Carta 1 - %s : %d\n", cartas[0].nome, cartas[0].populacao);
                printf("Carta 2 - %s : %d\n", cartas[1].nome, cartas[1].populacao);
                if (cartas[0].populacao > cartas[1].populacao)
                    printf("Carta 1 (%s) venceu!\n", cartas[0].nome);
                else if (cartas[0].populacao < cartas[1].populacao)
                    printf("Carta 2 (%s) venceu!\n", cartas[1].nome);
                else printl("Empate!");
                soma1 += cartas[0].populacao; // soma a caracteristica da carta 1
                soma2 += cartas[1].populacao; // soma a caracteristica da carta 2
                break;

            case '2': printl("\n2 - Área"); // Analisa e mostra o vencedor dessa caractequistica
                printf("Carta 1 - %s : %f km²\n", cartas[0].nome, cartas[0].area);
                printf("Carta 2 - %s : %f km²\n", cartas[1].nome, cartas[1].area);
                if (cartas[0].area > cartas[1].area)
                    printf("Carta 1 (%s) venceu!\n", cartas[0].nome);
                else if (cartas[0].area < cartas[1].area)
                    printf("Carta 2 (%s) venceu!\n", cartas[1].nome);
                else printl("Empate!");
                soma1 += cartas[0].area; // soma a caracteristica da carta 1
                soma2 += cartas[1].area; // soma a caracteristica da carta 2
                break;

            case '3': printl("\n3 - PIB per capita"); // Analisa e mostra o vencedor dessa caractequistica
                printf("Carta 1 - %s : %f\n", cartas[0].nome, cartas[0].pib_per_capita);
                printf("Carta 2 - %s : %f\n", cartas[1].nome, cartas[1].pib_per_capita);
                if (cartas[0].pib_per_capita > cartas[1].pib_per_capita)
                    printf("Carta 1 (%s) venceu!\n", cartas[0].nome);
                else if (cartas[0].pib_per_capita < cartas[1].pib_per_capita)
                    printf("Carta 2 (%s) venceu!\n", cartas[1].nome);
                else printl("Empate!");
                soma1 += cartas[0].pib_per_capita; // soma a caracteristica da carta 1
                soma2 += cartas[1].pib_per_capita; // soma a caracteristica da carta 2
                break;

            case '4': printl("\n4 - PIB"); // Analisa e mostra o vencedor dessa caractequistica
                printf("Carta 1 - %s : %f\n", cartas[0].nome, cartas[0].pib);
                printf("Carta 2 - %s : %f\n", cartas[1].nome, cartas[1].pib);
                if (cartas[0].pib > cartas[1].pib)
                    printf("Carta 1 (%s) venceu!\n", cartas[0].nome);
                else if (cartas[0].pib < cartas[1].pib)
                    printf("Carta 2 (%s) venceu!\n", cartas[1].nome);
                else printl("Empate!");
                soma1 += cartas[0].pib; // soma a caracteristica da carta 1
                soma2 += cartas[1].pib; // soma a caracteristica da carta 2
                break;

            case '5': printl("\n5 - Densidade populacional"); // Analisa e mostra o vencedor dessa caractequistica
                printf("Carta 1 - %s : %f\n", cartas[0].nome, cartas[0].densidade_populacional);
                printf("Carta 2 - %s : %f\n", cartas[1].nome, cartas[1].densidade_populacional);
                if (cartas[0].densidade_populacional < cartas[1].densidade_populacional)
                    printf("Carta 1 (%s) venceu!\n", cartas[0].nome);
                else if (cartas[0].densidade_populacional > cartas[1].densidade_populacional)
                    printf("Carta 2 (%s) venceu!\n", cartas[1].nome);
                else printl("Empate!");
                soma1 += cartas[0].densidade_populacional; // soma a caracteristica da carta 1
                soma2 += cartas[1].densidade_populacional; // soma a caracteristica da carta 2
                break;
        }
    }

    printl("\nSoma das caracteristicas:");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);

    if (soma1 > soma2) printf("Carta 1 (%s) venceu a rodada!\n", cartas[0].nome);
    else if (soma1 < soma2) printf("Carta 2 (%s) venceu a rodada!\n", cartas[1].nome);
    else printl("Empate!");

    return 0;
}

// Pede as caracteristicas das cartas para o usuário e ja faz a verificação se a entrada do usuario é valida.
void pedirCaracteristicas(uint8_t *caracteristicas){
    printl("Escolha duas caracteristicas para comparar, ex: '2 5', para comparar área e densidade populacional.");
    printl("1 - População");
    printl("2 - Área");
    printl("3 - PIB per capita");
    printl("4 - PIB");
    printl("5 - Densidade populacional");
    printl("Digite o número das características: ");
ler:scanf(" %c %c", &caracteristicas[0], &caracteristicas[1]); // Ponto de leitura. Lê as caracteristicas que o usuario escolher

    if (caracteristicas[0] != caracteristicas[1]) {
        if (caracteristicas[0] <= '5' || caracteristicas[1] <= '5') return; // retorna normalmente armazenando os valores na variavel.
        else printl("Característica inválida, escolha novamente:");
    }
    printl("Características iguais, escolha novamente:");
    goto ler; // volta para o ponto de leitura e verifica novamente
}

// Função para exibir os detalhes de uma carta.
void showCard(struct Carta *carta) {
    printf("\n--- Detalhes da Carta ---\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %c0%d\n", carta->estado, carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f Km²\n", carta->area);
    printf("Densidade populacional: %.2f hab/Km²\n", carta->densidade_populacional);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("PIB per capita: %.2f reais\n", carta->pib_per_capita);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("-------------------------\n");
}

void loadCard(struct Carta *carta){
    printf("Digite o estado (A até H): ");
    carta->estado = getchar();
    // scanf(" %c", &carta->estado); // Lê um caractere (o estado).

    printf("Digite o código da carta (1 até 4): ");
    scanf(" %u", &carta->codigo); // Lê um inteiro sem sinal (o codigo).

    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", carta->nome); // Lê uma string (o nome da cidade).

    printf("Digite a população: ");
    scanf(" %u", &carta->populacao); // Lê um inteiro sem sinal (a quantidade da população).

    printf("Digite a área: ");
    scanf(" %f", &carta->area); // Lê um float (a área).

    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib); // Lê um float (o PIB).

    printf("Digite a quantidade de pontos turísticos: ");
    scanf(" %u", &carta->pontos_turisticos); // Lê um inteiro sem sinal (a quantidade de pontos turísticos).

    // Calcula a densidade populacional.
    // carta.densidade_populacional = carta.populacao / carta.area;
    carta->densidade_populacional = (float)carta->populacao / carta->area;

    // Calcula o PIB per capita.
    // carta->pib_per_capita = carta->pib / carta->populacao;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;
}
