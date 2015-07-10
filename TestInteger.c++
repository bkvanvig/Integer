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
    vector<int>::iterator x = shift_left_digits(v.begin(), v.begin()+3, 2, w.begin());
    vector<int> y = {0, 0, 1, 2, 3,};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));

}

TEST(IntegerFixture, shift_left_2){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_left_digits(v.begin()+1, v.begin()+4, 1, w.begin());
    vector<int> y = {0, 2, 3, 4};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_left_3){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_left_digits(v.begin(), v.begin()+1, 0, w.begin());
    vector<int> y = {1};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_left_4){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_left_digits(v.begin(), v.begin()+2, 0, w.begin());
    vector<int> y = {1, 2};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_left_5){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_left_digits(v.begin(), v.begin()+1, 4, w.begin());
    vector<int> y = {0, 0, 0, 0, 1};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

// ------------------
// shift_right_digits
// ------------------

TEST(IntegerFixture, shift_right_1){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_right_digits(v.begin(), v.begin()+1, 0, w.begin());
    vector<int> y = {1};

    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_right_2){
    vector<int> v = {1, 0, 0, 0, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_right_digits(v.begin(), v.begin()+1, 1, w.begin());
    vector<int> y = {0};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_right_3){
    vector<int> v = {0, 0, 0, 1, 0, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_right_digits(v.begin(), v.begin()+4, 3, w.begin());
    vector<int> y = {1};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_right_4){
    vector<int> v = {1, 0, 1, 0, 1, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_right_digits(v.begin(), v.begin()+5, 1, w.begin());
    vector<int> y = {0, 1, 0, 1,};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

TEST(IntegerFixture, shift_right_5){
    vector<int> v = {1, 1, 1, 1, 1, 1};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int>::iterator x = shift_right_digits(v.begin(), v.begin()+6, 3, w.begin());
    vector<int> y = {1, 1, 1};
    ASSERT_TRUE(equal(w.begin(), x, y.begin()));
}

// ------------------
// plus_digits
// ------------------

TEST(IntegerFixture, plus_1){
    vector<int> v = {0, 1, 0};
    vector<int> w = {2, 2, 2, 2, 2, 2, 0, 0};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.begin()+2, w.begin(), w.begin()+5, x.begin());
    vector<int> y = {2, 3, 2, 2, 2};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, plus_2){
    vector<int> v = {1, 0, 1, 0, 1, 0};
    vector<int> w = {2, 1, 2, 1, 2, 1, 0};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.begin()+4, w.begin(), w.begin()+5, x.begin());
    vector<int> y = {3, 1, 3, 1, 2, 0, 0};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, plus_3){
    vector<int> v = {9, 9, 9, 9, 9, 9};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.begin()+4, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {1, 2, 2, 0, 1};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, plus_4){
    vector<int> v = {9, 9, 9, 9, 9, 6, 0, 0};
    vector<int> w = {1, 9, 4, 2, 8, 2, 0, 0};
    vector<int> x = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.begin()+6, w.begin(), w.begin()+6, x.begin());
    vector<int> y = {0, 9, 4, 2, 8, 9, 0};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, plus_5){
    vector<int> v = {9, 9, 9, 9, 9, 9};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.begin()+5, w.begin(), w.begin()+4, x.begin());
    vector<int> y = {1, 2, 2, 2, 0, 1};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}
TEST(IntegerFixture, plus_6){
    vector<int> w = {1, 4, 3, 2};
    vector<int> v = {3, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = plus_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {4, 6, 3, 2};
    //ASSERT_EQ(x, y);
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

// ------------------
// minus_digits
// ------------------

TEST(IntegerFixture, minus_1){
    vector<int> v = {0, 0, 0, 0, 0, 3};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = minus_digits(v.begin(), v.begin()+6, w.begin(), w.begin()+6, x.begin());
    vector<int> y = {8, 7, 7, 7, 7, 0};
    ASSERT_EQ(x, y);
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, minus_2){
    vector<int> v = {0, 0, 0, 0, 0, 3};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = minus_digits(v.begin()+3, v.begin()+6, w.begin()+3, w.begin()+6, x.begin());
    vector<int> y = {8, 7, 0, 0, 0, 0};
    ASSERT_EQ(x, y);
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, minus_3){
    vector<int> v = {0, 0, 0, 0, 0, 3};
    vector<int> w = {2, 2, 2, 2, 2, 2};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = minus_digits(v.begin()+2, v.begin()+6, w.begin(), w.begin()+3, x.begin());
    vector<int> y = {8, 7, 7, 2, 0, 0};
    ASSERT_EQ(x, y);
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

//TEST(IntegerFixture, minus_4){}

//TEST(IntegerFixture, minus_5){}


// ------------------
// multiplies_digits
// ------------------

TEST(IntegerFixture, multiplies_1){
    vector<int> v = {3};
    vector<int> w = {2};
    vector<int> x = {0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {6};
    int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }

    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    ASSERT_EQ(x, y);
}

TEST(IntegerFixture, multiplies_2){
    vector<int> v = {3, 0, 3};
    vector<int> w = {2};
    vector<int> x = {0, 0, 0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {6, 0, 6};
     int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    ASSERT_EQ(x, y);
}

TEST(IntegerFixture, multiplies_3){
    vector<int> v = {1, 2, 3};
    vector<int> w = {5};
    vector<int> x = {0, 0, 0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {5, 0, 6, 1};
     int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    ASSERT_EQ(x, y);
}

TEST(IntegerFixture, multiplies_4){
    vector<int> v = {1, 2, 3, 5};
    vector<int> w = {0};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {0};
     int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }
    //ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    ASSERT_EQ(x, y);
}

TEST(IntegerFixture, multiplies_5){
    vector<int> v = {1, 2, 3, 5};
    vector<int> w = {1};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    vector<int> y = {1, 2, 3, 5};
     int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
}

TEST(IntegerFixture, multiplies_6){
    std::vector<int> v = {3, 2, 1};
    std::vector<int> w = {6, 5, 4};
    std::vector<int> x = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = multiplies_digits(v.begin(), v.end(), w.begin(), w.end(), x.begin());
    std::vector<int> u = {8, 8, 0, 6, 5};
     int sz = x.size();
    bool sigzero = false;
    int result = 0;
    while (sz > 0){

        if (x.at(sz-1) != 0 && !sigzero){
            sigzero = true;
        }
        if (!sigzero && x.at(sz-1) == 0){
            //typename C::iterator it = _x.begin()+sz-1;
            x.pop_back();
            //--_size;
            --sz;
            continue;
        }

        // If reached, _x[sz] is either an important 0, or middle nonzero
        ++result;
        --sz;
    }
    // if we are trimming a long vector of 0's, cut to one 0
    if (result == 0){
        result = 1;
        x.push_back(0);
    }
    ASSERT_EQ(x, u);
}

// ------------------
// divides_digits
// ------------------

TEST(IntegerFixture, divide_1){
    vector<int> v = {0, 0, 3, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(v.begin(), v.begin()+3, w.begin()+2, w.begin()+3, x.begin());
    vector<int> y = {0, 0, 1, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, divide_2){
    vector<int> v = {0, 0, 3, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(v.begin(), v.begin()+3, w.begin()+4, w.begin()+5, x.begin());
    vector<int> y = {0, 6, 0, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, divide_3){
    vector<int> v = {0, 0, 0, 3, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(v.begin(), v.begin()+4, w.begin()+3, w.begin()+4, x.begin());
    vector<int> y = {0, 5, 7, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, divide_4){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(v.begin(), v.begin()+1, w.begin(), w.begin()+1, x.begin());
    vector<int> y = {3, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}

TEST(IntegerFixture, divide_5){
    vector<int> v = {3, 0, 0, 0, 0, 0};
    vector<int> w = {1, 2, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(w.begin(), w.begin()+1, v.begin(), v.begin()+1, x.begin());
    vector<int> y = {0, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}
TEST(IntegerFixture, divide_6){
    vector<int> v = {0, 0, 1, 0, 0, 0};
    vector<int> w = {1, 3, 3, 4, 5, 6};
    vector<int> x = {0, 0, 0, 0, 0, 0};
    vector<int>::iterator x1 = divides_digits(v.begin(), v.begin()+3, w.begin()+1, w.begin()+3, x.begin());
    vector<int> y = {3, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(x.begin(), x1, y.begin()));
    //ASSERT_EQ(x, y);
    //ASSERT_TRUE(false);
}

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
    Integer<int> y = 100320;
    ASSERT_FALSE(x == y);
}

TEST(IntegerFixture, equal_3){
    Integer<int> v = 103;
    Integer<int> w = 103;
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

TEST(IntegerFixture, output_5){
    Integer<int> x("400000");
    ostringstream w;
    w << x;
    ASSERT_EQ("400000", w.str());
}
TEST(IntegerFixture, output_6){
    Integer<int> x("0020045");
    ostringstream w;
    w << x;
    ASSERT_EQ("20045", w.str());
}



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
    Integer<int> x = 12345600;
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("12345600", w.str());
}

TEST(IntegerFixture, constr_2){
    Integer<int> x = 43589273;
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("43589273", w.str());
}

TEST(IntegerFixture, constr_3){
    Integer<int> x = 0;
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("0", w.str());
}

//TEST(IntegerFixture, constr_4){}

//TEST(IntegerFixture, constr_5){}

// ------------------
// explicit_constructor
// ------------------

TEST(IntegerFixture, exconstr_1){
    Integer<int> x("12345600");
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("12345600", w.str());
}

TEST(IntegerFixture, exconstr_2){
    Integer<int> x("48938485");
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("48938485", w.str());
}

TEST(IntegerFixture, exconstr_3){
    Integer<int> x("0");
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("0", w.str());
}

TEST(IntegerFixture, exconstr_4){
    Integer<int> x("000000004");
    int i = x.getSize();
    ostringstream w;
    auto y = x.getContainer();
    while (i > 0 ){
        w << y.at(i-1);
        --i;
    }
    ASSERT_EQ("4", w.str());
}

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
    ASSERT_EQ(v, u);
}


TEST(IntegerFixture, pluseq_2){
    Integer<int> v = 2341;
    Integer<int> w = 23;
    v += w;
    Integer<int> u = 2364;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, pluseq_3){
    Integer<int> v = 10002;
    Integer<int> w = -12348;
    Integer<int> u = -2346;
    v += w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, pluseq_4){
    Integer<int> v = -10002;
    Integer<int> w = 12348;
    Integer<int> u = 2346;
    v += w;
    ASSERT_EQ(v, u);
}
TEST(IntegerFixture, pluseq_5){
    Integer<int> v = 1342341;
    Integer<int> w =  23;
    v += w;
    Integer<int> u = 1342364;
    ASSERT_EQ(v, u);
}
TEST(IntegerFixture, pluseq_6){
    Integer<int> v = 23;
    Integer<int> w = 2341;
    v += w;
    Integer<int> u = 2364;
    ASSERT_EQ(v, u);
}


// ------------------
// operator -=
// ------------------

TEST(IntegerFixture, minuseq_1){
    Integer<int> v = 10002;
    Integer<int> w = 12348;
    Integer<int> u = 2346;
    w -= v;
    ASSERT_EQ(w, u);
}

TEST(IntegerFixture, minuseq_2){
    Integer<int> v = 123456;
    Integer<int> w = 123456;
    Integer<int> u = 0;
    v -= w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, minuseq_3){
    Integer<int> v = 10;
    Integer<int> w = 8;
    Integer<int> u = 2;
    v -= w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, minuseq_4){
    Integer<int> v = -10;
    Integer<int> w = -8;
    Integer<int> u = -2;
    v -= w;
    ASSERT_EQ(v, u);
}

//TEST(IntegerFixture, minuseq_5){}

// ------------------
// operator *=
// ------------------

TEST(IntegerFixture, multeq_1){
    Integer<int> v = 10;
    Integer<int> w = 8;
    Integer<int> u = 80;
    v *= w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, multeq_2){
    Integer<int> v = 123;
    Integer<int> w = 456;
    Integer<int> u = 56088;
    v *= w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, multeq_3){
    Integer<int> v = 11111;
    Integer<int> w = 3242;
    Integer<int> u = 36021862;
    v *= w;
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, multeq_4){
    Integer<int> v = 111111;
    Integer<int> w = 222222;
    Integer<int> u("24691308642");
    v *= w;
    ASSERT_EQ(v, u);
}

//TEST(IntegerFixture, multeq_5){}

// ------------------
// operator /=
// ------------------

TEST(IntegerFixture, diveq_1){
    Integer<int> v = 11111;
    Integer<int> w = 3242;
    Integer<int> u = 3;
    v /= w;
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);

}

TEST(IntegerFixture, diveq_2){
    Integer<int> v = 100;
    Integer<int> w = 25;
    Integer<int> u = 4;
    v /= w;
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, diveq_3){
    Integer<int> v = 54990;
    Integer<int> w = 235;
    Integer<int> u = 234;
    v /= w;
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);
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
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, modeq_2){
    Integer<int> v = 37;
    Integer<int> w = 15;
    Integer<int> u = 7;
    v %= w;
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);
}

TEST(IntegerFixture, modeq_3){
    Integer<int> v = 54990;
    Integer<int> w = 37;
    Integer<int> u = 8;
    v %= w;
    //ASSERT_TRUE(v==u);
    ASSERT_EQ(v, u);
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
    ostringstream w;
    w << v;
    ASSERT_EQ("549", w.str());
    //ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, sreq_2){
    Integer<int> v ("1324871239");
    Integer<int> u = 13;
    v >>= 8;
    ostringstream w;
    w << v;
    ASSERT_EQ("13", w.str());
    //ASSERT_TRUE(v==u);
}

TEST(IntegerFixture, sreq_3){
    Integer<int> v ("3733737373");
    Integer<int> u ("373373737");
    v >>= 1;
    ostringstream w;
    w << v;
    ASSERT_EQ("373373737", w.str());
    //ASSERT_TRUE(v==u);
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
    Integer<int> x = 1232421;
    ASSERT_EQ(abs(x), 1232421);
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
    v.pow(132413);
    ASSERT_TRUE(v==u);
}

// TEST(IntegerFixture, pow_4){
//     Integer<int> v = 2;
//     Integer<int> u ("");
//     v = v.pow(4423)-1;
//     ASSERT_TRUE(v==u);
// }

//TEST(IntegerFixture, pow_5){}