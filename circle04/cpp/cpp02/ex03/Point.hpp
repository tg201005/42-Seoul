/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:08:52 by tyi               #+#    #+#             */
/*   Updated: 2023/05/26 14:48:56 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP


#include "Fixed.hpp"
#include <iostream>

class Point{
    
    private:
        Fixed x;
        Fixed y;

    public:
        Point();
        Point(const Point &point);
        Point(const float x, const float y);
        ~Point();

        Point&  operator=(const Point &point);
        

        Fixed   getX() const;
        Fixed   getY() const;
};

std::ostream&   operator<<(std::ostream &out, const Point &point);

#endif