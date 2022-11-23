#include "source_location.hpp"
#include <iostream>

void func(const gech::source_location val = gech::source_location::current()) {
    std::cout << val.file_name() << '\n' <<
                 val.function_name() << '\n' <<
                 val.line() << '\n' <<
                 val.column() << '\n';
}

int main() {
    func();
    return 0;
}