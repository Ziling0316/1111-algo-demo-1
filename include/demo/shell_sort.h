#pragma once
#include "imgui.h"
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/range/adaptor/transformed.hpp>

using namespace std;

namespace Demo {

class ShellSort {
   public:
    // Constructors
    ShellSort();

    void Render();
    vector<string> Sort();

   private:
    vector<int> nums;
};

}  // namespace Demo