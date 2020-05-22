//
// Created by Rick Mercer on 2019-01-02.
//
// This #define tells Catch to provide a main().
// Only do this in one cpp file.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "LoopFun.hpp"

TEST_CASE("isPrime") {
    REQUIRE(isPrime(3));
    REQUIRE_FALSE(isPrime(9));
    // Add more REQUIREs
}

TEST_CASE ("fibonacci") {
    REQUIRE(1 == fibonacci(1));
    // Add more REQUIREs
}

TEST_CASE ("factorial") {
    REQUIRE(24 == factorial(4));
    // Add more REQUIREs
 }

TEST_CASE ("vowelCount") {
     REQUIRE(11 == vowelCount("How much wood could a woodchuck chuck"));
     REQUIRE(10 == vowelCount("Ako Ay NnakatIra sa Pinas"));
    // Add more REQUIREs
}


TEST_CASE ("numberOfPairs") {
    REQUIRE(0 == numberOfPairs("BbB"));
    REQUIRE(3 == numberOfPairs("aabbcc"));
    REQUIRE(2 == numberOfPairs("bbb"));
    REQUIRE(3 == numberOfPairs("!!!!"));
    // Add more REQUIREs
}

TEST_CASE("isSorted") {
    // You might need to cast str.length(), an unsigned long
    // to an int like this: static_cast<int>(str.length())
    REQUIRE(isSorted(""));
    REQUIRE(isSorted("abcdefgh"));
    REQUIRE(isSorted("1234567"));
    REQUIRE_FALSE(!isSorted("bcad"));
    REQUIRE_FALSE(!isSorted("1234567"));
    // Add more REQUIREs
}

TEST_CASE ("howSwedish") {
    // You might need to cast str.length(), an unsigned long
    // to an int like this: static_cast<int>(str.length())
    REQUIRE(2 == howSwedish("abbAbbab"));
    REQUIRE(1 == howSwedish("abba ab ab"));
    REQUIRE(3 == howSwedish("abbabbabbA"));
    // Add more REQUIREs
}

TEST_CASE ("allAsLeft") {
    REQUIRE("AAA" == allAsLeft("aaaAAA").substr(0,3));
    REQUIRE("AB" == allAsLeft("BA"));
    REQUIRE("ABaadf" == allAsLeft("BaadfA"));

    // Add more REQUIREs
}

TEST_CASE ("mirrorEnds") {
    REQUIRE("aasdsaa" == mirrorEnds("aasdsaa"));
    REQUIRE("ab" == mirrorEnds("abXYZba"));
    REQUIRE("aba" == mirrorEnds("aba"));
    REQUIRE("abX" == mirrorEnds("abXYfZXba"));
    REQUIRE("" == mirrorEnds(""));
    // Add more REQUIREs
}

TEST_CASE ("starOut") {
    REQUIRE(starOut("sm**eil*ly") == "siy");
    REQUIRE(starOut("sm*eil**ly") == "siy");
    REQUIRE(starOut("s*eil*ly") == "iy");
    REQUIRE(starOut("****eil*ly") == "iy");
    REQUIRE(starOut("sm**eil*") == "si");
    REQUIRE(starOut("sm**ei**l*ly") == "y");
    REQUIRE(starOut("*a*b*c*d") == "");
    // Add more REQUIREs
}