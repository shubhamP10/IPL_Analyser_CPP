#include <iostream>
#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

class IPL_Controller {
    IPLAnalyserView *iplIO;
    IPLAnalyser iplAnalyser;
    vector<IPLMostRunsCSV> batsmanList;

    public:
        IPL_Controller(IPLAnalyserView *view, IPLAnalyser model) {
            iplIO = view;
            iplAnalyser = model;
            batsmanList = iplAnalyser.loadData(MOST_RUNS_FILE_PATH); 
        }

        void displayWelcomeMessage() {
            iplIO->displayWelcomeMessage();
        }

        void displayTopAvgBtasmanData() {
            iplIO->displayTopAvgBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVG));
        }

        void displayTopSRBatsmanData() {
             iplIO->displayTopSRBatsman(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SR));
        }

        void displayBatsmanWhoHitsMaxSixAndFours() {
            iplIO->displayBatsmanWhoHitsMaxSixAndFours(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SIX_AND_FOURS));
        }

        void displayBatsmanWithSRAnd6sAnd4s() {
            iplIO->displayBatsmanWithSRAnd6sAnd4s(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.SR_WITH_6sAND4s));
        }

        void displayBatsmanWithBestAverageAndSR() {
            iplIO->displayBatsmanWithBestAverageAndSR(iplAnalyser.getBatsmanBy(batsmanList, iplAnalyser.AVERAGE_WITH_SR));
        }
};

int main() {

    IPLAnalyserViewImpl iplViewImpl;
    IPLAnalyserView *iplIO = &iplViewImpl;
    IPLAnalyser iplAnalyser;
    IPL_Controller controller(iplIO, iplAnalyser);

    controller.displayWelcomeMessage();
    controller.displayTopAvgBtasmanData();
    controller.displayTopSRBatsmanData();
    controller.displayBatsmanWhoHitsMaxSixAndFours();
    controller.displayBatsmanWithSRAnd6sAnd4s();
    controller.displayBatsmanWithBestAverageAndSR(); 


    return 0;
}