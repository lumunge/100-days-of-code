/*
 *  Class Diagram
 *
 *  ClickCounter
 *  **************************
 *
 *  count: int
 *
 *  **************************
 *
 *  click(): void
 *  setClickCount(clickCount: int): void
 *  getClickCount(): int
 *
 * *****************************
 *
 * */

public class ClickCounter{
    private int count;

    public ClickCounter(){
        count = 0;
    }

    public void click(){
        count++;
    }

    public void setClickCount(int clickCount){
        count = clickCount;
    }

    public int getClickCount(){
        return count;
    }
}

