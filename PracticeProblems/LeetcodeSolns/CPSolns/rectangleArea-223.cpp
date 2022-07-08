// Rectangle area- Leetcode #223
class Solution {
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
            int AA = (ax2 - ax1) * (ay2 - ay1);
            int AB = (bx2 - bx1) * (by2 - by1);

            int x1 = max(ax1, bx1);
            int x2 = min(ax2, bx2);
            
            int y1 = max(ay1, by1);
            int y2 = min(ay2, by2);

            int width = max(x2 - x1, 0);
            int height = max(y2 - y1, 0);

            int areaIntersection = width * height;

            return AA + AB - areaIntersection;
        }
};
