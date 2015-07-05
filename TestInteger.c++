// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <vector>
#include <iterator>

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

// -----------
// TestInteger
// -----------

// -----------------
// shift_left_digits
// -----------------

TEST(IntegerFixture, shift_left_1){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_left_digits(v.begin(), v.begin()+3, 2, w.begin());
    vector<int> y = {0, 1, 2, 3, 0, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));

}

TEST(IntegerFixture, shift_left_2){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_left_digits(v.begin()+1, v.begin()+4, 1, w.begin());
    vector<int> y = {0, 0, 2, 3, 4, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_left_3){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_left_digits(v.begin(), v.begin()+1, 0, w.begin());
    vector<int> y = {0, 0, 0, 0, 0, 1};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_left_4){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_left_digits(v.begin(), v.begin()+2, 0, w.begin());
    vector<int> y = {0, 0, 0, 0, 1, 2};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_left_5){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_left_digits(v.begin(), v.begin()+1, 4, w.begin());
    vector<int> y = {0, 1, 0, 0, 0, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

// ------------------
// shift_right_digits
// ------------------

TEST(IntegerFixture, shift_right_1){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_right_digits(v.begin(), v.begin()+1, 0, w.begin());
    vector<int> y = {1, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_right_2){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_right_digits(v.begin(), v.begin()+1, 1, w.begin());
    vector<int> y = {0, 1, 0, 0, 0, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_right_3){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_right_digits(v.begin(), v.begin()+1, 4, w.begin());
    vector<int> y = {0, 0, 0, 0, 1, 0};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_right_4){
    vector<int> v = {1, 0, 1, 0, 1, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_right_digits(v.begin(), v.begin()+6, 1, w.begin());
    vector<int> y = {0, 1, 0, 1, 0, 1};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

TEST(IntegerFixture, shift_right_5){
    vector<int> v = {1, 1, 1, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    shift_right_digits(v.begin(), v.begin()+3, 3, w.begin());
    vector<int> y = {0, 0, 0, 1, 1, 1};
    ASSERT_TRUE(equal(w.begin(), w.end(), y.begin()));
}

// ------------------
// plus_digits
// ------------------

TEST(IntegerFixture, plus_1){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    plus_digits(v.begin(), v.begin()+1, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 0, 0, 2, 2, 3};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, plus_2){
    vector<int> v = {1, 0, 1, 0, 1, 0};
    vector<int> w = {2, 1, 2, 1, 2, 1};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    plus_digits(v.begin(), v.begin()+4, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 0, 1, 2, 2, 2};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, plus_3){
    vector<int> v = {9, 9, 9, 9, 9, 9};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    plus_digits(v.begin(), v.begin()+4, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 1, 0, 2, 2, 1};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, plus_4){
    vector<int> v = {6, 9, 9, 9, 9, 9};
    vector<int> w = {2, 8, 2, 4, 9, 1};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    plus_digits(v.begin(), v.begin()+6, w.begin(), w.begin()+6, x.begin());
    vector<int> y = {9, 8, 2, 4, 9, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, plus_5){
    vector<int> v = {9, 9, 9, 9, 9, 9};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    plus_digits(v.begin(), v.begin()+5, w.begin(), w.begin()+4, x.begin());
    vector<int> y = {1, 0, 2, 2, 2, 1};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

// ------------------
// minus_digits
// ------------------

TEST(IntegerFixture, minus_1){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    minus_digits(v.begin(), v.begin()+6, w.begin(), w.begin()+6, x.begin());
    vector<int> y = {0, 7, 7, 7, 7, 8};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, minus_2){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    minus_digits(v.begin(), v.begin()+3, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 0, 0, 0, 0, 8};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, minus_3){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    minus_digits(v.begin(), v.begin()+4, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 0, 0, 2, 7, 8};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

//TEST(IntegerFixture, minus_4){}

//TEST(IntegerFixture, minus_5){}

// ------------------
// multiplies_digits
// ------------------

TEST(IntegerFixture, mult_1){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    multiplies_digits(v.begin(), v.begin()+3, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 6, 6, 6, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, mult_2){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    multiplies_digits(v.begin(), v.begin()+3, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {0, 6, 6, 6, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, mult_3){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 1};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    multiplies_digits(v.begin(), v.begin()+6, w.begin()+5, w.begin()+6, x.begin());
    vector<int> y = {3, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

//TEST(IntegerFixture, mult_4){}

//TEST(IntegerFixture, mult_5){}

// ------------------
// divides_digits
// ------------------

TEST(IntegerFixture, divide_1){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    divides_digits(v.begin(), v.begin()+3, w.begin()+2, w.begin()+3, x.begin());
    vector<int> y = {0, 0, 0, 1, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, divide_2){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    divides_digits(v.begin(), v.begin()+3, w.begin()+4, w.begin()+5, x.begin());
    vector<int> y = {0, 0, 0, 0, 6, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

TEST(IntegerFixture, divide_3){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    divides_digits(v.begin(), v.begin()+4, w.begin()+3, w.begin()+4, x.begin());
    vector<int> y = {0, 0, 7, 5, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
}

//TEST(IntegerFixture, divide_4){}

//TEST(IntegerFixture, divide_5){}

// ------------------
// operator==
// ------------------

TEST(IntegerFixture, equal_1){
    Integer<int> x = 123;
    Integer<int> y = 12413241;
    ASSERT_FALSE(x == y);
}

TEST(IntegerFixture, equal_2){
    Integer<int> x = 100000;
    Integer<int> y = 100000;
    ASSERT_TRUE(x == y);
}

TEST(IntegerFixture, equal_3){
    Integer<int> v = 100;
    Integer<int> w = 100;
    ASSERT_TRUE(v == w);

}

//TEST(IntegerFixture, equal_4){}

//TEST(IntegerFixture, equal_5){}


// ------------------
// operator<
// ------------------

TEST(IntegerFixture, lt_1){
    Integer<int> x = 74;
    Integer<int> y = 134;
    ASSERT_TRUE(x < y);
}

TEST(IntegerFixture, lt_2){
    Integer<int> x = 123;
    Integer<int> y = -44;
    ASSERT_FALSE(x < y);
}

TEST(IntegerFixture, lt_3){
    Integer<int> x = 123;
    Integer<int> y = 123;
    ASSERT_FALSE(x < y);
}

TEST(IntegerFixture, lt_4){
    Integer<int> x = -123;
    Integer<int> y = 1;
    ASSERT_TRUE(x < y);
}

TEST(IntegerFixture, lt_5){
    Integer<int> x = -123;
    Integer<int> y = -1;
    ASSERT_TRUE(x < y);
}

// ------------------
// operator<< (output)
// ------------------

TEST(IntegerFixture, output_1){
    Integer<int> x = -123;
    ostringstream w;
    w << x;
    ASSERT_EQ("-123", w.str());
}

TEST(IntegerFixture, output_2){
    Integer<int> x = 123456789;
    ostringstream w;
    w << x;
    ASSERT_EQ("123456789", w.str());
}

TEST(IntegerFixture, output_3){
    Integer<int> x = 0;
    ostringstream w;
    w << x;
    ASSERT_EQ("0", w.str());
}

TEST(IntegerFixture, output_4){
    Integer<int> x("0000045");
    ostringstream w;
    w << x;
    ASSERT_EQ("45", w.str());
}

//TEST(IntegerFixture, output_5){}


// ------------------
// valid()
// ------------------

TEST(IntegerFixture, valid_1){
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, valid_2){
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, valid_3){
    //ASSERT_TRUE(false);
}

//TEST(IntegerFixture, valid_4){}

//TEST(IntegerFixture, valid_5){}

// ------------------
// constructor
// ------------------

TEST(IntegerFixture, constr_1){
    Integer<int> x = 123456;
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("123456", w.str());
}

TEST(IntegerFixture, constr_2){
    Integer<int> x = 43589273;
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("43589273", w.str());
}

TEST(IntegerFixture, constr_3){
    Integer<int> x = 0;
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("0", w.str());
}

//TEST(IntegerFixture, constr_4){}

//TEST(IntegerFixture, constr_5){}

// ------------------
// explicit_constructor
// ------------------

TEST(IntegerFixture, exconstr_1){
    Integer<int> x("123456");
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("123456", w.str());
}

TEST(IntegerFixture, exconstr_2){
    Integer<int> x("48938485");
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("48938485", w.str());
}

TEST(IntegerFixture, exconstr_3){
    Integer<int> x("0");
    int i = 0;
    ostringstream w;
    auto y = x.getContainer();
    while (i < x.getSize()){
        w << y.at(i);
        ++i;
    }
    ASSERT_EQ("0", w.str());
}

//TEST(IntegerFixture, exconstr_4){}

//TEST(IntegerFixture, exconstr_5){}


// ------------------
// operator -
// ------------------

TEST(IntegerFixture, neg_1){
    Integer<int> x = 437291347;
    Integer<int> y = -437291347;
    ASSERT_TRUE(-x == y);
}

TEST(IntegerFixture, neg_2){
    Integer<int> x = 123456;
    Integer<int> y = -123456;
    ASSERT_TRUE(-x == y);
}

TEST(IntegerFixture, neg_3){
    Integer<int> x = 341238;
    Integer<int> y = -341238;
    ASSERT_TRUE(-x == y);
}

//TEST(IntegerFixture, neg_4){}

//TEST(IntegerFixture, neg_5){}

// ------------------
// operator +=
// ------------------

TEST(IntegerFixture, pluseq_1){
    Integer<int> v = 300000;
    Integer<int> w = 123456;
    Integer<int> u = 423456;
    v += w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, pluseq_2){
    Integer<int> v = 2341;
    Integer<int> w = 123;
    Integer<int> u = 2464;
    v += w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, pluseq_3){
    Integer<int> v = 10002;
    Integer<int> w = -12348;
    Integer<int> u = -2346;
    v += w;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, pluseq_4){}

//TEST(IntegerFixture, pluseq_5){}

// ------------------
// operator -=
// ------------------

TEST(IntegerFixture, minuseq_1){
    Integer<int> v = 10002;
    Integer<int> w = 12348;
    Integer<int> u = -2346;
    v -= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, minuseq_2){
    Integer<int> v = 123456;
    Integer<int> w = 123456;
    Integer<int> u = 0;
    v -= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, minuseq_3){
    Integer<int> v = 10;
    Integer<int> w = 8;
    Integer<int> u = 2;
    v -= w;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, minuseq_4){}

//TEST(IntegerFixture, minuseq_5){}

// ------------------
// operator *=
// ------------------

TEST(IntegerFixture, multeq_1){
    Integer<int> v = 10;
    Integer<int> w = 8;
    Integer<int> u = 80;
    v *= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, multeq_2){
    Integer<int> v = 123;
    Integer<int> w = 456;
    Integer<int> u = 56088;
    v *= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, multeq_3){
    Integer<int> v = 11111;
    Integer<int> w = 3242;
    Integer<int> u = 36021862;
    v *= w;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, multeq_4){}

//TEST(IntegerFixture, multeq_5){}

// ------------------
// operator /=
// ------------------

TEST(IntegerFixture, diveq_1){
    Integer<int> v = 11111;
    Integer<int> w = 3242;
    Integer<int> u = 3;
    v /= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, diveq_2){
    Integer<int> v = 100;
    Integer<int> w = 25;
    Integer<int> u = 4;
    v /= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, diveq_3){
    Integer<int> v = 54990;
    Integer<int> w = 235;
    Integer<int> u = 234;
    v /= w;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, diveq_4){}

//TEST(IntegerFixture, diveq_5){}

// ------------------
// operator %=
// ------------------

TEST(IntegerFixture, modeq_1){
    Integer<int> v = 15151515;
    Integer<int> w = 2;
    Integer<int> u = 1;
    v %= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, modeq_2){
    Integer<int> v = 37;
    Integer<int> w = 15;
    Integer<int> u = 7;
    v %= w;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, modeq_3){
    Integer<int> v = 54990;
    Integer<int> w = 37;
    Integer<int> u = 8;
    v %= w;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, modeq_4){}

//TEST(IntegerFixture, modeq_5){}

// ------------------
// operator <<=
// ------------------

TEST(IntegerFixture, sleq_1){
    Integer<int> v = 45452;
    v <<= 4;
    ostringstream w;
    w << v;
    ASSERT_EQ("454520000", w.str());
}

TEST(IntegerFixture, sleq_2){
    Integer<int> v = 1111111;
    v <<= 2;
    ostringstream w;
    w << v;
    ASSERT_EQ("111111100", w.str());
}

TEST(IntegerFixture, sleq_3){
    Integer<int> v = 54990;
    v <<= 1;
    ostringstream w;
    w << v;
    ASSERT_EQ("549900", w.str());
}

//TEST(IntegerFixture, sleq_4){}

//TEST(IntegerFixture, sleq_5){}

// ------------------
// operator >>=
// ------------------

TEST(IntegerFixture, sreq_1){
    Integer<int> v = 54990;
    Integer<int> u = 549;
    v >>= 2;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, sreq_2){
    Integer<int> v = 1324871239;
    Integer<int> u = 13;
    v >>= 8;
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, sreq_3){
    Integer<int> v = 3733737373;
    Integer<int> u = 373373737;
    v >>= 1;
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, sreq_4){}

//TEST(IntegerFixture, sreq_5){}

// ------------------
// abs
// ------------------

TEST(IntegerFixture, abs_1){
    Integer<int> x = -12323421;
    ASSERT_EQ(abs(x), 12323421);
}

TEST(IntegerFixture, abs_2){
    Integer<int> x = 12323421;
    ASSERT_EQ(abs(x), 12323421);
}

TEST(IntegerFixture, abs_3){
    Integer<int> x = 0;
    ASSERT_EQ(abs(x), 0);
}

//TEST(IntegerFixture, abs_4){}

//TEST(IntegerFixture, abs_5){}

// ------------------
// pow
// ------------------

TEST(IntegerFixture, pow_1){
    Integer<int> v = 2;
    Integer<int> u = 16;
    v.pow(4);
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, pow_2){
    Integer<int> v = 1234;
    Integer<int> u = 1522756;
    v.pow(2);
    ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, pow_3){
    Integer<int> v = 1;
    Integer<int> u = 1;
    v.pow(1324161423);
    ASSERT_TRUE(v==u);
}

//TEST(IntegerFixture, pow_4){}

//TEST(IntegerFixture, pow_5){}