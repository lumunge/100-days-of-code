#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given a set of n segments {[a0 , b0 ], [a1 , b1 ], . . . , [an−1) , bn−1]} with integer coordinates on a line, 
 * find the minimum number m of points such that each segment contains at least one point. 
 * That is, find a set of integers X of the minimum size such that for any segment [a i , b i ] there is a point x ∈ X such
 * that ai ≤ x ≤ bi .
*/

//print vector pairs
void printPair(vector<pair<int, int>> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    cout << endl;
}
//print array elements
void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
//Sorting vector pair elements by their second coordinate
bool sortBySec(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
//return minimum points
void minPoints(vector<pair<int, int>> set, int n){
    vector<pair<int, int>> sortedSet;
    vector<int> coords;
    int i = 0;
    // Creating a vector pair with the coordinates
    for(int j = 0; j < set.size(); j++){
        sortedSet.push_back(make_pair(set[j].first, set[j].second));
    }
    //Sort coordinates based on their second values
    sort(sortedSet.begin(), sortedSet.end(), sortBySec);
    //looping while 0 < length of vector
    while(i < n){
        //Assigning the second number of a coordinate to comparator
        int comparator = sortedSet[i].second;
        //Adding the comparator to solution vector
        coords.push_back(comparator);
        //Incrementing i
        int p = i + 1;
        if(p >= n)
            break;
        //Assigning first digit of coordinate to compareTo
        int compareTo = sortedSet[p].first;
        //Loop while comparator is greater than compareTo
        while(comparator >= compareTo){
            p += 1;
            if(p >= n)
                break;
            //Assigning comparedTo to first coordinate
            compareTo = sortedSet[p].first;
        }
        i = p;
    }
    cout << coords.size() << endl;
    printArr(coords);
}

int main(){
    vector<pair<int, int>> set;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        int b;
        cin >> a >> b;
        set.push_back(make_pair(a, b));
    }
    minPoints(set, n);
    return 0;
}
