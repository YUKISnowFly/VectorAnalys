class File
{
private:
	FILE* fp;

public:
	void open(char* str);
	void print();
	void close();
	Vector3 getVec();
};

void File::open(char* str)
{
	fp = fopen(str, "r");
}

Vector3 File::getVec()
{
	char str[50];
	char tempStr[3][20];
	Vector3 vec;

	fgets(str, 50, fp);

	for (int i = 0, j = 0, k = 0; i < 50; i++)
	{
		if (str[i] == '\t' || str[i] == '\n')
		{
			if (k == 0) vec.x = atof(tempStr[k]);
			else if (k == 1) vec.y = atof(tempStr[k]);
			else if (k == 2) vec.z = atof(tempStr[k]);
			j = 0;
			k++;
			if (str[i] == '\n') break;
		}
		else
		{
			tempStr[k][j] = str[i];
			j++;
		}
	}

	return vec;
}

void File::close()
{
	fclose(fp);
}