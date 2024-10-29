#pragma once

#include "framework.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stb_image.h>

class Image
{
public:
    /// @brief Loads the image at the given path. I pretty much just copied most of this from the internet and so I don't really understand any of it
    /// @param filename path
    /// @param texture I honestly don't know what this does 
    /// @param width Width of the image
    /// @param height Height of the image
    Image(const char *filename, GLuint texture = 0, int width = 0, int height = 0);


    /// @brief Called in LoadTextureFromFile(), beyond what is said in its name I don't know what it does
    /// @param data 
    /// @param data_size 
    /// @param out_texture 
    /// @param out_width 
    /// @param out_height 
    /// @return 
    bool LoadTextureFromMemory(const void *data, size_t data_size, GLuint *out_texture, int *out_width, int *out_height);


    /// @brief Loads a texture from a file I guess
    /// @param file_name 
    /// @param out_texture 
    /// @param out_width 
    /// @param out_height 
    /// @return 
    bool LoadTextureFromFile(const char *file_name, GLuint *out_texture, int *out_width, int *out_height);

    /// @brief Displays the previously loaded image
    void dispImage();

public:
    int width_;
    int height_;
    GLuint texture_;
    const char *path;
};