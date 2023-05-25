/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:41:33 by tyi               #+#    #+#             */
/*   Updated: 2023/05/25 16:51:14 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int checkArgs(int ac, std::string filename, std::string s1, std::string s2)
{
    if (argc != 4) {
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
}

int main(int ac, char* av[]) 
{
    checkArgs(ac, filename, s1, s2);
    replaceInFile(filename, s1, s2);
    return 0;
}
