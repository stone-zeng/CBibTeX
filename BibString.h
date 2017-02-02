#ifndef _BIB_STRING_H_
#define _BIB_STRING_H_

#include <string>

namespace CBibTeX
{
    // TODO: 20170124  use UNICODE.
    //typedef std::string BibString;

    class BibString
    {
    private:
        std::string _data;
    public:
        //********** 类内类型 **********//
        typedef std::string::size_type SizeType;
        typedef std::string::difference_type DifferenceType;

        //********** 构造函数 **********//
        BibString();
        BibString(const char*);
        BibString(const std::string&);
        BibString(const BibString&, const SizeType&, const DifferenceType&);

        //********** 析构函数 **********//
        // TODO: 20170202  目前为空
        ~BibString();

        //********** 成员字段 **********//
        const SizeType npos = (SizeType)(-1);

        //********** 常量成员函数 **********//
        const char* cString() const;
        SizeType findCharacter(const char& ch, const SizeType& beginPos = 0) const;
        bool isEmpty() const;

        // 不使用 length()
        const SizeType size() const;

        //********** 非常量成员函数 **********//
        void erase(const SizeType&, const DifferenceType&);
        void deleteLeftRightSpace();
        void toUpperCase();

        //********** 运算符 **********//
        BibString operator=(const BibString&);
        BibString operator+=(const char&);
        
        char operator[](const SizeType&) const;
        bool operator==(const BibString&) const;
    };
}

#endif