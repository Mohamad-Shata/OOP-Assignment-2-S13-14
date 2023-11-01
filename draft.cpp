#include <iostream>
#include <string>

class BigReal {
private:
    string number;
    string intpart;
    string fractionpart;
    string sign;
    
bool isValidReal(const string& realNumber) {
    // Check if the string is empty
    if (realNumber.empty()) {
        return false;
    }

    // Check if the string starts with a valid sign (+ or -)
    if (realNumber[0] != '+' && realNumber[0] != '-' && !isdigit(realNumber[0])) {
        return false;
    }

    // Check if the string contains more than one decimal point
    int decimalCount = 0;
    for (char c : realNumber) {
        if (c == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                return false;
            }
        } else if (!isdigit(c) && c != '+' && c != '-') {
            return false;
        }
    }

    // Check if the string ends with a digit
    if (!isdigit(realNumber.back())) {
        return false;
    }

    return true;
}
public:
    BigReal(string realNumber) {
        if (isValidReal(realNumber)) {
            if(realNumber[0] == '+' || realNumber[0] == '-'){
                sign = realNumber[0];
                realNumber[0] = '0';
                if(realNumber.find('.')){
                intpart = realNumber.substr(0,realNumber.find('.'));
                fractionpart = realNumber.substr(realNumber.find('.'), realNumber.back());
                }else{
                intpart = realNumber;
                }
            }else{
                if(realNumber.find('.')){
                intpart = realNumber.substr(0,realNumber.find('.'));
                fractionpart = realNumber.substr(realNumber.find('.'), realNumber.back());
                }else{
                intpart = realNumber;
                }
            }
        } else {
            intpart = "0.0";
        }
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
