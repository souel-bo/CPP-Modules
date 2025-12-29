/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:09:44 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/29 21:10:27 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;

    if (deserializedData == &data)
    {
        std::cout << "Deserialization successful: pointers match." << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed: pointers do not match." << std::endl;
    }

    return 0;
}