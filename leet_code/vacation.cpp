#include <vector>
using namespace std;

/*
3
10 [40] 70
20 50 [80]
30 [60] 90

1- find max path
    - by simple example
    - make it complex
    - use recursion
2- except identical indexes
3- memoization


//vector<vector<int>> twoDVector(rows, vector<int>(columns, initialValue));


*/

int max_path(vector<int> days_vec, int days_no) {
  int current_path = 0;

  int prev_activity = 0;
  int activity = 0;

  int max_path = 0;
  int step = 0;

  for (int i = 0; i < days_vec.size(); i++) {
    // vector<int> normal_days={0,1,2};
    for (int a = 0; a < 3; a++)
        activity = days_vec[i][a];
        current_path = activity + prev_activity;
        
        prev_activity=activity;

    // normal_days.erase(step);
  }
  max_path = max(current_path, max_path(days_vec, days_no))
}










int max_path(vector<int> day1_vec , vector<int>  day2_vec, int days_no) {

    int current_path = 0;
    int max_path = 0;

    for (int i = 0; i < day1_vec.size(); i++) 
    {
        // vector<int> normal_days={0,1,2};
        for (int j = 0; j < day2_vec.size(); j++)
            current_path = day1_vec[i] + day2_vec[j];
            if (current_path>max_path)
            {
                max_path=current_path;
            }
    }
        return max_path;
    
}













