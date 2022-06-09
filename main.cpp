#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol54;

/*
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
*/

tuple<vector<vector<int>>, vector<int>>
testFixture1()
{
  auto input = vector<vector<int>>{
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  auto output = vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5};
  return make_tuple(input, output);
}

/*
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

tuple<vector<vector<int>>, vector<int>>
testFixture2()
{
  auto input = vector<vector<int>>{
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}};
  auto output = vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  auto matirx = get<0>(f);
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.spiralOrder(matirx)) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto matirx = get<0>(f);
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.spiralOrder(matirx)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}