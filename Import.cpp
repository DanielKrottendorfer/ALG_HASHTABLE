#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

#include "Import.hpp"

using namespace std;

vector<vector<string>> Import::getData(string fileName)
{

  ifstream csvFile;
  csvFile.open(fileName);
  string dummy, temp[7][30];
  getline(csvFile, dummy); // discard first row

  dataVector.push_back(vector<string>()); // datum
  dataVector.push_back(vector<string>()); // open
  dataVector.push_back(vector<string>()); // high
  dataVector.push_back(vector<string>()); // low
  dataVector.push_back(vector<string>()); // close
  dataVector.push_back(vector<string>()); // volume
  dataVector.push_back(vector<string>()); // adj

  for (int i = 0; i < 30; i++) // data from last 30 days
  {
    getline(csvFile, temp[0][i], ',');  // datum
    getline(csvFile, temp[1][i], ',');  // open
    getline(csvFile, temp[2][i], ',');  // high
    getline(csvFile, temp[3][i], ',');  // low
    getline(csvFile, temp[4][i], ',');  // close
    getline(csvFile, temp[5][i], ',');  // volume
    getline(csvFile, temp[6][i], '\n'); // adj

    dataVector[0].push_back(temp[0][i]); // datum
    dataVector[1].push_back(temp[1][i]); // open
    dataVector[2].push_back(temp[2][i]); // high
    dataVector[3].push_back(temp[3][i]); // low
    dataVector[4].push_back(temp[4][i]); // close
    dataVector[5].push_back(temp[5][i]); // volume
    dataVector[6].push_back(temp[6][i]); // adj
  }

  csvFile.close();

  return dataVector;
};
