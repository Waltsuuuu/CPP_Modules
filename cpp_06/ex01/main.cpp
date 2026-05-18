#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main()
{
	Data* data = new Data;

	data->id = 1;
	data->content = "Is my data secure?";

	std::cout << "DATA BEFORE SERIALIZATION" << std::endl;
	std::cout << "Address: " << data << std::endl;
	std::cout << "id: " << data->id << std::endl;
	std::cout << "content: " << data->content << std::endl;

	uintptr_t serialized_data = Serializer::serialize(data);

	std::cout << "\nSERIALIZED VALUE" << std::endl;
	std::cout << serialized_data << std::endl;

	Data* deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "\nDATA AFTER DESERIALIZATION" << std::endl;
	std::cout << "Address: " << deserialized_data << std::endl;
	std::cout << "id: " << deserialized_data->id << std::endl;
	std::cout << "content: " << deserialized_data->content << std::endl;

	std::cout << "\nPOINTER COMPARISON" << std::endl;

	if (data == deserialized_data)
		std::cout << "SUCCESS: pointers match" << std::endl;
	else
		std::cout << "FAILURE: pointers do not match" << std::endl;

	delete data;

	return (0);
}