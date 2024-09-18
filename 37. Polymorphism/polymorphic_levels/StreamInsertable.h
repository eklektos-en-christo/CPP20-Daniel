//
// Created by Εκλεκτός εν Χριστώ on 6/19/24.
//

#ifndef PRACTICE_STREAMINSERTABLE_H
#define PRACTICE_STREAMINSERTABLE_H

#include <iostream>

// Interface - no member varibles, only pure virtual function(s)
// derived classes need to override and implement the pure virtual functions to use this
// for polymorphic behavior
class StreamInsertable
{
    friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);

public:
    virtual void stream_insert(std::ostream& out) const = 0;
};

#endif //PRACTICE_STREAMINSERTABLE_H
