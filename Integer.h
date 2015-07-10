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


// --------
// <digits
// --------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @return   a bool 
 * the sequences are of decimal digits
 * output whether ([b1, e1) < [b2, e2))
 */
template <typename II1, typename II2>
bool lt_digits(II1 b1, II1 e1, II2 b2, II2 e2){
    std::vector<int> num1;
    std::vector<int> num2;

    while (b1 != e1){ 
        num1.push_back(*b1++);
    }
    while (b2 != e2){ 
        num2.push_back(*b2++);}

    // if num1 has larger magnitude, false
    if (num1.size() > num2.size())
        return false;

    // if num1 has smaller magnitude, true
    if (num1.size() < num2.size())
        return true;

    // otherwise, same magnitude, must compare digits individually
    for (int i = num1.size(); i > 0; --i){
        //cout << num1.at(i-1) << " vs " << num2.at(i-1) << endl;
        if (num1.at(i-1) < num2.at(i-1))
            return true;
        if (num1.at(i-1) == num2.at(i-1))
            continue;
        if (num1.at(i-1) > num2.at(i-1))
            return false;
    }
    return false;
}
// --------
// <digits
// --------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @return   a bool 
 * the sequences are of decimal digits
 * output whether ([b1, e1) < [b2, e2))
 */
template <typename II1, typename II2>
bool eq_digits(II1 b1, II1 e1, II2 b2, II2 e2){
    std::vector<int> num1;
    std::vector<int> num2;

    while (b1 != e1){ 
        num1.push_back(*b1++);
    }
    while (b2 != e2){ 
        num2.push_back(*b2++);}

    // if num1 has larger magnitude, false
    if (num1.size() > num2.size())
        return false;

    // if num1 has smaller magnitude, true
    if (num1.size() < num2.size())
        return false;

    // otherwise, same magnitude, must compare digits individually
    for (int i = num1.size(); i > 0; --i){
        //cout << num1.at(i-1) << " vs " << num2.at(i-1) << endl;
        if (num1.at(i-1) < num2.at(i-1))
            return false;
        if (num1.at(i-1) == num2.at(i-1))
            continue;
        if (num1.at(i-1) > num2.at(i-1))
            return false;
    }
    return true;
}


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
        ++x;
        --n;
    }
    // copy bits
    while (b != e){
        *x = *b;
        ++b;
        ++x;
    }

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
            --n;
        }
        else{
            *x = *b;
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
    while (b1 != e1){

        // if num2 has ended
        if (b2 == e2){
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
        
        // set carry bit if necessary
        if (value > 9){
            carry = value / 10;
            value %= 10;
        }
        *x = value;
        ++x;
    }
    // if the first number has ended, but the second hasn't,
    // copy second number directly to output iterator
    while (b2 != e2){
        value = carry + *b2;
        carry = 0;
        ++b2;
        if (value > 9){
            carry = value / 10;
            value %= 10;
        }
        *x = value;
        ++x;
    }

    // In case there is a final carry bit, write it
    if (carry != 0){
        *x = carry;
        ++x;
    }

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
    }

    return x;}


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

    // otherwise, do long multiplication
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
    if (num1.size() < num2.size()){
        std::vector<int> v(num1.size());
        v = num1;
        num1 = num2;
        num2 = v;
    }

    /* This assumes the natural form of the bottom number being shorter or equal to the top number
     * In this case, the top number is num1, the bottom number is num2
     */
     int carry = 0;
    for (int i = 0; i < num2.size(); ++i){
        
        for (int j = 0; j < num1.size(); ++j){

            int tmp1 = num1.at(j);
            int tmp2 = num2.at(i);

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

    // Write product to output iterator
    int k = 0;
    while (k < result.size()){
        *x = result[k];
        ++x;
        ++k;
    }

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

    /* Divide num1 by num2
     * This algorithm does NOT assume num1 is bigger than num2
     * OR that both are non-zero
     */
    int diff = 0;
    std::vector<int> num1;
    std::vector<int> num2;

    // This result vector will hold the final answer
    std::vector<int> result;

    // Read numbers into vectors
    while (b1 != e1){ 
        num1.push_back(*b1++);
    }
    while (b2 != e2){ 
        num2.push_back(*b2++);}
    

     // If num1 < num2 then return 0 as answer
    if (num1.size() <= num2.size() && num1.back() < num2.back()){
        *x = 0; 
        ++x;
        return x;
    }

    // if num2 = 0 -> error
    if (num2.size() == 1 && num2.at(0) == 0){
        throw invalid_argument("Divide by zero");
    }

    // if num2 = 1 -> answer = num1
    if (num2.size() == 1 && num2.at(0) == 1){
        int i = 0;
        for (int i = 0; i< num1.size(); ++i){
            *x = num1[i];
            ++x;
        }
        return x;
    }

    // else regular divide
    std::vector<int> numshift(num1.size());
    result.resize(num1.size());
    std::vector<int> one(1);
    one.at(0) =1;

    vector<int>::iterator it = numshift.begin();

    diff = num1.size()-num2.size();
    if (diff > 0){
        it = shift_left_digits(one.begin(), one.end(), diff, it);
    }
    
    // cout << "shifted ";
    //     for (int l = numshift.size(); l >0; --l){
    //         cout << numshift.at(l-1) << " ";

    //     }
    //     cout << endl;

    //     cout << "num1 ";
    //     for (int l = num1.size(); l >0; --l){
    //         cout << num1.at(l-1) << " ";

    //     }
    //     cout << endl;

    //     cout << "num2 ";
    //     for (int l = num2.size(); l >0; --l){
    //         cout << num2.at(l-1) << " ";

    //     }
    //     cout << endl;

    //     cout << "result ";
    //     for (int l = result.size(); l >0; --l){
    //         cout << result.at(l-1) << " ";

    //     }
    //     cout << endl;

    while (num1.size() > 1 || (num1.size() == 1 && num1.front() != 0)){

        int size = num1.size() + num2.size()+1;
        // Multiply shifted 1's place by num2
        std::vector<int> tmp(size);
        multiplies_digits(num2.begin(), num2.end(), numshift.begin(), numshift.end(), tmp.begin());
        for (int j = 0; j <= tmp.size(); ++j){
                if (tmp.back() == 0)
                    tmp.pop_back();
            }

        // cout << "tmp ";
        // for (int l = tmp.size(); l >0; --l){
        //     cout << tmp.at(l-1) << " ";

        // }
        // cout << endl;
        
        if (lt_digits(tmp.begin(), tmp.end(), num1.begin(), num1.end()) 
            || eq_digits(tmp.begin(), tmp.end(), num1.begin(), num1.end())){
            // This means the shifted digit is part of the answer, 
            // should be subtracted until no longer able

            // Subtract the multiplied value and copy value to num1
            std::vector<int> v(num1.size());
            auto m = minus_digits(num1.begin(), num1.end(), tmp.begin(), tmp.end(), v.begin());
            copy(v.begin(), m, num1.begin());

            // add the shifted num to result and copy into result
            std::vector<int> w(result.size());
            plus_digits(numshift.begin(), numshift.end(), result.begin(), result.end(), w.begin());
            copy (w.begin(), w.end(), result.begin());
            
            for (int j = 0; j <= num1.size(); ++j){
                if (num1.back() == 0)
                    num1.pop_back();
            }

        }
        else{
            std::vector<int> v(numshift.size()-1);
            shift_right_digits(numshift.begin(), numshift.end(), 1, v.begin());
            copy(v.begin(), v.end(), numshift.begin());
            numshift.pop_back();
        }
        // cout << "shifted ";
        // for (int l = numshift.size(); l >0; --l){
        //     cout << numshift.at(l-1) << " ";

        // }
        // cout << endl;

        // cout << "num1 ";
        // for (int l = num1.size(); l >0; --l){
        //     cout << num1.at(l-1) << " ";

        // }
        // cout << endl;

        // cout << "result ";
        // for (int l = result.size(); l >0; --l){
        //     cout << result.at(l-1) << " ";

        // }
        // cout << endl;

        if (lt_digits(num1.begin(), num1.end(), num2.begin(), num2.end())){
            //cout << "num1 < num2";
            break;
        }



    }
     for (int i = 0; i < result.size(); ++i){
        *x = result.at(i);
        ++x;
     }   


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
        if (lhs._size != rhs._size)
            return false;
        if (lhs._neg != rhs._neg)
            return false;
        for (int i = 0; i < lhs._size; ++i){
            if (lhs._x.at(i) != rhs._x.at(i))
                return false;
        }
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

        int trim(){
            bool sigzero = false;
            auto sz = _x.size();
            int result = 0;
            while (sz > 0){

                if (_x.at(sz-1) != 0 && !sigzero){
                    sigzero = true;
                }
                if (!sigzero && _x.at(sz-1) == 0){
                    typename C::iterator it = _x.begin()+sz-1;
                    _x.erase (it);
                    --_size;
                    --sz;
                    continue;
                }

                // If reached, _x[sz] is either an important 0, or middle nonzero
                ++result;
                --sz;
            }
            // if we are trimming a long vector of 0's, cut to one 0
            if (result == 0)
                result = 1;

            return result;
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
            _neg = false;

            if (value == 0){
                _size = 1;
                _neg = false;
                _x.push_back(0);
                return;
            }

            // Set neg flag if negative
            if (value < 0){
                _neg = true;
                value *= -1;
            }

            // Otherwise, write into vector least significant digit first
            // i.e. store value 123456 as {6, 5, 4, 3, 2, 1}
            while (value > 0){
                int mod = value % 10;
                _x.push_back(mod);
                value = value/10;
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

            // switch negative flag
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
            
            int max = _size > rhs._size ? _size+1 : rhs._size+1;
            while (_size < max){
                _x.push_back(0);
                ++_size;
            }
            auto b1 = _x.begin();
            auto b2 = rhs._x.begin();
            auto e1 = _x.end();
            auto e2 = rhs._x.end();
            auto x = _x.begin();

            if (!_neg && !rhs._neg){
                x = plus_digits(b1, e1, b2, e2, x);
            }
            if (_neg && rhs._neg){
                _neg = true;
                x = plus_digits(b1, e1, b2, e2, x);
            }

            // In these cases, magnitude matters
            // if lhs is bigger than right hand side, want to say lhs-rhs & change sign to neg
            // if rhs is bigger than lhs, want to say rhs-lhs & change sign to pos
           if (_neg && !rhs._neg){
                
                if (lt_digits(b1, e1, b2, e2)){
                    x = minus_digits(b1, e1, b2, e2, x);
                    _neg = true;
                }
                else{
                    x = minus_digits(b2, e2, b1, e1, x);
                    _neg = false;
                }

           }
           if (!_neg && rhs._neg){
                if (lt_digits(b1, e1, b2, e2)){
                    x = minus_digits(b1, e1, b2, e2, x);
                    _neg = false;
                }
                else{
                    x = minus_digits(b2, e2, b1, e1, x);
                    _neg = true;
                }
           }
           

            
            _size = trim();

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

            if (*this == rhs){
                x = minus_digits(b1, e1, b2, e2, x);
                _size = 1;
                _neg = false;
                return *this;
            }

            // If -num1 - +num2
            // Add together, change sign to negative
            if (_neg && !rhs._neg)
            {
                _neg = true;
                x = plus_digits(b1, e1, b2, e2, x);
                _size = trim();
                return *this;
            }

            // if +num1 - -num2
            // add together, sign is postive
            if (!_neg && rhs._neg){
                _neg = false;
                x = plus_digits(b1, e1, b2, e2, x);
                _size = trim();
                return *this;
            }

            // if -num1 - -num2
            // calculate num2-num1
            // sign depends on their magnitude
            if (_neg && rhs._neg){
                //if num1 < num2, sign is positive
                if (lt_digits(b1, e1, b2, e2)){
                    x = minus_digits(b2, e2, b1, e1, x);
                    _neg = false;
                }
                else{
                    x = minus_digits(b1, e1, b2, e2, x);
                    _neg = true;
                }
                _size = trim();
                return *this;

            }
            
            // if +num1 - +num2 
            // if num1 < num2, calculate num2 - num1 sign is negative
            // if num2 < num1, calculate num1 - num2 sign is positive
            if (lt_digits(b1, e1, b2, e2)){
                x = minus_digits(b2, e2, b1, e1, x);
                _neg = true;
            }
            else{
                x = minus_digits(b1, e1, b2, e2, x);
                _neg = false;
            }

            _size = trim();
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            
            // Double size in case needed
            int i = _size +rhs._size;
            while (_size < i){
                _x.push_back(0);
                ++_size;
            }

            auto b1 = _x.begin();
            auto b2 = rhs._x.begin();
            auto e1 = _x.end();
            auto e2 = rhs._x.end();
            auto x = _x.begin();

            x = multiplies_digits(b1, e1, b2, e2, x);

            // Change sign flag according to signs of digits
            if (_neg && !rhs._neg)
                _neg = true;
            else if (!_neg && rhs._neg)
                _neg = true;
            else
                _neg = false;


            _size = trim();
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
            std::vector<int> v(_size);
            auto b1 = _x.begin();
            auto b2 = rhs._x.begin();
            auto e1 = _x.end();
            auto e2 = rhs._x.end();
            auto x = v.begin();

            x = divides_digits(b1, e1, b2, e2, x);

            // Change sign flag according to signs of digits
            if (_neg && !rhs._neg)
                _neg = true;
            else if (!_neg && rhs._neg)
                _neg = true;
            else
                _neg = false;

            copy(v.begin(), v.end(), _x.begin());
            _size = trim();
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
            //while (e > 0){}
            return *this;}};

#endif // Integer_h
