#include "files.h"
#include <bits/stdc++.h>

namespace files {
    //list of files that are stored in the "./data" directory, to be sorted
    const std::string pokemonRandomLarge            = "data/pokemonRandomLarge.csv";
    const std::string pokemonRandomMedium           = "data/pokemonRandomMedium.csv";
    const std::string pokemonRandomSmall            = "data/pokemonRandomSmall.csv";
    const std::string pokemonReverseSortedLarge     = "data/pokemonReverseSortedLarge.csv";
    const std::string pokemonReverseSortedMedium    = "data/pokemonReverseSortedMedium.csv";
    const std::string pokemonReverseSortedSmall     = "data/pokemonReverseSortedSmall.csv";
    const std::string pokemonSortedLarge            = "data/pokemonSortedLarge.csv";
    const std::string pokemonSortedMedium           = "data/pokemonSortedMedium.csv";
    const std::string pokemonSortedSmall            = "data/pokemonSortedSmall.csv";

    //function to return all the file directory as a list of strings
    std::array<std::string, 9> getFilesArray(){
        std::array<std::string, 9> fileNames;
        fileNames[0] = pokemonRandomLarge;
        fileNames[1] = pokemonRandomMedium;
        fileNames[2] = pokemonRandomSmall;
        fileNames[3] = pokemonReverseSortedLarge;
        fileNames[4] = pokemonReverseSortedMedium;
        fileNames[5] = pokemonReverseSortedSmall;
        fileNames[6] = pokemonSortedLarge;
        fileNames[7] = pokemonSortedMedium;
        fileNames[8] = pokemonSortedSmall;

        return fileNames;
    }

    //function for parsing the .csv files.
    std::vector<float> readCSV(std::string directory){
        std::ifstream infile(directory.c_str());

        if(!infile) {
            std::cerr << "Error: Could not open file " << directory << std::endl;
            return std::vector<float>();
        }

        size_t lineNo = 0;
        std::string line;
        while(std::getline(infile, line)){
            std::cout << line << std::endl;
            
            if(lineNo > 0){
                
            }

            ++lineNo;
        }

        return std::vector<float>();
    }
}



