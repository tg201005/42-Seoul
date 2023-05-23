#include <iostream>
#include <fstream>
#include <string>

void    replaceInFile(std::string filename, std::string s1, std::string s2) 
{
    // Open the input file
    std::ifstream inputFile;
    
    inputFile.open(filename);
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    // Create the output file
    std::string outputFilename = filename + ".replace";
    
    std::ofstream outputFile;
    outputFile.open(outputFilename);
    if (!outputFile) {
        std::cerr << "Failed to create output file." << std::endl;
        return;
    }

    // Process the file content line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Replace s1 with s2 in the line
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }

        // Write the modified line to the output file
        outputFile << line;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
}

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Insufficient arguments. Usage: program_name <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    if (s1.empty()) {
        std::cerr << "s1 cannot be empty." << std::endl;
        return 1;
    }
    std::string s2 = argv[3];
    if (s2.empty()) {
        std::cerr << "s2 cannot be empty." << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);
    return 0;
}
