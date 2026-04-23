#ifndef SEARCH_QUERY_H
#define SEARCH_QUERY_H

#include <cstdint>
#include <string>

class SearchQuery {
public:
    std::string input;
    uint64_t max_results;

public:
    bool is_valid();
};

#endif
