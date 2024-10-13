//https://leetcode.com/problems/couples-holding-hands/

/* just iterate over the array and find its next couple 
   if the current partner is even then next will be odd and vice versa
   if the next partner is not in its correct position then swaps will increase and the values will be swapped
   both in array as well as map index */




class Solution {
private:
   void swap(int first,int second,vector<int>&row,unordered_map<int,int>& map){
        int temp = row[first];
        map[temp] = second;
        map[row[second]] = first;
        row[first] = row[second];
        row[second] = temp;


    }
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> map;
        for(int i=0;i<row.size();++i){
            map[row[i]] = i;
        }

        int swaps = 0;
        for(int i=0;i<row.size();i+=2){
            int first = row[i];
            int second = first + ((first%2 == 0)?1:-1);
            // cout<<first<<" "<<second<<endl;
            if(row[i+1] != second){
                swaps++;
                swap(i+1,map[second],row,map);
            }
        }

        return swaps;
    }
};