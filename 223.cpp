class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate the area of both squares invididually
        int aX = abs(ax1 - ax2);
        int aY = abs(ay1 - ay2);
        int aArea = aX * aY;

        int bX = abs(bx1 - bx2);
        int bY = abs(by1 - by2);
        int bArea = bX * bY;

        // Before finding the area of intersection, you need to prove that
        // they intersect
        // If the edges are touching, we still have to count that as an intersection
        // for some edge cases, but if they are not on top of each other it will
        // result in zero (aArea + bArea - 0)
        if((ax1 <= bx1 && bx1 <= ax2) || (bx1 <= ax1 && ax1 <= bx2)) {
            if((ay1 <= by1 && by1 <= ay2) || (by1 <= ay1 && ay1 <= by2)) {

                // Find intersection in x (is)
                int isXLeft = max(ax1, bx1);
                int isXRight = min(ax2, bx2);
                int isX = abs(isXLeft - isXRight);
        
                // Find intersection in y
                int isYBottom = max(ay1, by1);
                int isYTop = min(ay2, by2);
                int isY = abs(isYBottom - isYTop);
        
                // Total intersection area
                int isArea = isX * isY;
        
                return aArea + bArea - isArea;
            }
        }

        return aArea + bArea;
    }
};
