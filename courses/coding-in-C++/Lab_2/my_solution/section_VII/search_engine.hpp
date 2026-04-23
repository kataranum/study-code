#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <cstdint>
#include <vector>

#include "web_resource.hpp"
#include "search_query.hpp"

struct SearchResult {
    size_t web_index;
    uint32_t occurances;
};

class SearchEngine {
private:
    std::vector<WebResource> database;
    uint64_t total_queries;

public:
    size_t get_amount_resources();
    uint64_t get_total_queries();

    const WebResource& fetch_result(const SearchResult& result);

    std::vector<SearchResult> process_query(const SearchQuery& query);
};

#endif
