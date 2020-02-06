#include <seqan3/alphabet/nucleotide/dna4.hpp>
#include <seqan3/range/views/complement.hpp>

int main()
{
    using seqan3::operator""_dna4;

    seqan3::dna4_vector vec{"ACGGTC"_dna4};

    // these are synonymous:
    auto vec_view1 = vec | seqan3::views::complement;
    auto vec_view2 = seqan3::views::complement(vec);

    // both views "behave" like a collection of the elements 'T', 'G', 'C', 'C', 'A', 'G'
    // but can be copied cheaply et cetera
}
