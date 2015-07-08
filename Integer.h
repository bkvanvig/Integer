// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector

using namespace std;



// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    // <your code>
    // shift bits
    while(n>0){
        *x = 0;
        //cout << 0;
        ++x;
        --n;
    }
    // copy bits
    while (b != e){
        *x = *b;
        //cout << *b;
        ++b;
        ++x;
    }
    //cout << endl;
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    // <your code>
    while (b != e){
        if (n > 0){
            *x = 0;
            //cout<< 0;
            --n;
        }
        else{
            *x = *b;
            //cout << *b;
            ++x;
        }
        ++b;
    }
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    int carry = 0;
    int value = 0;
    /* This needs to accomodate numbers of varying sizes
     * so if [b1, e1) is 3 digits, and [b2, e2) is 8
     * we need to keep assigning the values to x after
     * one of the ends (e1 or e2) is reached
     */
    while (b1 != e1 || b2 != e2){
        // if num1 has ended
        if (b1 == e1 && b2 == e2)
            break;
        if (b1 == e1){
            value = carry + *b2;
            carry = 0;
            ++b2;
        }
        // if num2 is ended
        else if (b2 == e2){
            value = carry + *b1;
            carry = 0;
            ++b1;
        }
        // still in middle of both
        else{
            value = *b1 + *b2 + carry;
            ++b1;
            ++b2;
            carry = 0;
        }
        
        if (value > 9){
            carry = value / 10;
            value %= 10;
        }
        
        *x = value;
        ++x;
        //cout << "x = " << value << endl;
        //cout << "carry = " << carry << endl;
    }

    if (carry != 0){
        *x = carry;
        ++x;
    }
    //cout << "end" << endl;

    return x;}

// ------------
// minus_digits
// ------------
/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    int value;
    bool borrow = false;

    while (b1 != e1 || b2 != e2){
        // if num1 has ended
        value = 0;

        if (borrow){
            //cout << "borrow -1 ";
            value = -1;
            borrow = false;
        }
        if (b1 == e1 && b2 == e2)
            break;
        if (b1 == e1){
            value += *b2;
            ++b2;
        }
        // if num2 is ended
        else if (b2 == e2){
            value += *b1;
            ++b1;
        }
        // still in middle of both
        else{
            // need to borrow
            if (*b1 < *b2){
                borrow = true;
                value += 10;
            }
            value += *b1 - *b2;
            ++b1;
            ++b2;
        }
        
        *x = value;
        ++x;
        //cout << "x = " << value << endl;
        //cout << "carry = " << carry << endl;
    }

    return x;}



// -----------------
// multiplies_digits
// -----------------
template < typename II1, typename II2, typename FI>
FI multiplication (II1 b1, II1 e1, II2 b2, II2 e2, FI x){
    int carry = 0;
    int value = 0;

    while ( b1 != e1){
        //cout << "carry " << carry << endl;
        int tmp1 = *b1;
        int tmp2 = *b2;
        value = (tmp1*tmp2) + carry;
        //cout << " " << tmp1;
        //cout << " " << tmp2;
        if (value > 9){
            //cout << " " << value;
            carry = value / 10;
            value = value %10;
            
        }
        //cout << "carry " << carry << endl;
        *x = value;
        ++x; 
        ++b1;
    }
    if (carry != 0){
        *x = carry;
        ++x;
    }
    return x;
}



template <typename II1, typename II2>
int findm (II1 b1, II1 e1, II2 b2, II2 e2){
    int len = 0;
    while (b1 != e1 && b2 != e2){
        ++len;
        ++b1; 
        ++b2;
    }
    return len-1;
}

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    // if either number is 0, return 0
    if ((*b2 ==0 && b2+1 == e2) || (*b1 ==0 && b1+1 == e1)){
        *x = 0;
        return ++x;
    }

    // if b2 is 1, return b1 as x
    if (*b2 ==1 && b2+1 == e2){
        while (b1 != e1){
            *x = *b1;
            ++x;
            ++b1;
        }
        return x;
    }

    // if b1 is 1, return b2 as x
    if (*b1 ==1 && b1+1 == e1){
        while (b2 != e2){
            *x = *b2;
            ++x;
            ++b2;
        }
        return x;
    }

    
    std::vector<int> num1;
    std::vector<int> num2;
    std::vector<int> result;
    vector<int>::iterator y = result.begin();
    while (b1 != e1){ 
        num1.push_back(*b1++);
    }
    while (b2 != e2){ 
        num2.push_back(*b2++);}
    result.resize(num1.size() + num2.size());

    /* This assumes the natural form of the bottom number being shorter or equal to the top number
     * In this case, the top number is num1, the bottom number is num2
     *
     */
     int carry = 0;
    for (int i = 0; i < num2.size(); ++i){
        
        for (int j = 0; j < num1.size(); ++j){
            //cout << "i: " << i << endl;
            //cout << "j: " << j << endl;
            int tmp1 = num1.at(j);
            int tmp2 = num2.at(i);
            //cout << "num1 " << tmp1 << endl;
            //cout << "num2 " << tmp2 << endl;
            //cout << "carry " << carry << endl;
            result[j+i] += (tmp1*tmp2) + carry;

            if (result[j+i] > 9){
                carry = result[j+i] / 10;
                result[j+i] = result[j+i] %10;
            }
            else
                carry = 0;
        }
        if (carry !=0)
            result[num1.size()+i] += carry;
            carry = 0;
        }
    int k = 0;
    while (k < result.size()){
        //cout << result[k] << " ";
        *x = result[k];
        ++x;
        ++k;
    }
    
    return x;


    //implementation of karatsuba algorithm
    /*
     * z0 = x0*y0
     * z1 = (x1+x0)*(y1+y0) - z2 - z0
     * z2 = x1*y1
     
    // if either number is 0, return 0
    if ((*b2 ==0 && b2+1 == e2) || (*b1 ==0 && b1+1 == e1)){
        *x = 0;
        return ++x;
    }

    // if b2 is 1, return b1 as x
    if (*b2 ==1 && b2+1 == e2){
        while (b1 != e1){
            *x = *b1;
            ++x;
            ++b1;
        }
        return x;
    }

    // if b1 is 1, return b2 as x
    if (*b1 ==1 && b1+1 == e1){
        while (b2 != e2){
            *x = *b2;
            ++x;
            ++b2;
        }
        return x;
    }
    // If one of the numbers is only 1 digit, just slow multiply
    if (b1 == e1+1 || b2 == e2+1){
        x = multiplication(b1, e1, b2, e2, x);
        return x;
    }

    // otherwise, do karatsuba
    int b = 10;
    //This is shortest length of 2 nums
    int m = findm(b1, e1, b2, e2);

    //split accordingly
    
    FI z0 = multiplication(b1, b1+m, b2, b2+m, z0);
    FI z2 = multiplication(b1+m, e1, b2+m, e2, z2);



    //multiply */


    return x;}


// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>

    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        if (lhs._x != rhs._x)
            return false;
        if (lhs._neg != rhs._neg)
            return false;
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        bool bothneg = false;
        int lhssize = lhs._size;
        int rhssize = rhs._size;

        //Check signs
        if (lhs._neg == true && rhs._neg == false)
            return true;
        if (lhs._neg == false && rhs._neg == true)
            return false;
        /* If both are negative
         * will return opposite unless equal
         */
        if (lhs._neg == true && rhs._neg == true)
            bothneg = true;

        //Check size
        if (lhssize != rhssize)
            return (bothneg ? !(lhssize < rhssize) : (lhssize < rhssize));

        //All numbers reaching this point will be same sign & size  
        int i = 0;
        while (i < lhssize){
            if(lhs._x.at(i) == rhs._x.at(i)){
                ++i;
                continue;
            }
            else if (lhs._x.at(i) < rhs._x.at(i))
                return (bothneg ? false : true);  
            else
                return (bothneg ? true : false);
        }

        //This will always be false even if both are negative, because here the #'s are equal
        return false; 
    }

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        // <your code>
            //Boolean to determine if a 0 is significant
            bool sigzero = true;
            bool empty = true;
            int size = rhs._size;
            int i = size;
            if (rhs._neg)
                lhs << "-";
            while (i > 0){
                int value = rhs._x.at(i-1);
                if (value!=0 && !sigzero)
                    sigzero=true;
                if (value == 0 && !sigzero){
                    --i;
                    continue;
                }
                empty = false;
                lhs << value;
                --i;
            }
        if (empty)
            lhs << "0";
        return lhs;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container

        bool _neg;// sign of value, true = negative
        int _size;
    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            // <your code>
            if (_size == _x.size())
                return true;
            return false;
}

    public:
        // ----------
        // getter
        // ----------
        C getContainer() {
            return _x;
        }

        int getSize(){
            return _size;
        }

        bool getNeg(){
            return _neg;
        }


        // ------------
        // constructors
        // ------------

        /**
         * reads value into backing container
         * @param value, int of number
         * @returns Integer representation of value
         */
        Integer (int value) {
            // <your code>
            
            _size = 0;
            //int rev = 0;
            _neg = false;

            if (value == 0){
                _size = 1;
                _neg = false;
                _x.push_back(0);
                return;
            }

            if (value < 0){
                _neg = true;
                value *= -1;
            }

            // while (value > 0){
            //     int mod = value % 10;
            //     rev *= 10;
            //     rev +=mod;
            //     value /= 10;
            //     ++_size;
            // }
            while (value > 0){
                int mod = value % 10;
                _x.push_back(mod);
                value /= 10;
                ++_size;
            }
            
            assert(valid());}

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            std::string::const_iterator b =value.begin();
            std::string::const_iterator e =value.end();
            if (*b =='-'){
                _neg = true;
                ++b;
            }
            _neg = false;
            _size = 0;
            --e;
            while (b!=e){
                if (*b == '0'){
                    ++b;
                    continue;
                }
                ++_size;
                _x.push_back(*e-'0');
                --e;
            }
            _x.push_back(*e-'0');
            ++_size;
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            // <your code>
            Integer x = *this;
            if (x._neg == true)
                x._neg = false;
            else
                x._neg = true;
            return x;}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            
            auto b1 = _x.begin();
            auto b2 = rhs._x.begin();
            auto e1 = _x.end();
            auto e2 = rhs._x.end();
            auto x = _x.begin();
           if (_neg && !rhs._neg){
                if (*this < rhs)
                    _neg = true;
                x = minus_digits(b2, e2, b1, e1, x);
                return *this;

           }
           if (!_neg && rhs._neg){
                if (*this < rhs)
                    _neg = true;
                x = minus_digits(b1, e1, b2, e2, x);
                return *this;
           }
           if (_neg && rhs._neg){
                _neg = true;
                x = plus_digits(b1, e1, b2, e2, x);
                return *this;
           }
           x = plus_digits(b1, e1, b2, e2, x);
            
            assert(valid());

            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            auto b1 = _x.begin();
            auto b2 = rhs._x.begin();
            auto e1 = _x.end();
            auto e2 = rhs._x.end();
            auto x = _x.begin();
            if (_neg && !rhs._neg)
            {
                _neg = true;
                x = plus_digits(b1, e1, b2, e2, x);
                return *this;
            }
            if (!_neg && rhs._neg){
                _neg = false;
                x = plus_digits(b1, e1, b2, e2, x);
                return *this;
            }
            if (_neg && rhs._neg){
                _neg = true;
                x = plus_digits(b1, e1, b2, e2, x);
                return *this;
            }

            x = minus_digits(b1, e1, b2, e2, x);
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>

            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>

            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            // Must increase size when adding 0's
            int i = n;
            auto it = _x.begin();
            while (i > 0){
                ++_size;
                _x.insert(it, 0);
                --i;
            }
            //cout << n;
            //cout << *this << endl;
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            // Must decrease size when popping #'s
            int i = n;
            auto it = _x.begin();
            while (i > 0){
                --_size;
                _x.erase(it);
                --i;
            }
            //cout << n;
            //cout << *this << endl;
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            _neg = false;
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif // Integer_h
