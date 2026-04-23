#ifndef WEB_RESOURCE_H
#define WEB_RESOURCE_H

#include <cstdint>
#include <string>

class WebResource {
private:
    std::string address;
    std::string content;
    uint64_t views;

public:
    const std::string& get_address();
    const std::string& get_content();
    uint64_t get_views();

    WebResource& increment_views();

    bool is_popular();
};

#endif
