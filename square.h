
class square
{
public:
	square(int);	
	~square();
	void print();
	void randomize();
	int score();

private:
	int size;
	int* array;
};
