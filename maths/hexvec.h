// Hexagonal co-ordinate system in three directions
// E: East, NE: North-East & NW: North-West

#ifndef HEXVEC_H
#define HEXVEC_H

// Declare vector class
template <class T> class vec;

class hexVec{

    public:

        // Default constructor initializes values to 0
        hexVec();

        hexVec( int E, int NE, int NW );

        // Only integer hex co-ordinates required
        int e, ne, nw;

        // Convert a hex vector to a 2-d array vector
        vec<int> convertToSquare();

        // Print the co-ordinates to console
        void print();

        // Add a hex co-ordinates
        hexVec operator + ( hexVec& object );

        // Subtract hex co-ordinates
        hexVec operator - ( hexVec& object );

    protected:
    private:

};
#endif // HEXVEC_H
