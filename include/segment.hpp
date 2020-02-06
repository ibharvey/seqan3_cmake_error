#pragma once


#include <vector>
#include <string>

#include <utility>
#include <seqan3/alignment/pairwise/align_pairwise.hpp>
#include <seqan3/alignment/scoring/nucleotide_scoring_scheme.hpp>
#include <seqan3/alphabet/nucleotide/dna4.hpp>
#include <seqan3/core/debug_stream.hpp>

using seqan3::operator""_dna4;

class segment {
    private:
        std::vector<segment> p3_edges;
        std::vector<segment> p5_edges;
        std::string name;
        std::string sequence;
    public:
        segment();
        segment(std::string name, std::string sequence);
        segment(std::vector<std::string> names, std::vector<std::string> sequences);
        std::string get_name() { return this->name; }
        
};
