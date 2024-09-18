//
// Created by Εκλεκτός εν Χριστώ on 6/19/24.
//

#include "StreamInsertable.h"

std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand)
{
    operand.stream_insert(out);
    return out;
}