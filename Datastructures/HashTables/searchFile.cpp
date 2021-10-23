#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include "patternMatching.cpp"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::ios_base;

int main(int argc, char** argv){
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);
    PatternSearching search;
    std::ifstream ifs("README.md");
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    cout << search.hashSearch(content, "PSEUDOCODE") << endl;
    time(&end);
    double tt = double(end - start);
    cout << "searched in " << fixed << tt << setprecision(5) << " secs" << endl;
    return 0;
}
