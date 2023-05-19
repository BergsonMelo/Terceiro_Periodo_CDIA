#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    string cpf;
    static int qtd_pessoas;
    int idade;
    float altura;
    static float soma_altura;
    public:
        Pessoa(const string& c, int i, float a){
            cpf = c;
            idade = i;
            altura = a;
            qtd_pessoas++;
            soma_altura += a;

        }

        ~Pessoa(){

        }

        string get_cpf(){
            return cpf;
        }

        static int get_qtd_pessoas(){
            return qtd_pessoas;
        }

        static float get_media_altura(){
            if(qtd_pessoas > 0){
                return soma_altura/qtd_pessoas;
            }
            else{
                return 0.0;
            }
        }
};

class Professor: public Pessoa{
    int matricula;
    int ano_admissao;
    int titulacao;
    static int contador;
    static int soma_idade;
 
    public:
        Professor(int m, int ano, int t, const string& c, int i, float a):Pessoa(c,i,a){ //Nao incremento qtd pessoas, pq invoco
            matricula = m;                                                             //construtor de pessoa.
            ano_admissao = ano;
            titulacao = t;
            soma_idade += i;
            contador++;
        }

        ~Professor(){

        }

        static float get_media_idade(){
            if(contador == 0){
                return 0.0;
            }
            else{
                return ((float)soma_idade)/contador;
            }
        }

    

        int get_matricula(){
            return matricula;
        }

        int get_ano_admissao(){
            return ano_admissao;
        }

        int get_titulacao(){
            return titulacao;
        }

        void set_matricula(int m){
            matricula = m;
        }

        void set_ano_titulacao(int ano){
            ano_admissao = ano;
        }

};

class Aluno:public Pessoa{
    int matricula;
    float cra;
    static int contador;
    static int soma_idade;

    public:
        Aluno(int m, float cr, const string& c, int i, float a):Pessoa(c,i,a){
            matricula = m;
            cra = cr;
            soma_idade+= i;
            contador++;
        }

        ~Aluno(){

        }

       static float get_media_idade(){
        if(contador == 0){
            return 0.0;
        }
        else{
            return ((float)soma_idade)/contador;
        }
       }

        int get_matricula(){
            return matricula;
        }

        float get_cra(){
            return cra;
        }

        void set_matricula(int m){
            matricula = m;
        }

        void set_cra(float cr){
            cra = cr;
        }
};

class Turma{
    Professor* prof_responsavel;
    Aluno** grupo; //ou Aluno* grupo[10]
    int codigo;
    int tamanho; //qtd que vai caber na turma
    int qtd_grupo;
    static Turma* instance;
    Turma(){
        codigo = 0;
        prof_responsavel = nullptr;
        qtd_grupo = 0;
        tamanho = 0;
    }
    public:
        static Turma* get_instance(){
            if(instance == nullptr){ //ou NULL
                instance = new Turma;
            }

                return instance;
            
        }
        ~Turma(){
        delete[] grupo;
    }

        void set_professor(Professor* p){
            prof_responsavel = p;
        }

        void create_grupo(int i){

            grupo = new Aluno*[i]; 
            //grupo = (Aluno**)malloc(sizeof(Aluno*)*i);

            tamanho = i;
        }

        void add_aluno(Aluno* a){

            if(grupo == nullptr){
                cout<<"Turma nao alocada"<<endl;
                return;
            }
            if(qtd_grupo< tamanho){
                grupo[qtd_grupo] = a;
                qtd_grupo++;
            }
            else{
                cout<<"Turma lotada."<<endl;
            }
        }

        Aluno* get_aluno(int i){
            return grupo[i];
        }

        Professor* get_professor(){
            return prof_responsavel;
        }

        float get_media_cra(){
            if(tamanho == 0){
                return 0.0;
            }
            float soma = 0.0;
            for(int i=0; i<qtd_grupo; i++){
                soma+= grupo[i]->get_cra();
            }
            return (soma / qtd_grupo);

        }
};

int Pessoa::qtd_pessoas = 0;
Turma* Turma::instance = NULL;
float Pessoa::soma_altura = 0.0;
int Aluno::contador = 0;
int Aluno::soma_idade = 0;
int Professor::contador = 0;
int Professor::soma_idade = 0;




int main(){
    Aluno a1(202101,9.4,"123456654",20,1.89);
    Aluno a2(202102,8.1,"869056654",25,1.81);
    Aluno a3(202103,7.0,"859456654",18,1.72);


    Professor p1(202301,2018,2020,"879495820419",60,1.78);

    Turma* t = Turma::get_instance();

    t->create_grupo(5);

    t->set_professor(&p1);
    t->add_aluno(&a1);
    t->add_aluno(&a2);
    t->add_aluno(&a3);
    

    cout<<"a) Media de altura das pessoas:: "<<Pessoa::get_media_altura()<<endl;
    cout<<"b) Quantidade de pessoas cadastradas no sistema::"<<Pessoa::get_qtd_pessoas()<<endl;
    cout<<"c) Media do cra da turma::"<<t->get_media_cra()<<endl;
    cout<<"d.1) Media de idade dos alunos:: "<<Aluno::get_media_idade()<<endl;
    cout<<"d.2) Media de idade dos professores:: "<<Professor::get_media_idade()<<endl;

}