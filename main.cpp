#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  const string input = am.get("input");
  const string output = am.get("output");

  /*ifstream inputfile("input3.txt");
  ofstream outputfile("output.txt");*/
  ifstream inputfile(input);
  ofstream outputfile(output);

  if (!inputfile.is_open()) {
    cout << "File not found!" << endl;
    return 0;
  }
  bool isEmpty = inputfile.peek() == EOF;

  int word_count;
  string the_word;

  inputfile >> word_count;

  map<string, int> counter;

  for(int i = 0; i < word_count; i++){
    inputfile >> the_word;
    if(counter[the_word] == -1){
        counter[the_word] = 1;
    }
    else{
        counter[the_word]++;
    }
  }

  for(auto the_word: counter){
    outputfile << the_word.first << ": " << the_word.second << endl;
  }



  inputfile.close();
  outputfile.close();

  return 0;
}