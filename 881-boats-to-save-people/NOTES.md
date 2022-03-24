};
```
​
**When n people allowed...**
​
```
class Solution {
public:
int numRescueBoats(vector<int>& people, int limit) {
sort(people.begin(), people.end());
int left = 0, right = people.size()-1, currWeight, totalBoats = 0;
while(left <= right) {
currWeight = 0;
totalBoats++;
while(left <= right and currWeight + people[right] <= limit) {
currWeight += people[right];
right--;
}
while(left <= right and currWeight + people[left] <= limit) {
currWeight += people[left];
left++;
}
}
return totalBoats;
}
};
```