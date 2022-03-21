public class SimpleLocation{
    // member variables
    // public - we can access them from any class
    /*
    public double longitude;
    public double latitude;
    */

    // private - only accessible from this class(SimpleLocation)
    private double longitude;
    private double latitude;
    
    // Getters - get private memeber and expose it to outside world
    public double getLatitude(){
        return this.latitude;
    }

    // Setter - allow change value
    public void setLatitude(double lat){
        // more control with setters
        if(lat < -180 || lat > 180)
            System.out.println("Invalid!!");
        else
            this.latitude = lat;
    }
   
    // OVERLOADING THE CONSTRUCTOR - two constructors taking different arguments
    // default constructor - no parameters
    public SimpleLocation(){
        this.longitude = -120.78;
        this.latitude = 32.9;
    }

    // constructor method - class definition
    // called when object is created
    // no return type
    public SimpleLocation(double longtude, double latitude){
        this.longitude = longitude;
        this.latitude = latitude;
    }
    
    // method
    public double getDist(double lat1, double long1, double lat2, double long2){
        return lat1+lat2+long1+long2;
    }
    
    // this refers to the calling object - loc1
    public double distance(SimpleLocation other){
        return getDist(this.latitude, this.longitude, other.latitude, other.longitude);
    }

    // Overloading methods
    // parameters must be different
    // public - can be accessed from anywhere
    // private - can only be called within this class - SimpleLocation
    public double distance(double otherLat, double otherLong){
        // body here
    }
}

