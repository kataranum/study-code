#include "search_engine.hpp"
#include "web_resource.hpp"

SearchEngine::SearchEngine() :
    database(std::vector<WebResource>()),
    total_queries(0)
{ }

size_t SearchEngine::get_amount_resources() const {
    return this->database.size();
}

uint64_t SearchEngine::get_total_queries() const {
    return this->total_queries;
}

const WebResource& SearchEngine::fetch_result(const SearchResult& result) const {
    return this->database[result.web_index];
}
