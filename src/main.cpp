#include "q1_generator.h"
#include "q2_algorithms.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> read_references_from_file(const std::string& filename) {
    std::vector<int> references;
    std::ifstream infile(filename);
    int page;

    while (infile >> page) {
        references.push_back(page);
    }

    return references;
}

int main() {
    std::cout << "Starting Page Replacement Simulation...\n";

    std::string input_file = "data/references.txt";
    std::string output_csv = "data/page_faults.csv";

    std::vector<int> references = read_references_from_file(input_file);
    std::cout << "Read " << references.size() << " references from file.\n";

    std::ofstream csv_file(output_csv);
    if (!csv_file.is_open()) {
        std::cerr << "Error: Could not open " << output_csv << " for writing.\n";
        return 1;
    }

    csv_file << "FrameSize,FIFO,LRU\n";
    std::cout << "FrameSize,FIFO,LRU\n";

    for (int frame_size = 1; frame_size <= 10; ++frame_size) {
        int fifo_faults = fifo_page_faults(references, frame_size);
        int lru_faults = lru_page_faults(references, frame_size);

        csv_file << frame_size << "," << fifo_faults << "," << lru_faults << "\n";
        std::cout << frame_size << "," << fifo_faults << "," << lru_faults << "\n";
    }

    csv_file.close();
    std::cout << "Page fault data written to: " << output_csv << "\n";

    return 0;
}
