#include <stdio.h>

int vazia(int tam_list){
  if(tam_list == 0)
    return 1;
  else
    return 0;
}

int cheia(int tam_vet, int tam_list){
  if(tam_list == tam_vet)
    return 1;
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

int alterar_elemento(int posicao, int tam_list, int *lista){
  int novo_valor;
  printf("Insira o novo valor: \n");
  scanf("%d", &novo_valor);
  if(posicao <= 0 || posicao > tam_list){
    printf("A posicao inserida e invalida.\n");
    return 0;
  }
  else
    lista[posicao - 1] = novo_valor;
return 1;
}

int inserir_elemento(int posicao, int novo_elemento, int *tam_list,int tam_vet, int *lista){
    if((cheia(*tam_list, tam_vet)) || (posicao > *tam_list + 1) || (posicao <= 0)){
        printf("A posicao inserida e invalida.\n");
        return 0;
    }
      for(int i= *tam_list; i>= posicao; i--)
          lista[i] = lista[i-1];
      lista[posicao - 1] = novo_elemento;
      *tam_list += 1;
      for(int i =0; i < *tam_list; i++ )
        printf("%d  ", lista[i]);
    return 1;
}

int remover_elemento(int posicao, int *tam_list, int *lista){
  int elemento_removido;
  if((posicao > *tam_list) || (posicao < 1)){
    printf("Posicao invalida.\n");
    return 0;
  }
  elemento_removido = lista[posicao - 1];
  for(int i = posicao - 1; i < *tam_list; i++)
    lista[i] = lista[i + 1];
  *tam_list -= 1;
  for(int i =0; i < *tam_list; i++ )
    printf("%d  ", lista[i]);
  printf("\nO elemento removido foi o numero %d.\n", elemento_removido);
  return 1;
}

int main() {
  int tamanho_vetor = 100;
  int lista[tamanho_vetor];
  int tamanho_lista = 0;
  char escolha;
  int posicao_inserir_elemento;
  int posicao_remover_elemento;
  int novo_elemento;
  int menu;
  for(int i=0; i<6; i++){
    lista[i] = i * 5;
    tamanho_lista += 1;
    }

  do{
    printf("\nDigite 1 para inserir um novo elemento ou 2 para remover um elemento: \n");
    scanf("%d", &menu);

    switch(menu){
      case 1:
        printf("Digite uma posicao e um elemento: \n");
        scanf("%d %d", &posicao_inserir_elemento, &novo_elemento);
        inserir_elemento(posicao_inserir_elemento, novo_elemento, &tamanho_lista, tamanho_vetor, lista);
        break;

      case 2:
        printf("Digite a posicao referente ao elemento que sera removido: \n");
        scanf("%d", &posicao_remover_elemento);
        
        remover_elemento(posicao_remover_elemento, &tamanho_lista, lista);
        break;
      
      default:
        printf("Valor invalido!\n");
        break;
    }

  printf("\nDeseja fazer outra alteracao (s ou n): \n ");
  scanf(" %c", &escolha);
 
  }while(escolha == 's');
}
