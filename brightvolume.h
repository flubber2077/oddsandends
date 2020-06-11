class brightVolume {
private:
    float brightFreqConstant = 300.0f;
    float brightFreq;
    float brightGain;
    float volume;
    bool brightOn = true;
    float sampleRate;
    float inputResistance; //a ratio of the assumed potentiometer value, should be larger than zero. .05 is a good start. circuit will not have unity gain, should be used more as a gain control
    
    
public:
    float updateFreq() {
       return brightFreqConstant/ (volume+inputResistance);
    };
    updateSampleRate();
    processSample(float input){
        float highpass = input - lowpass(input);
        float output = input * volume/(1+inputResistance);
        if brightOn = true {
            output += highpass *volume/(volume+inputResistance);
        }
        return output;
    };
}
