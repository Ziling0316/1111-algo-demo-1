#pragma once
#include "imgui.h"
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/range/adaptor/transformed.hpp>

using std::string;
using std::vector;
using std::stringstream;
using std::swap;
using std::getline;

namespace Demo {

class SelectionSort {
   public:
    // Constructors
    SelectionSort();

    void Render();
    vector<string> Sort();

   private:
    vector<int> nums;
};

}  // namespace Demo