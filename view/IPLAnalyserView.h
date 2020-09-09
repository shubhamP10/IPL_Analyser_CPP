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
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopAvgBatsman(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman With Top Batting Average in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Average : " << topBatsman.average << endl;
}