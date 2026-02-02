/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormmain.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:03:51 by astefane          #+#    #+#             */
/*   Updated: 2026/02/02 20:22:29 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORMMAIN_HPP
# define ROBOTOMYREQUESTFORMM_HPP
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestFormmain : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestFormmain();
		RobotomyRequestFormmain(const std::string& target);
		RobotomyRequestFormmain(const RobotomyRequestFormmain& other);
		RobotomyRequestFormmain& operator=(const RobotomyRequestFormmain& other);
		~RobotomyRequestFormmain();
		void	executionAction() const;
};


#endif
