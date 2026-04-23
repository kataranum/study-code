#include <iostream>
#include "search_engine.hpp"
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

int main(void) {
    return 0;
}
