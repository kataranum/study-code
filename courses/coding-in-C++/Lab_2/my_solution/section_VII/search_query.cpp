#include "search_query.hpp"
#include <cstdint>

SearchQuery::SearchQuery(const std::string& input, uint64_t max_results)
: input(std::string(input)), max_results(max_results) { }

SearchQuery::SearchQuery(const std::string& input)
: SearchQuery(input, UINT64_MAX) { }

bool SearchQuery::is_valid() const {
    if (this->input.empty()) {
        return false;
    }

    return true;
}
