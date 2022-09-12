#pragma once

#include "pch.h"

namespace Magma
{
    class IndexBuffer
    {
    public:
        IndexBuffer() = default;
        ~IndexBuffer();

        bool Load(void* data, uint32_t numIndices, uint8_t elementSize);
        void Delete();

        void Bind();
        void Unbind();
        
    private:
        GLuint bufferId;
    };
}