#pragma once
#include "Synthesizer.h"

namespace Steinberg{
namespace Vst{
namespace PPSynth{

template<class Precision, int32 numChannels, int32 numOscillators, int32 numFilters, class ParameterStorage>
Synthesizer<Precision, numChannels, numOscillators, numFilters, ParameterStorage>::Synthesizer(float sampleRate, ParameterStorage* paramStorage){
	this->initOscillators();
	this->initFilters();
}

template <class Precision, int32 numChannels, int32 numOscillators, int32 numFilters, class ParameterStorage>
Synthesizer<Precision, numChannels, numOscillators, numFilters, ParameterStorage>::~Synthesizer() {
	// finalize oscillators
	for(int32 i = 0; i < numOscillators; i++){
		if(this->oscillators[i]) {
			delete this->oscillators[i];
		}
	}

	// finalize filters
	for(int32 i = 0; i < numFilters; i++){
		if(this->filters[i]){
			delete this->filters[i];
		}
	}
}


template<class Precision, int32 numChannels, int32 numOscillators, int32 numFilters, class ParameterStorage>
tresult Synthesizer<Precision, numChannels, numOscillators, numFilters, ParameterStorage>::process(ProcessData& data){

}

template <class Precision, int32 numChannels, int32 numOscillators, int32 numFilters, class ParameterStorage>
void Synthesizer<Precision, numChannels, numOscillators, numFilters, ParameterStorage>::initOscillators(float sampleRate, ParameterStorage* paramStorage) {
	// initialize oscillators
	for(int32 i = 0; i < numOscillators; i++){
		this->oscillators[i] = new Oscillator(paramStorage, sampleRate);
	}
}

template <class Precision, int32 numChannels, int32 numOscillators, int32 numFilters, class ParameterStorage>
void Synthesizer<Precision, numChannels, numOscillators, numFilters, ParameterStorage>::initFilters(float sampleRate, ParameterStorage* paramStorage) {
	// initialize filters
	for(int32 i = 0; i < numFilters; i++){
		this->filters[i] = new Filter(paramStorage, sampleRate);
	}
}

}
}
}