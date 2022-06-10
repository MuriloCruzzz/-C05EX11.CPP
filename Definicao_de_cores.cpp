#include <iostream> // biblioteca da linguagem
#include <windows.h> // .h (biblioteca que não é do c++)
using namespace std;

// definição de cores pela sequencia oficial do SO
#define black     0 // Preto
#define blue      1 // Azul
#define green     2 // Verde
#define cyan      3 // Ciano
#define red       4 // Vermelho
#define magenta   5 // Magenta
#define brown     6 // Marrom
#define lgray     7 // Cinza claro
#define dgray     8 // Cinza escuro
#define lblue     9 // Azul claro
#define lgreen   10 // Verde claro
#define lcyan    11 // Ciano claro
#define lred     12 // Vermelho claro
#define lmagenta 13 // Magenta claro
#define yellow   14 // Amarelo
#define white    15 // Branco

void clear(void) // procedimento: limpa a tela
{
  HANDLE TELA; // pega a tela
  DWORD ESCRITA = 0; //
  COORD POS; // cordenation posição cartesiana
  TELA = GetStdHandle(STD_OUTPUT_HANDLE); // acesse e coloque o que voce pegou de modo saida
  POS.X = 0; // struct : posiçao 0
  POS.Y = 0; // struct : posição zero canro superior a esquerda
  FillConsoleOutputCharacter(TELA, 32, 80 * 25, POS, // preencha o a tela com os caracteres 32, 80*25( 80 colunas por 25 linhas)
    &ESCRITA);
  SetConsoleCursorPosition(TELA, POS); // depois que limpou a tela volte para a posição 0
  return;
}

void color(int COR_FUNDO, int COR_TEXTO)
{
  HANDLE TELA;
  int COR;
  TELA = GetStdHandle(STD_OUTPUT_HANDLE);

  if (COR_FUNDO<0 and COR_FUNDO>15 and COR_TEXTO<0 and
    COR_TEXTO > 15)
    COR = 15;
  else
    COR = COR_TEXTO + COR_FUNDO * 16; // formula para aplicar a cor devido ao padrão de OP
  SetConsoleTextAttribute(TELA, COR);
  return;
}
