// Leetcode 84

class LargestRectangleInHistogram{
    static int largestRectangle(int[] heights){
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, currArea = 0, i;
        for(i = 0; i < heights.length;){
            if(stack.isEmpty() || heights[stack.peek()] <= heights[i]){
                stack.push(i++);
            }else{
                int top = stack.pop();
                if(stack.isEmpty()) currArea = heights[top] * i;
                else currArea = heights[top] * (i - stack.peek() - 1);
                if(currArea > maxArea) maxArea = currArea;
            }
        }
        while(!stack.isEmpty()){
            int top = stack.pop();
            if(stack.isEmpty()) currArea = heights[top] * i;
            else currArea = heights[top] * (i - stack.peek() - 1);
            if(currArea > maxArea) maxArea = currArea;
        }
        return maxArea;
    }

    public static void main(String[] args){
        int[] heights = {2, 1, 5, 6, 2, 3};
        System.out.println(largestRectangle(heights));
    }
}
