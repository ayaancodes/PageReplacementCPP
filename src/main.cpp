#include "q1_generator.h"

int main() {
    int total_refs = 1000;
    int page_range = 20;

    auto refs = generate_page_references(total_refs, page_range);
    save_references_to_file(refs, "data/references.txt");

    return 0;
}
