#pragma once

#include "framework.h"

class LinePlot
{
public:
    /// @brief Creates a line plot 
    /// @param name Name of plot
    /// @param x Array of x data
    /// @param y Array of y data
    /// @param length Number of data points to plot
    /// @param size Size of plotting space
    /// @param flags ImPlot flags
    LinePlot(const char *name, const float *x, const float *y, int length, const ImVec2 &size = ImVec2(-1, 0), ImPlotFlags flags_x = 0, ImPlotFlags flags_y = 0);

    ~LinePlot();
};