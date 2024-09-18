//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

/*
 * final - keyword, restricts how you override functions in derived classes, restricts how
 * you can derive from a base class
 *
 * we can restrict the derived class to override our virtual functions - mark the function as final
 * we can restrict the derived classes from inheriting from the base class - mark the class as final
 *
 * if the function in a class is virtual, marking it final will cause the compiler error when
 * any derived class will try to inherit it
*/

// class is final - it can't be inherited
class Plane final
{
    Plane() = default;
};

// inheriting a final class
//class Helicopter : public Plane
//{
//
//};

int main()
{
    return 0;
}