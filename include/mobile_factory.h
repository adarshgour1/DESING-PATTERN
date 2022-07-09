#ifndef __MOBILE_FACTORY_H
#define __MOBILE_FACTORY_H

#include "log_timestamp.h"

namespace MobileFactory
{
    const short Android = 1;
    const short Iphone = 2;
    //--------------------Abstract Classes------------------------

    class ICamera
    {
    protected:
        short _megaPixel;

    public:
        virtual short camera_quality() = 0;
    };

    class ISize
    {
    protected:
        float _screenSize;

    public:
        virtual float mobile_size() = 0;
    };

    class IProcessor
    {
    protected:
        std::string _processorName;

    public:
        virtual std::string processor_type() = 0;
    };

    //----------------- Adroid Mobile Classes ----------------------

    class AndroidCamera : public ICamera
    {
    public:
        virtual short camera_quality();
    };

    class AndroidSize : public ISize
    {
    public:
        virtual float mobile_size();
    };

    class AndroidProcessor : public IProcessor
    {
    public:
        virtual std::string processor_type();
    };

    //----------------- Iphone Mobile Classes ----------------------

    class IphoneCamera : public ICamera
    {
    public:
        virtual short camera_quality();
    };

    class IphoneSize : public ISize
    {
    public:
        virtual float mobile_size();
    };

    class IphoneProcessor : public IProcessor
    {
    public:
        virtual std::string processor_type();
    };
    //------------------Factory Class---------------------------------
    class IMobile
    {
    public:
        virtual ICamera *create_camera() = 0;
        virtual ISize *get_mobile_size() = 0;
        virtual IProcessor *get_processor_details() = 0;
    };

    class AndroidMoble : public IMobile
    {
    public:
        ICamera *create_camera();
        ISize *get_mobile_size();
        IProcessor *get_processor_details();
    };

    class IphoneMoble : public IMobile
    {
    public:
        ICamera *create_camera();
        ISize *get_mobile_size();
        IProcessor *get_processor_details();
    };

    IMobile *get_mobile_type(const short type);

} // namespace MobileFactory

#endif //__MOBILE_FACTORY_H