// Leetcode #171 - Excel sheet column number

class ExcelColumnNumber{
    static int titleNum(String columnTitle){
        int columnNum = 0;
        for(char c : columnTitle.toCharArray()){
            int offset = 1 + c - 'A';
            columnNum = columnNum * 26 + offset;
        }
        return columnNum;
    }

    public static void main(String[] args){
        System.out.println(titleNum("A"));
        System.out.println(titleNum("AB"));
        System.out.println(titleNum("ZY"));
    }
}
