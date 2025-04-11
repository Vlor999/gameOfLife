#pragma once
#include <string>

class Case
{
    private:
        int value;
    public:
        Case(int value) : value(value) {}
        Case() : value(0) {}
        ~Case() = default;

        int getValue() const {
            return value;
        }
};
