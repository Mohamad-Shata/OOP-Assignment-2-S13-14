#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>

using namespace std;

class BigReal {
private:
    string number;
    string intpart;
    string fractionpart;
    string sign;

    bool isValidReal(const string& realNumber);

    string addZerosToLeft(const string& number, int numZeros);

    string addWithCarry(const string& num1, const string& num2, int& carry) const;

    string subtractWithBorrow(const string& num1, const string& num2, int borrow) const;

    bool findMaxValue(const string& num1, const string& num2) const;

public:
    BigReal(const string& realNumber);

    BigReal operator+(const BigReal& other) const;

    bool operator<(const BigReal& other) const;

    bool operator>(const BigReal& other) const;

    bool operator==(const BigReal& other) const;

    friend ostream& operator<<(ostream& out, const BigReal& num);
};

#endif // BIGREAL_H
