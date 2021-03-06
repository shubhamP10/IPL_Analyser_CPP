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
    enum SortBy {
        AVERAGE = 1, STRIKE_RATE, SIX_AND_FOURS, SR_WITH_6sAND4s, 
        AVERAGE_WITH_SR, MAX_RUNS_WITH_AVERAGE, ECONOMY,
        SR_WITH_5w_AND_4w, BOWLING_AVG_WITH_SR, MAX_WICKETS_WITH_AVG, 
        BATTING_BOWLING_AVERAGE, MOST_RUNS_AND_WICKETS
        };
    vector<IPLMostRunsCSV> loadBatsmanData(string fileName);
    vector<IPLMostWicketsCSV> loadBowlerData(string fileName);
    vector<IPLMostRunsCSV> getBatsmanBy(vector<IPLMostRunsCSV> batsmanList, SortBy sortBy);
    vector<IPLMostWicketsCSV> getBowlerBy(vector<IPLMostWicketsCSV> bowlerList, SortBy sortBy);
    vector<All_Rounder> loadAllRounderData(vector<IPLMostRunsCSV> batsmanList, vector<IPLMostWicketsCSV> bowlerList);
    vector<All_Rounder> getAllRounderBy(vector<All_Rounder> allRounderList, SortBy sortBy);

    
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
        bowler.strikeRate = stod(csvData.at(row).at(10));
        bowler.average = stod(csvData.at(row).at(8));

        bowlerList.push_back(bowler);
    }
    return bowlerList;
}

vector<IPLMostRunsCSV> IPLAnalyser::getBatsmanBy(vector<IPLMostRunsCSV> batsmanList, SortBy sortBy) {

    for(int i = 0; i < batsmanList.size() - 1; i++) {
        for(int j = i + 1; j < batsmanList.size(); j++) {
            switch(sortBy) {
                case AVERAGE :
                    if(batsmanList[i].average < batsmanList[j].average) {
                        swap(batsmanList[i], batsmanList[j]);
                    }
                    break;
                    
                case STRIKE_RATE : 
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

vector<IPLMostWicketsCSV> IPLAnalyser::getBowlerBy(vector<IPLMostWicketsCSV> bowlerList, SortBy sortBy) {
    
    for(int i = 0; i < bowlerList.size() - 1; i++) {
        for(int j = i + 1; j < bowlerList.size(); j++) {
            switch(sortBy) {
                case AVERAGE :
                    if(bowlerList[i].average > bowlerList[j].average) {
                        swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
                case STRIKE_RATE :
                    if(bowlerList[i].strikeRate > bowlerList[j].strikeRate) {
                        swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
                case ECONOMY :
                    if(bowlerList[i].economy > bowlerList[j].economy) {
                        swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
                case SR_WITH_5w_AND_4w :
                    if((bowlerList[i].strikeRate > bowlerList[j].strikeRate)) {
                        if((bowlerList[i].fiveWickets + bowlerList[i].fourWickets) < (bowlerList[j].fiveWickets + bowlerList[j].fourWickets))
                            swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
                case BOWLING_AVG_WITH_SR :
                    if((bowlerList[i].average > bowlerList[j].average)) {
                        if(bowlerList[i].strikeRate > bowlerList[j].strikeRate)
                            swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
                case MAX_WICKETS_WITH_AVG :
                    if((bowlerList[i].wickets < bowlerList[j].wickets)) {
                        if(bowlerList[i].average > bowlerList[j].average)
                            swap(bowlerList[i], bowlerList[j]);
                    }
                    break;
            }
        }
    }
    return bowlerList;               
}

vector<All_Rounder> IPLAnalyser::loadAllRounderData(vector<IPLMostRunsCSV> batsmanList, vector<IPLMostWicketsCSV> bowlerList) {
    vector<All_Rounder> allRounderList;
    int count = 0;
    for(int i = 0; i < batsmanList.size(); i++) {
        for(int j = 0; j < bowlerList.size(); j++) {
            if(bowlerList[j].playerName == batsmanList[i].playerName) {
                All_Rounder allRounder;
                allRounder.playerName = bowlerList[j].playerName;
                allRounder.runs = bowlerList[j].runs;
                allRounder.wickets = bowlerList[j].wickets;
                allRounder.bowlingAverage = bowlerList[j].average;
                allRounder.battingAverage = batsmanList[j].average;
                allRounderList.push_back(allRounder);
                count++;
            }
        }
    }

    return allRounderList;
}

vector<All_Rounder> IPLAnalyser::getAllRounderBy(vector<All_Rounder> allRounderList, SortBy sortBy) {
    for(int i = 0; i < allRounderList.size() - 1; i++) {
        for(int j = i + 1; j < allRounderList.size(); j++) {
            switch(sortBy) {
                case BATTING_BOWLING_AVERAGE :
                    if(allRounderList[i].battingAverage < allRounderList[j].battingAverage) {
                        if(allRounderList[i].bowlingAverage > allRounderList[j].bowlingAverage)
                        swap(allRounderList[i], allRounderList[j]);
                    }
                    break;
                
                case MOST_RUNS_AND_WICKETS :
                    if(allRounderList[i].runs < allRounderList[j].runs) {
                        if(allRounderList[i].wickets < allRounderList[j].wickets)
                        swap(allRounderList[i], allRounderList[j]);
                    }
                    break;
            }
        }
    }
    return allRounderList;
}