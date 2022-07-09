#include "toy_factory.h"
namespace ToyFactory
{
    void Car::assemble_parts()
    {
        Log1 << "Car is assembled";
    }

    void Car::combine_parts()
    {
        Log1 << "Car is combined";
    }

    void Car::prepare_parts()
    {
        Log1 << "Car Parts are prepared";
    }

    void Car::show_product()
    {
        Log1 << "Car is ready";
    }

    void Bus::assemble_parts()
    {
        Log1 << "Bus is assembled";
    }

    void Bus::combine_parts()
    {
        Log1 << "Bus is combined";
    }

    void Bus::prepare_parts()
    {
        Log1 << "Bus Parts are prepared";
    }

    void Bus::show_product()
    {
        Log1 << "Bus is ready";
    }

    void Plane::assemble_parts()
    {
        Log1 << "Plane is assembled";
    }

    void Plane::combine_parts()
    {
        Log1 << "Plane is combined";
    }

    void Plane::prepare_parts()
    {
        Log1 << "Plane Parts are prepared";
    }

    void Plane::show_product()
    {
        Log1 << "Plane is ready";
    }

    Toy *get_toy_object(short type)
    {
       Toy *toy;
        switch (type)
        {
        case 1:
            toy = new Car;
            break;

        case 2:
            toy = new Bus;
            break;
        case 3:
            toy = new Plane;
            break;
        default:
            toy = NULL;
            break;
        }

        return toy;
    }
} // namespace ToyFactory
