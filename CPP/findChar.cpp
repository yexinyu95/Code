#include <iostream>


/* find the first occurrence(index) of character c in given string s,
   and using reference to record the occurrence times in occ,
   but occ need to initialize first, 
*/
auto findChar(const std::string& s, char c, int& occ)
{
    auto ret = s.size();
    occ = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
            {ret = i;}
            ++occ;
        }
    }

    return ret;
}
