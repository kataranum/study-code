#include "search_engine.hpp"
#include "web_resource.hpp"

SearchEngine::SearchEngine() :
    database(std::vector<WebResource>()),
    total_queries(0)
{ }
