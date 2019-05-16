#include <iostream>
#include <utility> // for Pairs
#include <sstream> // to take in words from a string
#include <vector>
#include <map>
#include <fstream>
#include <string>


int main() {

  std::map<std::string, std::vector<std::pair<int,int>>> m;
  std::ifstream in;
  in.open("input.txt");

  std::string oneWord, line;
  int lc = 0, wc = 0; // linecount, wordcount,
  std::vector<std::pair<int,int>> u;

  // Print the entire file
  while(std::getline(in,line)){
    lc++;
    // Extract one word from the string
    std::istringstream words(line);
    while(words >> oneWord){
      wc++;
      u = m[oneWord];
      u.push_back(std::make_pair(lc,wc));
      m.erase(oneWord);
      m.insert(std::make_pair(oneWord, u));

    }
    wc = 0; // reset wordcount

  }


  // Print
  for(auto i = m.begin(); i != m.end(); i++){
    std::cout<< i->first << " " << i->second.size() << " [" ;
      for(auto j = i->second.begin(); j != i->second.end(); j++)
        std::cout << "(" << j->first << "," << j->second << ")"; 
      std::cout << "]" << std::endl;
  }

  
}