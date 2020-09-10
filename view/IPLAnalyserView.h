#pragma once
#include <iostream>
#include <vector>
#include "../model/IPLMostRunsCSV.h"

using namespace std;

class IPLAnalyserView {
    public :
        virtual void displayWelcomeMessage() = 0;
        virtual void displayTopAvgBatsman(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman) = 0;
};

class IPLAnalyserViewImpl : public IPLAnalyserView {
    public:
        IPLAnalyserViewImpl() {}
        virtual void displayWelcomeMessage();
        virtual void displayTopAvgBatsman(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman);
};

void IPLAnalyserViewImpl::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserViewImpl::displayTopAvgBatsman(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman With Top Batting Average in IPL 2019" << endl << "Name: " << topBatsman[0].playerName << endl
            << "Average : " << topBatsman[0].average << endl;
}

void IPLAnalyserViewImpl::displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman With Top Batting Strike Rate in IPL 2019" << endl << "Name: " << topBatsman[0].playerName << endl
            << "Strike Rate : " << topBatsman[0].strikeRate << endl;
}

void IPLAnalyserViewImpl::displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman Who Hits Max Fours And Sixes in IPL 2019" << endl << "Name: " << topBatsman[0].playerName << endl
            << "Sixes : " << topBatsman[0].sixes << endl << "Fours : " << topBatsman[0].fours << endl;
}

void IPLAnalyserViewImpl::displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman Who Hits Max Fours And Sixes With Best Striking Rate in IPL 2019" << endl 
            << "Name: " << topBatsman[0].playerName << endl << "Sixes : " << topBatsman[0].sixes << endl 
            << "Fours : " << topBatsman[0].fours << endl << "Strike Rate : " << topBatsman[0].strikeRate << endl;
}

void IPLAnalyserViewImpl::displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman Who Best Average And Best Striking Rate in IPL 2019" << endl 
            << "Name: " << topBatsman[0].playerName << endl
            << "Average : " << topBatsman[0].average << endl << "Strike Rate : " << topBatsman[0].strikeRate << endl;
}

void IPLAnalyserViewImpl::displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman) {
    cout << "\nBatsman Who Hits Maximum Runs And Having Best Batting Average in IPL 2019" << endl 
            << "Name: " << topBatsman[0].playerName << endl
            << "Average : " << topBatsman[0].average << endl << "Runs : " << topBatsman[0].runs << endl;
}