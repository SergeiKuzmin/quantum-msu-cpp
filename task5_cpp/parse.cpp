#include <iostream>
#include <fstream>
#include <string>
#include "elf.h"

#define NUM_SEC 4
#define NUM_SYM 6

int main()
{
    std::string filename_in = "libsecret.so";
    std::string filename_out = "libsecretnew.so";
    std::ifstream str_in(filename_in, std::ios::binary);
    Elf64_Ehdr e_header;
    Elf64_Shdr s_header;
    Elf64_Sym sym;

    str_in.read(reinterpret_cast<char*>(&e_header), sizeof(e_header));
    str_in.seekg(e_header.e_shoff + sizeof(Elf64_Shdr) * NUM_SEC);
    str_in.read(reinterpret_cast<char*>(&s_header), sizeof(s_header));
    str_in.seekg(s_header.sh_addr + sizeof(Elf64_Sym) * NUM_SYM);
    str_in.read(reinterpret_cast<char*>(&sym), sizeof(sym));
    if (!str_in.is_open()) std::cout << "Failed" << std::endl;
    str_in.close();

    std::cout << "st_other = " << sym.st_other << std::endl;
    sym.st_other = 0;
    std::ofstream str_out(filename_out, std::ios::binary | std::ios::in | std::ios::out);
    if (!str_out.is_open()) std::cout << "Failed" << std::endl;
    str_out.seekp(s_header.sh_addr + sizeof(Elf64_Sym) * NUM_SYM);
    str_out.write(reinterpret_cast<char*>(&sym), sizeof(sym));
    str_out.close();
    return 0;
}
