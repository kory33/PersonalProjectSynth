#include "Oscillator.h"

namespace Steinberg{
namespace Vst{
namespace PPSynth{

Steinberg::Vst::PPSynth::Oscillator::Oscillator(ParameterContainer* paramStorage, double sampleRate){
	this->paramStorage = paramStorage;
	this->sampleRate = sampleRate;
}

}
}
}
