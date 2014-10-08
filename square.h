
class square
{
public:
	square(int);	
	square(const square& rhs);
	~square();
	void print();
	void randomize();
	int score();

	bool operator> (square &lhs);
	bool operator< (square &lhs);
	square& operator= (square &lhs);
private:
	int size;
	int* array;
};
