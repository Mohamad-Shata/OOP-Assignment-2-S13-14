#include <iostream>
#include <string>

class BigReal {
private:
    std::string number;
    bool isNegative;
    int decimalPlace;

    bool isValidReal(const std::string& realNumber) {
        // Implement your validation logic here
        // Return true if the realNumber is a valid real number, false otherwise
    }

public:
    BigReal(double realNumber = 0.0) {
        number = std::to_string(realNumber);
        isNegative = (realNumber < 0);
        decimalPlace = 0;
    }

    BigReal(const std::string& realNumber) {
        if (isValidReal(realNumber)) {
            number = realNumber;
            isNegative = (realNumber[0] == '-');
            decimalPlace = 0;
        } else {
            // Handle invalid real number input
            // You can throw an exception or handle it in any other way you prefer
        }
    }

    void setNum(const std::string& realNumber) {
        if (isValidReal(realNumber)) {
            number = realNumber;
            isNegative = (realNumber[0] == '-');
            decimalPlace = 0;
        } else {
            // Handle invalid real number input
            // You can throw an exception or handle it in any other way you prefer
        }
    }

    int size() {
        return number.size();
    }

    int sign() {
        return (isNegative ? -1 : 1);
    }

    BigReal operator+(const BigReal& other) {
        // Implement addition logic here
        // Return the result as a new BigReal object
    }

    BigReal operator-(const BigReal& other) {
        // Implement subtraction logic here
        // Return the result as a new BigReal object
    }

    bool operator<(const BigReal& anotherReal) {
        // Implement less than comparison logic here
        // Return true if this BigReal is less than anotherReal, false otherwise
    }

    bool operator>(const BigReal& anotherReal) {
        // Implement greater than comparison logic here
        // Return true if this BigReal is greater than anotherReal, false otherwise
    }

    bool operator==(const BigReal& anotherReal) {
        // Implement equality comparison logic here
        // Return true if this BigReal is equal to anotherReal, false otherwise
    }

    friend std::ostream& operator<<(std::ostream& out, const BigReal& num) {
        out << num.number;
        return out;
    }
};

int main() {
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    std::cout << n3 << std::endl;
    n3 = n3 + BigReal(0.9);
    std::cout << n3 << std::endl;

    return 0;
}
