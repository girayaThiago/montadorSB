#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <stdexcept>
/*
Lê um arquivo assembly e solta um arquivo objeto q é uma sequencia de numeros (igual questão 3 da prova)
tem que guardar os arquivos antes de processar, pré-processados e processados.

*/

std::unordered_map<std::string, int> token_dict;

// enum class known_instructions: int {
//     NOP,    // gambiarra pro enum ficar bonitinho
//     ADD,    //1op, tamanho 2 //cod = 1
//     SUB,    //1op, tamanho 2
//     MULT,   //1op, tamanho 2
//     DIV,    //1op, tamanho 2
//     JMP,    //1op, tamanho 2
//     JMPN,   //1op, tamanho 2
//     JMPP,   //1op, tamanho 2
//     JMPZ,   //1op, tamanho 2
//     COPY,   //2op, tamanho 3
//     LOAD,   //1op, tamanho 2
//     STORE,  //1op, tamanho 2
//     INPUT,  //1op, tamanho 2
//     OUTPUT, //1op, tamanho 2
//     STOP    //0op, tamanho 1
// };


std::vector<std::string> known_instructions = {
    "ADD", //1op, tamanho 2 //cod = 1
    "SUB", //1op, tamanho 2
    "MULT", //1op, tamanho 2
    "DIV",  //1op, tamanho 2
    "JMP",  //1op, tamanho 2
    "JMPN", //1op, tamanho 2
    "JMPP", //1op, tamanho 2
    "JMPZ", //1op, tamanho 2
    "COPY", //2op, tamanho 3
    "LOAD", //1op, tamanho 2
    "STORE",//1op, tamanho 2
    "INPUT",//1op, tamanho 2
    "OUTPUT",//1op, tamanho 2
    "STOP"//0op, tamanho 1
}; 

std::vector<std::string> known_directives = {
    "SECTION",//1op, tamanho 0 (TEXT or DATA)
    "SPACE",//op, tamanho 1
    "CONST",//1op, tamanho 1
    "EQU",//1op, tamanho 0
    "IF",//1op, tamanho 0
    "MACRO",//0op, tamanho 0
    "ENDMACRO"//0op, tamanho 0
};


void init_map(){
    int count = 1;
    for (auto str : known_instructions){
        token_dict.insert(std::make_pair(str, count++));
    }
    return;
}

std::string get_token(std::string str, std::string delim = " "){
    std::size_t pos = str.find(delim);
    std::string token = str.substr(0, pos);
    str.erase(0, pos + delim.size());
    return token;
}

int main ( int argc, char *argv[] ) {
    std::string filename = "./asm/bin.asm";
    //for (int i  = 0; i < argc; i++) std::cout << "arg[" << i << "] = " << argv[i] << "\n";
    if (argc == 3){
        if (std::string("-file").compare(argv[1]) == 0){
            filename = argv[2];
            std::cout << "yay!\n";
        }
        else {
            std::cout << "oh no :D\n";
        }
    }
    std::cout << filename << "\n";
    std::ifstream file(filename);
    if (file.is_open()){
        std::cout << "file is open\n";
        std::string line = std::string();
        std::string token, delimiter = " ";
        while (std::getline(file,line)) {
            token = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter)+1);
            if (token.compare("ADD")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("SUB")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }  
            else if (token.compare("MULT")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("DIV")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("JMP")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("JMPN")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }   
            else if (token.compare("JMPP")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            } 
            else if (token.compare("JMPZ")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("COPY")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);    // 2 args
            }
            else if (token.compare("LOAD")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("STORE")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("INPUT")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("OUTPUT")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);
            }
            else if (token.compare("STOP")){
                token = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter)+1);    //0 args
            } else {
                //throw error (unknown instruction/directive)
            }
        }
        
        file.close();
    } else {
        std::cout << "file couldn't be opened\n";
    }
    return 0;
}