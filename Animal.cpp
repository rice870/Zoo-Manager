
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
#include "Animal.h"

Animal::Animal(int weight, string species, string diet, string name, string favourite_treat){
    this->fatigue = 0;
    this->happiness = 0;
    this->hunger = 0;
    this->weight = weight;
    this->species = species;
    this->diet = diet;
    this->name = name;
    this->favourite_treat = favourite_treat;
    this->posX = 0;
    this->posY = 0;
}

Animal::Animal():Animal(0, "", "", "", ""){}

void Animal::getFed(string food, int amountKg){
    if (diet==food){
        hunger -= amountKg;
        hunger = max(hunger, 0);
    }
    
    if (food==favourite_treat){
        hunger -= amountKg;
        hunger = max(hunger, 0);
        happiness += amountKg;
    }
};

void Animal::rest(){
    fatigue = 0;
}

void Animal::get_visited() {
    fatigue += 1;
}

void Animal::set_fatigue(int fatigue){
    this->fatigue = fatigue;
}

void Animal::set_hunger(int hunger){
    this->hunger = hunger;
}

void Animal::set_weight(int weight){
    this->weight = weight;
}

void Animal::set_fatigue(string species){
    this->species = species;
}

void Animal::set_diet(string diet){
    this->diet = diet;
}

void Animal::set_name(string name){
    this->name = name;
}

void Animal::set_favourite_treat(string favourite_treat){
    this->favourite_treat = favourite_treat;
}

void Animal::set_posX(int _posX) {
    posX = _posX;
}

void Animal::set_posY(int _posY) {
    posY = _posY;
}


int Animal::get_fatigue(){
    return fatigue;
}

int Animal::get_happiness(){
    return happiness;
}

int Animal::get_hunger(){
    return hunger;
}

int Animal::get_weight(){
    return weight;
}

string Animal::get_species(){
    return species;
}

string Animal::get_name(){
    return name;
}

string Animal::get_favourite_treat(){
    return favourite_treat;
}

int Animal::get_posX() {
    return posX;
}

int Animal::get_posY() {
    return posY;
}