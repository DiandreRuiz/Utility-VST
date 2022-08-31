/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,true, 50, 20);
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setRange(-60.0f,0.0f,0.01f);
    mGainSlider.setValue(-20.0f);
    addAndMakeVisible(mGainSlider);
    mGainSlider.addListener(this);
    setSize (200, 300);
    
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void GainSliderAudioProcessorEditor::resized()
{
    
    mGainSlider.setBounds(getWidth()/2 - 50 ,getHeight()/2 - 75, 100, 150);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void GainSliderAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){

    if(slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
        
    }
    
    
}
