#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <cstdint>
#include <vector>

#include "web_resource.hpp"
#include "search_query.hpp"

/**
 * @brief A single search result returned by SearchEngine::process_query
 *
 * A WebResource can be loaded from this result
 */
struct SearchResult {
    size_t web_index;
    uint32_t occurances;
};

/**
 * @brief A whole search engine that stores multiple WebResources and searches
 * for its contents to return SearchResults.
 *
 * Also tracks some basic Metadata like how many queries have been processed.
 */
class SearchEngine {
private:
    /// Collection of all WebResources that this SearchEngine manages
    std::vector<WebResource> database;
    /// Total amount of processed queries.
    uint64_t total_queries;

public:
    /**
     * @brief Create a new empty SearchEngine
     */
    SearchEngine();

    /**
     * @brief Try to upload the given resource into the database
     * 
     * @param resource Given, fully initialized WebResource
     * @return true Upload successful, database updated
     * @return false Upload failure (duplicate address), database remains untouched
     */
    bool upload_web_resource(const WebResource& resource);

    /**
     * @brief Get how many resources are available in total
     * 
     * @return size_t 
     */
    size_t get_amount_resources() const;
    /**
     * @brief Get how many queries have been processed up until now
     * 
     * @return uint64_t 
     */
    uint64_t get_total_queries() const;

    /**
     * @brief Load a specific SearchResult (get a const reference to it)
     * 
     * @param result SearchResult to load
     * @return const WebResource& WebResource that the SearchResult points to
     */
    const WebResource& fetch_result(const SearchResult& result);

    /**
     * @brief Process the given query
     *
     * This function takes the input of the query and splits it into "tokens"
     * seperating whitespaces. It then searches every saved WebResource and
     * counts how many occurances of this token exist in there. If there's more
     * than zero it will be part of the returned vector.
     *
     * The returned SearchResult vector contains all WebResources with at least
     * one occurance of any given token, and how many occurances there were for
     * each result.
     * 
     * @param query Given query 
     * @return std::vector<SearchResult> All search results
     */
    std::vector<SearchResult> process_query(const SearchQuery& query);
};

#endif
