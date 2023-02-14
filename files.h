#ifndef files_h
#define files_h

#include <string>
#include <vector>
#include <array>

namespace files {
    extern const std::string pokemonRandomLarge;
    extern const std::string pokemonRandomMedium;
    extern const std::string pokemonRandomSmall;
    extern const std::string pokemonReverseSortedLarge;
    extern const std::string pokemonReverseSortedMedium;
    extern const std::string pokemonReverseSortedSmall;
    extern const std::string pokemonSortedLarge;
    extern const std::string pokemonSortedMedium;
    extern const std::string pokemonSortedSmall;

    std::array<std::string, 9> getFilesArray();

    std::vector<float> readCSV(std::string directory);
}

#endif
