#include "state.h"

State add(const State &s1, const State &s2)
{
    State s3;
    auto it2_global = s2.begin();
    for(auto it1 = s1.begin(); it1 != s1.end(); ++it1)
    {
        if (it1->first > it2_global->first)
        {
            for(auto it2 = it2_global; ((it2->first <= it1->first) && (it2 != s2.end())); it2++)
            {
                if (it1->first == it2->first)
                {
                    s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2->second));
                } else {
                    s3.insert(std::pair<Fock, Amp>(it2->first, it2->second));
                }
                it2_global = it2;
            }
        } else {
            if (it1->first < it2_global->first)
            {
                s3.insert(std::pair<Fock, Amp>(it1->first, it1->second));
                it2_global++;
            } else {
            s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2_global->second));
            it2_global++;
            }
        }
    }
    return s3;
}

void print(const State &s)
{
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << it->first << " = " << it->second << std::endl;
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
