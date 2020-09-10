#pragma once
#include <iostream>
#include "../model/IPLMostRunsCSV.h"

using namespace std;

class IPLAnalyserView {
    public :
        virtual void displayWelcomeMessage() = 0;
        virtual void displayTopAvgBatsman(IPLMostRunsCSV topBatsman) = 0;
        virtual void displayTopSRBatsman(IPLMostRunsCSV topBatsman) = 0;
        virtual void displayBatsmanWhoHitsMaxSixAndFours(IPLMostRunsCSV topBatsman) = 0;
};

class IPLAnalyserViewImpl : public IPLAnalyserView {
    public:
        IPLAnalyserViewImpl() {}
        virtual void displayWelcomeMessage();
        virtual void displayTopAvgBatsman(IPLMostRunsCSV topBatsman);
        virtual void displayTopSRBatsman(IPLMostRunsCSV topBatsman);
        virtual void displayBatsmanWhoHitsMaxSixAndFours(IPLMostRunsCSV topBatsman);
};

void IPLAnalyserViewImpl::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserViewImpl::displayTopAvgBatsman(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman With Top Batting Average in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Average : " << topBatsman.average << endl;
}

void IPLAnalyserViewImpl::displayTopSRBatsman(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman With Top Batting Strike Rate in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Strike Rate : " << topBatsman.strikeRate << endl;
}

void IPLAnalyserViewImpl::displayBatsmanWhoHitsMaxSixAndFours(IPLMostRunsCSV topBatsman) {
    cout << "\nBatsman Who Hits Max Fours And Sixes in IPL 2019" << endl << "Name: " << topBatsman.playerName << endl
            << "Sixes : " << topBatsman.sixes << endl << "Fours : " << topBatsman.fours << endl;
}