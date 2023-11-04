#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>

class BigReal {
private:
    std::string number;
    std::string intpart;
    std::string fractionpart;
    std::string sign;

    bool isValidReal(const std::string& realNumber);

public:
    BigReal(const BigReal& other);
    BigReal(const std::string& realNumber);

    bool findMaxValue(const std::string& str1, const std::string& str2) const;

    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;
    bool operator<(const BigReal& other) const;
    bool operator>(const BigReal& other) const;
    bool operator==(const BigReal& other) const;

    BigReal& operator=(BigReal& other);

    friend std::ostream& operator<<(std::ostream& out, const BigReal& num);
};

#endif // BIGREAL_H
