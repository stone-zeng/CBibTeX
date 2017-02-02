#include <string>

#include "BibString.h"

using namespace std;

namespace CBibTeX
{
    //********** 构造函数 **********//
    BibString::BibString()
    {}

    BibString::BibString(const char* s)
    {
        _data = s;
    }

    BibString::BibString(const std::string& s)
    {
        _data = s;
    }

    BibString::BibString(const BibString& s, const SizeType& beginPos, const DifferenceType& len)
    {
        _data = string(s._data, beginPos, len);
    }

    //********** 析构函数 **********//
    BibString::~BibString()
    {}

    //********** 常量成员函数 **********//
    const char* BibString::cString() const
    {
        // 标准库封装
        return _data.c_str();
    }

    BibString::SizeType BibString::findCharacter(const char& ch, const SizeType& beginPos) const
    {
        if (beginPos != npos)
        {
            auto pos_Character = beginPos;

            if (beginPos == 0 && (*this)[beginPos] == ch)
                return 0;

            else
            {
                do
                {
                    pos_Character = _data.find(ch, pos_Character + 1);
                } while (pos_Character != npos && (*this)[pos_Character - 1] == '\\');

                return pos_Character;
            }
        }
        else
            return npos;
    }

    bool BibString::isEmpty() const
    {
        // 标准库封装
        return _data.empty();
    }

    const BibString::SizeType BibString::size() const
    {
        // 标准库封装
        return _data.size();
    }

    //********** 非常量成员函数 **********//
    void BibString::erase(const SizeType& beginPos, const DifferenceType& len)
    {
        // 标准库封装
        _data.erase(beginPos, len);
    }

    void BibString::deleteLeftRightSpace()
    {
        const std::string blankCharList(" \n\r\t");

        //std::string s_result(s);

        // 找到左侧非零字符 -> 移动位置，取子串
        auto pos = _data.find_first_not_of(blankCharList);
        if (pos != _data.npos)
            _data = _data.substr(pos);

        // 找到右侧非零字符 -> 直接取子串
        pos = _data.find_last_not_of(blankCharList);
        if (pos != _data.npos)
            _data = _data.substr(0, pos + 1);
    }

    void BibString::toUpperCase()
    {
        // 将 s_result 的每个字符改为大写
        for (auto& ch : _data)
            ch = (char)toupper(ch);
    }

    //********** 运算符 **********//
    BibString BibString::operator=(const BibString& s)
    {
        _data = s._data;
        return *this;
    }

    BibString BibString::operator+=(const char& ch)
    {
        _data += ch;
        return *this;
    }

    char BibString::operator[](const SizeType& idx) const
    {
        return _data[idx];
    }

    bool BibString::operator==(const BibString& s) const
    {
        if (_data == s._data)
            return true;
        else
            return false;
        //if (_data != s._data)
        //    return false;
    }
}
