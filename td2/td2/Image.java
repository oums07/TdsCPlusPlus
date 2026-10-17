package td2;

public class Image {
	private int width, height;
	char[][] img;
	
	
	public Image(int width, int height) {
		this.width = width;
		this.height = height;
		this.img = new char[height][width];
		
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				img[i][j] = '_';
			}
		}
	}
	
	public void set(Point p) {
		int x = p.getX();
		int y = p.getY();
		img[y][x] = 'X';
	}
	
	public void unset(Point p) {
		int x = p.getX();
		int y = p.getY();
		img[y][x] = '_';
	}
	
	public String toString() {
		String s = "" ;
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				s += img[i][j];
			}
			s += "\n";
		}
		return s;
	}
	
}
