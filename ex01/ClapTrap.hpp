/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:36 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:54:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>
#include <iomanip>

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class ClapTrap {
	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap &operator=(ClapTrap other);
		void swap(ClapTrap &first, ClapTrap &second);

		// Functions
		void attack(const std::string &target);
		void attack(ClapTrap& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status(void);

		// Getters
		std::string get_name() const;
		int get_hitpoints() const;
		int get_energypoints() const;
		int get_attackdamage() const;

		// Setters
		void set_name(std::string const name);
		void set_hitpoints(int const hitpoints);
		void set_energypoints(int const energypoints);
		void set_attackdamage(int const attackdamage);

	protected:
		std::string name_;
		int hit_points_;
		int energy_points_;
		int attack_dmg_;
};

#endif