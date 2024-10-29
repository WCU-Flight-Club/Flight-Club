#pragma once

#include <math.h>
#include <vector>

#include "../imgui_files/imgui.h"
#include "../imgui_files/imgui_impl_glfw.h"
#include "../imgui_files/imgui_impl_opengl3.h"
#include "../imgui_files/implot.h"

#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <glad/glad.h>
#include <GLFW/glfw3.h>// Will drag system OpenGL headers

#include "data.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif


#define SET_WIN_ORIGIN ImGui::SetNextWindowPos(ImVec2(0, 0))
#define SET_WIN_SIZE ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize)
#define PLOT_TO_ORIGIN_FLAG ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_RangeFit

#define SET_COLOR_BLACK ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f))

