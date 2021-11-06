public class SimpleLocation{
    public double longitude;
    public double latitude;

    /* constructor */
    public SimpleLocation(double longtude, double latitude){
        this.longitude = longitude;
        this.latitude = latitude;
    }

    public double getDist(double lat1, double long1, double lat2, double long2){
        return lat1+lat2+long1+long2;
    }

    public double distance(SimpleLocation other){
        return getDist(this.latitude, this.longitude, other.latitude, other.longitude);
    }
}

