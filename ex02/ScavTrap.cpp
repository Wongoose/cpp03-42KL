/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:54 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:54:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default contructor called for ScavTrap" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_dmg_ = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "Name contructor called for ScavTrap" << std::endl;
	this->name_ = name;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_dmg_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "Copy contructor called for ScavTrap" << std::endl;
	this->name_ = copy.name_;
	this->hit_points_ = copy.hit_points_;
	this->energy_points_ = copy.energy_points_;
	this->attack_dmg_ = copy.attack_dmg_;
}

ScavTrap::~ScavTrap() {
	std::cout << "Default destructor called for ScavTrap: " << this->name_ << std::endl;
}

void ScavTrap::swap(ScavTrap &first, ScavTrap &second) {
	std::swap(first.name_, second.name_);
	std::swap(first.hit_points_, second.hit_points_);
	std::swap(first.energy_points_, second.energy_points_);
	std::swap(first.attack_dmg_, second.attack_dmg_);
}

ScavTrap &ScavTrap::operator=(ScavTrap other) {
	ScavTrap::swap(*this, other);
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->energy_points_ == 0) {
		std::cout << "ScavTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "ScavTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ScavTrap: " << this->name_ << " attacks " << target << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
}

void ScavTrap::attack(ClapTrap &target) {
	if (this->energy_points_ == 0) {
		std::cout << "ScavTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "ScavTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "ScavTrap: " << this->name_ << " attacks " << target.get_name() << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
	target.takeDamage(this->attack_dmg_);
}

void ScavTrap::guardGate() {
	if (this->energy_points_ == 0) {
		std::cout << "ScavTrap: " << this->name_ << " doesn't have enough energy to guard the gate!" << std::endl;
		return;
  	}
	this->energy_points_--;
    std::cout << "ScavTrap: " << this->name_ << " is now in Gate keeper mode!" << std::endl;
}