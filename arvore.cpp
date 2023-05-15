#include <iostream>
using namespace std;

//ARVORE BINARIA:::

class No{
    No* esquerda;
    No* direita;
    int conteudo;
    public:
        No(int c){
            conteudo = c;
            esquerda = NULL;
            direita = NULL;
        }

        ~No(){

        }

        No* get_esquerda(){
            return esquerda;
        }

        No* get_direita(){
            return direita;
        }

        int get_conteudo(){
            return conteudo;
        }

        void set_esquerda(No* e){
            esquerda = e;
        }

        void set_direita(No* d){
            direita = d;
        }

        void set_conteudo(int c){
            conteudo = c;
        }
};


class Arvore{
    No* raiz;
    No** ptr_raiz;
    public:
        Arvore(){
            raiz = NULL;
            ptr_raiz = &raiz;
            
        }

        ~Arvore(){
            
        }

        bool vazia(){
            if(raiz == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        No* busca(No* r, int dado){
            No* achou;
            if(raiz == NULL){
                //cout<<"Retornou nulo"<<endl;
                return NULL;
                
            }
            if(r->get_conteudo() == dado){
                //cout<<"Retornou r"<<endl;
                return r;
            }
            //cout<<"Procurando na esquerda"<<endl;
            if(r->get_esquerda() != NULL){
                achou = busca(r->get_esquerda(), dado);
            }
            else{
                achou = NULL;
                //cout<<"Nao esta na esquerda"<<endl;
            }
            
            if(achou == NULL){
                //cout<<"Procurando na direita"<<endl;
                if(r->get_direita() != NULL){
                    achou = busca(r->get_direita(), dado);
                }
                else{
                    achou = NULL;
                }
            }
            //cout<<"Terminou a busca."<<endl;
            return achou;
        }

        bool insere_raiz(int c){
            No* novo_no = new No(c);
            if(raiz != NULL){
                return false;
            }
            novo_no->set_direita(NULL);
            novo_no->set_esquerda(NULL);
            *ptr_raiz = novo_no;
            //ptr_raiz = &novo_no;
            return true;
        }

        bool insere_direita(int c_pai, int c_filho){
            No* pai;
            No* filho;
            No* novo_no;
            filho = busca(raiz, c_filho);
            if(filho != NULL){
                return false; //significa que o elemento ja existe;
                //cout<<"Erro no filho direita"<<endl;
            }
            pai = busca(raiz, c_pai);
            if(pai == NULL){
                //cout<<"Pai direita nao existe"<<endl;
                return false; //pai nao existe.
                
            }

            if(pai->get_direita() != NULL){
                //cout<<"Ja existe elemento no pai direita"<<endl;
                return false; //Pai já tem elemento na direita.
                
            }

            //cout<<"Hora de alocar direita"<<endl;

            novo_no = new No(c_filho);
            novo_no->set_direita(NULL);
            novo_no->set_esquerda(NULL);
            //cout<<"Inserido na direita"<<endl;
            pai->set_direita(novo_no);
            return true;

        }

        bool insere_esquerda(int c_pai, int c_filho){
            No* pai;
            No* filho;
            No* novo_no;
            filho = busca(raiz, c_filho);
            if(filho != NULL){
                return false;
            }

            pai = busca(raiz, c_pai);
            if(pai == NULL){
                return false;
            }
            if(pai->get_esquerda() != NULL){
                return false;
            }
            //cout<<"Hora de alocar esquerda"<<endl;
            novo_no = new No(c_filho);
            novo_no->set_esquerda(NULL);
            novo_no->set_direita(NULL);
            pai->set_esquerda(novo_no);
            //cout<<"Inserido na esquerda"<<endl;
            return true;
        }

        bool exibe_pre_ordem(No* r){
            if(raiz == NULL){
                cout<<"Arvore vazia"<<endl;
                return false;
            }
            
            cout<<r->get_conteudo()<<" ";
            
            if(r->get_esquerda() != NULL){
                exibe_pre_ordem(r->get_esquerda());
            }
            if(r->get_direita()!= NULL){
                exibe_pre_ordem(r->get_direita());
            }
        }

        bool exibe_in_ordem(No* r){
            if(r == NULL){
                return false;
            }

            if(r->get_esquerda() != NULL){
                exibe_in_ordem(r->get_esquerda());
            }
            cout<<r->get_conteudo()<<" ";
            if(r->get_direita() != NULL){
                exibe_in_ordem(r->get_direita());
            }
        }

        bool exibe_pos_ordem(No* r){
            if(r== NULL){
                return false;
            }

            if(r->get_esquerda() != NULL){
                exibe_pos_ordem(r->get_esquerda());
            }
            if(r->get_direita() != NULL){
                exibe_pos_ordem(r->get_direita());
            }
            cout<<r->get_conteudo()<<" ";
        }

        void exibir(int escolha){
            if (escolha == 1){
                exibe_pre_ordem(raiz);
            }
            if (escolha == 2){
                exibe_in_ordem(raiz);
            }
            if (escolha == 3){
                exibe_pos_ordem(raiz);
            }
        }

 
};

class Arvore_BP{
    No* raiz;
    No** ptr_raiz;
    public:
        Arvore_BP(){
            raiz = NULL;
            ptr_raiz = &raiz;
        }

        ~Arvore_BP(){

        }

        bool vazia(){
            if(raiz == NULL){
                return true;
            }

            else{
                return false;
            }
        }

        bool insere_raiz(int c){
            No* novo_no;
            if(raiz != NULL){
                return false;
            }
            novo_no = new No(c);
            novo_no->set_esquerda(NULL);
            novo_no->set_direita(NULL);
            *ptr_raiz = novo_no;
            return true;
        }

        No* busca(No* r, int dado){
            No* achou;
            if(r == NULL){
                return NULL;
            }
            if(r->get_conteudo() == dado){
                return r;
            }
            if(r->get_conteudo() > dado){
                return busca(r->get_esquerda(), dado);
            }
            else{
                return busca(r->get_direita(), dado);
            }
        }

        bool inserir(int dado){
            No* novo_no;
            No* atual;
            No* antecessor;
            novo_no = new No(dado);
            novo_no->set_direita(NULL);
            novo_no->set_esquerda(NULL);
            if(raiz == NULL){
                *ptr_raiz = novo_no;
                return true;
            }
            atual = raiz;
            while(atual != NULL){
                antecessor = atual;
                if(atual->get_conteudo() > dado){
                    atual = atual->get_esquerda();
                }
                else{
                    atual = atual->get_direita();
                }
            }
            if(antecessor->get_conteudo() > dado){
                antecessor->set_esquerda(novo_no);
            }
            else{
                antecessor->set_direita(novo_no);
            }
            return true;


        }

        void exibe_in_ordem(No* r){
            if(r != NULL){
                exibe_in_ordem(r->get_esquerda());
                cout<<r->get_conteudo()<<" ";
                exibe_in_ordem(r->get_direita());
                
            }
        }

        void exibir(int e){
            if(e == 1){
                exibe_in_ordem(raiz);
            }
        }
};

int main(){
    Arvore a1;
    Arvore_BP a2;
    a1.insere_raiz(15);
    a1.insere_direita(15, 8);
    a1.insere_direita(8, 22);
    a1.insere_esquerda(15, 9);
    a1.insere_esquerda(9, 20);
    a1.exibir(1);
    cout<<endl;
    a1.exibir(2);
    cout<<endl;
    a1.exibir(3);
    cout<<endl;
    
    a2.insere_raiz(15);
    a2.inserir(8);
    a2.inserir(22);
    a2.inserir(9);
    a2.inserir(20);
    a2.exibir(1);

}