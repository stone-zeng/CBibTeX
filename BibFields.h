#ifndef _BIB_FIELDS_H_
#define _BIB_FIELDS_H_

#include "BibString.h"

namespace CBibTeX
{
    namespace Field
    {
        //********** 一级域类型 **********//
        class _BaseField
        {
        public:
            _BaseField() = default;
            _BaseField(const BibString& str_content);

            virtual BibString output() = 0;

            // DEBUG
            //std::string xxx;
            // DEBUG
        };

        //********** 二级域类型 **********//
        // 姓名列表域
        class _NameList : public _BaseField
        {
        public:
            using _BaseField::_BaseField;

            BibString output();
        };

        // 普通列表域
        class _List : public _BaseField
        {
        public:
            using _BaseField::_BaseField;

            BibString output();
        };

        // 普通域
        class _General : public _BaseField
        {
        private:
            BibString _content;

        public:
            //using _BaseField::_BaseField;
            _General() = default;
            _General(const BibString& str_content);

            BibString output();
        };

        //********** 三级域类型 **********//
        class Address : public _General
        {
        public:
            using _General::_General;
        };

        class Author : public _NameList
        {
        public:
            using _NameList::_NameList;
        };

        class BookTitle : public _General
        {
        public:
            using _General::_General;
        };

        class Chapter : public _General
        {
        public:
            using _General::_General;
        };

        class CrossRef : public _General
        {
        public:
            using _General::_General;
        };

        class Edition : public _General
        {
        public:
            using _General::_General;
        };

        class Editor : public _NameList
        {
        public:
            using _NameList::_NameList;
        };

        class HowPublished : public _General
        {
        public:
            using _General::_General;
        };

        class Institution : public _General
        {
        public:
            using _General::_General;
        };

        class Month : public _General
        {
        public:
            using _General::_General;
        };

        class Note : public _General
        {
        public:
            using _General::_General;
        };

        class Number : public _General
        {
        public:
            using _General::_General;
        };

        class Organization : public _General
        {
        public:
            using _General::_General;
        };

        class Pages : public _General
        {
        public:
            using _General::_General;
        };

        class Publisher : public _General
        {
        public:
            using _General::_General;
        };

        class School : public _General
        {
        public:
            using _General::_General;
        };

        class Series : public _General
        {
        public:
            using _General::_General;
        };

        class Title : public _General
        {
        public:
            using _General::_General;
        };

        class Type : public _General
        {
        public:
            using _General::_General;
        };

        class Volume : public _General
        {
        public:
            using _General::_General;
        };

        class Year : public _General
        {
        public:
            using _General::_General;
        };
    }

    struct BibFields
    {
        Field::Address         address;
        Field::Author          author;
        Field::BookTitle       booktitle;
        Field::Chapter         chapter;
        Field::CrossRef        crossref;
        Field::Edition         edition;
        Field::Editor          editor;
        Field::HowPublished    howpublished;
        Field::Institution     institution;
        Field::Month           month;
        Field::Note            note;
        Field::Number          number;
        Field::Organization    organization;
        Field::Pages           pages;
        Field::Publisher       publisher;
        Field::School          school;
        Field::Series          series;
        Field::Title           title;
        Field::Type            type;
        Field::Volume          volume;
        Field::Year            year;

        BibFields() = default;
    };
}

#endif