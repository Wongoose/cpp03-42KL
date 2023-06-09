/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:27 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:53:28 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
	ClapTrap alfons = ClapTrap("Alfons");
	ClapTrap berta = ClapTrap();
	berta.set_name("Berta");

	alfons.status();
	alfons.attack("something");
	alfons.set_attackdamage(4);
	
	std::cout << GREEN << std::endl << "--- Alfons attacks Berta, Berta heals to full ---" << std::endl << std::endl;
	alfons.attack(berta);
	berta.status();
	berta.beRepaired(3);
	berta.beRepaired(3);
	
	std::cout << RED << std::endl << "--- Alfons attacks Berta to death, Berta can't heal ---" << std::endl << std::endl;
	alfons.attack(berta);
	alfons.attack(berta);
	alfons.attack(berta);
	berta.beRepaired(3);
	
	std::cout << BLUE <<std::endl << "--- Copying Alfons into new ClapTrap Charlie ---" << std::endl << std::endl;
	ClapTrap charlie = alfons;
	charlie.status();
	charlie.set_name("Charlie");
	charlie.status();
	charlie.attack(alfons);
	
	std::cout << YELLOW << std::endl << "--- Setting Energy to 1 ---" << std::endl << std::endl;
	charlie.set_energypoints(1);
	charlie.status();
	charlie.attack(alfons);
	charlie.attack(alfons);
	alfons.attack(charlie);
	charlie.beRepaired(3);
	
	std::cout << DEFAULT << std::endl;
}
