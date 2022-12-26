/* PROBLEM STATEMENT:
 * On an infinite plane a robot stands at (0,0) and faces north.
 * It can "G" go straight 1 unit
 *        "L" turn 90 degrees to the left
 *        "R" turn 90 degrees to the right
 * Instructions are performed infinately.
 * Return true iff there exists a circle in the plane such that it never leaves the circle.
 *
 * Sample:
 * Input: instructions = "GGLLGG"
 * Output: true
 * Explanation: The robot returns to thr origin
 *
 * Input: instructions = "GG"
 * Output: false
 * Explanation: The robot moves north infinitely
 *
 * Approach.
 * Iterate through the list of instructions.
 * Finally if the position of the robot(0,0) does not change or direction changes
 * return true, otherwise false.
 */

class BoundedRobot{
    static boolean isBounded(String instructions){
        //movable directions
        int dirs[][] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        //track rotation
        int rot = 0;
        //origin
        int x = 0; int y = 0;
        for(char c : instructions.toCharArray()){
            if(c == 'G'){//move up
                x += dirs[rot][0];
                y += dirs[rot][1];
            }else if(c == 'L'){//face left
                rot = (rot + 1) % 4;
            }else{//face right
                rot = (rot + 3) % 4;
            }
        }
        return (x == 0 && y == 0 || rot != 0);
    }

    public static void main(String[] args){
        String instructions = "GGLLGG";
        String instructions1 = "GG";
        String instructions2 = "GL";
        System.out.println(isBounded(instructions));
        System.out.println(isBounded(instructions1));
        System.out.println(isBounded(instructions2));
    }
}
