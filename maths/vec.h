#ifndef VEC_H
#define VEC_H

class hexVec;

class vec{

    public:

        vec();

        vec( int X, int Y );

        ~vec();

        int x;

        int y;

        hexVec convertToHex();

        vec operator + ( vec& object );

        vec operator - ( vec& object );

        vec operator * ( int );

        bool operator > ( vec& object );

        bool operator < ( vec& object );

    protected:
    private:
};

#endif // VEC_H
