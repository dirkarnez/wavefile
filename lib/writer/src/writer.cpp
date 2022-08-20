#include <iostream>
#include <fstream>
#include "writer.h"
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

SineOscillator::SineOscillator(float freq, float amp, float sampRate) : frequency(freq), amplitude(amp), sampleRate(sampRate)
{
    offset = 2 * M_PI * frequency / this->sampleRate;
};

float SineOscillator::process()
{
    auto sample = this->amplitude * sin(this->angle);
    angle += this->offset;
    return sample;
    // Asin(2pif/sr)
};

inline void writeToFile(std::ofstream &file, int value, int size)
{
    file.write(reinterpret_cast<const char *>(&value), size);
}

Writer::Writer(float sampRate, float bitDepth) : sampleRate(sampRate), bitDepth(bitDepth)
{
}

void Writer::write(const std::string file_name, std::function<float()> callback)
{
    int duration = 2;
    std::ofstream audioFile;
    audioFile.open(file_name, std::ios::binary);

    // Header chunk
    audioFile << "RIFF";
    audioFile << "----";
    audioFile << "WAVE";

    // Format chunk
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4);                                    // Size
    writeToFile(audioFile, 1, 2);                                     // Compression code
    writeToFile(audioFile, 1, 2);                                     // Number of channels
    writeToFile(audioFile, this->sampleRate, 4);                      // Sample rate
    writeToFile(audioFile, this->sampleRate * this->bitDepth / 8, 4); // Byte rate
    writeToFile(audioFile, this->bitDepth / 8, 2);                    // Block align
    writeToFile(audioFile, this->bitDepth, 2);                        // Bit depth

    // Data chunk
    audioFile << "data";
    audioFile << "----";

    int preAudioPosition = audioFile.tellp();

    auto maxAmplitude = pow(2, this->bitDepth - 1) - 1;

    for (int i = 0; i < sampleRate * duration; i++)
    {
        float sample = callback(); // sineOscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        writeToFile(audioFile, intSample, 2);
    }

    int postAudioPosition = audioFile.tellp();

    audioFile.seekp(preAudioPosition - 4);
    writeToFile(audioFile, postAudioPosition - preAudioPosition, 4);

    audioFile.seekp(4, std::ios::beg);
    writeToFile(audioFile, postAudioPosition - 8, 4);

    audioFile.close();
}