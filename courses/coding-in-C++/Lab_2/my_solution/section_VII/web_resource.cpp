#include "web_resource.hpp"

WebResource::WebResource(const std::string& address, const std::string& content) :
    address(std::string(address)),
    content(std::string(content)),
    views(0)
{ }
