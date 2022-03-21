public class SimpleLocation{
    // member variables
    public double longitude;
    public double latitude;
   
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
    public double distance(double otherLat, double otherLong){
        // body here
    }
}

