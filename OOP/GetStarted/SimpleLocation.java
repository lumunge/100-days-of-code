public class SimpleLocation{
    // member variables
    public double longitude;
    public double latitude;

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
    
    // this referes to the calling object - loc1
    public double distance(SimpleLocation other){
        return getDist(this.latitude, this.longitude, other.latitude, other.longitude);
    }
}

