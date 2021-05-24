#include <iostream>
#include <fstream>
#include <string>
#include "elf.h"

int main()
{
    int num_of_sec = 4;
    int num_of_sym = 6;
    std::string filename_in = "libsecret.so";
    std::string filename_out = "libsecretnew.so";
    std::ifstream str_in(filename_in, std::ios::binary);
    Elf64_Ehdr e_header;
    Elf64_Shdr s_header;
    Elf64_Sym sym;

    str_in.read(reinterpret_cast<char*>(&e_header), sizeof(e_header));
    str_in.seekg(e_header.e_shoff + sizeof(Elf64_Shdr) * num_of_sec);
    str_in.read(reinterpret_cast<char*>(&s_header), sizeof(s_header));
    str_in.seekg(s_header.sh_addr + sizeof(Elf64_Sym) * num_of_sym);
    str_in.read(reinterpret_cast<char*>(&sym), sizeof(sym));
    str_in.close();

    sym.st_other = 0;
    std::ofstream str_out(filename_out, std::ios::binary | std::ios::in | std::ios::out);
    str_out.seekp(s_header.sh_addr + sizeof(Elf64_Sym) * num_of_sym);
    str_out.write(reinterpret_cast<char*>(&sym), sizeof(sym));
    str_out.close();
    return 0;
}
