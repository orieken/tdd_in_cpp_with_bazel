#ifndef Soundex_h
#define Soundex_h

#include <unordered_map>
#include "string"

class Soundex {

public:
    std::string encode(const std::string &word) const {
        return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
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

        auto it = encodings.find(lower(letter));
        return it == encodings.end() ? NotADigit : it->second;
    }

    std::string upperFront(const std::string &string) const {
        return std::string(1,
                           std::toupper(static_cast<unsigned char>(string.front())));
    }

private:
    const std::string NotADigit{"*"};

    char lower(char c) const {
        return std::tolower(static_cast<unsigned char>(c));
    }

    std::string tail(const std::string &word) const {
        return word.substr(1);
    }

    std::string head(const std::string &word) const {
        return word.substr(0, 1);
    }

    std::string encodedDigits(const std::string &word) const {
        std::string encoding;
        encodeHead(encoding, word);
        encodeTail(encoding, word);

        return encoding;
    }

    void encodeHead(std::string &encoding, const std::string &word) const {
        encoding += encodedDigit(word.front());
    }

    void encodeTail(std::string &encoding, const std::string &word) const {
        for (auto i = 1u; i < word.length(); i++) {
            if (!isComplete(encoding))
                encodeLetter(encoding, word[i], word[i - 1]);
        }
    }

    void encodeLetter(std::string &encoding, char letter, char lastLetter) const {
        auto digit = encodedDigit(letter);
        if (digit != NotADigit &&
            (digit != lastDigit(encoding) || isVowel(lastLetter)))
            encoding += digit;
    }

    std::string lastDigit(const std::string &encoding) const {
        if (encoding.empty()) return NotADigit;
        return std::string(1, encoding.back());
    }

    bool isComplete(const std::string &encoding) const {
        return encoding.length() == MaxCodeLength;
    }

    bool isVowel(char letter) const {
        return std::string("aeiouy").find(lower(letter)) != std::string::npos;
    }

    static const size_t MaxCodeLength{4};

    std::string zeroPad(const std::string &word) const {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif