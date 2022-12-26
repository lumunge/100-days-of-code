## Public and Private, Getters and Setters
Rule of thumb - make member variables private - control who sees and changes class member variables.
              - methods can be either private or public.

Getters and Setters - more control over member variables.

#### Java primitive types:
Boolean, Byte, Short, Int, Long, Float, Double, Char

#### Java object types:
Arrays, Classes and everything else

## Memory Models
```java
int var1 = 40;
SimpleLocation loc1;
loc1 = new SimpleLocation(44.56, -90.45); // created new object in the heap referenced with an address
                                          // loc1 holds the reference to the object - the address to the newly created object in heap
SimpleLocation loc2 = new SimpleLocation(34.67, -89.44);
loc2.latitude = -80.39
```
#### The Model
var1 [52]                       HEAP
loc1 [] --------------> latitude:   [44.56] 
                        longitude:  [-90.45]
loc2 [] --------------> latitude:   [-80.39]
                        longitude:  [-89.44]

Example II
```java
// class declaration
public class SimpleLocation{
    public double lat;
    public double lon;

    public SimpleLocation(double latln, double lonln){
        this.lat = latln;
        this.lon = lonln;
    }
}

class LocationTester{
    public static void main(String[] args){
        SimpleLocation loc1 = new SimpleLocation(45.89, -90.44);
        SimpleLocation loc2 = new SimpleLocation(22.19, -45.89);
        loc1 = loc2;
        loc1.lat = -16.3;
        System.out.println(loc2.lat + ", " + loc2.lon);
    }
}
```

Output ---> [-16.3, -45.89]

## Scoping.
*Local variables* - declared inside methods.
*Parameters* - can be used inside methods.
*Member variables*  - belong to a class. Declared outside any methods in the class
                    - Scope is entire class.

```java
public class LocationTester{
    public static void main(String[] args){
        double lat = -34.17;
        SimpleLocation loc1 = new SimpleLocation(lat, -45.44);
    }
}
```
