#ifndef Soundex_h
#define Soundex_h

#include <unordered_map>
#include "string"

class Soundex {

public:
    std::string encode(const std::string &word) const {
        return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
    }

    std::string encodedDigit(char letter) const {
        const std::unordered_map<char, std::string> encodings{
                {'b', "1"},
                {'c', "2"},
                {'d', "3"},
                {'f', "1"},
                {'g', "2"},
                {'j', "2"},
                {'k', "2"},
                {'l', "4"},
                {'m', "5"},
                {'n', "5"},
                {'p', "1"},
                {'q', "2"},
                {'r', "6"},
                {'s', "2"},
                {'t', "3"},
                {'v', "1"},
                {'x', "2"},
                {'z', "2"}
        };

        auto it = encodings.find(letter);

        return it == encodings.end() ? "" : it->second;
    }

    std::string upperFront(const std::string &string) const {
        return std::string(1,
                           std::toupper(static_cast<unsigned char>(string.front())));
    }

private:
    std::string tail(const std::string &word) const {
        return word.substr(1);
    }

    std::string head(const std::string &word) const {
        return word.substr(0, 1);
    }

    std::string lastDigit(const std::string &encoding) const {
        if (encoding.empty()) return "";
        return std::string(1, encoding.back());
    }

    std::string encodedDigits(const std::string &word) const {
        std::string encoding;
        for (auto letter: word) {
            if (isComplete(encoding)) break;
            if (encodedDigit(letter) != lastDigit(encoding))
                encoding += encodedDigit(letter);
        }
        return encoding;
    }

    bool isComplete(const std::string &encoding) const {
        return encoding.length() == MaxCodeLength - 1;
    }

    static const size_t MaxCodeLength{4};

    std::string zeroPad(const std::string &word) const {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif