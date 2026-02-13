class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //speed = dist/time
        //time = dist/speed

        //time = (target-pos)/speed

        std::stack<double> stt;
        int n = position.size();
        //int m = speed.size();
        std::vector<std::pair<int,double>> vec;
        double time = 0;
        int closest;
        
        

        for(int i = 0; i < n; i++)
        {
            double time = (double)(target-position[i])/ speed[i];
            vec.push_back({position[i],time}); 
        }

        //sorting the vector in descending order
        sort(vec.begin(),vec.end(), [](auto & a, auto & b)
        {
            return a.first>b.first;
        });

        
        double lastTime = 0;
        int fleet = 0;

        for(int i = 0; i < n; i++)
        {
            double currtime = vec[i].second;
            if(currtime> lastTime)
            {
                fleet++;
                lastTime = currtime;
            }
        }
       



         

        return fleet;


        

    }
};
