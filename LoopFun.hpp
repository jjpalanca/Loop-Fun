/*
 * LoopFun.cpp
 *
 * LoopFun.cpp contains ten free functions that require a
 * while or a for loop. Some some perform mathematical
 * calculations, some process strings.
 *
 * Programmer Rick Mercer and Jessmer John Palanca
 */
#ifndef LOOPFUN_HPP_
#define LOOPFUN_HPP_

#include <string> // for class string

using namespace std;

// 1) isPrime
//
// One evening, while listening intently at the Very Large Array
// (VLA) radio astronomy observatory 333 miles east of Oro
// Valley AZ, Ellie hears a powerful signal: a prime number
// pattern emanating from the star Vega, confirmed by others
// the world over, undeniable and strong in its pulsing power.
// What Ellie recognized was the repeating series of the
// first 26 prime numbers. This is someone near Vega trying
// to contact anyone who is listening:
//
//  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71
//
// A prime number is a natural number greater than 1 that has
// no positive divisors other than 1 and itself. Complete
// function isPrime that returns true if the argument is a
// prime number. Hint: Consider writing a loop that divides
// the argument num by every integer from 2 to num-1,
// returning false if num was found to be evenly divisible
// by any one of those.
//
//  isPrime(10) returns false
//  isPrime(11) returns true
//
bool isPrime(int num) {
    int x = 2;
    int count = 0;
    while (x <= (num - 1)) {
        if (num % x == 0) {
            count++;
        }
        x++;
    }
    if (count == 0) {
        return true;
    } else if (count > 0) {
        return false;
    }
}


// 2) fibonacci
//
// In the movie "The Da Vinci Code" with Tom Hanks, this password
// used to unlock a much sought after artifact: 1 2 3 5 8 13 21.
// These are the 2nd through 8th Fibonacci numbers. Fibonacci numbers
// have so much interest, there exists a Fibonacci Quarterly
//
//   http://www.fq.math.ca/
//
// Implement function fibonacci that returns the nth Fibonacci number.
// Fibonnaci numbers can be computed as the sum of the preceeding two.
// You will find it useful to keep track the two previous Fibonacci
// numbers. This is harder than it looks.
//
//  fibonacci(1) returns 1
//  fibonacci(2) returns 1
//  fibonacci(3) returns 2
//  fibonacci(4) returns 3
//  fibonacci(5) returns 5
//  fibonacci(6) returns 8
//
int fibonacci(int n) {
    int fib;
    int i = 0;
    int predecessor = 1;
    int successor = 1;

    while (i < n) {
        if (i <= 1) {
            fib = 1;
        } else {
            fib = predecessor + successor;
            predecessor = successor;
            successor = fib;
        }
        i++;
    }
    return fib;
}


// 3) factorial
//
// Given an integer argument return n factorial, which is written as n!.
// 5! = 5*4*3*2*1 or in general, n! = n*(n-1)*(n-2) …*2*1. Use a for loop.
//
//  factorial(0) returns 1
//  factorial(1) returns 1
//  factorial(2) returns 2, which is 2 * 1
//  factorial(3) returns 6, which is 3 * 2 * 1
//  factorial(4) returns 24, which is 4 * 3 * 2 * 1
//
// Precondition: n >= 0
//
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        int i;
        int fact = 1;
        for (i = n; i > 0; i--) {
            fact = fact * i;
        }
        return fact;
    }
}


// 4) vowelCount
//
// "How much wood could a woodchuck chuck" contains 11 vowels.  How do we
// know? Five of the 26 English alphabet letters are vowels: a, e, i, o,
// and u. By looking at each letter in the woodchuck string, we find
// 11 vowels. Complete function vowelCount that returns the number of vowels
// in the given std::string argument. This is case insensitive. Upper and lower
// case vowels count. We do not consider y to be a vowel.
//
//  vowelCount("a e i o u A E I O U") returns 10
//  vowelCount("y+_x1Y2x!y") returns 0
//
int vowelCount(std::string str) {
    string vowel = "aeiouAEIOU";
    int i = 0;
    int vowelCount = 0;

    while (i < str.length()) {
        int j = 0;
        while (j < vowel.length()) {
            if (vowel[j] == str[i]) {
                vowelCount++;
            }
            j++;
        }
        i++;
    }
    return vowelCount;
}


// 5) numberOfPairs
//
// Return the number of times two consecutive characters occur in str.
// This is case sensitive:
//
//  numberOfPairs ("BbB") returns 0
//  numberOfPairs ("") returns 0
//  numberOfPairs ("abc") returns 0
//  numberOfPairs ("aabbcc") returns 3
//  numberOfPairs ("!!!") returns 2
//
int numberOfPairs(std::string str) {
    int i = 0;
    int pairCount = 0;

    while (i < (str.length() - 1)) {
        if (str[i] == str[i + 1]) {
            pairCount += 1;
        }
        i++;
    }
    return pairCount;
}


// 6) howSwedish
//
// ABBA is a band, they have many songs including Fernando
// and Dancing Queen. ABBA is actually a Swedish band. If we
// wanted to find out howSwedish a std::string is, we could
// find out how many times the std::string contains the
// std::string "abba".  We want to look for this str::string
// in a case insensitive manner. So "abba" counts, and so
// does "aBbA". We also want to check for overlapping abba's
// such as in the std::string "abbAbba" that contains "abba" twice.
//
//  howSwedish("") returns 0
//  howSwedish("ABB") returns 0
//  howSwedish("AbBa") returns 1
//  howSwedish("AbBa a B b a") returns 1
//  howSwedish("!abbABba!") returns 2
//  howSwedish("abbAbba") returns 2
//
int howSwedish(std::string str) {
    char c1 = ' ';
    char c2 = ' ';
    char c3 = ' ';
    char c4 = ' ';
    string word = " ";
    int count = 0;

    for (int i = 0; i < (static_cast<int>(str.length()) - 1); i++) {
        c1 = tolower(str[i]);
        c2 = tolower(str[i + 1]);
        c3 = tolower(str[i + 2]);
        c4 = tolower(str[i + 3]);
        word = c1;
        word += c2;
        word += c3;
        word += c4;
        if (word == "abba") {
            count++;
        }
    }

    return count;
}


// 7) allAsLeft
//
// Given a String, return the same characters in the std::string in the same
// order except all upper case 'A's are to the left.
//
//  allAsLeft("") returns ""
//  allAsLeft("A") returns "A"
//  allAsLeft("G") returns "G"
//  allAsLeft("AB") returns "AB"
//  allAsLeft("BA") returns "AB"
//  allAsLeft("ABCaDEFGaA") returns "AABCaDEFGa";
//
std::string allAsLeft(std::string str) {
    char a = 'A';
    string temp = "";
    if (str.length() == 1 or str.length() == 0) {
        return str;
    } else if (str.length() > 1) {
        int i = 0;

        while (i < str.length()) {

            if (str[i] == a) {
                temp = str.erase(i, 1);
                temp = a + temp;
                str = temp;
            }
            i++;
        }
        return str;
    }
}


// 8) isSorted
//
// Given a String, return true of the letters are in ascending order.
// Note:  'a' < 'b' and  '5' < '8'
//
//  isSorted("") returns true
//  isSorted("a") returns true
//  isSorted("abbcddef") returns true
//  isSorted("123456") returns true
//  isSorted("12321") returns false
//
bool isSorted(std::string str) {
    int i = 0;
    if ((static_cast<int>(str.length())) == 0 or (static_cast<int>(str.length())) == 1) {
        return true;
    } else {
        while (i < ((static_cast<int>(str.length())) - 1)) {
            if (str[i] <= str[i + 1]) {
                return true;
            } else {
                return false;
            }
        }
    }
}


// 9) mirrorEnds
//
// Given a string, look for a mirror image (backwards) string at both the beginning
// and end of the given string. In other words, zero or more characters at the very
// beginning of the given string, and at the very end of the string in reverse order
// (possibly overlapping). For example, the string "abXYZba" has the mirror end "ab".
//
//  mirrorEnds("abXYZba") return "ab"
//  mirrorEnds("abca") returns "a"
//  mirrorEnds("aba") returns "aba"
//
std::string mirrorEnds(std::string str) {

    if (str.length() % 2 == 0) {
        int num = str.length() / 2;
        string str1 = str.substr(0, num);
        string str2 = str.substr(num, num);
        reverse(str2.begin(), str2.end());

        int i = 0;
        string mirrorEnds = "";
        int count = 0;

        while (i < num) {
            if (str1[i] == str2[i]) {
                mirrorEnds = mirrorEnds + str1[i];
                count++;
            }
            i++;
        }
        if (count == num) {
            return str;
        } else if (count != num) {
            return mirrorEnds;
        }
    }
    if (str.length() % 2 != 0) {
        int num = str.length() / 2;
        string str1 = str.substr(0, num);
        string str2 = str.substr(num + 1, num);
        reverse(str2.begin(), str2.end());

        int i = 0;
        string mirrorEnds = "";
        int count = 0;

        while (i < num) {
            if (str1[i] == str2[i]) {
                mirrorEnds = mirrorEnds + str1[i];
                count++;
            }
            i++;
        }
        if (count == num) {
            return str;
        } else if (count != num) {
            return mirrorEnds;
        }
    }
}


// 10) starOut
//
// Return a version of the given string, where for every star (*) in the string
// the star and the chars immediately to its left and right are gone.
// So "ab*cd" yields "ad" and "ab**cd" also yields "ad".
//
//  starOut("ab*cd") returns "ad"
//  starOut("ab**cd") returns "ad"
//  starOut("sm*eilly") returns "silly"
//
std::string starOut(std::string str) {
    char star = '*';
    string temp = "";

    int i = 0;
    while (i < str.length()) {
        if ((str[i] == star) && (str[i + 1] != star)) {

            if (i == 0) {
                temp = str.erase(i, 2);
                str = temp;
                i = i - 1;
            } else {
                temp = str.erase(i - 1, 3);
                str = temp;
                i = i - 2;
            }
        } else if ((str[i] == star) && (str[i + 1] == star)) {
            int j = i;
            int count = 0;
            while (j < str.length()) {
                if (str[j] == star) {
                    count++;
                } else if (str[j] != star) {
                    break;
                }
                j++;
            }

            if (i == 0) {
                temp = str.erase(i, count + 1);
                str = temp;
                i = i - 1;
            } else {
                temp = str.erase(i - 1, count + 2);
                str = temp;
                i = i - 2;
            }
        }
        i++;

    }
    return str;
}

#endif  // LOOPFUN_HPP_
