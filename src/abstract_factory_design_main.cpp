#include "log_timestamp.h"
#include "mobile_factory.h"

#define ANDRO 1

int main()
{

#ifdef ANDRO
    MobileFactory::IMobile *mob = MobileFactory::get_mobile_type(MobileFactory::Android);
#else
    MobileFactory::IMobile *mob = MobileFactory::get_mobile_type(MobileFactory::Iphone);
#endif

    MobileFactory::ICamera *cam = mob->create_camera();
    MobileFactory::ISize *size = mob->get_mobile_size();
    MobileFactory::IProcessor *procss = mob->get_processor_details();

    Log1 << "Camera Quality: " << cam->camera_quality();
    Log1 << "Mobile Screen Size: " << size->mobile_size();
    Log1 << "Processor: " << procss->processor_type();

    std::cout << std::endl;
    return EXIT_SUCCESS;
}