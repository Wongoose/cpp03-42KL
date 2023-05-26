/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:34 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:53:34 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default contructor called for ClapTrap" << std::endl;
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_dmg_ = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Name contructor called for ClapTrap" << std::endl;
	this->name_ = name;
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_dmg_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy contructor called for ClapTrap" << std::endl;
	this->name_ = copy.name_;
	this->hit_points_ = copy.hit_points_;
	this->energy_points_ = copy.energy_points_;
	this->attack_dmg_ = copy.attack_dmg_;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called for ClapTrap " << this->name_ << std::endl;
}

void ClapTrap::swap(ClapTrap &first, ClapTrap &second) {
	std::swap(first.name_, second.name_);
	std::swap(first.hit_points_, second.hit_points_);
	std::swap(first.energy_points_, second.energy_points_);
	std::swap(first.attack_dmg_, second.attack_dmg_);
}

ClapTrap &ClapTrap::operator=(ClapTrap other) {
	ClapTrap::swap(*this, other);
	return (*this);
}

// Functions
void ClapTrap::attack(const std::string &target) {
	if (this->energy_points_ == 0) {
		std::cout << "ClapTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "ClapTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap: " << this->name_ << " attacks " << target << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
}

void ClapTrap::attack(ClapTrap &target) {
	if (this->energy_points_ == 0) {
		std::cout << "ClapTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "ClapTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ClapTrap: " << this->name_ << " attacks " << target.name_ << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
	target.takeDamage(this->attack_dmg_);
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ == 0) {
		std::cout << "ClapTrap: " << this->name_ << " is already dead!" << std::endl;
		return;
	}
	this->hit_points_ -= amount;
	std::cout << "ClapTrap: " << this->name_ << " took " << amount << " points of damage!" << std::endl;
	if (this->hit_points_ <= 0) {
		this->hit_points_ = 0;
		std::cout << "ClapTrap: " << this->name_ << " just DIED!" << std::endl;
		return;
	}
	std::cout << "ClapTrap: " << this->name_ << " HP is [" << this->hit_points_ << "]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points_ == 0) {
		std::cout << "ClapTrap: " << this->name_ << " doesn't have enough energy to be repaired!" << std::endl;
		return;
	}
	if (this->hit_points_ == 0) {
		std::cout << "ClapTrap: " << this->name_ << " is already dead!" << std::endl;
		return;
	}
	this->hit_points_ += amount;
	this->energy_points_--;
	std::cout << "ClapTrap: " << this->name_ << " just repaired " << amount << " points of HP and now has " << this->hit_points_ << " HP!" << std::endl;
}

void ClapTrap::status(void) {
	std::cout << std::endl << "=======STATUS REPORT======" << std::endl;
	std::cout << "Name: " << this->name_ << std::endl;
	std::cout << "Hitpoints: " << this->hit_points_ << std::endl;
	std::cout << "Energy points: " << this->energy_points_ << std::endl;
	std::cout << "Attack damage: " << this->attack_dmg_ << std::endl;
	std::cout << std::endl;

}

// Getters
std::string ClapTrap::get_name() const {return (this->name_);}

int ClapTrap::get_hitpoints() const {return (this->hit_points_);}

int ClapTrap::get_energypoints() const {return (this->energy_points_);}

int ClapTrap::get_attackdamage() const {return (this->attack_dmg_);}

// Setters
void ClapTrap::set_name(std::string const name) {this->name_ = name;}

void ClapTrap::set_hitpoints(int const hitpoints) {this->hit_points_= hitpoints;}

void ClapTrap::set_energypoints(int const energypoints) {this->energy_points_ = energypoints;}

void ClapTrap::set_attackdamage(int const attackdamage) {this->attack_dmg_ = attackdamage;}
