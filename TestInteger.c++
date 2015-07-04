// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

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


