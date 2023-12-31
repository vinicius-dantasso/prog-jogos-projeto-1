/**********************************************************************************
// FontDemo
// 
// Cria��o:     07 Out 2011
// Atualiza��o: 16 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Testa a classe Font com exibi��o de texto com diversas fontes.
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "TitleScreen.h"
#include "Level.h"

// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(640, 480);
    engine->window->Color(255,255,255);
    engine->window->Title("Fil� - The Great Escapade");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new TitleScreen());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

