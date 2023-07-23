using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace bumgardner_midterm
{
    //JARED BUMGARDNER
    //COP4365c Midterm Assignment


    //|=====================================|
    //|_________List of All Shapes__________|
    //|=====================================|
    public class ListShapes                                 //List of all Shapes - Class
    {
        //properties
        public List<Shape> queue = new List<Shape>();
        public Object[] register;

        //methods
        public void enqueue(Shape toQueue)          
        {
            queue.Add(toQueue);
        }

        public void finalizeQueue(List<Shape> allShapes)
        {
            //Parse Queue of shapes for detail
            Shape[] shapesFromList = allShapes.ToArray();

            //Create final register
            register = new Object[2 * shapesFromList.Length];

            //Finalize parsed list of shapes
            for (int i = 0; i <= shapesFromList.Length - 1; i++)
            {
                //add shapes to register
                register[i] = shapesFromList[i];

                //register string for object
                string infoString = shapesFromList[i].ToString();
                register[++i] = infoString;
            }

            //print info
            for (int j = 0; j <= shapesFromList.Length - 1; j++)
            {
                shapesFromList[j].about();
            }

        }

        //constructors
        public ListShapes() { } //Default

        public ListShapes(Shape toQueue) //Initial shape provided
        {
            this.enqueue(toQueue);
        }
    }


    //|=====================================|
    //|________________Shape________________|
    //|=====================================|
    public abstract class Shape                             //Shape - Class
    {
        //method
        public virtual void about()
        {
            Console.Write("\n--area: {0}", this.AREA);
        }

        public virtual string toString()
        {
            return String.Format("\n{0}", this.AREA);
        }

        //properties
        public abstract double AREA                         //Read-only area
        {
            get;
        }

    }

    //|=====================================|
    //|__________Dimensioned Shape__________|
    //|=====================================|
    public abstract class TwoDimensionalShape : Shape               //2D Shape - Class
    {
        //method
        public abstract override void about();

        //properties
        public abstract override double AREA                        //Read-only area
        {
            get;
        }

    }

    public abstract class ThreeDimensionalShape : Shape             //3D Shape - Class
    {
        //method
        public override void about()
        {
            Console.Write("\n--volume: {0}", VOLUME);
            base.about();
        }

        public override string toString()
        {
            return String.Format("\n{0},\n{1}", this.AREA, this.VOLUME);
        }

        //properties
        public abstract override double AREA                        //Read-only area & volume
        {
            get;
        }
        public abstract double VOLUME
        {
            get;
        }

    }

    //|=====================================|
    //|___________Specified Shape___________|
    //|=====================================|
    public class Circle : TwoDimensionalShape                           //Circle - Class
    {
        //properties
        public override double AREA
        {
            get;
        }

        //methods
        public override void about()
        {
            Console.Write("\n\nType: CIRCLE\n-area: {0}", this.AREA);
        }

        //constructors
        public Circle() { } //Default

        public Circle(double radius) //Radius Provided
        {
            this.AREA = Math.PI * radius * radius;
        }
    }

    public class Square : TwoDimensionalShape                           //Square - Class
    {
        //properties
        public override double AREA
        {
            get;
        }

        //methods
        public override void about()
        {
            Console.Write("\n\nType: SQUARE\n-area: {0}", this.AREA);
        }

        //constructors
        public Square() { } //Default

        public Square(double length) //Length Provided
        {
            this.AREA = length * length;
        }
    }

    public class Sphere : ThreeDimensionalShape                         //Sphere - Class
    {
        //properties
        public override double AREA
        {
            get;
        }
        public override double VOLUME
        {
            get;
        }

        //methods
        public override void about()
        {
            Console.Write("\n\nType: SPHERE");
            base.about();
        }

        //constructors
        public Sphere() { } //Default

        public Sphere(double radius) //Area-Volume Provided
        {
            this.AREA = 4 * Math.PI * radius * radius;
            this.VOLUME = (4.0 / 3.0) * Math.PI * radius * radius * radius;
        }
    }

    public class Cube : ThreeDimensionalShape                                      //Cube - Class
    {
        //properties
        public override double AREA
        {
            get;
        }
        public override double VOLUME
        {
            get;
        }

        //methods
        public override void about()
        {
            Console.Write("\n\nType: CUBE");
            base.about();
        }

        //constructors
        public Cube() { } //Default

        public Cube(double length) //Area - Volume Provided
        {
            //calc area & volume
            this.AREA = 6 * length * length;
            this.VOLUME = length * length * length;
        }

    }

    //|=====================================|
    //|_______________Program_______________|
    //|=====================================|
    class Program
    {
        static void Main(string[] args)
        {
            //Setup Shape Enroller
            ListShapes enroller = new ListShapes();


            //Intro / get initial values from user
            Console.Write("\n***Shapes***\n");
            Console.Write("\n-How many shapes would you like to create? ");
            string numShapeRaw = Console.ReadLine();

            int numShapes;
            Int32.TryParse(numShapeRaw, out numShapes);

            //Test for value bounds
            while (numShapes < 0)
            {
                Console.Write("\nError: try again.");
                Console.Write("\n-How many shapes would you like to create? ");
                string retryRaw = Console.ReadLine();

                int retry;
                Int32.TryParse(retryRaw, out retry);

                numShapes = retry;

            }


            //Create desired shapes
            for (int i = 1; i <= numShapes; i++)
            {
                Console.Write("\n-Select a shape to create: ");
                Console.Write("\n---[1]: Circle\n---[2]: Square");
                Console.Write("\n---[3]: Sphere\n---[4]: Cube");
                Console.Write("\n");
                string shapeChoiceRaw = Console.ReadLine();
                int shapeChoice;
                Int32.TryParse(shapeChoiceRaw, out shapeChoice);


                //Get data for chosen shapes
                switch (shapeChoice)
                {
                    case 1: //Circle
                            //Get user input
                        Console.Write("\n---(Circle) Please enter a radius: ");
                        Console.Write("\n");
                        string radiusCircleRaw = Console.ReadLine();

                        int radiusC;
                        Int32.TryParse(radiusCircleRaw, out radiusC);
                        Console.Write("\n");

                        //Create circle
                        Circle circ = new Circle(radiusC);
                        enroller.enqueue(circ);
                        break;

                    case 2: //Square
                            //Get user input
                        Console.Write("\n---(Square) Please enter a side length: ");
                        Console.Write("\n");
                        string lengthSquareRaw = Console.ReadLine();

                        int lengthS;
                        Int32.TryParse(lengthSquareRaw, out lengthS);
                        Console.Write("\n");

                        //Create square
                        Square squa = new Square(lengthS);
                        enroller.enqueue(squa);
                        break;

                    case 3: //Sphere
                            //Get user input
                        Console.Write("\n---(Sphere) Please enter a radius: ");
                        Console.Write("\n");
                        string radiusSphereRaw = Console.ReadLine();

                        int radiusS;
                        Int32.TryParse(radiusSphereRaw, out radiusS);
                        Console.Write("\n");

                        //Create sphere
                        Sphere sph = new Sphere(radiusS);
                        enroller.enqueue(sph);
                        break;

                    case 4: //Cube
                            //Get user input
                        Console.Write("\n---(Cube) Please enter a side length: ");
                        Console.Write("\n");
                        string lengthCubeRaw = Console.ReadLine();

                        int lengthC;
                        Int32.TryParse(lengthCubeRaw, out lengthC);
                        Console.Write("\n");

                        //Create cube
                        Cube cub = new Cube(lengthC);
                        enroller.enqueue(cub);
                        break;

                    default: //default
                        Console.Write("\nERROR: try again; not valid input");
                        Console.Write("\n-Select a shape to create: ");
                        Console.Write("\n---[1]: Circle\n---[2]: Square");
                        Console.Write("\n---[3]: Sphere\n---[4]: Cube");
                        Console.Write("\n");
                        shapeChoiceRaw = Console.ReadLine();
                        Int32.TryParse(shapeChoiceRaw, out shapeChoice);

                        break;
                }

            }
            //Process Shapes
            enroller.finalizeQueue(enroller.queue);

            //Bye
            Console.Write("\n\nBye.\n");
            Console.Beep();
            Console.ReadLine();
        }
    }
}