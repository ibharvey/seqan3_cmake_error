#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <segment.hpp>

#include <utility>
#include <seqan3/alignment/pairwise/align_pairwise.hpp>
#include <seqan3/alignment/scoring/nucleotide_scoring_scheme.hpp>
#include <seqan3/alphabet/nucleotide/dna5.hpp>
#include <seqan3/core/debug_stream.hpp>
//Reverse complement
#include <seqan3/range/views/complement.hpp>
#include <seqan3/std/ranges>


class something{
    public:
        something();
};