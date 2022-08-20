#ifndef _WRITER_H_
#define _WRITER_H_

#include <iostream>
#include <functional>

class SineOscillator {
private:
    float frequency;
    float amplitude;
    float angle = 0.0f;
    float offset = 0.0f;
    float sampleRate;
public:
    SineOscillator(float freq, float amp, float sampRate);
    float process();
};

class Writer {
private:
    float sampleRate;
    float bitDepth;
public:
    Writer(float sampRate, float bitDepth);
    void write(const std::string file_name, std::function<float()> callback);
};

#endif