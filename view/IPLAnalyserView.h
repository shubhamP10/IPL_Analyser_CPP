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
    cout << "=======================================================";
    cout << "\nBatsman With Top Batting Average in IPL 2019" << endl;

    for(int i = 0; i < 3; i++) {
        cout  << "\nName: " << topBatsman[i].playerName << endl << "Average : " << topBatsman[i].average << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman) {
    cout << "=======================================================";
    cout << "\nBatsman With Top Batting Strike Rate in IPL 2019" << endl; 
    for(int i = 0; i < 3; i++) {
        cout << "\nName: " << topBatsman[i].playerName << endl << "Strike Rate : " << topBatsman[i].strikeRate << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman) {
    cout << "=======================================================";
    cout << "\nBatsman Who Hits Max Fours And Sixes in IPL 2019" << endl;
    for(int i = 0; i < 3; i++) {
        cout  << "\nName: " << topBatsman[i].playerName << endl << "Sixes : " << topBatsman[i].sixes << endl << "Fours : " << topBatsman[i].fours << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman) {
    cout << "=======================================================";
    cout << "\nBatsman Who Hits Max Fours And Sixes With Best Striking Rate in IPL 2019" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nName: " << topBatsman[i].playerName << endl << "Sixes : " << topBatsman[i].sixes << endl 
            << "Fours : " << topBatsman[i].fours << endl << "Strike Rate : " << topBatsman[i].strikeRate << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman) {
    cout << "=======================================================";
    cout << "\nBatsman Who Best Average And Best Striking Rate in IPL 2019" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nName: " << topBatsman[i].playerName << endl << "Average : " 
                << topBatsman[i].average << endl << "Strike Rate : " << topBatsman[i].strikeRate << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman) {
    cout << "=======================================================";
    cout << "\nBatsman Who Hits Maximum Runs And Having Best Batting Average in IPL 2019" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nName: " << topBatsman[i].playerName << endl << "Average : " 
            << topBatsman[i].average << endl << "Runs : " << topBatsman[i].runs << endl;
    }
    cout << "=======================================================";
}