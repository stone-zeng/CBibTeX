#ifndef _BIB_DATA_H_
#define _BIB_DATA_H_

#include <string>
#include <vector>

#include "BibString.h"
#include "BibEntry.h"

namespace CBibTeX
{
    // 获取并处理 Bib 数据库
    class BibData
    {
    private:
        typedef std::vector<BibEntry> BibList;
    public:
        BibData() = default;
        // 文件名，std::string 格式
        BibData(const std::string& fileName);

        // 原始 Bib 数据，BibString 格式
        BibString str_BibData;
        // Bib 条目列表，vector 格式
        BibList vec_bibEntryList;

        // 删除注释
        void deleteComment();
        // 获取 Bib 列表
        void getBibEntryList();
    };
}

#endif