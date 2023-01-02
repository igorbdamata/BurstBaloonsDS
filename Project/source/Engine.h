#pragma once
#include "Entity.h"

class Engine
{
public:
    Engine();
    void InitializeVideo();
    void UpdateScreens();
    void RenderInLowerScreen(Entity entity);
};