#ifndef ENGINE_CONTEXT_H
#define ENGINE_CONTEXT_H

#include <memory>

class GameObject;

class EngineContext {
public:
    virtual void addObject(std::shared_ptr<GameObject> obj) = 0;
};

#endif
