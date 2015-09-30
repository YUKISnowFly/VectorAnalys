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

void Fps::Start()	//現在時間を開始時間に
{
	startTime = clock();
}

void Fps::End()		//現在時間と開始時間との差を経過時間に
{
	endTime = clock() - startTime;
}

double Fps::Get()	//経過時間を秒にしてdouble型でreturn
{
	double t = (double)endTime / CLOCKS_PER_SEC;
	return t;
}