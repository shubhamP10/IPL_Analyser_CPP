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
    IPL_Controller(IPLAnalyserView *view, IPLAnalyser model) {
        iplIO = view;
        iplAnalyser = model;
        batsmanList = iplAnalyser.loadBatsmanData(MOST_RUNS_FILE_PATH);
        bowlerList = iplAnalyser.loadBowlerData(MOST_WICKETS_FILE_PATH);
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
                    iplIO->displayTopAvgBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVG));
                    break;
                case 2:
                    iplIO->displayTopSRBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SR));
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
                    iplIO->displayBatsmanWithMaxRunsAndAverage(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVERAGE_WITH_SR));
                    break;
                case 7:
                    iplIO->displayTopBowlingAverages(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.AVG));
                    break;
                case 8:
                    iplIO->displayTopStrikeRatesOfBowlers(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.SR));
                    break;
                case 9:
                    iplIO->displayBestBowlingEconomy(iplAnalyser.getBowlerBy(bowlerList, iplAnalyser.ECONOMY));
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