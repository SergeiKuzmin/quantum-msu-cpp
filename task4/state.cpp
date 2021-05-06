#include "state.h"

State add(const State &s1, const State &s2)
{
    State s3;
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while ((it1 != s1.end()--) && (it2 != s2.end()--))
    {
        if (it1->first == it2->first)
        {
            s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2->second));
            it1++;
            it2++;
        } else {
            if (it1->first > it2->first)
            {
                s3.insert(std::pair<Fock, Amp>(it2->first, it2->second));
                it2++;
            } else {
                s3.insert(std::pair<Fock, Amp>(it1->first, it1->second));
                it1++;
            }
        }
    }
    /*
    if ((it1 == s1.end()--) && (it2 != s2.end()--))
    {
        bool fl = true;
        while (it2 != s2.end())
        {
            if (it1->first == it2->first)
            {
                fl = false;
                s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2->second));
            } else {
                s3.insert(std::pair<Fock, Amp>(it2->first, it2->second));
            }
            it2++;
        }
        if (fl == true) s3.insert(std::pair<Fock, Amp>(it1->first, it1->second));
    } else {
        if ((it1 != s1.end()--) && (it2 == s2.end()--))
        {
            bool fl = true;
            while (it1 != s1.end())
            {
                if (it1->first == it2->first)
                {
                    fl = false;
                    s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2->second));
                } else {
                    s3.insert(std::pair<Fock, Amp>(it1->first, it1->second));
                }
                it1++;
            }
            if (fl == true) s3.insert(std::pair<Fock, Amp>(it2->first, it2->second));
        } else {
            if (it1->first == it2->first)
            {
                s3.insert(std::pair<Fock, Amp>(it1->first, it1->second + it2->second));
            } else {
                s3.insert(std::pair<Fock, Amp>(it1->first, it1->second));
                s3.insert(std::pair<Fock, Amp>(it2->first, it2->second));
            }
        }
    }
    */
    return s3;
}

void print(const State &s)
{
    for(auto it = s.begin(); it != s.end(); it++)
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
            for(auto it = vec.begin(); it != vec.end(); it++)
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
