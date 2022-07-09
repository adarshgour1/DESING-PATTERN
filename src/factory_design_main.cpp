#include "log_timestamp.h"
#include "toy_factory.h"

int main()
{
	for (int i = 1; i < 4; i++)
	{
		ToyFactory::Toy *toy = ToyFactory::get_toy_object(i);
		toy->prepare_parts();
		toy->combine_parts();
		toy->assemble_parts();
		toy->show_product(); 
	}

	Log1 << "\n";
	return EXIT_SUCCESS;
}