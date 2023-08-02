/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:11:40 by tyi               #+#    #+#             */
/*   Updated: 2023/05/27 19:27:47 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

typedef struct  s_vector{
    float  x;
    float  y;
}               Vector;

Vector* get_Vector(Point const finish_p, Point const start_p){
    Vector *vec = new Vector;
    vec->x = (start_p.getX().toFloat() - finish_p.getX().toFloat());
    vec->y = (start_p.getY().toFloat() - finish_p.getY().toFloat());
    
    return (vec);
}

float   calculates_angle_between_two_vectors(Vector *v1, Vector *v2){ 
    float dotProduct = v1->x * v2->x + v1->y * v2->y;
    float magnitudeProduct = std::sqrt(v1->x * v1->x + v1->y * v1->y) * std::sqrt(v2->x * v2->x + v2->y * v2->y);
    float cosineAngle = dotProduct / magnitudeProduct;
    float angleInRadians = std::acos(cosineAngle);
    return (angleInRadians);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    
    Vector* vec_1 = get_Vector(a, point);
    Vector* vec_2 = get_Vector(b, point);
    Vector* vec_3 = get_Vector(c, point);

    float   angle1 = calculates_angle_between_two_vectors(vec_1, vec_2);
    float   angle2 = calculates_angle_between_two_vectors(vec_2, vec_3);
    float   angle3 = calculates_angle_between_two_vectors(vec_3, vec_1);

    delete vec_1;
    delete vec_2;
    delete vec_3;

    float epsilon = 0.0001;

    if (std::abs(angle1 - M_PI) < epsilon || std::abs(angle2 - M_PI) < epsilon || std::abs(angle3 - M_PI) < epsilon){
        // std::cout << "Point is on the edge of the triangle" << std::endl;
        return (false);
    }

    //sum of angles
    float sum = angle1 + angle2 + angle3;
    
    // std::cout << "angle1: " << angle1 << std::endl;
    // std::cout << "angle2: " << angle2 << std::endl;
    // std::cout << "angle3: " << angle3 << std::endl;

    // std::cout << "sum :: " << sum << std::endl;
    // std::cout << "Pi :: " << M_PI << std::endl;
    // std::cout << "2Pi :: " << 2 * M_PI << std::endl;
    
    if (std::abs(2 * M_PI - sum) < 3 * epsilon)
        return (true);
    
    return (false);
}


