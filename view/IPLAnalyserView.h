#pragma once
#include <iostream>
#include <vector>
#include "../model/IPLMostRunsCSV.h"
#include "../model/IPLMostWicketsCSV.h"

using namespace std;

class IPLAnalyserView {
    public :
        virtual void displayWelcomeMessage() = 0;
        virtual int getUserChoice() = 0;
        virtual void displayTopAvgBatsman(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman) = 0;
        virtual void displayTopBowlingAverages(vector<IPLMostWicketsCSV> topBowler) = 0;
        virtual void displayTopStrikeRatesOfBowlers(vector<IPLMostWicketsCSV> topBowler) = 0;
        virtual void displayBestBowlingEconomy(vector<IPLMostWicketsCSV> topBowler) = 0;
        virtual void display5wAnd4wWithBestStrikeRate(vector<IPLMostWicketsCSV> topBowler) = 0;
};

class IPLAnalyserViewImpl : public IPLAnalyserView {
    public:
        IPLAnalyserViewImpl() {}
        virtual void displayWelcomeMessage();
        virtual int getUserChoice();
        virtual void displayTopAvgBatsman(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayTopSRBatsman(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWhoHitsMaxSixAndFours(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithSRAnd6sAnd4s(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithBestAverageAndSR(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayBatsmanWithMaxRunsAndAverage(vector<IPLMostRunsCSV> topBatsman);
        virtual void displayTopBowlingAverages(vector<IPLMostWicketsCSV> topBowler);
        virtual void displayTopStrikeRatesOfBowlers(vector<IPLMostWicketsCSV> topBowler);
        virtual void displayBestBowlingEconomy(vector<IPLMostWicketsCSV> topBowler);
        virtual void display5wAnd4wWithBestStrikeRate(vector<IPLMostWicketsCSV> topBowler);
};

void IPLAnalyserViewImpl::displayWelcomeMessage() {
    system("clear");
    cout << "Welcome To IPL Analyser" << endl;
}

int IPLAnalyserViewImpl::getUserChoice() {
    int choice;
    cout << "1. Best Batting Averages\n2. Best Batting Strike Rates\n3. Maximum 4s And 6s" << endl
        << "4. Best Strike Rate With 4s and 6s\n5. Best Batting Averages With Strike Rate" << endl
        << "6. Maximum Runs With Best Average\n7. Top Bowling Averages\n8. Bowler's Batting Strike Rates" << endl 
        << "9. Best Bowling Economy\n10. 5 Wickets And 4 wickets\nPress Other Key To Exit" << endl;
    cin >> choice;
    return choice;
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
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayTopBowlingAverages(vector<IPLMostWicketsCSV> topBowler) {
    cout << "=======================================================";
    cout << "\nTop Bowling Averages in IPL 2019" << endl;
    int count = 0;
    for(int i = 0; i < topBowler.size(); i++) {
        if(topBowler[i].average != 0 && count < 3) {
            cout << "\nName: " << topBowler[i].playerName << endl << "Average : " 
            << topBowler[i].average << endl;
            count++;
        }
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayTopStrikeRatesOfBowlers(vector<IPLMostWicketsCSV> topBowler) {
    cout << "=======================================================";
    cout << "\nTop Batting Strike Rates of Bowlers in IPL 2019" << endl;
    int count = 0;
    for(int i = 0; i < topBowler.size(); i++) {
        if(topBowler[i].strikeRate != 0 && count < 3) {
            cout << "\nName: " << topBowler[i].playerName << endl << "Strike Rate : " 
            << topBowler[i].strikeRate << endl;
            count++;
        }
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::displayBestBowlingEconomy(vector<IPLMostWicketsCSV> topBowler) {
    cout << "=======================================================";
    cout << "\nBest Bowling Economy in IPL 2019" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nName: " << topBowler[i].playerName << "\nOvers Bowled: " << topBowler[i].overs << endl 
        << "Economy : " << topBowler[i].economy << endl;
    }
    cout << "=======================================================\n";
}

void IPLAnalyserViewImpl::display5wAnd4wWithBestStrikeRate(vector<IPLMostWicketsCSV> topBowler) {
    cout << "=======================================================";
    cout << "\nHighest 4 wickets and 5 wickets with Best SR in IPL 2019" << endl;
    int count = 0;
    for(int i = 0; i < topBowler.size(); i++) {
        if(topBowler[i].strikeRate != 0 && count < 3) {
            cout << "\nName: " << topBowler[i].playerName << endl << "Strike Rate : " 
            << topBowler[i].strikeRate << endl << "4 wicket haul: " << topBowler[i].fourWickets << endl
            << "5 wicket haul: " << topBowler[i].fiveWickets << endl;
            count++;
        }
    }
    cout << "=======================================================\n";
}