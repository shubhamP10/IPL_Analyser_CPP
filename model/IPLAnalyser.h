#pragma once
#include <iostream>
#include <vector>
#include "../libraries/csv_reader.h"
#include "IPLMostRunsCSV.h"
#include "IPLMostWicketsCSV.h"

using namespace std;

class IPLAnalyser {
    vector<vector<string>> readCSVData(string fileName);

public:
    enum SortBy {AVG = 1, SR, SIX_AND_FOURS, SR_WITH_6sAND4s, AVERAGE_WITH_SR, MAX_RUNS_WITH_AVERAGE};
    vector<IPLMostRunsCSV> loadBatsmanData(string fileName);
    vector<IPLMostWicketsCSV> loadBowlerData(string fileName);
    vector<IPLMostRunsCSV> getBatsmanBy(vector<IPLMostRunsCSV> batsmanList, SortBy sortBy);
};

vector<vector<string>> IPLAnalyser::readCSVData(string fileName) {
    CSV_Reader csv;
    return csv.read_file(fileName);
}

vector<IPLMostRunsCSV> IPLAnalyser::loadBatsmanData(string fileName) {
    vector<vector<string>> csvData = readCSVData(fileName);
    vector<IPLMostRunsCSV> batsmanList;
   
    for(int row = 0; row < csvData.size(); row++) {
        IPLMostRunsCSV batsman(csvData.at(row).at(1), csvData.at(row).at(6), stod(csvData.at(row).at(7)), stod(csvData.at(row).at(9)));
        batsman.runs = stoi(csvData.at(row).at(5));
        batsman.hundreds = stoi(csvData.at(row).at(10));
        batsman.fifties = stoi(csvData.at(row).at(11));
        batsman.fours = stoi(csvData.at(row).at(12));
        batsman.sixes = stoi(csvData.at(row).at(13));

        batsmanList.push_back(batsman);
    }
    return batsmanList;
}

vector<IPLMostWicketsCSV> IPLAnalyser::loadBowlerData(string fileName) {
    vector<vector<string>> csvData = readCSVData(fileName);
    vector<IPLMostWicketsCSV> bowlerList;

    for(int row = 0; row < csvData.size(); row++) {
        IPLMostWicketsCSV bowler(csvData.at(row).at(1), stoi(csvData.at(row).at(6)), stod(csvData.at(row).at(4)), stod(csvData.at(row).at(9)));
        bowler.runs = stoi(csvData.at(row).at(5));
        bowler.fourWickets = stoi(csvData.at(row).at(11));
        bowler.fiveWickets = stoi(csvData.at(row).at(12));
        bowler.strikeRate = stoi(csvData.at(row).at(10));
        bowler.average = stoi(csvData.at(row).at(8));

        bowlerList.push_back(bowler);
    }
    return bowlerList;
}


vector<IPLMostRunsCSV> IPLAnalyser::getBatsmanBy(vector<IPLMostRunsCSV> batsmanList, SortBy sortBy) {

    for(int i = 0; i < batsmanList.size() - 1; i++) {
        for(int j = i + 1; j < batsmanList.size(); j++) {
            switch(sortBy) {
                case AVG :
                    if(batsmanList[i].average < batsmanList[j].average) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;
                    
                case SR : 
                    if(batsmanList[i].strikeRate < batsmanList[j].strikeRate) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;

                case SIX_AND_FOURS : 
                    if((batsmanList[i].fours + batsmanList[i].sixes) < (batsmanList[j].fours + batsmanList[j].sixes)) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;

                case SR_WITH_6sAND4s : 
                    if((batsmanList[i].fours + batsmanList[i].sixes) < (batsmanList[j].fours + batsmanList[j].sixes) && batsmanList[i].strikeRate < batsmanList[j].strikeRate) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;
                
                case AVERAGE_WITH_SR : 
                    if((batsmanList[i].strikeRate < batsmanList[j].strikeRate) && (batsmanList[i].average < batsmanList[j].average) ) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;
                case MAX_RUNS_WITH_AVERAGE : 
                    if((batsmanList[i].runs < batsmanList[j].runs) && (batsmanList[i].average < batsmanList[j].average) ) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;
            }    
        }
    }
    return batsmanList;
}
