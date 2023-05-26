/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:11:40 by tyi               #+#    #+#             */
/*   Updated: 2023/05/26 14:52:53 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//vector point to point

typedef struct  s_vector{
    Fixed  x;
    Fixed   y;
}               Vector;

Vector get_Vector(Point const a, Point const b){
    return (Vector(b.getX() - a.getX(), b.getY() - a.getY()));
}

//"Create a function that calculates the angle formed by two vectors. 
//The function will return an int representing the angle in degrees.

Point calculates_angle_between_two_vectors(Vector v1, Vector v2){ 

    Point dotProduct = v1.x * v2.x + v1.y * v2.y;
    Point magnitudeProduct = std::sqrt(v1.x * v1.x + v1.y * v1.y) * std::sqrt(v2.x * v2.x + v2.y * v2.y);
    Point cosineAngle = dotProduct / magnitudeProduct;
    Point angleInRadians = std::acos(cosineAngle);
    return (angleInRadians);
}

//check t

bool bsp(Point const a, Point const b, Point const c, Point const point){
    
    Vector a = get_Vector(a, point);
    Vector b = get_Vector(b, point);
    Vector c = get_Vector(c, point);

    Point   angle1 = calculates_angle_between_two_vectors(a, b);
    Point   angle2 = calculates_angle_between_two_vectors(b, c);
    Point   angle3 = calculates_angle_between_two_vectors(c, a);
    
    //first check angle is 180
//     if (angle1 == 180 || angle2 == 180 || angle3 == 180){
        
//         std::cout << "angle is 180" << std::endl;
//         return (false);
//     }

//     //second check angle is 360

//     if (angle1 + angle2 + angle3 == 360){
           
//         std::cout << "Point is in triangle" << std::endl;
//         return (true);
//     }
//     else{
//         std::cout << "Point isn't in triangle " << std::endl;
//         return (false);
//     }
    return (true);
}


