#include "insertion_sort.h"

namespace Demo {

    InsertionSort::InsertionSort() {}

    vector<string> InsertionSort::Sort() {
        vector<string> res;
        boost::format fmt("%1$c%2$03d");
        int j;
        for(int i = 1; i < students.size(); i++){
            j = i;
            Student v = students[i];
            while(j>0 && students[j-1] > v){
                students[j] = students[j-1];
                j--;
            }
            students[j] = v;
            res.push_back(
                boost::join(
                    students | boost::adaptors::transformed(
                        [&fmt](Student x) {
                            fmt % x._class % x._id;
                            return fmt.str();
                        }
                    ), ",")
            );
        }
        return res;
    }


    void InsertionSort::Render() {
        static char input[1024] =
            "A053,Z102,B059,A016,C001,X060";
        ImGui::InputText("Input", input, sizeof(input));
        ImGui::SameLine();
        static vector<string> res;

        if (ImGui::Button("Start!")) {
            students.clear();
            stringstream ss(input);
            string s;
            while(getline(ss, s, ',')){
                students.emplace_back(s);
            }
            res = Sort();
        }
        for(auto& x : res) {
            ImGui::Text(x.c_str());
        }
    }
}