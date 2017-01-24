#ifndef _BIB_FIELDS_H_
#define _BIB_FIELDS_H_

#include "BibString.h"

namespace CBibTeX
{
    namespace Field
    {
        class _BaseField
        {
        public:
            _BaseField();
            _BaseField(const BibString& str_content);
        };

        class Author :_BaseField
        {
        //public:
        //    Author();
        //    Author(const CBibTeX::BibString& str_author);
        };

        class Date
        {};

        class Title
        {};
    }

    struct BibFieldSet
    {
        Field::Author  author;
        Field::Date    date;
        Field::Title   title;
    };
}

#endif