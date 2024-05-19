//
//  add id method.cpp
//  zoo management
//
//  Created by yanzhen li on 19/5/2024.
//

#include <stdio.h>
int Zoo::generateUniqueID() {
    int id;
    do {
        id = std::rand(); // Generate a random ID
    } while (usedAnimalIDs.find(id) != usedAnimalIDs.end()); // Check if the ID is already used
    usedAnimalIDs.insert(id); // Mark the ID as used
    return id; // Return the unique ID
}
int Zoo::addAnimal(Animal* animal, Enclosure* enclosure) {
    int id = generateUniqueID();
    animal->setID(id); // Set the unique ID to the animal
    enclosure->addAnimal(animal); // Add the animal to the enclosure
    return id;
}
