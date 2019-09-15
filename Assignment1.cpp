/* Assignment1.cpp
  This program takes a file full of DNA strands, computes the Statistics such as average length and Variance, and outputs to a file those Statistics as well as 1000 string based on those Statistics
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

//The main function which takes a file name and output stream as input and then processes the data from the input to the output
void processData(string fileName, ofstream& output){
  ifstream input (fileName);

  if (input.is_open()){
    int lineCount = 0;
    int charCount = 0;
    double mean = 0.0;
    double standardDeviation = 0.0;
    double variance = 0.0;
    int numA = 0;
    int numT = 0;
    int numC = 0;
    int numG = 0;
    int numAA = 0;
    int numAT = 0;
    int numAC = 0;
    int numAG = 0;
    int numTA = 0;
    int numTT = 0;
    int numTC = 0;
    int numTG = 0;
    int numCA = 0;
    int numCT = 0;
    int numCC = 0;
    int numCG = 0;
    int numGA = 0;
    int numGT = 0;
    int numGC = 0;
    int numGG = 0;
    int numBigrams = 0;
    int numNucleotides = 0;
    string line;

    while (getline(input,line)){
      lineCount++;
      for (int i = 0; i < line.length(); i++){
        line[i] = toupper(line[i]);
        switch(line[i]){ //This block computes the number of each nucleotide
          case 'A':
            numA++;
            numNucleotides++;
            break;
          case 'T':
            numT++;
            numNucleotides++;
            break;
          case 'C':
            numC++;
            numNucleotides++;
            break;
          case 'G':
            numG++;
            numNucleotides++;
            break;
        }
        if ((i+1) <= line.length()){ //This block computes the number of each bigram
          line[i+1] = toupper(line[i+1]);
          string temp = "aa";
          temp[0] = line[i];
          temp[1] = line[i+1];
          if (temp == "AA"){
            numAA++;
            numBigrams++;
          } else if (temp == "AT"){
            numAT++;
            numBigrams++;
          } else if (temp == "AC"){
            numAC++;
            numBigrams++;
          } else if (temp == "AG"){
            numAG++;
            numBigrams++;
          } else if (temp == "TA"){
            numTA++;
            numBigrams++;
          } else if (temp == "TT"){
            numTT++;
            numBigrams++;
          } else if (temp == "TC"){
            numTC++;
            numBigrams++;
          } else if (temp == "TG"){
            numTG++;
            numBigrams++;
          } else if (temp == "CA"){
            numCA++;
            numBigrams++;
          } else if (temp == "CT"){
            numCT++;
            numBigrams++;
          } else if (temp == "CC"){
            numCC++;
            numBigrams++;
          } else if (temp == "CG"){
            numCG++;
            numBigrams++;
          } else if (temp == "GA"){
            numGA++;
            numBigrams++;
          } else if (temp == "GT"){
            numGT++;
            numBigrams++;
          } else if (temp == "GC"){
            numGC++;
            numBigrams++;
          } else if (temp == "GG"){
            numGG++;
            numBigrams++;
          }
        }
      }
    }

    mean = numNucleotides/lineCount; //Computes the mean
    input.close();
    input.open(fileName);
    while (getline(input,line)){ //Computes the variance
      int temp;
      temp = line.length() - mean;
      variance = variance + pow(temp,2);
    }
    variance = variance/lineCount;
    standardDeviation = sqrt(variance); //Computes standard deviation
    output << "Statistics for file: " << fileName << endl;
    output << "Total number of nucleotides: " << numNucleotides << endl;
    output << "Average length of each DNA strand: " << mean << endl;
    output << "Variance: " << variance << endl;
    output << "Standard Deviation: " << standardDeviation << endl;
    output << "Percentage of nucleotide A: " << (numA*100.0)/numNucleotides << endl;
    output << "Percentage of nucleotide T: " << (numT*100.0)/numNucleotides << endl;
    output << "Percentage of nucleotide C: " << (numC*100.0)/numNucleotides << endl;
    output << "Percentage of nucleotide G: " << (numG*100.0)/numNucleotides << endl;
    output << "Chance of AA Bigram: " << (numAA*100.0)/numBigrams << "%\n";
    output << "Chance of AT Bigram: " << (numAT*100.0)/numBigrams << "%\n";
    output << "Chance of AC Bigram: " << (numAC*100.0)/numBigrams << "%\n";
    output << "Chance of AG Bigram: " << (numAG*100.0)/numBigrams << "%\n";
    output << "Chance of TA Bigram: " << (numTA*100.0)/numBigrams << "%\n";
    output << "Chance of TT Bigram: " << (numTT*100.0)/numBigrams << "%\n";
    output << "Chance of TC Bigram: " << (numTC*100.0)/numBigrams << "%\n";
    output << "Chance of TG Bigram: " << (numTG*100.0)/numBigrams << "%\n";
    output << "Chance of CA Bigram: " << (numCA*100.0)/numBigrams << "%\n";
    output << "Chance of CT Bigram: " << (numCT*100.0)/numBigrams << "%\n";
    output << "Chance of CC Bigram: " << (numCC*100.0)/numBigrams << "%\n";
    output << "Chance of CG Bigram: " << (numCG*100.0)/numBigrams << "%\n";
    output << "Chance of GA Bigram: " << (numGA*100.0)/numBigrams << "%\n";
    output << "Chance of GT Bigram: " << (numGT*100.0)/numBigrams << "%\n";
    output << "Chance of GC Bigram: " << (numGC*100.0)/numBigrams << "%\n";
    output << "Chance of GG Bigram: " << (numGG*100.0)/numBigrams << "%\n";
    output << endl;
    output << "The following are 1000 strings generated based on the stats above: \n";

    int perA = (numA*100)/numNucleotides;
    int perT = (numT*100)/numNucleotides;
    int perC = (numC*100)/numNucleotides;
    int perG = (numG*100)/numNucleotides;
    int x = perA + perT;
    int y = x + perC;
    default_random_engine generator;
    normal_distribution<double> distribution(mean,standardDeviation);
    srand(time(0));

    //This block generates the strings based on the mean, standard deviation, and Percentage of each nucleotide
    for (int i = 1; i <= 1000; i++){
      string newLine = "";
      int length = (int)(distribution(generator) + 0.5);
      for (int n = 1; n <= length; n++){
        int seed = rand() % 100 + 1;
        if (seed <= perA){
          newLine = newLine + "A";
        } else if (seed > perA && seed <= x){
          newLine = newLine + "T";
        } else if (seed > x && seed <= y){
          newLine = newLine + "C";
        } else {
          newLine = newLine + "G";
        }
      }
      output << newLine << endl;
    }

    input.close();
  } else {
    cout << "Cannot open file.\n";
  }
}

//The main function which is used just to interact with the user
int main(int argc, char* argv[]) {
  ofstream file ("SebastianBrumm.out");
  file << "Name: Sebastian Brumm\n";
  file << "ID: 2319132\n";
  file << "Date: 9/14/19\n";
  file << "Assignment 1\n";
  file << "Section 01\n";
  file << endl;
  processData(argv[1],file);
  cout << "File processed and outputted to SebastianBrumm.txt\n";
  char answer = 'y';
  string name;
  while (answer == 'y'){
    cout << "Would you like to process another file?(y/n)\n";
    cin >> answer;
    if (answer == 'y'){
      cout << "What is the name of the file and please include extension: \n";
      cin >> name;
      processData(name,file);
      cout << "File processed and outputted to SebastianBrumm.txt\n";
    }
  }

  file.close();
  return 0;
}
