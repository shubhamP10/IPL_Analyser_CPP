#pragma once
#include <iostream>
#include <vector>
#include "../libraries/csv.h"

using namespace std;

class IPLService {
    vector<vector<string>> readCSVData(string fileName);

    public:
        vector<IPLMostRunsCSV> loadData(string fileName);
        IPLMostRunsCSV getBatsmanWithTopBattingAverage(vector<IPLMostRunsCSV> batsmanList);
};

vector<vector<string>> IPLService::readCSVData(string fileName) {
    CSV csv;
    return csv.read_file(fileName);
}

vector<IPLMostRunsCSV> IPLService::loadData(string fileName) {

    vector<vector<string>> csvData = readCSVData(fileName);
    vector<IPLMostRunsCSV> batsmanList;

    for(int row = 0; row < csvData.size(); row++) {
        IPLMostRunsCSV batsman(csvData.at(row).at(1), csvData.at(row).at(6), stoi(csvData.at(row).at(2)), stoi(csvData.at(row).at(3)));
        batsman.notOuts = stoi(csvData.at(row).at(4));
        batsman.runs = stoi(csvData.at(row).at(5));
        batsman.hundreds = stoi(csvData.at(row).at(10));
        batsman.fifties = stoi(csvData.at(row).at(11));
        batsman.fours = stoi(csvData.at(row).at(12));
        batsman.sixes = stoi(csvData.at(row).at(13));
        batsman.average = stod(csvData.at(row).at(7));
        batsman.strikeRate = stod(csvData.at(row).at(9));

        batsmanList.push_back(batsman);
    }

    return batsmanList;
}

IPLMostRunsCSV IPLService::getBatsmanWithTopBattingAverage(vector<IPLMostRunsCSV> batsmanList) {
    IPLMostRunsCSV topAvgBatsman;

    for(int i = 0; i < batsmanList.size() - 1; i++) {
        for(int j = i + 1; j < batsmanList.size(); j++) {
            if(batsmanList[i].average < batsmanList[j].average) {
                swap(batsmanList[i], batsmanList[j]);
            }
        }
    }

    return batsmanList.at(0);
}
