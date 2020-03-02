/*


*/

#include <seqan3/io/sequence_file/input.hpp>
#include <seqan3/alignment/pairwise/align_pairwise.hpp>
#include <seqan3/alignment/scoring/nucleotide_scoring_scheme.hpp>
#include <seqan3/alignment/scoring/gap_scheme.hpp>
#include <seqan3/core/debug_stream.hpp>

#include <seqan3/range/views/complement.hpp>
#include <range/v3/view/repeat.hpp>
#include <range/v3/view/reverse.hpp>
#include <range/v3/to_container.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/for_each.hpp>
#include <range/v3/view/repeat_n.hpp>

int main(int argc, char ** argv)
{
    seqan3::sequence_file_input fin{argv[1]};
    auto config =   seqan3::align_cfg::mode{seqan3::global_alignment} | 
                    seqan3::align_cfg::aligned_ends{seqan3::free_ends_all} |
                    seqan3::align_cfg::scoring{seqan3::nucleotide_scoring_scheme
                        {
                            seqan3::match_score{4},
                            seqan3::mismatch_score{-2}
                        }
                    } |
                    seqan3::align_cfg::gap{seqan3::gap_scheme{seqan3::gap_score{-4}}} |
                    seqan3::align_cfg::result{seqan3::with_alignment};

    auto first_rec = *fin.begin();
    auto first_seq = seqan3::get<seqan3::field::seq>(first_rec);

    // Get all the other sequences in the file.
    auto back_recs = fin | seqan3::views::drop(1) | ranges::to<std::vector>();
    auto back_seqs = back_recs | std::views::transform([] (auto s) { return seqan3::get<seqan3::field::seq>(s) ;});
    // Duplicate each sequence
    auto back_seqs_2 = ranges::views::for_each(back_seqs, [] (auto c) {
        return ranges::yield_from(ranges::views::repeat_n(c,2));
    }) | ranges::to<std::vector>();
    // Couldn't figure out the range function, so got halfway and
    // went back to traditional iterators.
    for(auto it = std::begin(back_seqs_2); it < std::end(back_seqs_2); it++)
    {
        *(++it) = seqan3::views::complement(std::views::reverse(*it));
    }
    // And back to ranges!
    auto pair_seqs = back_seqs_2    | std::views::transform([first_seq](auto s){return std::pair{first_seq, s};})
                                    | ranges::to<std::vector>();

    auto results = seqan3::align_pairwise(pair_seqs, config);
    for (auto r = std::begin(results); r != std::end(results); r++)
    {
        auto temp = *r;
        seqan3::debug_stream << temp.score() << "\n";
    }
}