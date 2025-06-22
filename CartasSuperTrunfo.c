/*
 * Desafio Super Trunfo - Países
 * Nível: Mestre
 * Tema: Batalha de Cartas no Super Trunfo
 * 
 * Este programa implementa um sistema completo de cadastro e batalha de cartas para o jogo Super Trunfo.
 * O usuário pode cadastrar duas cartas, calcular atributos e comparar as cartas em batalha.
 * 
 * Autor: Felipe Boechat
 */

#include <stdio.h>

int main() {
    // Declaração das variáveis para a Carta 1
    char estado1;           // Letra do estado (A-H)
    char codigo1[4];        // Código da carta (ex: A01)
    char nomeCidade1[50];   // Nome da cidade
    unsigned long int populacao1; // População da cidade
    float area1;            // Área em km²
    float pib1;             // PIB em bilhões de reais
    int pontosTuristicos1;  // Número de pontos turísticos
    float densidadePopulacional1; // Densidade populacional (hab/km²)
    float pibPerCapita1;          // PIB per capita (reais)
    float superPoder1;            // Super Poder da carta

    // Declaração das variáveis para a Carta 2
    char estado2;           // Letra do estado (A-H)
    char codigo2[4];        // Código da carta (ex: A01)
    char nomeCidade2[50];   // Nome da cidade
    unsigned long int populacao2; // População da cidade
    float area2;            // Área em km²
    float pib2;             // PIB em bilhões de reais
    int pontosTuristicos2;  // Número de pontos turísticos
    float densidadePopulacional2; // Densidade populacional (hab/km²)
    float pibPerCapita2;          // PIB per capita (reais)
    float superPoder2;            // Super Poder da carta

    // Mensagem de boas-vindas
    printf("=== Super Trunfo - Batalha de Cartas ===\n\n");

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite a letra do estado (A-Z): ");
    do {
        scanf(" %c", &estado1);
        // Converter para maiúscula se for minúscula
        if (estado1 >= 'a' && estado1 <= 'z') {
            estado1 = estado1 - 32;
        }
        // Validar se é uma letra de A a Z
        if (estado1 < 'A' || estado1 > 'Z') {
            printf("Entrada inválida! Digite apenas uma letra de A a Z: ");
        }
    } while (estado1 < 'A' || estado1 > 'Z');
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade1);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    
    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite a letra do estado (A-Z): ");
    do {
        scanf(" %c", &estado2);
        // Converter para maiúscula se for minúscula
        if (estado2 >= 'a' && estado2 <= 'z') {
            estado2 = estado2 - 32;
        }
        // Validar se é uma letra de A a Z
        if (estado2 < 'A' || estado2 > 'Z') {
            printf("Entrada inválida! Digite apenas uma letra de A a Z: ");
        }
    } while (estado2 < 'A' || estado2 > 'Z');
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo2);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade2);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    
    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos para as cartas
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Cálculo do Super Poder (soma de todos os atributos numéricos)
    // Incluindo o inverso da densidade populacional (quanto menor a densidade, maior o poder)
    superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    // Exibição dos dados das cartas
    printf("\n=== RESULTADO DO CADASTRO ===\n");
    printf("┌─────────────────────────────────────────────────────────────\n");
    printf("│ CARTA 1\n");
    printf("├─────────────────────────────────────────────────────────────\n");
    printf("│ Estado: %c\n", estado1);
    printf("│ Código: %-4s\n", codigo1);
    printf("│ Cidade: %s\n", nomeCidade1);
    printf("│ População: %lu habitantes\n", populacao1);
    printf("│ Área: %.2f km²\n", area1);
    printf("│ PIB: %.2f bilhões de reais\n", pib1);
    printf("│ Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("│ Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("│ PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("│ Super Poder: %.2f\n", superPoder1);
    printf("└─────────────────────────────────────────────────────────────\n\n");

    printf("┌─────────────────────────────────────────────────────────────\n");
    printf("│ CARTA 2\n");
    printf("├─────────────────────────────────────────────────────────────\n");
    printf("│ Estado: %c\n", estado2);
    printf("│ Código: %-4s\n", codigo2);
    printf("│ Cidade: %s\n", nomeCidade2);
    printf("│ População: %lu habitantes\n", populacao2);
    printf("│ Área: %.2f km²\n", area2);
    printf("│ PIB: %.2f bilhões de reais\n", pib2);
    printf("│ Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("│ Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("│ PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("│ Super Poder: %.2f\n", superPoder2);
    printf("└─────────────────────────────────────────────────────────────\n");

    // Comparação das cartas
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("População: %s (%d)\n", 
           populacao1 > populacao2 ? "Carta 1 venceu" : "Carta 2 venceu",
           populacao1 > populacao2 ? 1 : 0);
    
    printf("Área: %s (%d)\n", 
           area1 > area2 ? "Carta 1 venceu" : "Carta 2 venceu",
           area1 > area2 ? 1 : 0);
    
    printf("PIB: %s (%d)\n", 
           pib1 > pib2 ? "Carta 1 venceu" : "Carta 2 venceu",
           pib1 > pib2 ? 1 : 0);
    
    printf("Pontos Turísticos: %s (%d)\n", 
           pontosTuristicos1 > pontosTuristicos2 ? "Carta 1 venceu" : "Carta 2 venceu",
           pontosTuristicos1 > pontosTuristicos2 ? 1 : 0);
    
    printf("Densidade Populacional: %s (%d)\n", 
           densidadePopulacional1 < densidadePopulacional2 ? "Carta 1 venceu" : "Carta 2 venceu",
           densidadePopulacional1 < densidadePopulacional2 ? 1 : 0);
    
    printf("PIB per Capita: %s (%d)\n", 
           pibPerCapita1 > pibPerCapita2 ? "Carta 1 venceu" : "Carta 2 venceu",
           pibPerCapita1 > pibPerCapita2 ? 1 : 0);
    
    printf("Super Poder: %s (%d)\n", 
           superPoder1 > superPoder2 ? "Carta 1 venceu" : "Carta 2 venceu",
           superPoder1 > superPoder2 ? 1 : 0);

    printf("\n=== FIM DA BATALHA ===\n");

    return 0;
}
