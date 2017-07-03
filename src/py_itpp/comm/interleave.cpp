#include "interleave.h"

BOOST_PYTHON_MODULE(interleave)
{
  // ----------------------------------------------------------------------
  // Instantiations
  // ----------------------------------------------------------------------

  generate_block_interleaver<double>("block_interleaver_double");
  generate_block_interleaver<short>("block_interleaver_short");
  generate_block_interleaver<int>("block_interleaver_int");
  generate_block_interleaver<std::complex<double>>("block_interleaver_complex");
  generate_block_interleaver<itpp::bin>("block_interleaver_bin");

  generate_cross_interleaver<double>("cross_interleaver_double");
  generate_cross_interleaver<short>("cross_interleaver_short");
  generate_cross_interleaver<int>("cross_interleaver_int");
  generate_cross_interleaver<std::complex<double>>("cross_interleaver_complex");
  generate_cross_interleaver<itpp::bin>("cross_interleaver_bin");

  generate_sequence_interleaver<double>("sequence_interleaver_double");
  generate_sequence_interleaver<short>("sequence_interleaver_short");
  generate_sequence_interleaver<int>("sequence_interleaver_int");
  generate_sequence_interleaver<std::complex<double>>("sequence_interleaver_complex");
  generate_sequence_interleaver<itpp::bin>("sequence_interleaver_bin");

}
