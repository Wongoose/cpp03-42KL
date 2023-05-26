/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:50 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:54:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class FragTrap : public ClapTrap {
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);

		// Destructor
		~FragTrap();

		// Operators
		FragTrap &operator=(FragTrap other);
		void swap(FragTrap &first, FragTrap &second);

		// Functions - Only these functions start with "FragTrap: " when called by this class.
		void attack(const std::string &target);
		void attack(ClapTrap& target);
		void highFivesGuys(void);
};

#endif