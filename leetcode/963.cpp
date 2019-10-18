#include "../common.h"

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {

        double area = DBL_MAX;

        for(int i =0;i<points.size();i++){
            auto p1=points[i];
            for(int j=i+1;j<points.size();j++){
                auto p2=points[j];
                for(int k=j+1;k<points.size();k++){
                    auto p3=points[k];

                    double cx, cy;
                    vector<int>p, pp, ppp;
                    if(checkVertical(p1,p2,p3)){
                        p  = p1;
                        pp = p2;
                        ppp=p3;
                    }else if(checkVertical(p2,p1,p3)){
                        p = p2;
                        pp = p1;
                        ppp= p3;
                    }else if(checkVertical(p3, p1, p2)){
                        p = p3;
                        pp = p1;
                        ppp = p2;
                    }else 
                        continue;

                    cx = (pp[0] + ppp[0])/2.0;
                    cy = (pp[1] + ppp[1])/2.0;

                    for(int q=k+1;q<points.size();q++){
                        auto p4=points[q];
                        if(abs(p[0] + p4[0] - 2*cx) <=1e-6 && abs(p[1]+p4[1] - 2*cy)<=1e-6){
                            double tmp = getdist(p, pp)*getdist(p,ppp);
                            if(tmp < area)
                                area = tmp;
                        }
                    }
                }
            }

        }
        if(area == DBL_MAX)
            return 0;
        return area;
    }

    double getdist(double x1, double x2, double y1, double y2){
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }
    double getdist(vector<int> & p1, vector<int>&p2){
        return sqrt((p2[0]-p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
    bool checkVertical(const vector<int>&p1, const vector<int>&p2, const vector<int> &p3){
        double x1 = p2[0] - p1[0];
        double y1 = p2[1] - p1[1];
        double x2 = p3[0] - p1[0];
        double y2 = p3[1] - p1[1];
        if(x1*x2 + y1*y2 ==0)
            return true;
        else
            return false;

    }
};


int main(){
    vector<vector<int>> points{{9171,9436},{17331,10643},{18663,10333},{7158,4188},{25369,11038},{14079,14809},{5674,12030},{14335,16475},{9271,14648},{15274,127},{7481,16943},{16197,3186},{14883,13036},{7348,3966},{17706,3071},{1447,7354},{8523,7961},{21534,9472},{5446,15287},{7736,1506},{5240,14857},{8439,5875},{14599,21752},{8871,9292},{3596,5867},{14882,11392},{6406,18071},{14277,13949},{7957,17360},{5793,5485},{1357,1144},{19121,15143},{5804,5181},{12210,4020},{8252,13301},{22934,13668},{4899,9382},{8369,5889},{14771,5926},{14071,12487},{13064,11500},{8030,8548},{21394,11043},{18933,6610},{7151,14809},{2828,8800},{6435,9988},{6554,12046},{13274,4248},{8716,2326}};
    Solution s;
    cout << s.minAreaFreeRect(points) << endl;
}
