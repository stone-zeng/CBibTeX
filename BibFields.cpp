#include "BibFields.h"

namespace CBibTeX
{
    namespace Field
    {
        //********** 一级域类型 **********//
        _BaseField::_BaseField(const BibString & str_content)
        {
            // DEBUG
            //xxx = str_content;
            // DEBUG
        }

        //********** 二级域类型 **********//
        // 姓名列表域
        BibString _NameList::output()
        {
            return BibString();
        }

        // 普通列表域
        BibString _List::output()
        {
            return BibString();
        }

        // 普通域
        _General::_General(const BibString & str_content)
        {
            _content = str_content;
        }

        BibString _General::output()
        {
            return BibString();
        }
    }
}
