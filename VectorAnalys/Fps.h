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

void Fps::Start()	//���ݎ��Ԃ��J�n���Ԃ�
{
	startTime = clock();
}

void Fps::End()		//���ݎ��ԂƊJ�n���ԂƂ̍����o�ߎ��Ԃ�
{
	endTime = clock() - startTime;
}

double Fps::Get()	//�o�ߎ��Ԃ�b�ɂ���double�^��return
{
	double t = (double)endTime / CLOCKS_PER_SEC;
	return t;
}