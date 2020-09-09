#include <iostream>
#include "../view/IPLAnalyserView.h"
#include "../model/IPLService.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

int main() {
    IPLAnalyserView iplIO;
    IPLService iplService;

    iplIO.displayWelcomeMessage();
    vector<IPLMostRunsCSV> batsmanList =  iplService.loadData(MOST_RUNS_FILE_PATH); 

    iplIO.displayTopAvgBatsman(iplService.getBatsmanBy(batsmanList, iplService.AVG));
    iplIO.displayTopSRBatsman(iplService.getBatsmanBy(batsmanList, iplService.SR));

    return 0;
}