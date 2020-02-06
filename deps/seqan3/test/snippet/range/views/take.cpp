#include <string>

#include <seqan3/core/debug_stream.hpp>
#include <seqan3/range/views/take.hpp>
#include <seqan3/std/ranges>

int main()
{
    std::string vec{"foobar"};
    auto v = vec | seqan3::views::take(3);
    seqan3::debug_stream << v << '\n'; // [f,o,o]

    auto v2 = vec | std::views::reverse | seqan3::views::take(3);
    seqan3::debug_stream << v2 << '\n'; // [r,a,b]
}
