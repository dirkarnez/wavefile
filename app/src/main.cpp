#include <iostream>
#include <reader.h>
#include <writer.h>

using namespace std;


int main() {
    const string file_name = "waveform.wav";

    const float sampleRate = 44100;
    const float bitDepth = 16;

    SineOscillator sineOscillator(440, 0.5, sampleRate);

    Writer writer(sampleRate, bitDepth);
    writer.write(file_name, [&sineOscillator]() { 
        return sineOscillator.process(); 
    });


    Reader reader;
    reader.read(file_name);


    return 0;
}