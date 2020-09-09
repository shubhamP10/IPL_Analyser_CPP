#include <iostream>

using namespace std;

class MostRunsCSV {
    public:
        string playerName, highestScore;
        int matches, innings, notOuts, runs, hundreds, fiffours, lies, sixes;
        double average, strikeRate;

        MostRunsCSV() { }

        MostRunsCSV(string playerName, string highestScore, int matches, int innings);
};

MostRunsCSV::MostRunsCSV(string playerName, string highestScore, int matches, int innings) {
    this->playerName = playerName;
    this->highestScore = highestScore;
    this->matches = matches;
    this->innings = innings;
}