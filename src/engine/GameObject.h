#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "GameContext.h"

class GameObject {
public:
    GameObject() = default;
    GameObject(const GameObject &) = delete;
    GameObject &operator=(const GameObject &) = delete;
    GameObject(GameObject &&) = delete;
    GameObject &operator=(GameObject &&) = delete;

    virtual ~GameObject() = default;

    virtual void setup(GameContext &ctx) {}
    virtual void update(GameContext &ctx) {}
    virtual void draw(GameContext &ctx) {}

    virtual void kill(GameContext &ctx) { mIsAlive = false; }
    virtual bool isAlive() { return mIsAlive; }

    // virtual void gotMessage(Context &ctx, ofMessage msg);

    // virtual void keyPressed(Context &ctx, int key);
    // virtual void keyReleased(Context &ctx, int key);
    // virtual void mouseMoved(Context &ctx, int x, int y);
    // virtual void mouseDragged(Context &ctx, int x, int y, int button);
    // virtual void mousePressed(Context &ctx, int x, int y, int button);
    // virtual void mouseReleased(Context &ctx, int x, int y, int button);
    // virtual void mouseEntered(Context &ctx, int x, int y);
    // virtual void mouseExited(Context &ctx, int x, int y);
private:
    bool mIsAlive = true;
};

#endif
