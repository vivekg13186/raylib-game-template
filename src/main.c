#include "raylib.h"
#include "schrift.h"
#include <stdio.h>
#include <stdlib.h>
int isPrintable(int c)
{
    switch (c)
    {
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
        return c;
    default:
        return 0;
    }
}

char *line;
int li = 0;

SFT sft;
SFT_Image* glyphs[130];

SFT_Image* add_glyph(int cp)
{

	SFT_Glyph gid;  //  unsigned long gid;
	if (sft_lookup(sft, cp, &gid) < 0)
		{
            printf("Missing char %c",cp);
            return 0;
        }

	SFT_GMetrics mtx;
	if (sft_gmetrics(sft, gid, &mtx) < 0){
       printf("bad glyph metrics %c",cp) ;
       return 0;
    }
		 
    SFT_Image* img =(SFT_Image*) malloc(sizeof(STF_Image));
    img->width  = (mtx.minWidth + 3) & ~3;
    img->height =  mtx.minHeight;


	im ->pixels = malloc(img.width * img.height);
	if (sft_render(sft, gid, img) < 0){
       printf("render issue    %c",cp) ;
       return 0;
    }
		


	return img;
}

int initFont()
{
    int s = 2;
    sft.xScale = 16 * s;
    sft.yScale = 16 * s;
    sft.flags = SFT_DOWNWARD_Y;
    sft.font = sft_loadfile("C:\\Users\\Vivek\\Developer\\lce\\src\\resources\\font.ttf");
    if (sft.font == NULL){
        return -1;
    }
    for(int i=0;i<130;i++){
        if(isPrintable(i)!=0){
            glyphs[i]= add_glyph(i);
        }else{
            glyphs[i]= 0;
        }
    }
}
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    line = malloc(1024);
    if(initFont()==-1){
        return -1;
    }

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        int keyCode = GetCharPressed();
        while (keyCode != 0)
        {
            if (isPrintable(keyCode) != 0)
            {
                line[li++] = keyCode;
                printf("%s\n", line);
            }

            keyCode = GetCharPressed();
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow(); // Close window and OpenGL context
    return 0;
}