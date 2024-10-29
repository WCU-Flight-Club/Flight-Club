#pragma once

#include "framework.h"
#include "LinePlot.h"
#include "Image.h"

class Window_main
{
public:
    /// @brief Creates the main window
    /// @param images A vector of loaded images which can be then be used within the window
    Window_main(std::vector<Image> images = {0});

public:
    bool window_1 = true;
};