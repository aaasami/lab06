#include "tddFuncs.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

std::string convertLineNumber(int lineNumber) {
  std::string retVal="";
  if (lineNumber > 0) 
    retVal += " line: " + std::to_string(lineNumber);
  return retVal;
}

void assertEquals(const char * const expected, 
		  const char * const actual, 
		  std::string message,
		  int lineNumber) {
  std::string line = convertLineNumber(lineNumber);
  if ( !strcmp(expected,actual) ) {  // if they are equal
    cout << "PASSED: " << message << line <<  endl;;
  } else {
    cout << "   FAILED: " << message << line << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertEquals(const char * const expected, 
		  std::string actual, 
		  std::string message,
		  int lineNumber) {
  assertEquals(std::string(expected),actual,message,lineNumber);
}

void assertTrue(bool expression,
		std::string message,
		int lineNumber) {
  std::string line = convertLineNumber(lineNumber);
  if (expression) {
    cout << "PASSED: " << message << line << endl;;
  } else {
    cout << "   FAILED: " << message << line << endl 
	 << "     Expected true, but was false " << endl;
  }
}

