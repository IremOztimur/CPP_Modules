/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:09:53 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/07 16:03:43 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	{
		std::cout << std::endl;
		Data* originalPtr = new Data;
		originalPtr->name = "Irem Oztimur";
		originalPtr->age = 25;

		Serializer serializer;
		uintptr_t serialized = serializer.serialize(originalPtr);

		Data* deserializedPtr = serializer.deserialize(serialized);

		if (deserializedPtr == originalPtr) {
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << GREEN << "Serialization and deserialization successful. Values match." << RESET << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
		}
		else {
			std::cout << RED << "Serialization and deserialization failed. Values do not match."<< RESET << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;

		delete originalPtr;

	}

	{
		int _int = 42;

		char *implicit_serialized = (char *)&_int;
		int *implicit_deserialized = (int *)implicit_serialized;

		std::cout << "Implicitly serialized value: " << *implicit_serialized << std::endl;
		std::cout << "Implicitly deserialized value: " << *implicit_deserialized << std::endl;
		std::cout << "Implicitly serialized address: " << implicit_serialized << std::endl;
		std::cout << "Implicitly deserialized address: " << implicit_deserialized << std::endl;

		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << std::endl;

		char *serialized = reinterpret_cast<char *>(&_int);
		int *deserialized = reinterpret_cast<int *>(serialized);

		std::cout << "Explicitly serialized value: " << *serialized << std::endl;
		std::cout << "Explicitly dserialized value: " << *deserialized << std::endl;
		std::cout << "Explicitly serialized address: " << serialized << std::endl;
		std::cout << "Explicitly dserialized address: " << deserialized << std::endl;

	}

	{
		std::cout << std::endl;
		Data* originalPtr = new Data;
		originalPtr->name = "Marvin Robot";
		originalPtr->age = 12893;

		Serializer serializer;
		uintptr_t serialized = serializer.serialize(originalPtr);

		Data* deserializedPtr = serializer.deserialize(serialized);
		std::cout << &serialized << std::endl;
		std::cout << originalPtr << std::endl;
		std::cout << deserializedPtr << std::endl;
		std::cout << deserializedPtr->name << std::endl;
		std::cout << originalPtr->name << std::endl;
	}
	return (0);
}
