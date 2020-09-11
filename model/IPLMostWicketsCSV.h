#pragma once
#include <iostream>

using namespace std;

class IPLMostWicketsCSV {
public:
    string playerName;
    int runs, wickets, fourWickets, fiveWickets;
    double average, strikeRate, economy, overs;

    IPLMostWicketsCSV() { }

    IPLMostWicketsCSV(string playerName, int wickets, double overs, double economy);
};

IPLMostWicketsCSV::IPLMostWicketsCSV(string playerName, int wickets, double overs, double economy) {
    this->playerName = playerName;
    this->wickets = wickets;
    this->overs = overs;
    this->economy = economy;
}