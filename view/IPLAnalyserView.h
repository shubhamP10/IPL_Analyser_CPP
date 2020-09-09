#pragma once
#include <iostream>
#include "../model/IPLMostRunsCSV.h"

using namespace std;

class IPLAnalyserView {
private:
    public:
    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayTopAvgBatsman(IPLMostRunsCSV topBatsman);
    void displayTopSRBatsman(IPLMostRunsCSV topBatsman);
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopAvgBatsman(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman With Top Batting Average Rate in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Average : " << topBatsman.average << endl;
}

void IPLAnalyserView::displayTopSRBatsman(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman With Top Batting Strike Rate in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Strike Rate : " << topBatsman.strikeRate << endl;
}