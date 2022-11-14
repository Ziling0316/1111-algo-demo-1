#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include "imgui.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;
using std::ostream;
using std::swap;
using std::map;
using std::transform;

namespace Demo {


struct Card{
    char _suit;
    int _number;
    static map<char, int> suit_map;
    static map<char, int> num_map;
    string _name;
    Card( string& s ){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        _suit = toupper(s.front());
        _number = num_map[s.back()] ? num_map[s.back()] : stoi(s.substr(1));
        _name = s;
        };
    bool operator<(const Card& b){
        if(_suit == b._suit){
            return _number <b._number;}
        else { return suit_map[_suit] < suit_map[b._suit]; }
    }
    friend ostream& operator<<(ostream& out, Card& v){
        out << v._name;
        return out;
    }
};


class QuickSort {
   public:
    // Constructors
    QuickSort();

    void Render();
    int Partition(int left, int right);
    void Sort(int left, int right, vector<string>&);

   private:
    vector<Card> nums;
};

}