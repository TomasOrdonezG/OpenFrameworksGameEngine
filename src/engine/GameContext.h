#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include "Canvas.h"
#include "EngineContext.h"

class GameContext {
public:
    GameContext(EngineContext &e, Canvas &c) : engine(e), canvas(c) {}

    EngineContext &engine;
    Canvas &canvas;

    float dt = 0.0f;
    float time = 0.0f;
};

#endif
