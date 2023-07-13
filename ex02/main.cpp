/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:52 by zwong             #+#    #+#             */
/*   Updated: 2023/07/13 13:44:01 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Same stuff, just another Derived Class with new function() and different print messages
int main (void) {
	ClapTrap jessy = ClapTrap("Jessy");
	FragTrap lilo = FragTrap("Lilo");

	jessy.status();
	lilo.status();
	
	std::cout << GREEN << std::endl << "--- THE TURN OF EVENTS ---" << std::endl << std::endl;
	
	lilo.highFivesGuys();
	jessy.attack(lilo);
	jessy.attack(jessy);
	lilo.attack(jessy);
	lilo.attack(jessy);
	lilo.attack(jessy);
	lilo.attack(jessy);
	lilo.status();
	lilo.beRepaired(20);
	
	std::cout << DEFAULT << std::endl;
}
