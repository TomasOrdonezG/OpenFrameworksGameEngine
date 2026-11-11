#ifndef CANVAS_H
#define CANVAS_H

#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofConstants.h"
#include "ofPixels.h"
#include "ofTexture.h"
#include <cstring>

class Canvas {
public:
    void setup(int scale) {
        mScale = std::max(1, scale);
        resize(ofGetWidth(), ofGetHeight());
    }

    void resize(int windowW, int windowH) {
        int w = std::max(1, windowW / mScale);
        int h = std::max(1, windowH / mScale);
        if (w == static_cast<int>(mPixels.getWidth()) && h == static_cast<int>(mPixels.getHeight())) {
            return;
        }
        mPixels.allocate(w, h, OF_PIXELS_RGBA);
        mTexture.allocate(mPixels);
        mTexture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }

    void clear() { std::memset(mPixels.getData(), 0, mPixels.getTotalBytes()); }

    void setPixel(int x, int y, const ofColor &col) {
        if (x >= 0 && x < width() && y >= 0 && y < height()) {
            mPixels.setColor(x, y, col);
        }
    }

    void present() {
        mTexture.loadData(mPixels);
        mTexture.draw(0, 0, ofGetWidth(), ofGetHeight());
    }

    int width() const { return mPixels.getWidth(); }
    int height() const { return mPixels.getHeight(); }
    int scale() const { return mScale; }

    void setScale(int scale) {
        mScale = std::max(1, scale);
        resize(ofGetWidth(), ofGetHeight());
    }

private:
    ofPixels mPixels;
    ofTexture mTexture;
    int mScale = 1;
};

#endif
