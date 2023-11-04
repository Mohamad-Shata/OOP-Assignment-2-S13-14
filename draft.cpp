#include <iostream>
#include <string>
#include <cmath>

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

        // Check if the string contains only valid characters
        for (char c : realNumber) {
            if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
                return false;
            }
        }

        // Check if the string has a valid sign
        if (realNumber[0] != '+' && realNumber[0] != '-' && !isdigit(realNumber[0])) {
            return false;
        }

        // Check if the string has a valid decimal point
        int decimalCount = 0;
        for (char c : realNumber) {
            if (c == '.') {
                decimalCount++;
            }
        }
        if (decimalCount > 1) {
            return false;
        }

        return true;
    }

public:
    BigReal(const string& realNumber) {
        if (!isValidReal(realNumber)) {
            throw invalid_argument("Invalid real number");
        }

        // Initialize the sign, intpart, and fractionpart
        sign = (realNumber[0] == '-') ? "-" : "+";
        size_t decimalPos = realNumber.find('.');
        if (decimalPos != string::npos) {
            intpart = realNumber.substr(0, decimalPos);
            fractionpart = realNumber.substr(decimalPos + 1);
        } else {
            intpart = realNumber.substr(0);
            fractionpart = "";
        }
        if (realNumber[0] == '+' || realNumber[0] == '-') {
            intpart.erase(0,1);
        }
        // Remove leading zeros from intpart
        size_t firstNonZero = intpart.find_first_not_of('0');
        if (firstNonZero != string::npos) {
            intpart = intpart.substr(firstNonZero);
        }

        // Remove trailing zeros from fractionpart
        size_t lastNonZero = fractionpart.find_last_not_of('0');
        if (lastNonZero != string::npos) {
            fractionpart = fractionpart.substr(0, lastNonZero + 1);
        }

        // Check if the number is zero
        if (intpart.empty() && fractionpart.empty()) {
            sign = "+";
        }

        // Construct the number string
        number = sign + intpart + "." + fractionpart;
    }
bool findMaxValue(const std::string& str1, const std::string& str2) const {
    if (str1.length() > str2.length()) {
        return true;
    } else if (str1.length() < str2.length()) {
        return false;
    } else {
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] > str2[i]) {
                return true;
            } else if (str1[i] < str2[i]) {
                return false;
            }
        }
    }
    return false;
}



    

    BigReal operator+(const BigReal& other) const {
        BigReal result("0");

        // variables used
        string fraction1 = fractionpart;
        string fraction2 = other.fractionpart;
        int sizeDiff = fraction1.size() - fraction2.size();
        string integer1 = intpart;
        string integer2 = other.intpart;
        int intsizeDiff = integer1.size() - integer2.size();

        if (intsizeDiff > 0) {

        for(int i = intsizeDiff ; i != 0 ; i--){

            integer2 = '0' + integer2;

            }
        } else if (intsizeDiff < 0) {

        for(int i = intsizeDiff ; i != 0 ; i++){

            integer1 = '0' + integer1;
            }  
        }

        if (sizeDiff > 0) {

            fraction2.insert(0 , sizeDiff , '0');

        } else if (sizeDiff < 0) {

            fraction1.resize(fraction2.size(),'0');
        }

        // addition of fraction part
        if(sign == other.sign){
        int carry = 0;
        for (int i = fraction1.length() - 1; i >= 0; i--) {
            int digit1 = fraction1[i] - '0';
            int digit2 = fraction2[i] - '0';
            int sum = digit1 + digit2 + carry;
            result.fractionpart = to_string(sum % 10) + result.fractionpart;
            carry = sum / 10;
        }            


        // Add any remaining carry
            result.intpart = addWithCarry(integer1, integer2, carry);

            result.number = sign + result.intpart + '.' + result.fractionpart;

        return result;
        }else{
            if(findMaxValue(integer1, integer2)){
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
        
        result.intpart = subtractWithBorrow(integer1 , integer2 , borrow);

        result.number = sign + result.intpart + '.' + result.fractionpart;
            }else if(!findMaxValue( integer1 , integer2)){
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
        result.intpart = subtractWithBorrow(integer2 , integer1 , borrow);

        result.number = other.sign + result.intpart + '.' + result.fractionpart;
            }else{
                result.number = '0';
            }
            return result;
        }
    }

    string addWithCarry(const string& num1, const string& num2, int carry) const {
        string result;

        for (int i = num1.length() - 1 ; i >= 0 ; i--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[i] - '0';
            int sum = digit1 + digit2 + carry;
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }

        return result;
    
    }

string subtractWithBorrow(const string& num1, const string& num2, int borrow) const {
    string result;
    int n = num1.length();

    for (int i = n - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';

        // Apply borrow
        digit1 -= borrow;

        // Perform subtraction
        int diff = digit1 - digit2;

        // Update borrow for the next iteration
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        // Convert the difference to a character and prepend it to the result
        result = to_string(diff) + result;
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
    void print() const {
        cout << number << endl;
    }
    void test(){
        cout << intpart << endl << fractionpart << endl;
    }
};

int main() {
    BigReal n1("-111.0");
    BigReal n2("1.5");
    BigReal n3 = n1 + n2;

    n3.print();

    return 0;
}
