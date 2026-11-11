#ifndef OF_APP_H
#define OF_APP_H

#include "engine/GameEngine.h"
#include "ofBaseApp.h"

class ofApp : public ofBaseApp {
public:
    void setup();

    void update();
    void draw();

    void windowResized(int w, int h);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    GameEngine mEngine;
};

#endif
