
//here i have used the set because of the complexity(time) as operation in set is of order of log n
//main set consist of atmost x element as mention in the question and rest element will be in the secondary set
//this is a great example of how to use set to get at most x top element 
//ofcourse the priority queeu can be used as well but in this case it will give the time complexity as nklogk which is
//more than before as we have to read the map again for each window and create the heap again and again hear we do noot req. that





class Solution {
    long long sum = 0;
    set<pair<int,int>>main;
    set<pair<int,int>>sec;
    int h =0;

    void insertIntoSet(const pair<int,int> &p){
        if(main.size()<h || p> *main.begin()){

            sum += 1LL*p.first*p.second;
            main.insert(p);

            if(main.size()>h){
                auto small = *main.begin();

                sum -= 1LL * small.first * small.second;

                main.erase(small);
                sec.insert(small);
            }
        }
        else{
            sec.insert(p);
        }
    }

    void removeFromSet(const pair<int,int> &p){
        if(main.find(p) != main.end()){
            sum -= 1LL*p.first*p.second;
            main.erase(p);

            if(!sec.empty()){
                auto large = *sec.rbegin();
                sec.erase(large);
                main.insert(large);
                sum += 1LL*large.first*large.second;
            }
        }
        else{
            sec.erase(p);
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        h =x;
        int n =  nums.size();
        unordered_map<int,int>freq;
        vector<long long>result;

        int i = 0;
        int j = 0;

        while(j<n){
            if(freq[nums[j]]>0){
                removeFromSet({freq[nums[j]], nums[j]});
            }

            freq[nums[j]]++;
            insertIntoSet({freq[nums[j]], nums[j]});

            if(j-i+1 == k){
                result.push_back(sum);

                removeFromSet({freq[nums[i]], nums[i]});
                freq[nums[i]]--;

                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }else{
                    insertIntoSet({freq[nums[i]], nums[i]});
                }
                i++;
            }

            j++;
        }


        return result;
    }
};