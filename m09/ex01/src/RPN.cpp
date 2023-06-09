/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:48:12 by ewurstei          #+#    #+#             */
/*   Updated: 2023/06/09 15:03:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/RPN.hpp"

/* 
Get an RPN expression as input from the user.
Split the input by space and iterate through each element.
If the element is a number, we push it onto the stack.
If it's an operator, we pop two numbers from the stack, perform the operation, and push the result back onto the stack.
In the end, we should be left with one number on the stack, which is the result.
*/

RPN::RPN() {
	std::cout << GRN "RPN calculator active" NC << std::endl;
}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& rhs) {
	m_pile = rhs.m_pile;
	return *this;
}

RPN::~RPN() {
	std::cout << RED "RPN calculator disable" NC << std::endl;
}

double RPN::calculation(double arg1, double arg2, std::string sign) {
	if (sign == "+")
		return (arg1 + arg2);
	else if (sign == "-")
		return (arg1 - arg2);
	else if (sign == "*")
		return (arg1 * arg2);
	else if (sign == "/") {
		if (arg2 == 0)
			throw std::runtime_error("division by 0");
		return (arg1 / arg2);
	}
}

bool	isArgNumber(const std::string& arg) {
	std::istringstream ss(arg);
	double arg1;
	ss >> arg1;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}