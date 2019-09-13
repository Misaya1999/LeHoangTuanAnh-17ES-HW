package ex3;

class Circle
{
	private double radius;
	public Circle(double value)
	{
		radius=value;
	}
	public double perimeter()
	{
		return 2*Math.PI*Math.pow(radius,2);
	}
	public double area()
	{
		return Math.PI*radius;
	}
    public static void main(String args[])
	{
		Circle Circ1, Circ2;
		Circ1 = new Circle(8);
		Circ2 = new Circle(16);	
		System.out.println("area of Circ1 is: "+Circ1.area());
		System.out.println("perimeter of Circ1 is: "+Circ1.perimeter());
		System.out.println("area of Circ2 is: "+Circ2.area());
		System.out.println("perimeter of Circ2 is: "+Circ2.perimeter());
	}
}
