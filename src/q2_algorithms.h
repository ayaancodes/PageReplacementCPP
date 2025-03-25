#ifndef Q2_ALGORITHMS_H
#define Q2_ALGORITHMS_H

#include <vector>

int fifo_page_faults(const std::vector<int>& references, int frame_size);
int lru_page_faults(const std::vector<int>& references, int frame_size);

#endif
