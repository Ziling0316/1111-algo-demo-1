#include "shell_sort.h"

namespace Demo {

    ShellSort::ShellSort() {}

    vector<string> ShellSort::Sort() {
        vector<string> res;
        vector<int> origin_nums;
        int h = 1;
        do {
            h = h*3+1; //找到比N大的最小值
        } while(h <= nums.size());

        for (int interval = h / 3; interval > 0; interval /= 3) {
            origin_nums = nums;
            for (int i = interval; i < nums.size(); i++) {
            int temp = nums[i];
            int j;
            for (j = i; j >= interval && nums[j - interval] > temp; j -= interval) {
                nums[j] = nums[j - interval];
            }
            nums[j] = temp;
            }
            h/=3;
            auto fmt = boost::format("\nh = %1$d\n") % h;
            res.push_back(fmt.str());
            res.push_back("\nOriginal Series:\n");
            res.push_back("");
            for(int i = 0; i < nums.size(); i++) {
                if(i == nums.size()-1) {
                    res.back() += to_string(origin_nums[i]);
                } else {
                    res.back() += to_string(origin_nums[i]) + ',';
                }
                if(i%h == h-1) {
                    res.push_back("");
                }
            }
            res.push_back("\nSorted Series:\n");
            res.push_back("");
            for(int i = 0; i < nums.size(); i++){
                if(i == nums.size()-1) {
                    res.back() += to_string(nums[i]);
                } else {
                    res.back() += to_string(nums[i]) + ',';
                }
                if(i%h == h-1) {
                    res.push_back("");
                }
            }
        }
        return res;
    }

    void ShellSort::Render() {
        static char input[1024] =
            "551,19,7,73,84,61,79,472,27,0,3,18,12,10,67,99,49,111,20,14,78,94,59,214,95,41,107,489,666,777,88,999";
        static char h_input[10] = "";
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
}