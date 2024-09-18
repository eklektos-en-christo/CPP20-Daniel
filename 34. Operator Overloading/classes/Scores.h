//
// Created by Εκλεκτός εν Χριστώ on 4/28/24.
//

#ifndef PRACTICE_SCORES_H
#define PRACTICE_SCORES_H

#include <iostream>
#include <string>

class Scores
{
public:
    Scores() = delete;
    explicit Scores(const std::string& course_name_param)
        : course_name{ course_name_param }
    {
    }

    // non const double& for reading and writing and const double& for working with const objects
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;

    void print_info() const;

private:
    std::string course_name{};
    double m_scores[20]{};
};

#endif //PRACTICE_SCORES_H
