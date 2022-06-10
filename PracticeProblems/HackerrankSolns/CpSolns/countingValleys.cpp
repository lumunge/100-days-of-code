// Counting valleys - https://www.hackerrank.com/challenges/counting-valleys/

int countingValleys(int steps, string path) {
    int h = 0, v = 0;
    for(int i = 0; i < steps; i++){
        if(path[i] == 'U') // mountain
            h++;
        else{
            if(h == 0) v++; // sea level
            h--;
        }
    }
    if(h < 0) v--;
    return v;
}
