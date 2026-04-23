#include "web_resource.hpp"

WebResource::WebResource(const std::string& address, const std::string& content) :
    address(std::string(address)),
    content(std::string(content)),
    views(0)
{ }

const std::string& WebResource::get_address() const {
    return this->address;
}

const std::string& WebResource::get_content() const {
    return this->content;
}

uint64_t WebResource::get_views() const {
    return this->views;
}
