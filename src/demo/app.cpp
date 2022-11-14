#include<memory>
#include "app.h"

#include "canvas.h"
#include "convex_hull.h"
#include "shortest_path.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

namespace Demo {

void RenderApp() {
    ImGui::Begin("Demo");

    // static auto convexHull = std::make_unique<ConvexHull>();
    // static auto shortestPath = std::make_unique<ShortestPath>();
    static auto bubbleSort = std::make_unique<BubbleSort>();
    static auto insertionSort = std::make_unique<InsertionSort>();
    static auto selectionSort = std::make_unique<SelectionSort>();
    static auto shellSort = std::make_unique<ShellSort>();
    static auto quickSort = std::make_unique<QuickSort>();

    if (ImGui::BeginTabBar("Demo")) {
        if (ImGui::BeginTabItem("Bubble Sort")) {
            bubbleSort->Render();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Selection Sort")) {
            selectionSort->Render();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Shell Sort")) {
            shellSort->Render();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Insertion Sort")) {
            insertionSort->Render();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Quick Sort")) {
            quickSort->Render();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}

}  // namespace Demo