#pragma once
#include <iostream>

using namespace std;

class IPLMostRunsCSV {
public:
    string playerName, highestScore;
    int runs, hundreds, fifties, fours, sixes;
    double average, strikeRate;

    IPLMostRunsCSV() { }

    IPLMostRunsCSV(string playerName, string highestScore, double average, double strikeRate);
};

IPLMostRunsCSV::IPLMostRunsCSV(string playerName, string highestScore, double average, double strikeRate) {
    this->playerName = playerName;
    this->highestScore = highestScore;
    this->average = average;
    this->strikeRate = strikeRate;
}