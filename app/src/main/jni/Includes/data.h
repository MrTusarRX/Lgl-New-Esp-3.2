#include <list>
#include <vector>
#include <string>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "Unity/Vector2.h"
#include "Unity/Vector3.h"
#include "Unity/Rect.h"
#include "Unity/Color.h"
#include "Unity/Quaternion.h"
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "Includes/Chams.h"
#include "Includes/MonoString.h"
#include "Includes/Strings.h"
#include "KittyMemory/MemoryPatch.h"
#include "Menu/Setup.h"
#include "NepDraw.h"
#include "NepAU/AutoUpdate.cpp"
using namespace NepSymbol;
#include "hooks.h"
#include "ESPManager.h"

ESPManager *espManager;
NepEsp es;

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

bool ESP, ESPLine, ESPBox, ESPBox3d, ESPrandom, ESPHealth, ESPDistance, IsAimBot, Money, Gold, Diamond, Medkits,Ammo, Health, Drone, Aidkit, Grenade, WinA, ESPCircle, ESPCount;
bool isMasskill = false;
bool isTelekill = false;
bool UnlimitedHealth, Glove, Gunskin, Skin, Damage, Aimbotm, Freezombie, Resume, Level,DamageX;

bool fly = false;
float axis = 1.7f;


int LevelRank = 1;

float LightRadius = 1;




float get_3D_Distance(float Self_x, float Self_y, float Self_z, float Object_x, float Object_y, float Object_z) {
    float x, y, z;
    x = Self_x - Object_x;
    y = Self_y - Object_y;
    z = Self_z - Object_z;
    return (float)(sqrt(x * x + y * y + z * z));
}



void *enemyPlayer = NULL;
void *playerlate = NULL;
void *get_Player(void *player) {
    playerlate = player;
    return playerlate;
}


Vector3 add(Vector3 a, Vector3 b) {
    Vector3 c;
    c.x= a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}
void Draw3dBox(NepEsp esp,Color espColor, Vector3 Transform,void * camera,int glHeight,int glWidth)
{
    Vector3 position2 = add(Transform, Vector3(0.6, 1.6, 0.6)); 
    Vector3 position3 = add(Transform, Vector3(0.6, 0, 0.6));
    Vector3 position4 = add(Transform, Vector3(-0.5, 0, 0.6)); 
    Vector3 position5 = add(Transform, Vector3(-0.5, 1.6, 0.6));
    Vector3 position6 = add(add(Transform, Vector3(0.6, 1.6, 0)), Vector3(0, 0, -0.6));
    Vector3 position7 = add(add(Transform, Vector3(0.6, 0, 0)), Vector3(0, 0, -0.6));
    Vector3 position8 = add(add(Transform, Vector3(-0.5, 0, 0)), Vector3(0, 0, -0.6)); 
    Vector3 position9 = add(add(Transform, Vector3(-0.5, 1.6, 0)), Vector3(0, 0, -0.6));

    Vector3 vector = WorldToScreenPoint(camera, position2);
    Vector3 vector2 = WorldToScreenPoint(camera, position3);
    Vector3 vector3 = WorldToScreenPoint(camera, position4);
    Vector3 vector4 = WorldToScreenPoint(camera, position5);
    Vector3 vector5 = WorldToScreenPoint(camera, position6);
    Vector3 vector6 = WorldToScreenPoint(camera, position7);
    Vector3 vector7 = WorldToScreenPoint(camera, position8);
    Vector3 vector8 = WorldToScreenPoint(camera, position9);

    if (vector.z > 0 && vector2.z > 0 && vector3.z > 0 && vector4.z > 0 && vector5.z > 0 && vector6.z > 0 && vector7.z > 0 && vector8.z > 0 )
    {
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector.x)), (glHeight - vector.y)), Vector2((glWidth - (glWidth - vector2.x)), (glHeight - vector2.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector3.x)), (glHeight - vector3.y)), Vector2((glWidth - (glWidth - vector2.x)), (glHeight - vector2.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector.x)), (glHeight - vector.y)), Vector2((glWidth - (glWidth - vector4.x)), (glHeight - vector4.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector4.x)), (glHeight - vector4.y)), Vector2((glWidth - (glWidth - vector3.x)), (glHeight - vector3.y)));
        
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector5.x)), (glHeight - vector5.y)), Vector2((glWidth - (glWidth - vector6.x)), (glHeight - vector6.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector7.x)), (glHeight - vector7.y)), Vector2((glWidth - (glWidth - vector6.x)), (glHeight - vector6.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector5.x)), (glHeight - vector5.y)), Vector2((glWidth - (glWidth - vector8.x)), (glHeight - vector8.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector8.x)), (glHeight - vector8.y)), Vector2((glWidth - (glWidth - vector7.x)), (glHeight - vector7.y)));
 
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector.x)), (glHeight - vector.y)), Vector2((glWidth - (glWidth - vector5.x)), (glHeight - vector5.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector2.x)), (glHeight - vector2.y)), Vector2((glWidth - (glWidth - vector6.x)), (glHeight - vector6.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector3.x)), (glHeight - vector3.y)), Vector2((glWidth - (glWidth - vector7.x)), (glHeight - vector7.y)));
        esp.DrawLine(espColor, 2, Vector2((glWidth -(glWidth -vector4.x)), (glHeight - vector4.y)), Vector2((glWidth - (glWidth - vector8.x)), (glHeight - vector8.y)));
    }
}


Color Ka = Color(0,0,0,255);
bool R;
bool G;
bool B;
Color getColor() {
    
    if(Ka.r == 0 && Ka.g == 0 && Ka.b == 0) {
        Ka.r = 255;
        G = true;
        Ka.b = 0;
    }
    if(Ka.r == 0 && Ka.g == 255 && Ka.b == 0) {
        B = true;
        R = false;
        G = false;
    }
    if(Ka.r == 0 && Ka.g == 0 && Ka.b == 255) {
        R = true;
        G = false;
        B = false;
    }
    if(Ka.r == 255 && Ka.g == 0 && Ka.b == 0) {
        G = true;
        R = false;
        B = false;
    }
    if(R) {
        Ka.r += 1;
        Ka.g = 0;
        Ka.b -= 1;
    }
    if(G) {
        Ka.r -= 1;
        Ka.g += 1;
        Ka.b = 0;
    }
    if(B) {
        Ka.r = 0;
        Ka.g -= 1;
        Ka.b += 1;
    }
    
    return Ka;
    
}

void DrawESP(NepEsp esp, int screenWidth, int screenHeight) {
   // esp.DrawText(Color::Yellow(), "X_Tusar", Vector2(screenWidth / 2, screenHeight/ 10), 33);
void *player = playerlate;
void *MyPlayer= myPlayer;

if(ESP && player != nullptr && MyPlayer != nullptr) {
//Code Goes Inside it
    if (espManager->enemies->empty()) {
        return;
    }
    for (int i = 0; i < espManager->enemies->size(); i++) {
        void *Cam = get_camera();
        if(Cam != nullptr) {
            
        
        //Code Goes Here
        void *Player = (*espManager->enemies)[i]->object;
        
        if (Player != nullptr) {
            if(PlayerAlive(Player)) {
            //Code Goes Here
            Color clr;
                clr.a = 255;
                Rect rect;
                Vector3 PlayerPos = GetPlayerLocation(Player);
                Vector3 MyPlayerPos = GetPlayerLocation(MyPlayer);
                Vector3 PosNew = {0.f, 0.f, 0.f};
                PosNew = WorldToScreenPoint(Cam, PlayerPos);
                if (PosNew.z < 1.f) continue;
                Vector3 Origin;
                Origin = PlayerPos;
                Origin.y += 0.7f;
                float posnum = 10 * 0.1; /******* Hight slider * 0.1 ********/
                float posnum2 = 10 * 0.1;/******* Size slider * 0.1 ********/
                Origin.y += posnum;
                Vector3 BoxPosNew = {0.f, 0.f, 0.f};
                BoxPosNew = WorldToScreenPoint(Cam, Origin);
                float Hight =
                abs(BoxPosNew.y - PosNew.y) * (posnum2 / posnum), Width = Hight * 0.6f;

                rect = Rect(BoxPosNew.x - Width / 2.f,
                            screenHeight - BoxPosNew.y,
                            Width, Hight
                );
                 Vector2 DrawFrom = Vector2(screenWidth / 2, screenHeight / 10.6);
            Vector2 DrawTo = Vector2((screenWidth- (screenWidth - BoxPosNew.x)) + 5, (screenHeight - BoxPosNew.y));
            
			
			
                int MaxHealth = GetMaxHealth(Player);
            int CurHealth = GetPlayerHealth(Player);
        int max;
                                max = 255;

                                int max2;
                                max2 = 255;

                                int max3;
                                max3 = 255;
								Color espColor = Color(255,255,255,255);
								Color healthc = Color(0,0,255,64);
								if(ESPrandom) {
									espColor=getColor();
								} else {
									espColor = Color(255,255,255,255);

								}
                              
            
            if (ESPLine) {
                esp.DrawLine(Color::Green(), 2, DrawFrom, DrawTo);
            }
            if (ESPBox) {
                esp.DrawBox(Color::Blue(), healthc, 4.0f, rect); 
             }

            if(ESPCircle) {
               esp.DrawFilledCircle( Color::Green(), Vector2(screenWidth / 2, screenHeight/8), 10.0f);
            }
            if(ESPHealth) {
               esp.DrawHorizontalHealthBar(Vector2(rect.x - 7.0f, rect.y), rect.h, MaxHealth, CurHealth);
            }
            if(ESPBox3d) {
                Draw3dBox(esp, espColor, PlayerPos, Cam, screenHeight, screenWidth);
            }
			if(ESPDistance) {
                char extra[30];
float DistanceTo = get_3D_Distance(MyPlayerPos.x, MyPlayerPos.y, MyPlayerPos.z, PlayerPos.x, PlayerPos.y, PlayerPos.z);                  
                sprintf(extra, "[%0.0f M]", DistanceTo);
                esp.DrawText(espColor,  extra, Vector2((screenWidth - (screenWidth - BoxPosNew.x)), (screenHeight - BoxPosNew.y - 10.0f)), 20.0f);                     
            }
          /*  if(ESPDistance) {
                int distance = (int) Vector2::Distance(Vector2(screenWidth , screenHeight), Vector2(BoxPosNew.x, BoxPosNew.y));
                std::string distances;
               
                
                   distances = float_to_string(distance / 100);
             
               
               
                esp.DrawText(espColor,  distances.c_str(), Vector2((screenWidth - (screenWidth - BoxPosNew.x)), (screenHeight - BoxPosNew.y - 10.0f)), 17);
                
            }
			*/
			if(ESPCount){
               esp.DrawFilledCircle(Color::Red(), Vector2(screenWidth / 2.0, screenHeight / 15.0f), 31.0f);
               std::string Allplayers;
               Allplayers += std::to_string((int32_t) espManager->enemies->size());
               esp.DrawText(espColor, Allplayers.c_str(), Vector2(screenWidth / 2.0, screenHeight / 13.0f), 30.0f);     
            }  
        }else {
            espManager->removeEnemyGivenObject(Player);
        }
    }
    }

}
    }
}
