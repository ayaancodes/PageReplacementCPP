#include "q3_belady.h"
#include "q2_algorithms.h"
#include <vector>
#include <iostream>
#include <set>
#include <cstdlib>

// Classic Belady anomaly checker
void simulate_belady_anomaly() {
    std::vector<int> belady_sequence = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    int faults_3 = fifo_page_faults(belady_sequence, 3);
    int faults_4 = fifo_page_faults(belady_sequence, 4);
    int lru_3 = lru_page_faults(belady_sequence, 3);
    int lru_4 = lru_page_faults(belady_sequence, 4);

    std::cout << "\nBelady's Anomaly Simulation (Hardcoded Sequence):\n";
    std::cout << "Reference Sequence: ";
    for (int num : belady_sequence) std::cout << num << " ";
    std::cout << "\n\n";

    std::cout << "FIFO (3 frames): " << faults_3 << " faults\n";
    std::cout << "FIFO (4 frames): " << faults_4 << " faults\n";
    std::cout << "LRU  (3 frames): " << lru_3 << " faults\n";
    std::cout << "LRU  (4 frames): " << lru_4 << " faults\n";

    if (faults_4 > faults_3) {
        std::cout << "\nBelady's Anomaly observed! More faults with more frames (FIFO).\n";
    } else {
        std::cout << "\nNo anomaly observed.\n";
    }
}

// Bonus: Generate sequences and test for Belady's Anomaly
void generate_belady_sequence_and_test() {
    std::cout << "\nSearching for sequence that causes Belady’s Anomaly...\n";

    int frame_small = 3;
    int frame_large = 4;

    for (int seed = 0; seed < 10000; ++seed) {
        std::vector<int> sequence;
        srand(seed);

        // Generate 12-page reference sequence with values between 1 and 5
        for (int i = 0; i < 12; ++i) {
            sequence.push_back(1 + rand() % 5);
        }

        int fifo_small = fifo_page_faults(sequence, frame_small);
        int fifo_large = fifo_page_faults(sequence, frame_large);

        if (fifo_large > fifo_small) {
            std::cout << "\n🎯 Found Belady sequence at seed " << seed << ":\n";
            std::cout << "Sequence: ";
            for (int val : sequence) std::cout << val << " ";
            std::cout << "\nFIFO (" << frame_small << " frames): " << fifo_small << " faults\n";
            std::cout << "FIFO (" << frame_large << " frames): " << fifo_large << " faults\n";
            return;
        }
    }

    std::cout << "\nNo sequence found in tested seeds. Try increasing the range.\n";
}
