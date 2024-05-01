
#include "GameMain.h"

using namespace std;

#undef main
int main()
{
    bool bInit = GameMain::GetInstance()->Init();
    bool bLoadData = GameMain::GetInstance()->LoadData();
    if (bInit == true && bLoadData == true)
    {
        GameMain::GetInstance()->Loop();
    }

    GameMain::GetInstance()->Close();
    GameMain::GetInstance()->FreeInstance();
    return 0;
}
