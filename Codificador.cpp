/*-------------------------
  MADE BY: Lucas Lima Aires
  -------------------------*/


#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void cifrador(string texto, int chave) {
    for (int i = 0; i < texto.size(); i++) { //Lê o tamanho da string 
        char c = texto[i];
        if (isalpha(c)) { //Verifica se cada caracter é uma letra
            int enc = (int)c + chave;
            if (islower(c)) { //Converte as letras minúsculas
                if (enc > 'z') {
                    enc -= 26;
                }
            } else if (isupper(c)) { //Converte as letras maiúsculas
                if (enc > 'Z') {
                    enc -= 26;
                }
            }
            cout << (char)enc;
        } else {
            cout << c; 
        }
    }
    cout << "\n\n";
}

void decifrador(string texto, int chave) { 
    for (int i = 0; i < texto.size(); i++) { //Lê o tamanho da string
        char c = texto[i];
        if (isalpha(c)) { //Verifica se cada caracter é uma letra
            int dec = (int)c - chave;
            if (islower(c)){ //Converte as letras minúsculas
                if (dec < 'a') {
                    dec += 26;
                }
            } else if (isupper(c)) { //Converte as letras maiúsculas
                if (dec < 'A') {
                    dec += 26;
                }
            }
            cout << (char)dec;
        } else {
            cout << c;
        }
    }
    cout << "\n\n";
}

int main() {
    std::string texto;
    int chave;
    int opc;

    cout << ">>Escolha a função desejada<<\n"; //Menu para selecionar função
    cout << ">>1. Cifrar texto<<\n";
    cout << ">>2. Decifrar texto<<\n ";
    cin >> opc;

    switch (opc) {
        case (1):
            cout << "Digite um texto a ser criptografado: ";
            cin.ignore();
            getline(cin, texto);
            cout << "\nDigite a chave: ";
            cin >> chave;
            cifrador(texto, chave);
            break;

        case (2):
            cout << "Digite um texto a ser descriptografado: ";
            cin.ignore();
            getline(cin, texto);
            cout << "\nDigite a chave: ";
            cin >> chave;
            decifrador(texto, chave);
            break;

        default:
            cout << "Opção inválida!";
            break;
    }
}
