
#define OLC_PGE_APPLICATION
#include <iostream>
#include "olcPixelGameEngine.h"
#include <thread>
static const size_t width = 256, height = 256;
static const size_t tapeSize = width * height * 3 + 10000;
static const UINT8 settings = 4;
static PUINT8 tape = (PUINT8)calloc(tapeSize, sizeof(unsigned char));
static PUINT8 const startPos = tape + width * height * 3 + settings + 1;

auto programCode = R"(

	+[<<<<+[<+[+>>+ +>-->+ |<<<<<]>+]|<<+|]

)";
class Window : public olc::PixelGameEngine
{
public:
	Window();

public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;
};
void graphicsfuck(const char* code);
bool close = false;
int main()
{

	Window FGWindow;
	if (FGWindow.Construct(width, width, 2, 2))
	{
		auto programThreadFunc = [&]() 
		{
			graphicsfuck(programCode);
			close = true;
		};
		std::thread programThread(programThreadFunc);
		FGWindow.Start();
		close = true;
		if(programThread.joinable())programThread.join();
	}
}


void graphicsfuck(const char* code)
{
	startPos[-1] = settings;
	startPos[-2] = 1;
	PUINT8 ptr = startPos;
	size_t loop;

	for (const char* i = code; *i != 0 && !close; i++)
	{
		if (ptr < tape || ptr > tape + tapeSize) throw std::out_of_range("the writing pointer is out of range");
		switch (*i)
		{
		case '>':
			++ptr;
			break;
		case '<':
			--ptr;
			break;
		case '+':
			++ * ptr;
			break;
		case '-':
			-- * ptr;
			break;
		case '|':
			ptr = startPos;
			break;
		case '.':
			putchar(*ptr);
			break;
		case ',':
			*ptr = getchar();
			break;
		case '[':
			continue;
			break;
		case ']':
			if (*ptr)
			{
				loop = 1;
				while (loop > 0)
				{
					--i;
					if (*i == '[')
						loop--;
					else if (*i == ']')
						loop++;
				}
			}
		}
		if (startPos[-3])
		{
			ptr = tape + (startPos[-5] + startPos[-4] * width) * 3;
			startPos[-3] = 0;
		}
	}
}

Window::Window()
{
	sAppName = "GaphicsFuck";
}

bool Window::OnUserCreate()
{
	return true;
}

bool Window::OnUserUpdate(float fElapsedTime)
{
	if (startPos[-2])
	{
		for (int y = 0; y < ScreenHeight(); y++)
			for (int x = 0; x < ScreenWidth(); x++)
			{
				PUINT8 color = tape + (x + y * width) * 3;
				Draw(x, y, olc::Pixel(color[0], color[1], color[2]));
			}
		startPos[-2] = 0;
	}
	return !close;
}
