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

std::unordered_map<std::string, std::vector<int>> nmt_table; 
std::unordered_map<std::string, std::vector<int>> ndt_table;

std::unordered_map<std::string, std::vector<int>> symbol_table; // lista de referencias a ocorrências de simbolos
std::unordered_map<std::string, int> initialized_table; // se um token aparece aqui, então ele foi inicializado, guarda a referencia em "tamanho" onde a variavel é inicializada

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

/// initializes map with word:code pair
void init_map(){
    int count = 1;
    for (auto str : known_instructions){
        token_dict.insert(std::make_pair(str, count++));
    }
    std::string testkey = "SUB";
    std::cout << testkey << " = " << token_dict.at(testkey) << "\n";
    return;
}


/// Extracts next word from current line. TODO: expected number of arguments? (this could be useful to throw errors)
std::string get_token(std::string str, std::string delim = " "){
    std::size_t pos = str.find(delim);
    std::string token = str.substr(0, pos);
    str.erase(0, pos + delim.size());
    return token;
}

int main ( int argc, char *argv[] ) {
    init_map();
    std::string filename = "./asm/bin.asm";
    //for (int i  = 0; i < argc; i++) std::cout << "arg[" << i << "] = " << argv[i] << "\n";
    if (argc == 3){
        if (std::string("-file").compare(argv[1]) == 0){
            filename = argv[2];
            std::cout << "yay!\n";
        }
        else {
            std::cout << "unknown flags passed use '-flag \"filename\"' to specify filename" << "\n";
        }
    }
    std::cout << filename << "\n";
    std::ifstream file(filename);
    if (file.is_open()){
        std::cout << "file is open\n";
        std::string line = std::string();
        

        while (std::getline(file,line)) {
            std::cout << "line read = " << line << "\n";
            read_tokens(line);
        }
        
        file.close();
    } else {
        std::cout << "file couldn't be opened\n";
    }
    return 0;
}

void read_tokens(std::string line){
    std::string token = get_token(line);
            std::cout << "token identified = " << token << "\n";
            // 
            if (token.compare("ADD")){
                token = get_token(line);
            } else if (token.compare("SUB")){
                token = get_token(line);
            }   else if (token.compare("MULT")){
                token = get_token(line);
            } else if (token.compare("DIV")){
                token = get_token(line);
            } else if (token.compare("JMP")){
                token = get_token(line);
            } else if (token.compare("JMPN")){
                token = get_token(line);
            } else if (token.compare("JMPP")){
                token = get_token(line);
            } else if (token.compare("JMPZ")){
                token = get_token(line);
            } else if (token.compare("COPY")){
                token = get_token(line);    // 2 args
            } else if (token.compare("LOAD")){
                token = get_token(line);
            } else if (token.compare("STORE")){
                token = get_token(line);
            } else if (token.compare("INPUT")){
                token = get_token(line);
            } else if (token.compare("OUTPUT")){
                token = get_token(line);
            } else if (token.compare("STOP")){
                token = get_token(line);    //0 args

            //DIRETIVAS
            } else if(token.compare("SECTION")){
                
            } else if(token.compare("SPACE")){
                
            } else if(token.compare("CONST")){
                
            } else if(token.compare("EQU")){
                
            } else if(token.compare("IF")){
                
            } else if(token.compare("MACRO")){
                
            } else if(token.compare("ENDMACRO")){
               
            } else if(token[0] == ';'){
                
            } else {
                //throw error (unknown instruction/directive)
            }
}
