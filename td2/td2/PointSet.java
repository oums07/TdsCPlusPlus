package td2;

import java.util.ArrayList;

public class PointSet{
	private ArrayList<Point> pts = new ArrayList<Point>(); // Ici on initialise diretement donc pas besoin de constructeur
	
	public void add(Point p) {
		pts.add(p);
	}
	
	public boolean has(Point p) {
		for (Point e:pts) {
			if (e.equals(p)) {return true;}
		}
		return false;
	}
	
	public String toString() {
		return pts.toString();
	}
	
	public ArrayList<Point> getPointSet() {
		return pts;
	}
	
	public PointSet union(PointSet other) {
		PointSet l = other;
		for (Point e:pts) {
			if (!l.has(e)) {
				l.add(e);
			}
		}
		return l;
	}
	
	public PointSet intersection(PointSet other) {
		PointSet l = new PointSet();
		for (Point e:pts) {
			if (other.has(e)) {
				l.add(e);
			}
		}
		return l;
	}
	
	public String draw(Image img) {
		for (Point p:pts) {
			img.set(p);
		}
		return img.toString();
	}
	
	public static void main(String[] args) {
		PointSet pts1 = new PointSet();
		PointSet pts2 = new PointSet();
		
		for (int i=0; i<5; i++) {
			pts1.add(new Point(i, i));
			pts2.add(new Point(i, 4-i));
		}
		
		//System.out.println(pts1.toString());
		//System.out.println(pts2.toString());
		
		//PointSet inter = pts1.intersection(pts2);
		//System.out.println(inter.toString());
		
		Image img = new Image(5, 5);	
		System.out.println(pts1.draw(img));
	}
	
}
