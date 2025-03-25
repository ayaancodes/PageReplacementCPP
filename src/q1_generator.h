#ifndef Q1_GENERATOR_H
#define Q1_GENERATOR_H

#include <vector>
#include <string>


std::vector<int> generate_page_references(int count, int page_range);
void save_references_to_file(const std::vector<int>& refs, const std::string& filename);

#endif
