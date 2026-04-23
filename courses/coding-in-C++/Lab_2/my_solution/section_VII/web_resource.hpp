#ifndef WEB_RESOURCE_H
#define WEB_RESOURCE_H

#include <cstdint>
#include <string>

/**
 * @brief Representation of a web resource
 * 
 * Comes with unique identifier (address), arbitrary content, and view counter.
 *
 */
class WebResource {
public:
    /// Minimum amount of views to be considered "popular"
    const static uint64_t POPULAR_MIN_VIEWS = 1000000;

private:
    /// Unique address to identify this WebResource
    std::string address;
    /// Content of this resource
    std::string content;
    /// How many times this resource has been loaded by someone
    uint64_t views;

public:
    /**
     * @brief Construct a new WebResource given address and content. Views are set to 0
     * 
     * @param address Unique address
     * @param content Content of this resource
     */
    WebResource(const std::string& address, const std::string& content);

    /**
     * @brief Get an immutable reference to the address string
     * 
     * @return const std::string&
     */
    const std::string& get_address() const;

    /**
     * @brief Get an immutable reference to the content string
     * 
     * @return const std::string& 
     */
    const std::string& get_content() const;

    /**
     * @brief Get how many views this resource has
     * 
     * @return uint64_t 
     */
    uint64_t get_views() const;

    /**
     * @brief Increment the views counter by 1
     * 
     * @return WebResource& 
     */
    WebResource& increment_views();

    /**
     * @brief Whether this resource is considered 'popular'
     * 
     * @return true View count is at least WebResource::POPULAR_MIN_VIEWS
     * @return false View count is less than WebResource::POPULAR_MIN_VIEWS
     */
    bool is_popular() const;
};

#endif
