#pragma once
#include "imgui.h"
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/range/adaptor/transformed.hpp>


using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::setw;

namespace Demo{
struct Student{
    char _class;
    int _id;
    Student(const string& s): _class(s.front()), _id(stoi(s.substr(1))){};
    bool operator>(const Student& b){
        if(_class == b._class){
            return _id < b._id;  //( "A123" < "A022" ) = 1
        }
        else return _class > b._class;//( "B034" > "A022" ) = 1
    }
    friend std::ostream& operator<<(std::ostream& out, Student& v) {
        out.fill('0');
        out << v._class << setw(3) << v._id;
        return out;
    }
};
class InsertionSort {
   public:
    // Constructors
    InsertionSort();

    void Render();
    vector<string> Sort();

   private:
    vector <Student> students;
};
}