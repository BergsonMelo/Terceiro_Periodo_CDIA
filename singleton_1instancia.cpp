#include <iostream>
using namespace std;

class kbd_acess{
    char last_char;
    int buffer_size;
    static kbd_acess* _instance;
    kbd_acess(char c = '0', int b = 0){
        last_char = c;
        buffer_size = b;
    }
    public:
        static kbd_acess* instance(){
            if(_instance == NULL){
                _instance = new kbd_acess; //Como construtor tem valores padroes, nao preciso passar parametros.
            }
            return _instance;
        }

        char get_last_char(){
            return last_char;
        }

        int get_buffer_size(){
            return buffer_size;
        }

        void set_last_char(char c){
            last_char = c;
        }

        void set_buffer_size(int b){
            buffer_size = b;
        }
            
};

kbd_acess* kbd_acess::_instance = NULL;

int main(){
    /*
    kbd_acess* my_kbd = kbd_acess::instance(); //Construtor privado, é assim que se instancia, e so instancia-se 1 objeto.

    my_kbd->set_buffer_size(10);
    my_kbd->set_last_char('h');
    cout<<my_kbd->get_buffer_size()<<endl;
    cout<<my_kbd->get_last_char()<<endl;
    */
    kbd_acess::instance()->set_buffer_size(50); //Quando eu chamo instance, o objeto é instanciado.
    kbd_acess::instance()->set_last_char('L');
    cout<<kbd_acess::instance()->get_buffer_size()<<endl;
    cout<<kbd_acess::instance()->get_last_char()<<endl;
}