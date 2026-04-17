#pragma once

#include "ICanvas.hpp"

class ICanvasDrawable
{
public:
    virtual void Draw(ICanvas& canvas) = 0;

    ~ICanvasDrawable() = default;
};
