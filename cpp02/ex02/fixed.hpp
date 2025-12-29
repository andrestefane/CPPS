/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:29:18 by astefane          #+#    #+#             */
/*   Updated: 2025/12/29 19:03:06 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class fixed
{
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    public:
        fixed();
        fixed(const int n);
        fixed(const float f);
        fixed(const fixed &other);
        ~fixed();
        fixed &operator=(const fixed &other);

        bool	operator>(const fixed &other) const;
		bool	operator<(const fixed &other) const;
		bool	operator>=(const fixed &other) const;
		bool	operator<=(const fixed &other) const;
		bool	operator==(const fixed &other) const;
		bool	operator!=(const fixed &other) const;

		fixed	operator+(const fixed &other) const;
		fixed	operator-(const fixed &other) const;
		fixed	operator/(const fixed &other) const;
		fixed	operator*(const fixed &other) const;

		fixed	&operator++();
		fixed	operator++(int);
		fixed	&operator--();
		fixed	operator--(int);

		static	fixed &min(fixed &a, fixed &b);
		static	fixed &max(fixed &a, fixed &b);
		static const fixed &min(const fixed &a, const fixed &b);
		static const fixed &max(const fixed &a, const fixed &b);


        int		getRawBits(void) const;
        void	setRawBits(int const raw);
        
		float   toFloat(void) const;
		int		toInt(void)	const;

};

std::ostream& operator<<(std::ostream& out, const fixed& value);


#endif