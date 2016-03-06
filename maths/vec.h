// Template 2-D vector class (no .cpp file)

#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <hexvec.h>

template <class T> class vec{

    public:

        // Default constructor sets values at 0
        vec(){ x =0; y = 0; }

        vec( T X, T Y ){ x = X; y = Y; }

        T x, y;

        // Convert a 2-D hex co-ord to corresponding hex co-ords
        hexVec convertToHex(){
            return hexVec( x, 0.5*(y + y%2), 0.5*(y - y%2) );
        }

        // Print vector to console
        void print(){
            std::cout << "(" << x << "," << y << ") " ;
        }

        // sum of two vectors
        vec<T> operator + ( vec<T>& object ){
            return vec<T>( x +object.x, y +object.y );
        }

        // Subtract a vector
        vec<T> operator - ( vec<T>& object ){
            return vec<T> ( x -object.x, y -object.y );
        }

        // Scale vector (by arbitary type)
        template < class N>
        vec<T> operator * ( N a ){
            return vec<T>( a*x, a*y );
        }

        // Check if a vector is greater than both components of amother
        bool operator > ( vec<T>& object ){
            return ( x > object.x && y > object.y );
        }

        // Check if a vector is less than both components of another
        bool operator < ( vec<T>& object ){
            return ( x < object.x && y < object.y );
        }

    protected:
    private:

};

#endif // VEC_H
