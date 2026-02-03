/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:44:24 by astefane          #+#    #+#             */
/*   Updated: 2026/02/02 18:26:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP
# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include "AForm.hpp"



class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		const	std::string& getName() const;
		int		getGrade() const;
		
		void	incrementGrade();
		void 	executeForm(AForm const & form) const;
		void	signForm(AForm& f);
		void	decrementGrade();
		void	sumGrade(int sumeGrade);
		void	restGrade(int restGrade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
		std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif