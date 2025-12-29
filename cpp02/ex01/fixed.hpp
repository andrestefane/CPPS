/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:29:18 by astefane          #+#    #+#             */
/*   Updated: 2025/12/29 14:29:36 by astefane         ###   ########.fr       */
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
        fixed & operator=(const fixed &other);
        ~fixed();

        int		getRawBits(void) const;
        void	setRawBits(int const raw);
        float   toFloat(void) const;
		int		toInt(void)	const;

};

std::ostream& operator<<(std::ostream& out, const fixed& value);


#endif