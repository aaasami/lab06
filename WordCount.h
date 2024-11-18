// WordCount.h

#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class WordCount {
public:
  WordCount();
  // Default Constructor

  int getTotalWords() const;
  // Return total number of word occurrences (for all words) in the
  // hash table.

  int getNumUniqueWords() const;
  // Return total number of unique words that exist in the hash table.
  // Note that multiple occurrences of a word is considered one unique
  // word.

  int getWordCount(std::string word) const;
  // Return the number of occurences for a specific word.
  // You may not assume the parameter is a valid word and must
  // strip / convert to lower case before looking in the hash table.
  // If the word does not exist in the table, return 0

  int incrWordCount(std::string word);
  // Update the hash table by incrementing the number of occurences for
  // the word. You MAY NOT assume the parameter word is a valid word.
  // Words must be hashed and stored containing all lower case
  // characters.
  // * If the word is not in the table, then add it with the number
  // of occurences equal to 1.
  // * If the word was added, this method updates the number of occurences
  // of the word in the hash table, and returns the current number of
  // occurences of the word after it was added.

  int decrWordCount(std::string word);
  // Update the hash table by decrementing the number of occurences for
  // the word. You MAY NOT assume the parameter word is a valid word.
  // The word must be converted to a valid word containing all
  // lower case characters to be searched through the hash table.
  // * If an entry for the word exists and the number of occurences is > 1,
  // then the number of occurences for this word entry is updated and this
  // method returns the updated number of occurences.
  // * If the number of occurences for the word is 1, then the key / value
  // pair entry in the hash table is removed from the vector and 0 is
  // returned.
  // * If the word does not exist, then this method returns -1.

  static bool isWordChar(char c);
  // Useful as a helper method in your code.
  // Returns true if c is a valid word character defined as either
  // a lower-case or upper-case alpha char.

  static std::string makeValidWord(std::string word);
  // Words cannot contain any digits, or special characters EXCEPT for
  // hyphens (-) and apostrophes (') that occur in the middle of a
  // valid word (the first and last characters of a word must be an alpha
  // character). All upper case characters in the word should be convertd
  // to lower case.
  // For example, "can't" and "good-hearted" are considered valid words.
  // "12mOnkEYs-$" will be converted to "monkeys".
  // "Pa55ive" will be stripped "paive".

private:
  const static size_t CAPACITY = 100;
  // capacity for the hash table array

  std::vector<std::pair<std::string, int> > table[CAPACITY];
  // hash table array of vectors. Each index in the array will contain
  // a vector. Each element in the vector contains a <string, int>
  // pair where the string value represents a unique word and the int
  // value represents the number of occurences for that word.

  size_t hash(std::string word) const;
  // Hash function that will return an index for the hash table.
};


#endif // WORDCOUNT_H
