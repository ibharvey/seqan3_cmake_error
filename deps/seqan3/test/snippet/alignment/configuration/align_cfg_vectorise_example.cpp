#include <seqan3/alignment/configuration/align_config_vectorise.hpp>

int main()
{
    // Enable SIMD vectorised alignment computation.
    auto cfg = seqan3::align_cfg::vectorise;
}
