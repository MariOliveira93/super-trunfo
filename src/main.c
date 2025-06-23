#include <stdio.h>
#include <string.h>
#include "../include/carta.h"

/**
 * Função para ler os dados de uma carta
 * @param carta Ponteiro para a estrutura da carta
 * @param numeroCarta Número da carta (1 ou 2)
 */
void lerCarta(struct Carta* carta, int numeroCarta) {
    printf("\n=== Cadastro da Carta %d ===\n", numeroCarta);
    
    printf("Digite o estado (ex: SP): ");
    scanf("%s", carta->estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade/país: ");
    scanf(" %[^\n]", carta->nome_cidade);
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

/**
 * Função para calcular os atributos derivativos (densidade populacional e PIB per capita)
 * @param carta Ponteiro para a estrutura da carta
 */
void calcularAtributosDerivativos(struct Carta* carta) {
    // Calcular densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    
    // Calcular PIB per capita
    if (carta->populacao > 0) {
        // PIB está em bilhões, convertemos para reais
        carta->pib_per_capita = (carta->pib * 1000000000) / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}

/**
 * Função para exibir os dados completos de uma carta
 * @param carta Estrutura da carta
 * @param numeroCarta Número da carta
 */
void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("\n=== Dados da Carta %d ===\n", numeroCarta);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade/País: %s\n", carta.nome_cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", carta.pib_per_capita);
}

/**
 * Função para exibir o menu principal de atributos
 */
void exibirMenu() {
    printf("\n=== ESCOLHA O ATRIBUTO PARA COMPARAÇÃO ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per capita\n");
    printf("Digite sua escolha (1-6): ");
}

/**
 * Função para exibir menu dinâmico (excluindo atributo já escolhido)
 * @param atributoJaEscolhido Atributo que já foi escolhido anteriormente
 */
void exibirMenuDinamico(int atributoJaEscolhido) {
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO PARA COMPARAÇÃO ===\n");
    
    if (atributoJaEscolhido != POPULACAO) printf("1. População\n");
    if (atributoJaEscolhido != AREA) printf("2. Área\n");
    if (atributoJaEscolhido != PIB) printf("3. PIB\n");
    if (atributoJaEscolhido != PONTOS_TURISTICOS) printf("4. Pontos Turísticos\n");
    if (atributoJaEscolhido != DENSIDADE_POPULACIONAL) printf("5. Densidade Populacional\n");
    if (atributoJaEscolhido != PIB_PER_CAPITA) printf("6. PIB per capita\n");
    
    printf("Digite sua escolha (1-6): ");
}

/**
 * Função para ler a opção do menu com validação
 * @return Opção escolhida pelo usuário
 */
int lerOpcaoMenu() {
    int opcao;
    while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 6) {
        printf("Opção inválida! Digite um número entre 1 e 6: ");
        while (getchar() != '\n');  // Limpar buffer
    }
    return opcao;
}

/**
 * Função para obter o valor de um atributo específico de uma carta
 * @param carta Estrutura da carta
 * @param atributo Código do atributo
 * @return Valor do atributo
 */
float obterValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case POPULACAO:
            return (float)carta.populacao;
        case AREA:
            return carta.area;
        case PIB:
            return carta.pib;
        case PONTOS_TURISTICOS:
            return (float)carta.pontos_turisticos;
        case DENSIDADE_POPULACIONAL:
            return carta.densidade_populacional;
        case PIB_PER_CAPITA:
            return carta.pib_per_capita;
        default:
            return 0.0;
    }
}

/**
 * Função para obter o nome de um atributo
 * @param atributo Código do atributo
 * @return Nome do atributo
 */
const char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case POPULACAO:
            return "População";
        case AREA:
            return "Área";
        case PIB:
            return "PIB";
        case PONTOS_TURISTICOS:
            return "Pontos Turísticos";
        case DENSIDADE_POPULACIONAL:
            return "Densidade Populacional";
        case PIB_PER_CAPITA:
            return "PIB per capita";
        default:
            return "Desconhecido";
    }
}

/**
 * Função para obter a unidade de medida de um atributo
 * @param atributo Código do atributo
 * @return Unidade do atributo
 */
const char* obterUnidadeAtributo(int atributo) {
    switch (atributo) {
        case POPULACAO:
            return "habitantes";
        case AREA:
            return "km²";
        case PIB:
            return "bilhões";
        case PONTOS_TURISTICOS:
            return "pontos";
        case DENSIDADE_POPULACIONAL:
            return "hab/km²";
        case PIB_PER_CAPITA:
            return "R$";
        default:
            return "";
    }
}

/**
 * Função para determinar o vencedor entre dois valores
 * @param valor1 Valor da carta 1
 * @param valor2 Valor da carta 2
 * @param atributo Atributo sendo comparado
 * @return 1 se carta1 vence, 2 se carta2 vence, 0 se empate
 */
int determinarVencedor(float valor1, float valor2, int atributo) {
    // Para densidade populacional, menor valor vence (regra especial)
    if (atributo == DENSIDADE_POPULACIONAL) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    } else {
        // Para outros atributos, maior valor vence
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
    }
}

/**
 * Função para exibir o resultado de uma comparação simples
 */
void exibirResultadoComparacao(struct Carta carta1, struct Carta carta2, int atributo, 
                              float valor1, float valor2, int vencedor) {
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributo: %s\n\n", obterNomeAtributo(atributo));
    
    // Formatação especial para diferentes tipos de valores
    if (atributo == POPULACAO || atributo == PONTOS_TURISTICOS) {
        printf("Carta 1 - %s (%s): %.0f %s\n", 
               carta1.nome_cidade, carta1.estado, valor1, obterUnidadeAtributo(atributo));
        printf("Carta 2 - %s (%s): %.0f %s\n", 
               carta2.nome_cidade, carta2.estado, valor2, obterUnidadeAtributo(atributo));
    } else {
        printf("Carta 1 - %s (%s): %.2f %s\n", 
               carta1.nome_cidade, carta1.estado, valor1, obterUnidadeAtributo(atributo));
        printf("Carta 2 - %s (%s): %.2f %s\n", 
               carta2.nome_cidade, carta2.estado, valor2, obterUnidadeAtributo(atributo));
    }
    
    // Exibir resultado usando operador ternário
    printf("\nResultado: %s\n", 
           (vencedor == 0) ? "Empate!" : 
           (vencedor == 1) ? "Carta 1 venceu!" : "Carta 2 venceu!");
    
    if (vencedor != 0) {
        printf("Vencedor: %s\n", 
               (vencedor == 1) ? carta1.nome_cidade : carta2.nome_cidade);
    }
}

/**
 * Função para exibir resultado completo da comparação com dois atributos
 */
void exibirResultadoComparacaoCompleta(struct Carta carta1, struct Carta carta2, 
                                      int atributo1, int atributo2,
                                      float valor1_attr1, float valor1_attr2,
                                      float valor2_attr1, float valor2_attr2,
                                      float soma1, float soma2, int vencedorFinal) {
    printf("\n=== RESULTADO DA COMPARAÇÃO COMPLETA ===\n");
    printf("Atributos comparados: %s e %s\n\n", 
           obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
    
    // Exibir valores individuais de cada atributo
    printf("--- Carta 1: %s (%s) ---\n", carta1.nome_cidade, carta1.estado);
    printf("%s: %.2f %s\n", obterNomeAtributo(atributo1), valor1_attr1, obterUnidadeAtributo(atributo1));
    printf("%s: %.2f %s\n", obterNomeAtributo(atributo2), valor1_attr2, obterUnidadeAtributo(atributo2));
    printf("Soma dos atributos: %.2f\n\n", soma1);
    
    printf("--- Carta 2: %s (%s) ---\n", carta2.nome_cidade, carta2.estado);
    printf("%s: %.2f %s\n", obterNomeAtributo(atributo1), valor2_attr1, obterUnidadeAtributo(atributo1));
    printf("%s: %.2f %s\n", obterNomeAtributo(atributo2), valor2_attr2, obterUnidadeAtributo(atributo2));
    printf("Soma dos atributos: %.2f\n\n", soma2);
    
    // Resultado final
    printf("=== RESULTADO FINAL ===\n");
    if (vencedorFinal == 0) {
        printf("EMPATE! Ambas as cartas têm a mesma soma de atributos.\n");
    } else {
        printf("VENCEDOR: Carta %d - %s\n", vencedorFinal, 
               (vencedorFinal == 1) ? carta1.nome_cidade : carta2.nome_cidade);
        printf("Diferença: %.2f pontos\n", 
               (vencedorFinal == 1) ? (soma1 - soma2) : (soma2 - soma1));
    }
}

/**
 * Função para comparar cartas com base em um único atributo
 */
void compararUmAtributo(struct Carta carta1, struct Carta carta2, int atributo) {
    float valor1 = obterValorAtributo(carta1, atributo);
    float valor2 = obterValorAtributo(carta2, atributo);
    int vencedor = determinarVencedor(valor1, valor2, atributo);
    
    exibirResultadoComparacao(carta1, carta2, atributo, valor1, valor2, vencedor);
}

/**
 * Função para comparar cartas com base em dois atributos
 */
void compararDoisAtributos(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2) {
    // Obter valores dos atributos para ambas as cartas
    float valor1_attr1 = obterValorAtributo(carta1, atributo1);
    float valor1_attr2 = obterValorAtributo(carta1, atributo2);
    float valor2_attr1 = obterValorAtributo(carta2, atributo1);
    float valor2_attr2 = obterValorAtributo(carta2, atributo2);
    
    // Calcular somas dos atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;
    
    // Determinar vencedor final baseado na soma
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;
    
    // Exibir resultado completo
    exibirResultadoComparacaoCompleta(carta1, carta2, atributo1, atributo2,
                                     valor1_attr1, valor1_attr2, valor2_attr1, valor2_attr2,
                                     soma1, soma2, vencedorFinal);
}

/**
 * Menu principal do programa
 * @return Opção escolhida pelo usuário
 */
int menuPrincipal() {
    printf("\n=== SUPER TRUNFO - MENU PRINCIPAL ===\n");
    printf("1. Comparação com um atributo (Nível Básico)\n");
    printf("2. Comparação com menu interativo (Nível Intermediário)\n");
    printf("3. Comparação com dois atributos (Nível Avançado)\n");
    printf("0. Sair\n");
    printf("Digite sua escolha: ");
    
    int opcao;
    while (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 3) {
        printf("Opção inválida! Digite um número entre 0 e 3: ");
        while (getchar() != '\n');
    }
    return opcao;
}

/**
 * Função principal do programa
 */
int main() {
    struct Carta carta1, carta2;
    int opcaoPrincipal;
    
    printf("=== BEM-VINDO AO SUPER TRUNFO ===\n");
    printf("Sistema completo de comparação de cartas!\n");
    
    // Cadastrar as duas cartas
    printf("\nPrimeiro, vamos cadastrar as duas cartas:\n");
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    // Calcular atributos derivativos
    calcularAtributosDerivativos(&carta1);
    calcularAtributosDerivativos(&carta2);
    
    // Exibir cartas cadastradas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Loop principal do programa
    do {
        opcaoPrincipal = menuPrincipal();
        
        switch (opcaoPrincipal) {
            case 1: {
                // Nível Básico - Comparação com um atributo pré-definido
                printf("\n=== NÍVEL BÁSICO ===\n");
                printf("Comparação usando População (atributo pré-definido)\n");
                compararUmAtributo(carta1, carta2, POPULACAO);
                break;
            }
            
            case 2: {
                // Nível Intermediário - Menu interativo
                printf("\n=== NÍVEL INTERMEDIÁRIO ===\n");
                exibirMenu();
                int atributo = lerOpcaoMenu();
                compararUmAtributo(carta1, carta2, atributo);
                break;
            }
            
            case 3: {
                // Nível Avançado - Dois atributos
                printf("\n=== NÍVEL AVANÇADO ===\n");
                
                // Escolher primeiro atributo
                exibirMenu();
                int atributo1 = lerOpcaoMenu();
                
                // Escolher segundo atributo (menu dinâmico)
                int atributo2;
                do {
                    exibirMenuDinamico(atributo1);
                    atributo2 = lerOpcaoMenu();
                    
                    if (atributo2 == atributo1) {
                        printf("Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
                        printf("Por favor, escolha um atributo diferente.\n");
                    }
                } while (atributo2 == atributo1);
                
                compararDoisAtributos(carta1, carta2, atributo1, atributo2);
                break;
            }
            
            case 0:
                printf("\nObrigado por jogar Super Trunfo!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        
        if (opcaoPrincipal != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
        }
        
    } while (opcaoPrincipal != 0);
    
    return 0;
}