#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "ofShader.h"
#include <string>
#include <unordered_map>

class ShaderManager {
public:
    static ShaderManager &getInstance() {
        static ShaderManager instance;
        return instance;
    }

    ShaderManager(const ShaderManager &) = delete;
    ShaderManager &operator=(const ShaderManager &) = delete;
    ShaderManager(ShaderManager &&) = delete;
    ShaderManager &operator=(ShaderManager &&) = delete;

    /**
     * @brief	Registers and loads a shader or returns an already registered one
     * @param	name	    Shader name
     * @return	ofShader&	Reference to the shader object
     */
    ofShader &getShader(const std::string &name) {
        auto it = mShaders.find(name);
        if (it == mShaders.end()) {
            it = mShaders.emplace(name, ofShader()).first;
            it->second.load(name);
        }
        return it->second;
    }

private:
    ShaderManager() = default;
    ~ShaderManager() = default;

    std::unordered_map<std::string, ofShader> mShaders;
};

#endif
