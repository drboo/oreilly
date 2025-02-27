/**************************************************************************************************
*
* \file Prototype.cpp
* \brief C++ Training - Example for the Prototype Design Pattern
*
* Copyright (C) 2015-2023 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Discuss the advantages and disadvantages of the given implementation of the classic
*       Prototype design pattern.
*
**************************************************************************************************/

#include <memory>
#include <cstdlib>
#include <iostream>


//---- <Animal.h> ---------------------------------------------------------------------------------

class Animal
{
 public:
   virtual ~Animal() = default;
   virtual void makeSound() const = 0;
   virtual std::unique_ptr<Animal> clone() const = 0;
};


//---- <Dog.h> ------------------------------------------------------------------------------------

class Dog : public Animal
{
 public:
   void makeSound() const override;
   std::unique_ptr<Animal> clone() const override;
};


//---- <Dog.cpp> ----------------------------------------------------------------------------------

void Dog::makeSound() const
{
   std::cout << " Dog::makeSound():  bark!\n";
}

std::unique_ptr<Animal> Dog::clone() const
{
   std::cout << " Dog::clone()\n";
   return std::make_unique<Dog>(*this);
}


//---- <Cat.h> ------------------------------------------------------------------------------------

class Cat : public Animal
{
 public:
   void makeSound() const override;
   std::unique_ptr<Animal> clone() const override;
};


//---- <Cat.cpp> ----------------------------------------------------------------------------------

void Cat::makeSound() const
{
   std::cout << " Cat::makeSound():  meow\n";
}

std::unique_ptr<Animal> Cat::clone() const
{
   std::cout << " Cat::clone()\n";
   return std::make_unique<Cat>(*this);
}


//---- <Main.cpp> ---------------------------------------------------------------------------------

int main()
{
   std::unique_ptr<Animal> dog( std::make_unique<Dog>() );
   std::unique_ptr<Animal> cat( std::make_unique<Cat>() );

   std::unique_ptr<Animal> dog2( dog->clone() );
   dog2->makeSound();

   std::unique_ptr<Animal> cat2( cat->clone() );
   cat2->makeSound();

   return EXIT_SUCCESS;
}
