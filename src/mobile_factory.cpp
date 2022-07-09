#include "mobile_factory.h"

namespace MobileFactory
{
    //-------------------------Android-----------------------------
    short AndroidCamera::camera_quality() {
        _megaPixel = 48;
        return _megaPixel;
    }

    float AndroidSize::mobile_size() {
        this->_screenSize = 10.2;
        return this->_screenSize;
    }

    std::string AndroidProcessor::processor_type() {
        this->_processorName = "Helio p100";
        return this->_processorName;
    }

    //-------------------------Iphone-----------------------------
    short IphoneCamera::camera_quality() {
        _megaPixel = 32;
        return _megaPixel;
    }

    float IphoneSize::mobile_size() {
        _screenSize = 5.6;
        return _screenSize;
    }

    std::string IphoneProcessor::processor_type() {
        _processorName = "Bhangar 10v";
        return _processorName;
    }

    //----------------------Camera------------------------------------
    ICamera *AndroidMoble::create_camera() {
        return new AndroidCamera;
    }
    
    ICamera *IphoneMoble::create_camera() {
        return new IphoneCamera;
    }

    //----------------------Size------------------------------------
    ISize *AndroidMoble::get_mobile_size() {
        return new AndroidSize;
    }

    ISize *IphoneMoble::get_mobile_size() {
        return new IphoneSize;
    }

    //----------------------Processor------------------------------------
    IProcessor *AndroidMoble::get_processor_details() {
        return new AndroidProcessor;
    }

    IProcessor *IphoneMoble::get_processor_details() {
        return new IphoneProcessor;
    }

    IMobile *get_mobile_type(const short type) {
        if(type == Android)
            return new AndroidMoble;
        else
            return new IphoneMoble;
    }

} // namespace MobileFactory
