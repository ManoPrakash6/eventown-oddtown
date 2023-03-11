/**
* Oddtown C++ Program
* @author : Mano Prakash P
* @brief  : Oddtown Problem (Problem Description):
*   The N residents of Oddtown love forming clubs and would like to maximize the number of them.
*   However, the club-forming traditions in Oddtown are as follows:
*   1. The number of people in each club must be odd.
*   2. The number of people shared by any two clubs remains even.
* @param  : Given input N (Number of people in the odd-town).
* @return : All possible 7-member club in an oddtown of N people.
**/

// Include necessary header files
#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;

int main()
{
  string fname;
  int N, club_strength;
  int a, b, c, d, e, f, g;
  double count;
  set<int> current;
  set<set<int>> result;
  set<set<int>>::iterator it;
  set<int>::iterator it_element;
  set<int> intersection;
  bool even_intersection_flag = false;

  // Input the number of members in the town
  cout << "Enter the number of members in the town: ";
  cin >> N;

  // High precision clock to measure the execution time
  chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

  // Right now, the code is tailored for 7-member club. So, commenting the input of club size
  /*
    cout << "Enter the club size: ";
    cin >> club_strength;
  */

  count = 0;
  for(a = 1; a <= N; a++)
  {
    for(b = a + 1; b <= N; b++)
    {
      // cout << "a = " << a << ", b = "<< b << endl;
      for(c = b + 1; c <= N; c++)
      {
        for(d = c + 1; d <= N; d++)
        {
          for(e = d + 1; e <= N; e++)
          {
            for(f = e + 1; f <= N; f++)
            {
              for(g = f + 1; g <= N; g++)
              {
                // Clear the older combination from the current set
                current.clear();

                // Current combination is being added into current set
                current.insert(a);
                current.insert(b);
                current.insert(c);
                current.insert(d);
                current.insert(e);
                current.insert(f);
                current.insert(g);

                // Compare the current combination for the oddtown criteria with the result set
                
                // 1. Each club in odd town has to have odd number of members
                if(current.size() % 2 == 1)
                {
                  // 2. Number of people shared by any two clubs remains even.
                  // If result is empty, then we are good to add the current set
                  if(result.empty())
                  {
                    result.insert(current);
                  }
                  else
                  {
                    // If the result is non-empty, then we have to compare each set within the
                    // Result set against the current set, and see if the interection is even

                    // Assume initially that there is an even intersection with all sets in result set.
                    even_intersection_flag = true;
                    
                    for(it = result.begin(); it != result.end(); ++it)
                    {
                      intersection.clear();

                      // Compare it and current set to see if they have even intersection
                      set_intersection(it->begin(), it->end(), current.begin(), current.end(), inserter(intersection, intersection.begin()));
            
                      if(intersection.size() % 2 != 0)
                      {
                        even_intersection_flag = false;
                        break;
                      }
                    }
                
                    // If the current set had even intersection with all the sets in the result set,
                    // then add it to the result set.
                    if(even_intersection_flag)
                    {
                      result.insert(current);
                    }
                  }
                }
                else
                {
                  //Club size is odd, and hence we ignore this set
                }
                count = count + 1;
              }
            }
          }
        }
      }
    }
  }

  // Note the end time as t2
  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

  // Calculate the time taken to compute all possible sets (t2 - t1)
  chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

  // Display the result set
  cout << "Possible 7 member clubs of " << N << " members in an odd-town are as follows: " << endl;
  for(it = result.begin(); it != result.end(); ++it)
  {
    cout << "{ ";
    for(it_element = it->begin(); it_element != it->end(); ++it_element)
    {
      cout << *it_element << " ";
    }
    cout << "}" << endl;
  }
  cout << "\n"<< result.size() << " Clubs are possibe in the above case." << endl;
  cout << "Time taken to compute our possible clubs: " << time_span.count() << " seconds.";
  return 0;
}