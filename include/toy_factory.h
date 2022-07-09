#ifndef __TOY_FACTORY_H
#define __TOY_FACTORY_H

#include "log_timestamp.h"

/**
 * @brief This for example of factory design pattern 
 * here we are giving one function as interface 
 * ans on depend on input to that function object is return
 * user is unaware of inner implemantion
 * 
 * In future if any new type arrived you can simply add in class
 * any specific fuction to that class is also added
 * 
 */
namespace ToyFactory
{
    /**
     * @brief This act as Abstract for all derived class and each virtual function needs to be defined in that class
     * 
     */
    class Toy
    {
    protected:
        std::string _name;
        float _price;

    public:
        virtual void prepare_parts() = 0;
        virtual void combine_parts() = 0;
        virtual void assemble_parts() = 0;
        virtual void show_product() = 0;
    };

    class Car : public Toy
    {
        void prepare_parts();
        void combine_parts();
        void assemble_parts();
        void show_product();
    };
    class Bus : public Toy
    {
        void prepare_parts();
        void combine_parts();
        void assemble_parts();
        void show_product();
    };
    class Plane : public Toy
    {
        void prepare_parts();
        void combine_parts();
        void assemble_parts();
        void show_product();
    };

    Toy *get_toy_object(short type);
} // namespace ToyFactory

#endif //__TOY_FACTORY_H