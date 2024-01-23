class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      
    int Top=0;
    int Bottom=matrix.size()-1;
    int Left=0;
    int Right=matrix[0].size()-1;
    int direction=0;
    int i;
    vector<int> ans;
    
    while(Top<=Bottom && Left<=Right)
    {
        if(direction==0)
        {
            for(i=Left;i<=Right;i++)
                ans.push_back(matrix[Top][i]);
            Top++;
        }
        else if(direction==1)
        {
            for(i=Top;i<=Bottom;i++)
                ans.push_back(matrix[i][Right]);
            Right--;
        }
        else if(direction==2)
        {
            for(i=Right;i>=Left;i--)
                ans.push_back(matrix[Bottom][i]);
            Bottom--;
        }
        else if(direction==3)
        {
            for(i=Bottom;i>=Top;i--)
                ans.push_back(matrix[i][Left]);
            Left++;
        }
        direction=(direction+1)%4;
    }
    return ans;

    }
};