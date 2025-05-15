#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

#define LIMPAR "cls"
#define PAUSAR "pause"


char jogador1[20], jogador2[20];

int jogo(int vitorias1, int vitorias2, int rodadas_necessarias) {
  printf("Digite o nome do jogador 1: ");
  scanf("%s", jogador1);
  printf("Digite o nome do jogador 2: ");
  scanf("%s", jogador2);
  int rodada = 1;

  while (vitorias1 < rodadas_necessarias && vitorias2 < rodadas_necessarias) {
    rodada++;
    printf("Rodada %d:\n", rodada);
    printf("%s, escolha sua jogada (1. Pedra, 2. Papel, 3. Tesoura): ", jogador1);
    int jogada1;
    scanf("%d", &jogada1);
    if (jogada1 < 1 || jogada1 > 3) {
      printf("Jogada inválida!\n");
      rodada--;
      continue;
    }

    system(LIMPAR);

    printf("%s, escolha sua jogada (1. Pedra, 2. Papel, 3. Tesoura): ", jogador2);
    int jogada2;
    scanf("%d", &jogada2);
    if (jogada2 < 1 || jogada2 > 3) {
      printf("Jogada inválida!\n");
      rodada--;
      continue;
    }

    printf("\n");
    switch (jogada1) {
      case 1:
        print_rock_left();
        break;
      case 2:
        print_paper_left();
        break;
      case 3:
        print_scissors_left();
        break;
    }
    switch (jogada2) {
      case 1:
        print_rock_right();
        break;
      case 2:
        print_paper_right();
        break;
      case 3:
        print_scissors_right();
        break;
    }
    if (jogada1 == jogada2) {
      printf("Empate!\n");
      rodada--;
    } else if ((jogada1 == 1 && jogada2 == 3) || (jogada1 == 2 && jogada2 == 1) || (jogada1 == 3 && jogada2 == 2)) {
      printf("%s ganhou a rodada!\n", jogador1);
      vitorias1++;
    } else {
      printf("%s ganhou a rodada!\n", jogador2);
      vitorias2++;
    }

    printf("Placar: %s %d - %d %s\n", jogador1, vitorias1, vitorias2, jogador2);

    system(PAUSAR);
    system(LIMPAR);
  }

  if (vitorias1 == rodadas_necessarias) {
    printf("🏆 %s venceu o jogo!\n", jogador1);
  } else {
    printf("🏆 %s venceu o jogo!\n", jogador2);
  }

  return 0;
}

int main() {
  int rodadas = 0, vitorias1 = 0, vitorias2 = 0, vitoria_necessaria, opcao;
  printf("JOGO: Pedra, Papel e Tesoura!\n");
  // printf("Digite o nome do jogador 1: ");
  // scanf("%s", jogador1);
  // printf("Digite o nome do jogador 2: ");
  // scanf("%s", jogador2);
  printf("Escolha uma opção:\n");
  printf("1. Melhor de 1\n");
  printf("2. Melhor de 3\n");
  printf("3. Melhor de 5\n");
  printf("4. Sair\n");
  do {
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > 4) {
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao < 1 || opcao > 4);
  switch (opcao) {
    case 1:
      system(LIMPAR);
      jogo(vitorias1, vitorias2, 1);
      break;
    case 2:
      system(LIMPAR);
      jogo(vitorias1, vitorias2, 2);
      break;
    case 3:
      system(LIMPAR);
      jogo(vitorias1, vitorias2, 3);
      break;
    case 4:
      system(LIMPAR);
      printf("Saindo do jogo...\n");
      return 0;
      break;
    default:
      printf("Opção inválida!\n");
      break;
  }
  printf("Fim do jogo!\n");
  return 0;
}