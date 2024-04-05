#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxproducts 100

int op, k = 0, j = 0;
struct Cliente
{
  char nome[25];
  int compras[maxproducts][1];
  float valor[maxproducts];
  float total;
};

struct Cliente cliente;
struct Produto
{ // molde do meu produto
  int codigo;
  char nome[20];
  char descricao[50];
  int quantidade; // verifca se tem quantidade, e retirar quantidade
  float preco;
};

struct Produto
    prod[maxproducts]; // cria o nosso produto com quantidade maxproducts

// void gerar() {
//   for (i = 0; i < 10; i++) {
//     codigo[i] = i;
//   }
// }

void cadastrar()
{
  if (k < maxproducts)
    {
    printf("Digite o nome do produto %iº: ", k + 1);
    fflush(stdin);
    fgets(prod[k].nome, sizeof(prod[k].nome), stdin);
    fflush(stdin);

    printf("Digite a descricao do produto %iº: ", k + 1);
    fflush(stdin);
    fgets(prod[k].descricao, sizeof(prod[k].descricao), stdin);
    fflush(stdin);

    printf("Digite a quantidade do produto %i: ", k + 1);
    scanf("%i", &prod[k].quantidade);

    printf("Digite o preco unitario do produto %i: ", k + 1);
    scanf("%f", &prod[k].preco);

    k++;
    }
}
void atualizar()
{
  int codigo;
  printf("Qual produto deseja atualizar?");
  scanf("%i", &codigo);
  codigo = codigo - 1;

  printf("Digite o nome do produto %iº: ", codigo + 1);
  fflush(stdin);
  fgets(prod[codigo].nome, 20, stdin);

  printf("Digite a descricao do produto %iº: ", codigo + 1);
  fflush(stdin);
  fgets(prod[codigo].descricao, 50, stdin);

  printf("Digite a quantidade do produto %i: ", codigo + 1);
  scanf("%i", &prod[codigo].quantidade);

  printf("Digite o preco unitario do produto %i: ", codigo + 1);
  scanf("%f", &prod[codigo].preco);
}
void compra()
{
  int codigo, quant, i;
  for (int i = 0; i < maxproducts; i++)
    {
    if (strlen(prod[i].nome) != 0)
    {
      printf("Produto %i: %s - %d \n", i + 1, prod[i].nome, prod[i].quantidade);
    }
    }
  printf("Escolha um produto: ");
  fflush(stdin);
  scanf("%i", &codigo);
  codigo = codigo - 1;

  printf("Digite a quantidade do produto %i: ", codigo + 1);
  fflush(stdin);
  scanf("%i", &quant);

  if (quant > prod[codigo].quantidade)
    {
    printf("Não temos essa quantidade.  \n");
    }
  else
    {
    cliente.compras[codigo][0] = quant;
    cliente.valor[codigo] = prod[codigo].preco * quant;
    cliente.total = cliente.total + cliente.valor[codigo];
    prod[codigo].quantidade = prod[codigo].quantidade - quant;
    printf("o Cliente %s comprou %i unidades do produto %s, totalizando R$ "
           "%.2f  \n",
           cliente.nome, quant, prod[codigo].nome, cliente.valor[codigo]);
    }
}
void historico()
{
  printf("O Cliente %s comprou: \n", cliente.nome);
  for (int i = 0; i < maxproducts; i++)
    {

    if (cliente.compras[i][0] != 0)
        {
      printf("Você comprou %i unidades do produto %s, totalizando R$ %.2f \n",
             cliente.compras[i][0], prod[i].nome, cliente.valor[i]);
        }
    }
  printf("O total da compra foi de %f", cliente.total);
}

void pesquisa()
{
  int codigo;
  printf("Qual produto deseja pesquisar?");
  scanf("%i", &codigo);
  codigo = codigo - 1;
  printf("Produto Encontrado\n");
  printf("Codigo: %d\n", codigo + 1);
  printf("Nome do produto: %s\n", prod[codigo].nome);
  printf("Descricao: %s\n", prod[codigo].descricao);
  printf("Quantidade: %i\n\n", prod[codigo].quantidade);
}

void moc()
{
  strcpy(prod[0].nome, "Porca");
  strcpy(prod[0].descricao, "Porca de corte");
  prod[0].quantidade = 1000;
  prod[0].preco = 0.30;

  strcpy(prod[1].nome, "Parafuso");
  strcpy(prod[1].descricao, "Parafuso de Sla");
  prod[1].quantidade = 2000;
  prod[1].preco = 0.10;

  strcpy(prod[2].nome, "Martelo");
  strcpy(prod[2].descricao, "Martelada");
  prod[2].quantidade = 400;
  prod[2].preco = 200;

  strcpy(prod[3].nome, "Prego");
  strcpy(prod[3].descricao, "Pregar a palavra");
  prod[3].quantidade = 3000;
  prod[3].preco = 1.50;
}
int main()
{

  moc();
  printf("Digite seu Nome: ");
  fflush(stdin);
  fgets(cliente.nome, sizeof(cliente.nome), stdin);

  do
  {

    printf("\n-------------------------------------------");
    printf("\n*********** CONTROLE DE ESTOQUE ***********");
    printf("\n-------------------------------------------");
    printf("\n[1] Gerar Codigo do Produto");
    printf("\n[2] Cadastro de Produtos/Quantidade e Preco"); // Feito.
    printf("\n[3] Pesquisa de produto");                     // Feito
    printf("\n[4] Atualizar Produtos");                      // Feito
    printf("\n[5] Venda e Baixa do Produto");                // Feito
    printf("\n[6] Historico de Venda");                      // Feito
    printf("\n[7] Sair");
    printf("\n");

    fflush(stdin);
    scanf("%i", &op);

    switch (op)
    {
    case 1:
      printf("Foi");
      break;
    case 2:
      cadastrar();
      break;
    case 3:
      pesquisa();

      break;
    case 4:
      atualizar();
      break;
    case 5:
      compra();
      break;
    case 6:
      historico();
      break;
    case 7:
      break;
    default:
      printf("Opção invalida");
    }
  }
  while (op != 7);
  return 0;
}
