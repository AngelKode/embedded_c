#pragma once
#ifndef CLASSES
#define CLASSES


#include <iostream>
#include <string>
#include <string_view>

class Animal {
	private:
		std::string name;
		std::string raze;
		int age;
	public:
		Animal() = default;

		Animal(std::string name, std::string raze, int age) {
			this->name = name;
			this->raze = raze;
			this->age = age;
		};
		
		~Animal() {};
		
		void eat() {
			std::cout << "im eating" << std::endl;
		}

		int get_age() {
			return this->age;
		}
		
		std::string get_name() {
			return this->name;
		}
		
		std::string get_raze() {
			return this->raze;
		}
};

class Dog : public Animal {
	private:
		int x;
	public:
		void bark() {
			std::cout << "Barking \n";
		}
		Dog(std::string name, std::string raze, int age) : Animal(name, raze, age){}

		~Dog() {};

		friend std::ostream& operator<<(std::ostream& os, const Dog& other){
			os << "Probando " << &other.x << '\n';
			return os;
		}
};

#endif //CLASSES

