#include "search_engine.hpp"
#include "search_query.hpp"
#include "web_resource.hpp"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>

SearchEngine::SearchEngine() :
    database(std::vector<WebResource>()),
    total_queries(0)
{ }

bool SearchEngine::upload_web_resource(const WebResource& resource) {
    for (int i = 0; i < this->database.size(); i++) {
        const WebResource& existing_resource = this->database[i];

        if (existing_resource.get_address() == resource.get_address()) {
            return false;
        }
    }

    this->database.push_back(resource);
    return true;
}

size_t SearchEngine::get_amount_resources() const {
    return this->database.size();
}

uint64_t SearchEngine::get_total_queries() const {
    return this->total_queries;
}

const WebResource& SearchEngine::fetch_result(const SearchResult& result) {
    WebResource& resource = this->database[result.web_index];
    resource.increment_views();
    return resource;
}

std::string str_to_lower(std::string str) {
    // shamelessly copied from here :P
    // https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c){ return std::tolower(c); });
    
    return str;
}

std::vector<std::string> split_string(std::string input, char split) {
    std::vector<std::string> result = std::vector<std::string>();

    size_t index = input.find(split);

    while (index != -1) {
        std::string token = input.substr(0, index);
        result.push_back(token);
        
        input = input.substr(index);
        index = input.find(split);
    }

    return result;
}

uint32_t find_occurances(std::string content, const std::string& substr) {
    uint32_t occurances = 0;

    size_t index = content.find(substr);

    while (index != -1) {
        occurances++;
        
        content = content.substr(index);
        index = content.find(substr);
    }

    return occurances;
}

std::vector<SearchResult> SearchEngine::process_query(const SearchQuery& query) {
    if (!query.is_valid()) {
        std::cout << "Invalid query" << std::endl;
        return std::vector<SearchResult>();
    }

    std::string input_lower = str_to_lower(query.input);
    std::vector<std::string> tokens = split_string(query.input, ' ');
    std::vector<SearchResult> results = std::vector<SearchResult>();

    this->total_queries++;

    for (uint32_t i = 0; i < this->database.size(); i++) {
        WebResource& resource = this->database[i];

        SearchResult result = SearchResult {
            i, 0
        };

        for (int j = 0; j < tokens.size(); j++) {
            const std::string& token = tokens[j];
            int32_t token_occurances = find_occurances(
                str_to_lower(resource.get_content()),
                token
            );

            result.occurances += token_occurances;
        }

        if (result.occurances == 0) {
            continue;
        }

        results.push_back(result);

        if (results.size() >= query.max_results) {
            break;
        }
    }

    return results;
}
