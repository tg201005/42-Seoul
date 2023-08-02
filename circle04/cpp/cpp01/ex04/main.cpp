#include <iostream>
#include <fstream>
#include <string>

void    replaceInFile(std::string filename, std::string s1, std::string s2) 
{
    std::ifstream inputFile;
    
    inputFile.open(filename);
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    std::ofstream outputFile;
    
    outputFile.open(filename + ".replace");
    if (!outputFile) {
        std::cerr << "Failed to create output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        
        size_t pos = 0;
        
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            
            line.erase(pos, s1.length());
            line.insert(pos, s2);

            pos += s2.length();
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << filename + ".replace" << std::endl;
}


int checkArgs(int ac, std::string s1, std::string s2)
{
    if (ac != 4) {
        std::cerr << "Insufficient arguments. Usage: program_name <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    if (s1.empty()) {
        std::cerr << "s1 cannot be empty." << std::endl;
        return 1;
    }
    
    if (s2.empty()) {
        std::cerr << "s2 cannot be empty." << std::endl;
        return 1;
    }
    return 0;
}

int main(int ac, char* av[]) 
{
    if (checkArgs(ac, av[2], av[3]))
        return 1;
    replaceInFile(av[1], av[2], av[3]);
    return 0;
}
