// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
 	int total = 0;
	for (size_t i = 0; i < CAPACITY; ++i) {
        for (const auto &pair : table[i]) {
            total += pair.second;
        }
    }
    return total;
}

int WordCount::getNumUniqueWords() const {
	int unique = 0;
    for (const auto &bucket : table) {
        if (!bucket.empty()) {
            unique += 1;
        }
    }
    return unique;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
    size_t index = hash(word);
    for (const auto &pair : table[index]) {
        if (pair.first == word) {
            return pair.second;
        }
    }
    return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
    size_t index = hash(word);
    for (auto &pair : table[index]) {
        if (pair.first == word) {
            pair.second++;
            return pair.second;
        }
    }
    table[index].push_back(word, 1);
    return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
    size_t index = hash(word);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == word) {
            if (it->second > 1) {
                it->second--;
                return it->second;
            } else {
                table[index].erase(it);
                return 0;
            }
        }
    }
    return -1;
}

bool WordCount::isWordChar(char c) {
	return (std::isalpha(c) || c == '-' || c == '\'');
}

std::string WordCount::makeValidWord(std::string word) {
	tansform(word.begin(), word.end(), word.begin(), std::tolower);

    string result;
    for (size_t i = 0; i < word.size(); ++i) {
        if (isalpha(word[i]) || ((word[i] == '-' || word[i] == '\'') && i > 0 && i < word.size() - 1)) {
            result += word[i];
        }
    }
    return result ;
}