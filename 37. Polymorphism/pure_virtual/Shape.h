//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_SHAPE_H
#define PRACTICE_SHAPE_H

#include <string>
#include <string_view>

class Shape
{
protected:
    // constructors are not useful outside the class - abstract class
    // derived can use these to create the shape part of the object
    Shape() = default;
    Shape(std::string_view desc);

public:
    // dtor should be public to delete shape*
    virtual ~Shape() = default;

    // pure virtual functions, no definition, only declaration to 0
    virtual double perimeter() const = 0;
    virtual double surface() const = 0;

private:
    std::string m_description{};
};

#endif //PRACTICE_SHAPE_H
