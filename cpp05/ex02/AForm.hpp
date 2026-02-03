/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:17:38 by astefane          #+#    #+#             */
/*   Updated: 2026/02/03 16:00:19 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm(const std::string& name, int gSign, int gExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string	getName() const;
		bool 		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		
		void		beSigned(const Bureaucrat& b);
		void		execute(Bureaucrat const& executor) const;

	class	GradeTooHighExpection : public std::exception
	{
		public:
			const char* what() const throw();
	};
	
	class	GradeTooLowExpection : public std::exception
	{
		public:
			const char* what() const throw();
	};
	
	class	FormNotSignedExpection : public std::exception
	{
		public:
			const char* what() const throw();	
	};

	protected:
		virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif