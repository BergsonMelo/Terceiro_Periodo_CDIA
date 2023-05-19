#include <iostream>
#include <string>
using namespace std;

class Veiculo{
  int ano_fabricacao;
  float valor;
  public:
  Veiculo(int a, float v){
    ano_fabricacao = a;
    valor = v;
  }
  ~Veiculo(){
   
  }

  int get_ano_fabricacao(){
    return ano_fabricacao;
  }

  float get_valor(){
    return valor;
  }

  void set_ano_fabricacao(int a){
    ano_fabricacao = a;
  }

  void set_valor(float v){
    valor = v;
  }

  protected:
    virtual void print_info(){
      cout<<"Ano de fabricacao:: "<<ano_fabricacao<<endl;
      cout<<"Valor do veiculo:: "<<valor<<endl;
    }

    virtual float ipva_calculado()=0;
};

class Carro: public Veiculo{
  float motor;
  int quantidade_portas;
  public:
    Carro(int a, float v, float m, int q):Veiculo(a,v){
      motor = m;
      quantidade_portas = q;
    }

    ~Carro(){
     
    }

    float get_motor(){
      return motor;
    }

    int get_quantidade_portas(){
      return quantidade_portas;
    }

    void set_motor(float m){
      motor = m;
    }

    void set_quantidade_portas(int q){
      quantidade_portas = q;
    }

    void print_info(){
      Veiculo::print_info();
      cout<<"Motor:: "<<motor<<endl;
      cout<<"Quantidade de portas::"<<quantidade_portas<<endl;
      cout<<endl;
    }

    float ipva_calculado(){
      int idade_do_veiculo = 2023 - Veiculo::get_ano_fabricacao();
      return ((idade_do_veiculo * (motor/10)) + (Veiculo::get_valor() / 1000));
    }
};

class Moto: public Veiculo{
  float cilindradas;
  int aro;
  public:  
    Moto(int a, float v, float c, int ar):Veiculo(a,v){
      cilindradas = c;
      aro = ar;
    }
    ~Moto(){
     
    }

    float get_cilindradas(){
      return cilindradas;
    }

    int get_aro(){
      return aro;
    }

    void set_cilindradas(float c){
      cilindradas = c;
    }

    void set_aro(int ar){
      aro = ar;
    }

    void print_info(){
      Veiculo::print_info();
      cout<<"Cilindradas:: "<<cilindradas<<endl;
      cout<<"Aro:: "<<aro<<endl;
      cout<<endl;
    }

    float ipva_calculado(){
      int idade_do_veiculo = 2023 - Veiculo::get_ano_fabricacao();
      return ((idade_do_veiculo * (cilindradas/100)) + (Veiculo::get_valor()/1100));
    }
};

class Caminhao:public Veiculo{
  float eixos;
  float carga;
  public:
    Caminhao(int a, float v, float e, float c):Veiculo(a,v){
      eixos = e;
      carga = c;
    }

    ~Caminhao(){
     
    }

    float get_eixos(){
      return eixos;
    }

    float get_carga(){
      return carga;
    }

    void set_eixos(float e){
      eixos = e;
    }

    void set_carga(float c){
      carga = c;
    }

    void print_info(){
      Veiculo::print_info();
      cout<<"Eixos:: "<<eixos<<endl;
      cout<<"Carga:: "<<carga<<"kg"<<endl;
      cout<<endl;
    }

    float ipva_calculado(){
      int idade_do_veiculo = 2023 - Veiculo::get_ano_fabricacao();
      return ((idade_do_veiculo * (eixos/2)) + (carga/1000) + (Veiculo::get_valor()/900));
    }
};


int main(){
  Carro c1(2015, 38000, 1.0, 4);
  c1.print_info();
  //cout<<"IPVA de c1::"<<c1.ipva_calculado()<<endl;

  Moto m2(2020, 20000, 150, 18);
  m2.print_info();

  //cout<<"IPVA de m1:: "<<moto2.ipva_calculado()<<endl;

  Caminhao ca1(2005, 40000, 6, 1500);
  ca1.print_info();
  //cout<<"IPVA de ca1:: "<<ca1.ipva_calculado()<<endl;

  //Para sobrescrever o método print_info() de veículo, esse método foi definido como virtual e foi necessário criar outro método 
  //com mesmo nome nas classes que herdaram de forma pública de veículo. Dessa forma, ao chamar print_info dos objetos, 
  //a exibiçao será de acordo com a implementaçao da classe do objeto.
}