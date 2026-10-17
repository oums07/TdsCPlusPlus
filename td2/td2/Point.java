package td2;

public class Point {
	private int x, y;
	
	public Point(int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "(" + this.x + "," + this.y + ")";
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	public Point clone() {
		Point p = new Point(x, y);
		return p;
	}
	
	public void move(int dx, int dy) {
		this.x += dx;
		this.y += dy;
	}
	
	public boolean equals(Point p1) {
		return (x == p1.getX() && this.y == p1.getY());
	}
	
	public static void main(String[] args) {
		Point p1 = new Point(4,1);
		System.out.println(p1.toString());
		Point p2 = p1.clone();
		p2.move(2, 3);
		System.out.println(p2.toString());
		System.out.println(p1.equals(p2));
		
	}
}
