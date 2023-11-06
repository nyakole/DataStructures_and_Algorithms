// https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

int frogJump(int n, vector<int> &heights)
{
    int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(heights[i]-heights[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(heights[i]-heights[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  return prev;
}