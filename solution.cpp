#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol54;
using namespace std;

/*takeaways
  - walk right until you can't, then walk down until you can't,
    then left, then up. Repeat until you are at the very last
    number in the matrix
  - shrink the bound every time you finish walking along with a
    direction and has to turn to a new direction next
    - this is the same idea of nodes being marked as
      visited so we don't visit them more than once
*/

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix)
{
  int n = matrix.size(), m = matrix[0].size();
  /* bounds */
  int top = 0, bottom = n - 1, left = 0, right = m - 1;
  int x = 0, y = 0, dir = 0;

  auto result = vector<int>();

  /* exit after you added the second to the
     last number as the bounds will not allow
     you to go anywhere
  */
  while (result.size() < m * n - 1)
  {
    if (dir == 0) /* right */
    {
      while (x < right)
        /* x will be on the bound when the loop exits
           - this is  x == right
        */
        result.push_back(matrix[y][x++]);
      /* finish visiting this row */
      top++;
    }
    else if (dir == 1) /* down */
    {
      while (y < bottom)
        result.push_back(matrix[y++][x]);
      right--;
    }
    else if (dir == 2) /*left */
    {
      while (x > left)
        result.push_back(matrix[y][x--]);
      bottom--;
    }
    else if (dir == 3)
    {
      while (y > top)
        result.push_back(matrix[y--][x]);
      left++;
    }

    dir = (dir + 1) % 4;
  }

  result.push_back(matrix[y][x]);
  return result;
}