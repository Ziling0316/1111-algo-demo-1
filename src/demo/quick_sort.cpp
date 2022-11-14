#include "quick_sort.h"

namespace Demo {

map<char, int> Card::suit_map{
{'H', 4},
{'S', 3},
{'D', 2},
{'C', 1}
};

map<char, int> Card::num_map{
    {'A', 14},{'a', 14},{'j', 11},{'J', 11},{'q', 12},{'Q', 12},{'k', 13},{'K', 13}
};

QuickSort::QuickSort() {}

void QuickSort::Sort(int left, int right, vector<string>& res) {
    if(left < right){
        int i = Partition(left, right);
        res.push_back(
            boost::join(
                nums | boost::adaptors::transformed(
                    [](Card x) {
                        return x._name;
                    }
                ), ",")
        );
        Sort(left, i-1, res);
        Sort(i+1, right, res);
    }
}

int QuickSort::Partition(int left, int right) {
    int i = left-1;
    Card v = nums[right];
    for(int j = left; j < nums.size(); j++){
        if(nums[j] < v) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    i++;
    swap(nums[i],nums[right]);
    return i;
}

void QuickSort::Render() {
    static char input[1024] =
        "C3,d5,hA,c5,sK,hj,s10";
    ImGui::InputText("Input", input, sizeof(input));
    ImGui::SameLine();
    static vector<string> res;

    if (ImGui::Button("Start!")) {
        nums.clear();
        stringstream ss(input);
        string s;
        while(getline(ss, s, ',')){
            nums.emplace_back(s);
        }
        Sort(0, nums.size()-1, res);
    }
    for(auto& x : res) {
        ImGui::Text(x.c_str());
    }
}

}