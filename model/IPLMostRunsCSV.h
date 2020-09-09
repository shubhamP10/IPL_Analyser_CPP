#include <iostream>

using namespace std;

class IPLMostRunsCSV {
    public:
        string playerName, highestScore;
        int matches, innings, notOuts, runs, hundreds, fifties, fours, sixes;
        double average, strikeRate;

        IPLMostRunsCSV() { }

        IPLMostRunsCSV(string playerName, string highestScore, int matches, int innings);
};

IPLMostRunsCSV::IPLMostRunsCSV(string playerName, string highestScore, int matches, int innings) {
    this->playerName = playerName;
    this->highestScore = highestScore;
    this->matches = matches;
    this->innings = innings;
}