#ifndef SETUP_H
#define SETUP_H

#include "../engine/GameObject.h"
#include <iostream>
#include <memory>

class Setup : public GameObject {
    void setup(GameContext &ctx) override {
        // TODO: ctx.engine.addObject(std::make_shared<Player>(...))
        std::cout << "set up\n";

        kill(ctx);
    }
};

#endif
