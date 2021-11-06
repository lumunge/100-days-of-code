public class LocationTester{
    public static void main(String[] args){
        SimpleLocation kenya = new SimpleLocation(243.9, -99.5);
        SimpleLocation ghana = new SimpleLocation(56.4, -33.2);

        System.out.println(kenya.distance(ghana));
    }
}
