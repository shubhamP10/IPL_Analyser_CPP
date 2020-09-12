#include <iostream>
#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"
#define MOST_WICKETS_FILE_PATH "../resources/IPL2019FactsheetMostWkts.csv"

using namespace std;

class IPL_Controller {
    IPLAnalyserView *iplIO;
    IPLAnalyser iplAnalyser;
    vector<IPLMostRunsCSV> batsmanList;
    vector<IPLMostWicketsCSV> bowlerList;
    

public:
    vector<All_Rounder> allRounderList;
    IPL_Controller(IPLAnalyserView *view, IPLAnalyser model) {
        iplIO = view;
        iplAnalyser = model;
        batsmanList = iplAnalyser.loadBatsmanData(MOST_RUNS_FILE_PATH);
        bowlerList = iplAnalyser.loadBowlerData(MOST_WICKETS_FILE_PATH);
        allRounderList = iplAnalyser.loadAllRounderData(batsmanList, bowlerList);
    }

    void displayWelcomeMessage() {
        iplIO->displayWelcomeMessage();
    }

    void createMenu() {
        int flag = 0;

        while(flag == 0) {
            int choice = iplIO->getUserChoice();
            switch(choice) {
                case 1:
                    iplIO->displayTopAvgBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVERAGE));
                    break;
                case 2:
                    iplIO->displayTopSRBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.STRIKE_RATE));
                    break;
                case 3:
                    iplIO->displayBatsmanWhoHitsMaxSixAndFours(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SIX_AND_FOURS));
                    break;
                case 4:
                    iplIO->displayBatsmanWithSRAnd6sAnd4s(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SR_WITH_6sAND4s));
                    break;
                case 5:
                    iplIO->displayBatsmanWithBestAverageAndSR(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVERAGE_WITH_SR));
                    break;
                case 6:
                    iplIO->displayBatsmanWithMaxRunsAndAverage(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.MAX_RUNS_WITH_AVERAGE));
                    break;
                case 7:
                    iplIO->displayTopBowlingAverages(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.AVERAGE));
                    break;
                case 8:
                    iplIO->displayTopStrikeRatesOfBowlers(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.STRIKE_RATE));
                    break;
                case 9:
                    iplIO->displayBestBowlingEconomy(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.ECONOMY));
                    break;
                case 10:
                    iplIO->display5wAnd4wWithBestStrikeRate(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.SR_WITH_5w_AND_4w));
                    break;
                case 11:
                    iplIO->displayBestBowlingAverageWithSR(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.BOWLING_AVG_WITH_SR));
                    break;
                case 12:
                    iplIO->displayMaxWicketsWithAverage(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.MAX_WICKETS_WITH_AVG));
                    break;
                case 13:
                    iplIO->displayBestBowlingAndBattingAverage(iplAnalyser.getAllRounderBy(allRounderList, iplAnalyser.BATTING_BOWLING_AVERAGE));
                    break;
                case 14:
                    iplIO->displayBestAllRounders(iplAnalyser.getAllRounderBy(allRounderList, iplAnalyser.MOST_RUNS_AND_WICKETS));
                    break;
                default :
                    flag = 1;
            }
        }
    }
};

int main() {

    IPLAnalyserViewImpl iplViewImpl;
    IPLAnalyserView *iplIO = &iplViewImpl;
    IPLAnalyser iplAnalyser;
    IPL_Controller controller(iplIO, iplAnalyser);

    controller.displayWelcomeMessage();
    controller.createMenu();

    return 0;
}