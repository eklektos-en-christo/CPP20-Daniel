//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_STREAMINSERTABLE_H
#define PRACTICE_STREAMINSERTABLE_H

#include <iostream>

// an interface for printing
class StreamInsertable
{
    friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);

public:
    virtual void stream_insert(std::ostream& out) const = 0;
};

#endif //PRACTICE_STREAMINSERTABLE_H
