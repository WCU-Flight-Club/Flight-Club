#define STB_IMAGE_IMPLEMENTATION
#include "Image.h"

Image::Image(const char *filename, GLuint texture, int width, int height)
{
    path = filename;
    texture_ = texture;
    width_ = width;
    height_ = height;

    bool ret = Image::LoadTextureFromFile(path, &texture_, &width_, &height_);
    IM_ASSERT(ret);
}

bool Image::LoadTextureFromMemory(const void *data, size_t data_size, GLuint *out_texture, int *out_width, int *out_height)
{
        // Load from file
        int image_width = 0;
        int image_height = 0;
        unsigned char *image_data = stbi_load_from_memory((const unsigned char *)data, (int)data_size, &image_width, &image_height, NULL, 4);
        if (image_data == NULL)
            return false;

        // Create a OpenGL texture identifier
        GLuint image_texture;
        glGenTextures(1, &image_texture);
        glBindTexture(GL_TEXTURE_2D, image_texture);

        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Upload pixels into texture
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
        stbi_image_free(image_data);

        *out_texture = image_texture;
        *out_width = image_width;
        *out_height = image_height;

        return true;
}

bool Image::LoadTextureFromFile(const char *file_name, GLuint *out_texture, int *out_width, int *out_height)
{
        FILE *f = fopen(file_name, "rb");
        if (f == NULL)
            return false;
        fseek(f, 0, SEEK_END);
        size_t file_size = (size_t)ftell(f);
        if (file_size == (size_t)-1)
            return false;
        fseek(f, 0, SEEK_SET);
        void *file_data = IM_ALLOC(file_size);
        fread(file_data, 1, file_size, f);
        bool ret = LoadTextureFromMemory(file_data, file_size, out_texture, out_width, out_height);
        IM_FREE(file_data);
        return ret;
}

void Image::dispImage()
{
    ImGui::Image((ImTextureID)(intptr_t)texture_, ImVec2(width_, height_));
}
