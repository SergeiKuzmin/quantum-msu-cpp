#include "state.h"


void print(const State &s)
{
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << " " << it->first << " = " << it->second << std::endl;
    }
}

namespace std{
    ostream& operator<<(ostream &stream, const std::vector<int>& vec)
    {
        if (!vec.empty())
        {
            stream << "{";
            for(auto it = vec.begin(); it != vec.end(); ++it)
            {
                stream << *it << ", ";
            }
            stream << "\b\b}";
        }
        return stream;
    }

    ostream& operator<<(ostream &stream, const std::complex<double> &value)
    {
        stream << value.real() << " + " << value.imag() << "i";
        return stream;
    }
}
