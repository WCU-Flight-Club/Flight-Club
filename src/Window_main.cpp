#include "Window_main.h"

Window_main::Window_main(std::vector<Image> images)
{
    if (window_1)
    {
        static float xs1[1001], ys1[1001];
        for (int i = 0; i < 1001; ++i) {
            xs1[i] = i * 0.001f;
            ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 10));
        }

        SET_WIN_ORIGIN;
        SET_WIN_SIZE;
        SET_COLOR_BLACK;
        ImGui::Begin("Flight Club", &window_1, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration);

        if (ImGui::Button("Reset plot"))
        {
            LinePlot plot("plot", xs1, ys1, 1001, ImVec2(-1, 0), PLOT_TO_ORIGIN_FLAG, PLOT_TO_ORIGIN_FLAG);
        }
        else
        {
            LinePlot plot("plot", xs1, ys1, 1001, ImVec2(-1, 0));
        }

        // TODO: Figure out how to scale and rotate images 
        // The image 'R1.png' is to rotate according data of the tilt of the rocket in air
        // Have the WCU Flight Club logo in one of the corners of the screen 

        //images[0].dispImage();

        ImGui::End();
        ImGui::PopStyleColor();
    }
}


