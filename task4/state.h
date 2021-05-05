#ifndef STATE
#define STATE

#include <ostream>
#include <iostream>
#include <complex>
#include <vector>
#include <map>

using Fock = std::vector<int>;
using Amp = std::complex<double>;
using State = std::map<Fock, Amp>;

State add(const State &s1, const State &s2);
void print(const State &s);

namespace std{
    ostream& operator<<(ostream &stream, const std::vector<int> &vec);
    ostream& operator<<(ostream &stream, const std::complex<double> &value);
}

#endif
