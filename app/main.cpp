#include<iostream>
#include<sstream>
#include <fstream>
#include<cmath>
#include<iomanip>
#include "../code/MessageDecoder.hpp"

using namespace std;


int main(int argc, char* argv[])
{
   if (argc < 2) {
        cout << "Usage: ./run_app <inputfilename>" << endl;
        return 0;
    } else {
        fstream inputFile(argv[1]);
        std::string jumbled_str;
        if(!inputFile.is_open()){
        cout << "Error: Could not open file."<< endl;
    }
      getline(inputFile, jumbled_str);
      stringstream str(jumbled_str);

      MessageDecoder decoder;

      decoder.generate_operator_queue(jumbled_str);
      string postfix = decoder.generate_postfix(jumbled_str);
      int answer = decoder.evaluate_postfix(postfix);
      cout << "Postfix Notation::" << postfix << endl;
      cout << "Final Answer::" << answer << endl;
      return 0;
    }
    
  return 0;
}