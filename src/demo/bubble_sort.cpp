#include "bubble_sort.h"
#include "demo_utils.h"

//#include "demo_utils.h"

namespace Demo {
BubbleSort::BubbleSort() {}
vector<string> BubbleSort::Sort() {
    vector<string> res;
    int flag, tmp;
    do {
        flag = 0;
        for(int i = 1; i < nums.size(); i++){
            if( nums[i] < nums[i-1] ){
                swap(nums[i-1], nums[i]);
                res.push_back(
                    boost::join(
                        nums | boost::adaptors::transformed([](int x) {
                            return std::to_string(x);}), ";")
                );
                flag = 1;
            }
        }
    } while(flag == 1);
    return res;
}
void BubbleSort::Render() {
    static char input[1024] =
        " 5 ;16 ; 7 ; 6; 19 ; 13;22 ; 0";
    ImGui::InputText("Input", input, sizeof(input));
    ImGui::SameLine();
    static vector<string> res;

    if (ImGui::Button("Start!")) {
        nums.clear();
        stringstream ss(input);
        int n;
        while(ss >> n){
            ss.ignore(50, ';');
            nums.push_back(n);
        }
        res = Sort();
    }
    for(auto& x : res) {
        ImGui::Text(x.c_str());
    }
}
}  // namespace Demo