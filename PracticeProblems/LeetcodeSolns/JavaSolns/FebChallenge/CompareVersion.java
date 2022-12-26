// Leetcode #165 - Compare version numbers

class CompareVersion{
    static int cmpVersion(String version1, String version2){
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int l1 = v1.length, l2 = v2.length;
        int max = Math.max(l1, l2);
        
        for(int i = 0; i < max; i++){
            int n1 = 0, n2 = 0;
            if(i >= l1) n1 = 0;
            else n1 = Integer.parseInt(v1[i]);
            if(i >= l2) n2 = 0;
            else n2 = Integer.parseInt(v2[i]);
            if(n1 < n2) return -1;
            if(n1 > n2) return 1;
        }
        return 0;
    }

    public static void main(String[] args){
        String version1 = "1.01", version2 = "1.001";
        String version3 = "1.0", version4 = "1.0.0";
        System.out.println(cmpVersion(version1, version2));
        System.out.println(cmpVersion(version3, version4));
    }
}
