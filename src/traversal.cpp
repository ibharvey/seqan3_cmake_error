#include "traversal.hpp"

something::something()
{
    segment *b = new segment();
    using seqan3::operator""_dna5;
    seqan3::dna5_vector vec{"ANACGTTCAGCGATGCGACGATCGATCGTCGGTC"_dna5};
    // these are synonymous:
    auto vec_view1 = vec | seqan3::views::complement | std::views::reverse;
    seqan3::debug_stream << "Reverse complement of " << vec << " is " << vec_view1 << '\n';


}