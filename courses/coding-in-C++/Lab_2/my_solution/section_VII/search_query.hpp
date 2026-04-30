#ifndef SEARCH_QUERY_H
#define SEARCH_QUERY_H

#include <cstdint>
#include <string>

/**
 * @brief Collected info for making a query in SearchEngine
 */
class SearchQuery {
public:
    /// Query input, tokens seperated by whitespace. The engine will search for
    /// each token seperatly.
    std::string input;

    /// Maximum amount of wanted results
    uint64_t max_results;

public:
    /**
     * @brief Construct a new Search Query object
     * 
     * @param input 
     * @param max_results 
     */
    SearchQuery(const std::string& input, uint64_t max_results);
    /**
     * @brief Construct a SearchQuery with max_results being UINT64_MAX
     * 
     * @param input 
     */
    SearchQuery(const std::string& input);

    /**
     * @brief Check whether the query is valid
     *
     * A query is valid if its input isn't empty.
     * 
     * @return true Query is valid and will return valid results in SearchEngine
     * @return false Query is invalid and won't return anything in SearchEngine
     */
    bool is_valid() const;
};

#endif
