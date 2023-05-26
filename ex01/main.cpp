/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:38 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:54:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void) {
	ScavTrap dobby = ScavTrap("Dobby");
	ScavTrap elvis = ScavTrap("Elvis");

	dobby.status();
	elvis.status();
	
	std::cout << GREEN << std::endl << "--- Fight ---" << std::endl << std::endl;
	
	elvis.guardGate();
	dobby.attack(elvis);
	elvis.attack(dobby);
	dobby.attack(elvis);
	elvis.beRepaired(10);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	elvis.beRepaired(1000);
	dobby.status();
	elvis.status();
	
	std::cout << RED << std::endl << "--- Copying a dead ScavTrap ---" << std::endl << std::endl;
	ScavTrap fiona = elvis;
	fiona.status();
	fiona.beRepaired(50);
	fiona.set_name("Fiona");
	fiona.status();
	fiona.beRepaired(50);
	
	std::cout << BLUE <<std::endl << "--- ClapTrap vs Scavtrap ---" << std::endl << std::endl;
	ClapTrap gunther = ClapTrap("Gunther");
	gunther.status();
	gunther.attack(dobby);
	gunther.set_attackdamage(100);
	gunther.attack(dobby);
	
	std::cout << DEFAULT << std::endl;
}