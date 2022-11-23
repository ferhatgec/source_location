// simple implementation of std::source_location for C++17 projects,
// works on GCC, Clang and MSVC (2019 and later)
// 
// usage is same as std::source_location
//
// MIT License
//
// Copyright (c) 2022 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#pragma once

#include <cstdint>
#include <string_view>

namespace gech {
    class source_location {
        std::uint_least32_t _line, 
            _column;
        std::string_view _file_name,
            _function_name;
    public:
        constexpr 
        source_location(std::uint_least32_t line, 
                        std::uint_least32_t column,
                        std::string_view file_name,
                        std::string_view function_name) 
                        : _line(line),
                          _column(column),
                          _file_name(file_name),
                          _function_name(function_name) {};
        
        constexpr
        source_location(const source_location& location) : 
            _line(location.line()),
            _column(location.column()),
            _file_name(location.file_name()),
            _function_name(location.function_name()) {};
        

        static constexpr
        gech::source_location current(
            const std::uint_least32_t line = __builtin_LINE(),
            #ifdef __clang__
                const std::uint_least32_t column = __builtin_COLUMN(),
            #else
                const std::uint_least32_t column = 0,
            #endif
            const std::string_view file_name = std::string_view(__builtin_FILE()),
            const std::string_view function_name = std::string_view(__builtin_FUNCTION())) 
        noexcept {
            return gech::source_location(line, column, file_name, function_name);
        }

        constexpr
        std::string_view file_name() const noexcept {
            return this->_file_name;
        }

        constexpr
        std::string_view function_name() const noexcept {
            return this->_function_name;
        }

        constexpr 
        std::uint_least32_t line() const noexcept {
            return this->_line;
        }

        constexpr
        std::uint_least32_t column() const noexcept {
            return this->_column;
        }
    };
}