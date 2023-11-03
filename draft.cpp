#include <iostream>
#include <string>

using namespace std;

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
            if (realNumber[0] == '+' || realNumber[0] == '-') {
                sign = realNumber[0];
                realNumber.erase(0,1);
                if (realNumber.find('.') != string::npos) {
                    intpart = realNumber.substr(0, realNumber.find('.'));
                    fractionpart = realNumber.substr(realNumber.find('.') + 1);
                } else {
                    intpart = realNumber;
                }
            } else {
                if (realNumber.find('.') != string::npos) {
                    intpart = realNumber.substr(0, realNumber.find('.'));
                    fractionpart = realNumber.substr(realNumber.find('.') + 1);
                } else {
                    intpart = realNumber;
                }
            }
        } else {
            intpart = realNumber;
        }
    }

BigReal operator+(const BigReal& other) const {
    BigReal result("0");

    // Perform addition on the integer parts
    double sum = stod(intpart) + stod(other.intpart);
    result.intpart = to_string(sum);

    // Perform addition on the fraction parts
    string fraction1 = fractionpart;
    string fraction2 = other.fractionpart;
    int sizeDiff = fraction1.size() - fraction2.size();

    if (sizeDiff > 0) {
        // Pad fraction2 with zeros
        fraction2.insert(0, sizeDiff, '0');
    } else if (sizeDiff < 0) {
        // Pad fraction1 with zeros
        fraction1.insert(0, -sizeDiff, '0');
    }

    int carry = 0;
    for (int i = fraction1.length() - 1; i >= 0; i--) {
        int digit1 = fraction1[i] - '0';
        int digit2 = fraction2[i] - '0';
        int sum = digit1 + digit2 + carry;
        result.fractionpart = to_string(sum % 10) + result.fractionpart;
        carry = sum / 10;
    }

    // Add any remaining carry
    if (carry > 0) {
        result.intpart = to_string(stod(result.intpart) + carry);
    }

    return result;
}


    BigReal operator-(const BigReal& other) const {
        BigReal result("0");

        // Perform subtraction on the integer parts
        double diff = stod(intpart) - stod(other.intpart);
        result.intpart = to_string(diff);

        // Perform subtraction on the fraction parts
        string fraction1 = fractionpart;
        string fraction2 = other.fractionpart;
        if (fraction1.size() > fraction2.size()) {
            while (fraction2.size() < fraction1.size()) {
                fraction2.push_back('0');
            }
        } else if (fraction1.size() < fraction2.size()) {
            while (fraction1.size() < fraction2.size()) {
                fraction1.push_back('0');
            }
        }

        int borrow = 0;
        for (int i = fraction1.length() - 1; i >= 0; i--) {
            int digit1 = fraction1[i] - '0';
            int digit2 = fraction2[i] - '0';
            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.fractionpart = to_string(diff) + result.fractionpart;
        }

        // Subtract any remaining borrow
        if (borrow > 0) {
            result.intpart = to_string(stod(result.intpart) - borrow);
        }

        return result;
    }

    bool operator<(const BigReal& anotherReal) const {
        if (sign != anotherReal.sign) {
            if (sign == "-") return true;
            else if (sign == "+") return false;
        }

        if (intpart.size() < anotherReal.intpart.size()) return true;
        else if (intpart.size() > anotherReal.intpart.size()) return false;
        else {
            for (int i = 0; i < intpart.size(); i++) {
                if (intpart[i] < anotherReal.intpart[i]) return true;
                else if (intpart[i] > anotherReal.intpart[i]) return false;
            }
        }

        string fraction1 = fractionpart;
        string fraction2 = anotherReal.fractionpart;
        if (fraction1.size() > fraction2.size()) {
            while (fraction2.size() < fraction1.size()) {
                fraction2.push_back('0');
            }
        } else if (fraction1.size() < fraction2.size()) {
            while (fraction1.size() < fraction2.size()) {
                fraction1.push_back('0');
            }
        }

        for (int i = 0; i < fraction1.size(); i++) {
            if (fraction1[i] < fraction2[i]) return true;
            else if (fraction1[i] > fraction2[i]) return false;
        }

        return false;
    }
void print() const {
    cout << intpart;
    if (!fractionpart.empty()) {
        // Remove trailing zeros from fractionpart
        size_t lastNonZero = fractionpart.find_last_not_of('0');
        if (lastNonZero != string::npos) {
            cout << fractionpart.substr(0, lastNonZero + 1);
        }
    }
    cout << endl;
}

    friend ostream& operator<<(ostream& out, const BigReal& num) {
        out << num.number;
        return out;
    }
};

int main() {
    BigReal n1("11.91");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    n3.print();

    return 0;
}
