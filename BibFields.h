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

            // DEBUG
            std::string xxx;
            // DEBUG
        };

        class Author : public _BaseField
        {
        public:
            using _BaseField::_BaseField;
        };

        class Date : public _BaseField
        {
        public:
            using _BaseField::_BaseField;
        };

        class Title : public _BaseField
        {
        public:
            using _BaseField::_BaseField;
        };
    }

    struct BibFieldSet
    {
        Field::Author  author;
        Field::Date    date;
        Field::Title   title;
    };
}

#endif