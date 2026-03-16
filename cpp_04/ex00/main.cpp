#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

static void test_subject_pdf_example()
{
    separator("TEST 1: SUBJECT-LIKE BASIC POLYMORPHISM");

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "j type:    " << j->getType() << std::endl;
    std::cout << "i type:    " << i->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
}

static void test_stack_polymorphism()
{
    separator("TEST 2: STACK OBJECTS + BASE REFERENCES");

    Dog dog;
    Cat cat;
    Animal animal;

    const Animal& a = dog;
    const Animal& b = cat;
    const Animal& c = animal;

    std::cout << "a type: " << a.getType() << std::endl;
    a.makeSound();

    std::cout << "b type: " << b.getType() << std::endl;
    b.makeSound();

    std::cout << "c type: " << c.getType() << std::endl;
    c.makeSound();
}

static void test_base_pointers_array()
{
    separator("TEST 3: ARRAY OF BASE POINTERS");

    const Animal* animals[6];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    animals[4] = new Dog();
    animals[5] = new Cat();

    for (int idx = 0; idx < 6; ++idx)
    {
        std::cout << "[" << idx << "] type = " << animals[idx]->getType() << " | sound = ";
        animals[idx]->makeSound();
    }

    for (int idx = 0; idx < 6; ++idx)
        delete animals[idx];
}

static void test_virtual_destructor()
{
    separator("TEST 4: DELETE THROUGH BASE POINTER");

    const Animal* a = new Dog();
    const Animal* b = new Cat();

    std::cout << "Deleting Dog as Animal*" << std::endl;
    delete a;

    std::cout << "Deleting Cat as Animal*" << std::endl;
    delete b;

    std::cout << "\nCheck output:" << std::endl;
    std::cout << "- Derived destructor should run before base destructor." << std::endl;
}

static void test_copy_constructors_and_assignment()
{
    separator("TEST 5: COPY CONSTRUCTOR / ASSIGNMENT");

    Dog originalDog;
    Dog copiedDog(originalDog);
    Dog assignedDog;
    assignedDog = originalDog;

    Cat originalCat;
    Cat copiedCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "originalDog type: " << originalDog.getType() << std::endl;
    std::cout << "copiedDog type:   " << copiedDog.getType() << std::endl;
    std::cout << "assignedDog type: " << assignedDog.getType() << std::endl;

    std::cout << "originalCat type: " << originalCat.getType() << std::endl;
    std::cout << "copiedCat type:   " << copiedCat.getType() << std::endl;
    std::cout << "assignedCat type: " << assignedCat.getType() << std::endl;

    std::cout << "\nSounds after copies:" << std::endl;
    copiedDog.makeSound();
    assignedDog.makeSound();
    copiedCat.makeSound();
    assignedCat.makeSound();
}

static void test_slicing()
{
    separator("TEST 6: OBJECT SLICING DEMO");

    Dog dog;
    Animal sliced = dog; // slicing on purpose

    std::cout << "dog type:    " << dog.getType() << std::endl;
    std::cout << "sliced type: " << sliced.getType() << std::endl;

    std::cout << "\nExpected:" << std::endl;
    std::cout << "- sliced is a real Animal object now, not a Dog." << std::endl;
    std::cout << "- sliced.makeSound() should call Animal::makeSound()." << std::endl;

    std::cout << "\nActual:" << std::endl;
    dog.makeSound();
    sliced.makeSound();
}

static void test_wrong_hierarchy_basic()
{
    separator("TEST 7: WRONG HIERARCHY");

    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* weird = new WrongCat();

    std::cout << "meta type:  " << meta->getType() << std::endl;
    std::cout << "weird type: " << weird->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    meta->makeSound();
    weird->makeSound();

    std::cout << "\nExpected:" << std::endl;
    std::cout << "- weird->getType() may say WrongCat" << std::endl;
    std::cout << "- but weird->makeSound() should call WrongAnimal::makeSound()" << std::endl;
    std::cout << "  if makeSound is NOT virtual in WrongAnimal." << std::endl;

    delete meta;
    delete weird;
}

static void test_wrong_hierarchy_reference()
{
    separator("TEST 8: WRONG HIERARCHY THROUGH REFERENCE");

    WrongCat wrongCat;
    const WrongAnimal& ref = wrongCat;

    std::cout << "ref type: " << ref.getType() << std::endl;
    std::cout << "ref sound: ";
    ref.makeSound();

    std::cout << "Expected: WrongAnimal sound, not WrongCat sound." << std::endl;
}

static void test_const_usage()
{
    separator("TEST 9: CONST CORRECTNESS");

    const Dog dog;
    const Cat cat;
    const Animal animal;

    std::cout << dog.getType() << std::endl;
    dog.makeSound();

    std::cout << cat.getType() << std::endl;
    cat.makeSound();

    std::cout << animal.getType() << std::endl;
    animal.makeSound();

    std::cout << "\nIf this test does not compile, check whether getType() and makeSound() are const." << std::endl;
}

int main()
{
    test_subject_pdf_example();
    test_stack_polymorphism();
    test_base_pointers_array();
    test_virtual_destructor();
    test_copy_constructors_and_assignment();
    test_slicing();
    test_wrong_hierarchy_basic();
    test_wrong_hierarchy_reference();
    test_const_usage();

    separator("END OF TESTS");
    return 0;
}