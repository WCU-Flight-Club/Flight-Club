#include "LinePlot.h"

LinePlot::LinePlot(const char *name, const float *x, const float *y, int length, const ImVec2 &size, ImPlotFlags flags_x, ImPlotFlags flags_y)
{
    if (ImPlot::BeginPlot(name, size))
    {
        ImPlot::SetupAxes("x", "y", flags_x, flags_y);
        ImPlot::PlotLine("reee", x, y, length);
        ImPlot::EndPlot();
    }
}

LinePlot::~LinePlot()
{
}
