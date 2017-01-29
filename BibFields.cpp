#include "BibFields.h"

namespace CBibTeX
{
    namespace Field
    {
        _BaseField::_BaseField()
        {}

        _BaseField::_BaseField(const BibString & str_content)
        {
            // DEBUG
            xxx = str_content;
            // DEBUG
        }
    }
}
