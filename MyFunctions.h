#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

#include <string>

// TODO: 20170124  inline: in case of an error of linking.
inline std::string::size_type findCharacter(const std::string& s, const char& ch,
    const std::string::size_type& beginPos = 0)
{
    if (beginPos != s.npos)
    {
        auto pos_Character = beginPos;

        if (beginPos == 0 && s[beginPos] == ch)
            return 0;

        else
        {
            do
            {
                pos_Character = s.find(ch, pos_Character + 1);
            } while (pos_Character != s.npos && s[pos_Character - 1] == '\\');

            return pos_Character;
        }
    }
    else
        return beginPos;
}

#endif