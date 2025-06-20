#include <stdio.h>
#include "../include/carta.h"

void lerCarta(struct Carta* carta, int numeroCarta) {
    printf("\n=== Dados da Carta %d ===\n", numeroCarta);
    
    printf("Digite o estado (uma letra): ");
    scanf(" %c", &carta->estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome_cidade);
    
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao_cidade);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area_cidade);
    
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
}

void calcularAtributos(struct Carta* carta) {
    // Calcular densidade populacional
    if (carta->area_cidade > 0) {
        carta->densidade_populacional = (float)carta->populacao_cidade / carta->area_cidade;
    } else {
        carta->densidade_populacional = 0;
    }
    
    // Calcular PIB per capita
    if (carta->populacao_cidade > 0) {
        carta->pib_per_capita = (carta->pib * 1000000000) / (float)carta->populacao_cidade;
    } else {
        carta->pib_per_capita = 0;
    }
}

void calcularSuperPoder(struct Carta* carta) {
    // Super Poder = população + área + PIB + pontos turísticos + PIB per capita + (1/densidade populacional)
    float inverso_densidade = 0;
    
    if (carta->densidade_populacional > 0) {
        inverso_densidade = 1.0f / carta->densidade_populacional;
    }
    
    // Atenção na conversão de tipos!
    carta->super_poder = (float)carta->populacao_cidade + 
                        carta->area_cidade + 
                        carta->pib + 
                        (float)carta->num_pontos_turisticos + 
                        carta->pib_per_capita + 
                        inverso_densidade;
}

void compararCartas(struct Carta carta1, struct Carta carta2) {
    printf("\n=== Comparação de Cartas ===\n");
    
    // População (maior vence)
    int resultado_populacao = carta1.populacao_cidade > carta2.populacao_cidade ? 1 : 0;
    printf("População: Carta %d venceu (%d)\n", resultado_populacao ? 1 : 2, resultado_populacao);
    
    // Área (maior vence)
    int resultado_area = carta1.area_cidade > carta2.area_cidade ? 1 : 0;
    printf("Área: Carta %d venceu (%d)\n", resultado_area ? 1 : 2, resultado_area);
    
    // PIB (maior vence)
    int resultado_pib = carta1.pib > carta2.pib ? 1 : 0;
    printf("PIB: Carta %d venceu (%d)\n", resultado_pib ? 1 : 2, resultado_pib);
    
    // Pontos Turísticos (maior vence)
    int resultado_pontos = carta1.num_pontos_turisticos > carta2.num_pontos_turisticos ? 1 : 0;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", resultado_pontos ? 1 : 2, resultado_pontos);
    
    // Densidade Populacional (MENOR vence - regra especial)
    int resultado_densidade = carta1.densidade_populacional < carta2.densidade_populacional ? 1 : 0;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado_densidade ? 1 : 2, resultado_densidade);
    
    // PIB per Capita (maior vence)
    int resultado_pib_per_capita = carta1.pib_per_capita > carta2.pib_per_capita ? 1 : 0;
    printf("PIB per Capita: Carta %d venceu (%d)\n", resultado_pib_per_capita ? 1 : 2, resultado_pib_per_capita);
    
    // Super Poder (maior vence)
    int resultado_super_poder = carta1.super_poder > carta2.super_poder ? 1 : 0;
    printf("Super Poder: Carta %d venceu (%d)\n", resultado_super_poder ? 1 : 2, resultado_super_poder);
}

void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("\n=== Carta %d ===\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu habitantes\n", carta.populacao_cidade);
    printf("Área: %.2f km²\n", carta.area_cidade);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

int main() {
    struct Carta carta1, carta2;
    
    printf("=== SUPER TRUNFO - NÍVEL AVANÇADO ===\n");
    printf("Vamos comparar duas cartas!\n");
    
    // Ler dados das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    // Calcular atributos derivados para ambas as cartas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    // Calcular Super Poder para ambas as cartas
    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);
    
    // Exibir dados completos das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Comparar as cartas
    compararCartas(carta1, carta2);
    
    return 0;
}