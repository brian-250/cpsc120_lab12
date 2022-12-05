// Brian Milian
// CPSC 120-12
// 2022-12-01
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 12-02
// Partners: @engenies
//
// There are four functions for 'make_message.cc'. 'HasMatchingFileExtension()'
// is to check if the file created in the running of the program has the
// required file extension to run the program. 'RandomDouble01()',
// 'RandomDouble11()', and 'CoinFlip()' generate random numbers.
//

#include "make_message_functions.h"

#include <iomanip>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  return ((file_name.size() >= extension.size()) &&
          (file_name.compare(file_name.size() - extension.size(),
                             extension.size(), extension) == 0));
  return false;
}

// Secret global variable to make the randome number generator
// predictable
std::seed_seq rng_seed{1, 2, 3, 4, 5};

// Secret global variable that is used by RandomDouble_01()
RandomNumberGenerator rng_01{0, 1, rng_seed};

// Secret global variable that is used by RandomDouble_11()
RandomNumberGenerator rng_11{-1, 1, rng_seed};

// Secret global variable that is used by CoinFlip()
RandomNumberGenerator rng_coin_flip{-1, 1, rng_seed};

// Returns a random double between o and 1
double RandomDouble01() {
  // RandomNumberGenerator rng = RandomNumberGenerator(1.0, 10.0);
  // int random_number = int(rng.next());
  double random_number01 = rng_01.next();
  return random_number01;
}

// Returns a random double between -1 and 1
double RandomDouble11() {
  double random_number11 = rng_11.next();
  return random_number11;
}

/// Return a True or False depending on a random value.
/// Generates a random number and then decides to return True or False
bool CoinFlip() {
  // number is greater than 0.0 and false otherwise.
  double rng_coin = rng_coin_flip.next();
  return (rng_coin > 0.0);
}