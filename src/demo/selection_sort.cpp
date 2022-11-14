#include "selection_sort.h"

//#include "demo_utils.h"

namespace Demo {

SelectionSort::SelectionSort() {}

vector<string> SelectionSort::Sort() {
    vector<string> res;
    int min, tmp;
    for(int i = 0; i < nums.size(); i++){
        min = i;
        for(int j = i+1; j < nums.size(); j++){
            if( nums[j] < nums[min]) min = j;
        }
        swap(nums[min], nums[i]);
        if(min != i) {
            res.push_back(
                boost::join(
                    nums | boost::adaptors::transformed([](int x) {
                        return std::to_string(x);}), ",")
            );
        }
    }
    return res;
}

void SelectionSort::Render() {
    static char input[1024] =
        "41,33,17,80,61,5,55";
    ImGui::InputText("Input", input, sizeof(input));
    ImGui::SameLine();
    static vector<string> res;

    if (ImGui::Button("Start!")) {
        nums.clear();
        stringstream ss(input);
        int n;
        while(ss >> n) {
            ss.ignore(50, ',');
            nums.push_back(n);
        }
        res = Sort();
    }
    for(auto& x : res) {
        ImGui::Text(x.c_str());
    }
}
}  // namespace Demo