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
};

int main() {

    IPLAnalyserViewImpl iplViewImpl;
    IPLAnalyserView *iplIO = &iplViewImpl;
    IPLAnalyser iplAnalyser;
    IPL_Controller controller(iplIO, iplAnalyser);

    controller.displayWelcomeMessage();
    controller.displayTopAvgBtasmanData();
    controller.displayTopSRBatsmanData();

    return 0;
}