#include <stdio.h>

void vazia(int tam_list){
  if(tam_list == 0)
    printf("\nA lista esta vazia.\n");
  else
    printf("\n\nA lista nao esta vazia.\n");
}

int cheia(int tam_vet, int tam_list){
  if(tam_list == tam_vet){
    printf("\nA lista esta cheia.\n");
    return -1;
  }
  else
    return 0;
}

int obter_elemento(int posicao, int tam_list, int *lista){
  int elemento;
  if(posicao <= 0 || posicao > tam_list){
    printf("A posicao inserida e invalida.\n");
    return 0;
  }
  else
    elemento = lista[posicao - 1];
  return elemento;
}

void alterar_elemento(int novo_valor, int posicao, int tam_list, int *lista){
  if(posicao <= 0 || posicao > tam_list)
    printf("A posicao inserida e invalida.\n");
  else
    lista[posicao - 1] = novo_valor;
  for(int i =0; i < tam_list; i++)
    printf("%d  ", lista[i]);
}

int inserir_elemento(int posicao, int novo_elemento, int *tam_list,int tam_vet, int *lista){
    if((cheia(tam_vet, *tam_list)) || (posicao > *tam_list + 1) || (posicao <= 0)){
        printf("A posicao inserida e invalida.\n\n");
        return 0;
    }
      for(int i= *tam_list; i>= posicao; i--)
          lista[i] = lista[i-1];
      lista[posicao - 1] = novo_elemento;
      *tam_list += 1;
      for(int i =0; i < *tam_list; i++ )
        printf("%d  ", lista[i]);
      printf("\n\n");
    return 1;
}

int remover_elemento(int posicao, int *tam_list, int *lista){
  int elemento_removido;
  if((posicao > *tam_list) || (posicao < 1)){
    printf("\nPosicao invalida.\n");
    return 0;
  }
  elemento_removido = lista[posicao - 1];
  for(int i = posicao - 1; i < *tam_list; i++)
    lista[i] = lista[i + 1];
  *tam_list -= 1;
  printf("\n");
  for(int i =0; i < *tam_list; i++ )
    printf("%d  ", lista[i]);
  printf("\nO elemento removido foi o numero %d.\n", elemento_removido);
  return 1;
}

int main() {
  int tamanho_vetor = 100;
  int lista[tamanho_vetor]; ///Criação da lista vazia.
  int tamanho_lista = 0;

  vazia(tamanho_lista); ///Verificação para saber se a lista está vazia.
  printf("\n");
  for(int i=0; i<6; i++){ ///Preenchendo a lista com alguns valores.
    lista[i] = i * 5;
    tamanho_lista += 1;
    }
  printf("Lista inicial:\n\n");
  for(int i =0; i < tamanho_lista; i++) ///Exibição inicial da lista.
    printf("%d  ", lista[i]);
  
  vazia(tamanho_lista); ///Verificação para saber se a lista continua vazia.
  cheia(tamanho_lista, tamanho_vetor); ///Verificação para saber se a lista está cheia.
  printf("\nTamanho da lista: %d\n", tamanho_lista); ///Exibição do tamanho da lista.

  printf("\nElemento selecionado: %d\n\n", obter_elemento(3, tamanho_lista, lista)); ///Obter o elemento da posição 3 da lista.

  alterar_elemento(44, 3, tamanho_lista, lista); ///Alteração de um elemento da lista. 1º parâmetro é o novo elemento,
  ///2º parâmetro é a posição do elemento que vai ser alterado.

  printf("\n\nElemento selecionado: %d\n\n", obter_elemento(3, tamanho_lista, lista));

  inserir_elemento(2, 50, &tamanho_lista, tamanho_vetor, lista); ///Inserindo novos elementos na lista.
  inserir_elemento(5, 81, &tamanho_lista, tamanho_vetor, lista); ///O 1º parâmetro é a posição na lista.
  inserir_elemento(1, 98, &tamanho_lista, tamanho_vetor, lista); ///O 2º parâmetro é o novo elemento.
  inserir_elemento(12, 1, &tamanho_lista, tamanho_vetor, lista);
  inserir_elemento(10, 65, &tamanho_lista, tamanho_vetor, lista);

  printf("\nTamanho da lista: %d\n", tamanho_lista);

  remover_elemento(8, &tamanho_lista, lista); ///Removendo elementos da lista.
  remover_elemento(6, &tamanho_lista, lista); ///O primeiro parâmetro refere-se a posição do elemento que será removido.
  remover_elemento(5, &tamanho_lista, lista);
  remover_elemento(13, &tamanho_lista, lista);
  remover_elemento(6, &tamanho_lista, lista);
  remover_elemento(1, &tamanho_lista, lista);
  remover_elemento(3, &tamanho_lista, lista);
  remover_elemento(2, &tamanho_lista, lista);
  remover_elemento(2, &tamanho_lista, lista);
  remover_elemento(1, &tamanho_lista, lista);
  remover_elemento(1, &tamanho_lista, lista);

  vazia(tamanho_lista);

}