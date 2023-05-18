namespace Math
{
    template<typename T>
    class Coord
    {
    public:
        T x;
        T y;
    public:
        Coord(T x = 0, T y = 0):
            x(x),
            y(y)
        {
        }
        
        ~Coord()
        {
        }
      
        void operator=(Coord<T> right)
        {
            x = right.x;
            y = right.y;
        }

	Coord<T> operator-(Coord<T> right)
	{
	    return Coord<T>(x - right.x, y - right.y);
	}

	template<typename TU>
        Coord<T> operator*(TU right)
        {
            return Coord<T>(right * x, right * y);
        }

        void operator-=(Coord<T> right)
        {
            this->x -= right.x;
 	    this->y -= right.y;	    
	}

        Coord<T> operator+(Coord<T> right)
        {
            return Coord<T>(this->x + right.x, this->y + right.y);
        }

	template<typename TU>
        void operator*=(TU right)
        {
	    this->x *= right;
	    this->y *= right;
        }

	void operator+=(Coord<T> right)
        {
            this->x += right.x;
	    this->y += right.y;
        }
    };    
    typedef Coord<float> Coordf;
}
