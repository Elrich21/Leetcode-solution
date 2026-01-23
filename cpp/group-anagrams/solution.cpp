class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {

unordered_map<string,vector<string>>ang;

for(string s: strs) //gets each string in the vector
{
string key = s; //stores the string in s temp
sort(key.begin(),key.end()); //sort according to teh acssii values
ang[key].push_back(s); // key-> aet , values in it -> eat,ate
//here u store the key in the hash map along with it value which is a vector o push_back function is used with the original string s
}

vector<vector<string>> result; //result to be displayed as string in arrays

for(auto pair:ang) //each element in a map is called a pair auto-> for auto asigning the type since pair here can change from string to vector
{
result.push_back(pair.second); //sinece result is a vector push_back to add item and ang.second-> is used to get the value (in the key-value pair) of the hash map, similary ang.first-> is used to get the key of the key-value pair
}

return result;
}
};
