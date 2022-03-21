// Creating objects

public class LocationTester{

    public static void main(String[] args){
        // creating new objects
        // calls constructor
        SimpleLocation loc1 = new SimpleLocation(243.9, -99.5);
        SimpleLocation loc2 = new SimpleLocation(56.4, -33.2);
        
        // invokes distance method
        // loc1 is the calling object - compare two distances
        System.out.println("Distance between is: " + loc1.distance(loc2));
    }
}
