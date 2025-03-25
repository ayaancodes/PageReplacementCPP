#include "q1_generator.h"
#include <fstream>
#include <random>
#include <iostream>
#include <string>


std::vector<int> generate_page_references(int count, int page_range) {
    std::vector<int> references;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, page_range);

    for (int i = 0; i < count; ++i) {
        references.push_back(distrib(gen));
    }

    return references;
}

void save_references_to_file(const std::vector<int>& refs, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (int ref : refs) {
        outFile << ref << " ";
    }

    outFile.close();
}
