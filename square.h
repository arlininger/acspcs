
class square
{
public:
	square(const int);	
	square(const square& rhs);
	~square();
	void print() const;
	void randomize();
	int score() const;

	bool operator> (const square &lhs);
	bool operator< (const square &lhs);
	square& operator= (const square &lhs);
private:
	int size;
	int* array;
};
