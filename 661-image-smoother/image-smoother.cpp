// class Solution {
// public:
//     vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//         vector<vector<int>> result;
         

        

//         for(int i=0;i<img.size();i++)
//         {        

//             vector<int> holder;
//             for(int j=0;j<img[i].size();j++)
//             {
//                 int sum=0;
//                 if(i==0 && j==0)
//                 {
//                     if()
//                     sum=img[i][j]+img[i][j+1]+img[i+1][j]+img[i+1][j+1];
//                     sum=sum/4;
//                 }
//                 else if(i == 0 && j == img[i].size()-1 )
//                 {
//                     sum=img[i][j]+img[i][j-1]+img[i+1][j]+img[i+1][j-1];
//                     sum=sum/4;
//                 }
//                 else if ( i == img.size()-1 && j==0 )
//                 {
//                     sum=img[i][j]+img[i-1][j]+img[i-1][j+1]+img[i][j+1];
//                     sum=sum/4;
//                 }
//                 else if ( i == img.size()-1 && j == img[i].size()-1 )
//                 {
//                     sum=img[i][j]+img[i-1][j]+img[i-1][j-1]+img[i][j-1];
//                     sum=sum/4;
//                 }

//                 else if( i==0 && j > 0 && j < img[i].size()-1 )
//                 {
//                      sum=img[i][j]+img[i][j+1]+img[i][j-1]+img[i+1][j]+
//                      img[i+1][j-1]+img[i+1][j+1];
//                      sum=sum/6;
//                 }
//                 else if(j==0 && i > 0 && i < img.size()-1)
//                 {
//                      sum=img[i][j]+img[i-1][j]+img[i+1][j]+
//                      img[i][j+1]+img[i+1][j+1]+img[i-1][j-1];
//                        sum=sum/6;
//                 }

//                 else if ( i == img.size()-1 && j>0 && j < img[i].size()-1)
//                 {
//                     sum=img[i][j]+img[i][j+1]+img[i][j-1]+
//                      img[i-1][j]+img[i-1][j+1]+img[i-1][j-1];
//                        sum=sum/6;
//                 }

//                 else if ( j == img[i].size()-1 && i > 0 && i < img.size()-1)
//                 {
//                     sum=img[i][j]+img[i+1][j]+img[i-1][j]+
//                      img[i][j-1]+img[i-1][j-1]+img[i+1][j-1];
//                        sum=sum/6;
//                 }
//                 else
//                 {
//                     sum=img[i][j]+img[i+1][j]+img[i-1][j]+
//                      img[i][j-1]+img[i][j+1]+img[i-1][j-1]+img[i-1][j+1]+img[i+1][j-1]+img[i+1][j+1];
//                        sum=sum/9;
//                 }

//                 holder.push_back(sum);
                
//             }
//             result.push_back(holder);
//         }
//         return result;
        
//     }
// };




class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result;
         int rows=img.size();
         int cols=img[0].size();       

        for(int i=0;i<rows;i++)
        {      
            vector<int> holder;
            for(int j=0;j<cols;j++)
            {
                int sum=0,count=0;

                for(int x=i-1;x<=i+1;x++)
                {
                    for(int y=j-1;y<=j+1;y++)
                    {
                        if(x<0 || x==rows || y<0 || y==cols )
                        {
                            continue;
                        }
                        sum+=img[x][y];
                        count++;
                    }
                }
                sum=sum/count;
              
                holder.push_back(sum);
                
            }
            result.push_back(holder);
        }
        return result;
        
    }
};