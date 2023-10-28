#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string convertToInclusiveSentence(const string& sentence) {
    string convertedSentence;
    string word;
    
    for (char c : sentence) {
        if (isalnum(c) || c == '\'') {
            word += c;
        } else {
            if (!word.empty()) {
                if (word == "he" || word == "He") {
                    convertedSentence += "he or she";
                } else if (word == "him" || word == "Him") {
                    convertedSentence += "him or her";
                } else if (word == "his" || word == "His") {
                    convertedSentence += "his or hers";
                } else {
                    convertedSentence += word;
                }
                word.clear();
            }
            convertedSentence += c;
        }
    }
    
    if (!word.empty()) {
        if (word == "he" || word == "He") {
            convertedSentence += "he or she";
        } else if (word == "him" || word == "Him") {
            convertedSentence += "him or her";
        } else if (word == "his" || word == "His") {
            convertedSentence += "his or hers";
        } else {
            convertedSentence += word;
        }
    }
    if(!convertedSentence.empty() && convertedSentence.back() != '.'){
        convertedSentence += '.';
    }else{};
    if(!convertedSentence.empty()){
        convertedSentence[0] = toupper(convertedSentence[0]);
    }
    for(int i = 1; i < convertedSentence.length(); i++){
        convertedSentence[i] = tolower(convertedSentence[i]);
    }
    return convertedSentence;
}

int main() {
    string sentence1;
    cout << "Enter a sentence: ";
    getline(cin, sentence1);

    string convertedSentence = convertToInclusiveSentence(sentence1);

    cout << "Converted sentence: " << convertedSentence << endl;
    return 0;
}
