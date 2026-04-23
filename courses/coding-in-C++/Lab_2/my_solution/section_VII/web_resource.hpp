#ifndef WEB_RESOURCE_H
#define WEB_RESOURCE_H

#include <cstdint>
#include <string>

class WebResource {
public:
    const uint64_t POPULAR_MIN_VIEWS = 1000000;

private:
    std::string address;
    std::string content;
    uint64_t views;

public:
    WebResource(const std::string& address, const std::string& content);

    const std::string& get_address() const;
    const std::string& get_content() const;
    uint64_t get_views() const;

    WebResource& increment_views();

    bool is_popular() const;
};

#endif
