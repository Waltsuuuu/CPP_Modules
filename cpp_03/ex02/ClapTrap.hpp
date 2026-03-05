#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	protected: // Changed to protected so derived classes can access.
		std::string	_name;		
		int			_hitPoints;		// 10
		int			_energyPoints;	// 10
		int			_attackDamage;	// 0

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator = (const ClapTrap& other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif