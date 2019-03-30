#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

#include "Import.hpp"
#include "StockValue.hpp"

using namespace std;

vector<vector<string>> Import::getData(string fileName, int index)
{
  vector<vector<string>> dataVector;
  ifstream csvFile;
  csvFile.open(fileName);
  string dummy, temp[8][30];
  getline(csvFile, dummy); // discard first row

  dataVector.push_back(vector<string>()); // datum
  dataVector.push_back(vector<string>()); // open
  dataVector.push_back(vector<string>()); // high
  dataVector.push_back(vector<string>()); // low
  dataVector.push_back(vector<string>()); // close
  dataVector.push_back(vector<string>()); // volume
  dataVector.push_back(vector<string>()); // adj
  dataVector.push_back(vector<string>()); // index of aktie

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
  string strIndex = to_string(index);
  temp[7][0] = strIndex;
  dataVector[7].push_back(temp[7][0]); // Index of aktie

  csvFile.close();

  return dataVector;
};

vector<StockValue> Import::importLastMonth(string fileName)
{
  ifstream csvFile;
  csvFile.open(fileName);

  vector<StockValue> skV;
  string line = "";

  string date;
  string open;
  string high;
  string low;
  string close;
  string volume;
  string adj;

  int d[3];
  float o;
  float h;
  float l;
  float c;
  int v;
  float a;

  getline(csvFile, line);

  for (int i = 0; i < 30; i++)
  {

    getline(csvFile, date, ',');   // datum
    getline(csvFile, open, ',');   // open
    getline(csvFile, high, ',');   // high
    getline(csvFile, low, ',');    // low
    getline(csvFile, close, ',');  // close
    getline(csvFile, volume, ','); // volume
    getline(csvFile, adj, '\n');   // adj

    d[0] = stoi(date.substr(0, 4));
    d[1] = stoi(date.substr(5, 2));
    d[2] = stoi(date.substr(8, 2));

    v = stoi(volume);

    o = stof(open);
    h = stof(high);
    l = stof(low);
    c = stof(close);
    a = stof(adj);

    StockValue n;
    n = StockValue(d, o, h, l, c, v, a);

    skV.push_back(n);
  }
  csvFile.close();
  return skV;
};