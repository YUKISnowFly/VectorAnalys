class Fps
{
private:
	clock_t
		startTime,
		endTime;

public:
	void Start();
	void End();
	double Get();
};

void Fps::Start()
{
	startTime = clock();
}

void Fps::End()
{
	endTime = clock() - startTime;
}

double Fps::Get()
{
	double t = (double)endTime / CLOCKS_PER_SEC;
	return t;
}