/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:48 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:54:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default contructor called for FragTrap" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_dmg_ = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "Name contructor called for FragTrap" << std::endl;
	this->name_ = name;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_dmg_ = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "Copy contructor called for FragTrap" << std::endl;
	this->name_ = copy.name_;
	this->hit_points_ = copy.hit_points_;
	this->energy_points_ = copy.energy_points_;
	this->attack_dmg_ = copy.attack_dmg_;
}

FragTrap::~FragTrap() {
	std::cout << "Default destructor called for FragTrap: " << this->name_ << std::endl;
}

void FragTrap::swap(FragTrap &first, FragTrap &second) {
	std::swap(first.name_, second.name_);
	std::swap(first.hit_points_, second.hit_points_);
	std::swap(first.energy_points_, second.energy_points_);
	std::swap(first.attack_dmg_, second.attack_dmg_);
}

FragTrap &FragTrap::operator=(FragTrap other) {
	FragTrap::swap(*this, other);
	return (*this);
}

void FragTrap::attack(const std::string &target) {
	if (this->energy_points_ == 0) {
		std::cout << "FragTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "FragTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "FragTrap: " << this->name_ << " attacks " << target << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
}

void FragTrap::attack(ClapTrap &target) {
	if (this->energy_points_ == 0) {
		std::cout << "FragTrap: " << this->name_ << " doesn't have enough energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points_ <= 0) {
		std::cout << "FragTrap: " << this->name_ << " is dead, can't attack!" << std::endl;
		return;
	}
	this->energy_points_--;
	std::cout << "FragTrap: " << this->name_ << " attacks " << target.get_name() << ", with " << this->attack_dmg_ << " points of damage!" << std::endl;
	target.takeDamage(this->attack_dmg_);
}

void FragTrap::highFivesGuys() {
	if (this->energy_points_ == 0) {
		std::cout << "FragTrap: " << this->name_ << " doesn't have enough energy to high five other guys!" << std::endl;
		return;
  	}
	this->energy_points_--;
    std::cout << "FragTrap: " << this->name_ << " YO GUYS WANNA HIGH FIVE?!" << std::endl;
}