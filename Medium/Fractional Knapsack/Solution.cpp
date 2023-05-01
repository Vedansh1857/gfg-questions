//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item> a,pair<double,Item> b){
        return (a.first > b.first);
    }
    double fractionalKnapsack(int W, Item arr[], int n){
        // Your code here
        vector<pair<double,Item>> vec;
        for(int i=0;i<n;i++){
            double fractionalValue = 1.0*(arr[i].value)/arr[i].weight; // Calculating rate of each item.
            pair<double,Item> p = make_pair(fractionalValue,arr[i]);
            vec.push_back(p); // The vector is of size 2 vec[0]->rate and vec[1]->pair ofvalues & weight.
        }
        sort(vec.begin(),vec.end(),cmp); // Jiska bhaav(rate) sabse zyada ho use knapsack me daal lo.
        double totalValue = 0;
        for(int i=0;i<n;i++){
            if(vec[i].second.weight > W){
                totalValue += W*vec[i].first; // If the weight is exceeding than the limit, take the fractional value(i.e.Only that much value which is of the remaining weight 'W';multiplying the rate and weight)
                W=0;
            }
            else{
                totalValue += vec[i].second.value;
                W -= vec[i].second.weight;
            }
        }
        return totalValue;
    }
};
