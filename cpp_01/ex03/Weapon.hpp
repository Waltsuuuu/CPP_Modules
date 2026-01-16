#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	private:
	std::string _type;

	public:
	Weapon( const std::string& type );

	// Returns const reference (Prevents caller from modifying, and ensures all users see the same weapon type)
	// Meaning if one object changes the weapon type, everyone holding that weapon sees the change.
	const std::string& getType() const;
	void	setType( const  std::string& type );
};

#endif