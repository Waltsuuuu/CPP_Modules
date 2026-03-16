#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

static void test_direct_objects()
{
    separator("DIRECT OBJECT CALL");

    // The compiler knows the exact type.
    // It directly calls the correct makeSound().
    std::cout << "--- Construction ---\n" << std::endl;

    Animal animal;
    std::cout << std::endl;

    Dog dog;
    std::cout << std::endl;

    Cat cat;
    std::cout << std::endl;

    std::cout << "--- Sound test ---\n" << std::endl;

    animal.makeSound();
    dog.makeSound();
    cat.makeSound();

    std::cout << "\n--- End of test ---\n" << std::endl;
}

static void test_subject_pdf()
{
    separator("SUBJECT TEST (BASE CLASS POINTERS)");

    // Base class pointers pointing to different objects.
    // Because makeSound() is virtual, the correct function
    // is chosen based on the object's real type at runtime.

    std::cout << "--- Construction ---\n" << std::endl;

    const Animal* meta = new Animal();
    std::cout << std::endl;

    const Animal* j = new Dog();
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "--- Types ---\n" << std::endl;

    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "j type:    " << j->getType() << std::endl;
    std::cout << "i type:    " << i->getType() << std::endl;

    std::cout << "\n--- Sound test ---\n" << std::endl;

    meta->makeSound();
    j->makeSound();
    i->makeSound();

    std::cout << "\n--- Destruction ---\n" << std::endl;

    delete meta;
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;
}

static void test_wrong_animal()
{
    separator("WRONGANIMAL (NO VIRTUAL)");

    // makeSound() is not virtual in WrongAnimal.
    // Even though the object is WrongCat,
    // the base version is called.

    std::cout << "--- Construction ---\n" << std::endl;

    const WrongAnimal* wrong = new WrongCat();
    std::cout << std::endl;

    std::cout << "--- Type ---\n" << std::endl;
    std::cout << "type: " << wrong->getType() << std::endl;

    std::cout << "\n--- Sound test ---\n" << std::endl;

    wrong->makeSound();

    std::cout << "\n--- Destruction ---\n" << std::endl;

    delete wrong;
}

int main()
{
    test_direct_objects();
    test_subject_pdf();
    test_wrong_animal();

    return 0;
}