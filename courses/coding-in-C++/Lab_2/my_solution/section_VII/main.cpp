#include <iostream>
#include <vector>
#include "search_engine.hpp"
#include "search_query.hpp"
#include "web_resource.hpp"

SearchEngine init_search_engine() {
    SearchEngine engine = SearchEngine();

    engine.upload_web_resource(WebResource(
        "ilovecake.com",
        "I like cake. I really like cake. I absolutely love cake. I \
        cannot imagine a live without cake. I eat cake 4 times per day, as \
        breakfast, as lunch, as dinner, and as a nighttime snack. My whole \
        house is full of cake. If I ever stopped eating cake, I'd die."
    ));
    engine.upload_web_resource(WebResource(
        "cpp-tutorial.com",
        "Hello, today in this guide I will introduce you to C++. Now, \
        you see that many people put C and C++ in the same boat by referring \
        to it as \"C/C++\", but that is actually misleading in my opinion."
    ));
    engine.upload_web_resource(WebResource(
        "RUST_IS_BETTER_THAN_CPP.rus",
        "RUST IS BETTER THAN C++!!!!!! C++ IS A MESS!!1! I HATE \
        PRETENDING TO BE MEMORY SAFE WHEN I'M ACTUALLY NOT!!!!!!!! RUST IS THE \
        ONLY MEMORY SAFE LANGUAGE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
    ));
    engine.upload_web_resource(WebResource(
        "RUST_IS_BETTER_THAN_CPP.rus/apology",
        "i must apologize for my outlash in my last blog post, where I \
        slammed on C++ for being a \"bad\" language. i accept that it has it's \
        uses and is still widespread today. rust is a viable alternative but \
        may not always be the better choice."
    ));

    return engine;
}

void print_results_info(const std::vector<SearchResult>& results, SearchEngine& engine) {
    for (size_t i = 0; i < results.size(); i++) {
        const SearchResult& result = results[i];
        const WebResource& resource = engine.fetch_result(result);

        std::cout << "Result " << i+1 << ":" << std::endl;
        std::cout << "\"" << resource.get_address() << "\"" << std::endl;
        std::cout << result.occurances << " occurances found" << std::endl;
        std::cout << "New view count is " << resource.get_views() << "\n" << std::endl;
    }
}

int main(void) {
    SearchEngine engine = init_search_engine();

    std::cout << "Search 1: Cake" << std::endl;
    SearchQuery query_1 = SearchQuery("Cake");
    std::cout << "Search 2: Rust" << std::endl;
    SearchQuery query_2 = SearchQuery("Rust");
    std::cout << "Search 3: C++" << std::endl;
    SearchQuery query_3 = SearchQuery("C++", 2);
    std::cout << std::endl;

    std::vector<SearchResult> result_1 = engine.process_query(query_1);
    std::vector<SearchResult> result_2 = engine.process_query(query_2);
    std::vector<SearchResult> result_3 = engine.process_query(query_3);

    std::cout << "Search 1 has " << result_1.size() << " results." << std::endl;
    std::cout << "Search 2 has " << result_2.size() << " results." << std::endl;
    std::cout << "Search 3 has " << result_3.size() << " results." << std::endl;
    std::cout << std::endl;

    print_results_info(result_1, engine);
    print_results_info(result_2, engine);
    print_results_info(result_3, engine);

    return 0;
}
