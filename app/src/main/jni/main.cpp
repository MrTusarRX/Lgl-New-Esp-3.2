
/*By Puruliaking007 X MrTusarRX */

#include "Includes/data.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_android_support_Menu_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas) {
                es = NepEsp(env, espView, canvas);
    if (es.isValid()){
        DrawESP(es, es.getWidth(), es.getHeight());
    }
    
 }


/*Hooks*/



int(*_MoneyX)(void *player);
int MoneyX(void *player) {
    if(player != NULL) {
        if(Money) {
            return 69696969696;
        }
    }
    return _MoneyX(player);
}
int(*_Diamond)(void *player);
int DiamondX(void *player) {
    if(player != NULL) {
        if(Diamond) {
            return 696969696969;
        }
    }
    return _Diamond(player);
}
int(*_Gold)(void *player);
int GoldX(void *player) {
    if(player != NULL) {
        if(Gold) {
            return 696969696969;
        }
    }
    return _Gold(player);
}
int(*_Ammo)(void *player);
int AmmoX(void *player) {
    if(player != NULL) {
        if(Ammo) {
            return 696969696969;
        }
    }
    return _Ammo(player);
}




void *get_MyPlayer(void *player) {  // ekhan theke amar player er instance peye jabo
    myPlayer = player;
    return myPlayer;
}

void (*heal)(void *instance,int value);
void(*old_HealthUpdate)(void *player);
void GameHealth(void *player) {
        if (player != NULL) {
        if (UnlimitedHealth) {
          heal(player, 9999999999);
   
   }
   if (fly) {
    Vector3 PlayerLocation = GetPlayerLocation(player); 
                    set_position(getTransform(player),
                                 Vector3(PlayerLocation.x, PlayerLocation.y = (float) axis, PlayerLocation.z));            
        }
        if (isTelekill) {
             Vector3 PlayerLocation = GetPlayerLocation(playerlate); 
             set_position(getTransform(player), Vector3(PlayerLocation.x , PlayerLocation.y , PlayerLocation.z - 4));            
        }
		
		if (isMasskill) {
             Vector3 PlayerLocation = GetPlayerLocation(myPlayer); //MyPlayer means your player//
             set_position(getTransform(playerlate), Vector3(PlayerLocation.x, PlayerLocation.y, PlayerLocation.z - 4));
        }
   }
    get_MyPlayer(player);
  return old_HealthUpdate(player);
}




int(*_Grenade)(void *player);
int GrenadeX(void *player) {
    if(player != NULL) {
        if(Grenade) {
            return 696969696969;
        }
    }
    return _Grenade(player);
}


int(*_Aidkit)(void *player);
int AidkitX(void *player) {
    if(player != NULL) {
        if(Aidkit) {
            return 696969696969;
        }
    }
    return _Aidkit(player);
}



void (*damage)(void *instance,float value);
void (*_AddDamage)(void *instance);
void AddDamageX(void *instance) {
    if (instance != NULL) {
       if(DamageX) {
            damage(instance, 99999.0f);
    }
    }
   
    return _AddDamage(instance);
}



void (*OnDestroy)(void *player);
void _OnDestroy(void *player) {
    if (player != NULL) {
        OnDestroy(player);
        espManager->removeEnemyGivenObject(player);
    }
}   




void (*update)(void *player);
void _update(void *player) {
    if (player != NULL) {
        update(player);
        enemyPlayer = player;
    }
    if (ESP) {
        if (enemyPlayer) {
            espManager->tryAddEnemy(player);
        }
    }
   get_Player(player);
update(player);
}





























// we will run our hacks in a new thread so our while loop doesn't block process main thread
void *hack_thread(void *) {
    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap("libil2cpp.so");
        sleep(3);
    } while (!il2cppMap.isValid() && mlovinit());
    setShader("_BumpMap");
    LogShaders();
    Wallhack();
    espManager = new ESPManager();
    
    do {
        sleep(1);
    } while (!isLibraryLoaded (OBFUSCATE("libMyLibName.so")));
    getAddress();
    
    HOOKAU(UpDate, _update, update);
	
	
    HOOKAU(Destroy, _OnDestroy, OnDestroy);
    HOOKAU(MoneyOffset, MoneyX, _MoneyX);
    HOOKAU(GoldOffset, GoldX, _Gold);
    HOOKAU(DiamondOffset, DiamondX, _Diamond);
    HOOKAU(AmmoOffset, AmmoX, _Ammo);

    
    HOOKAU(HealthUp, GameHealth, old_HealthUpdate);
    heal = (void (*)(void *, int))HealthOffset.getAddr();
    
    HOOKAU(grenade, GrenadeX, _Grenade);
    HOOKAU(Medikit, AidkitX, _Aidkit);
    //HOOKAU(Lamage, DamageX, _Damage);
    
   
    
    HOOKAU(LatUpdate, AddDamageX, _AddDamage);
    damage = (void (*)(void *, float))SetDamage.getAddr();
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
   return NULL;
}


jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
                        OBFUSCATE("Category_Gun"),
            OBFUSCATE("6_Toggle_Unlimited Ammo"),		
           OBFUSCATE("415_Toggle_Get Weapon Damage"),
            
            OBFUSCATE("406_Toggle_Unlimited Grenade"),
            OBFUSCATE("407_Toggle_Unlimited Medikits"),
			OBFUSCATE("Category_Player"), //Not counted
            OBFUSCATE("416_Toggle_Masskill Test"),
			OBFUSCATE("417_Toggle_Teleport"),
			OBFUSCATE("403_Toggle_Fly"),
			OBFUSCATE("404_SeekBar_Fly Position_1_21"),
			OBFUSCATE("Category_Shop"),
            OBFUSCATE("8_Toggle_Unlimited Gold"),//1
            OBFUSCATE("9_Toggle_Unlimited Diamond"),//1
            OBFUSCATE("10_Toggle_Unlimited Money"),//1
             OBFUSCATE("Category_Esp"),
			OBFUSCATE("418_Toggle_Esp Test"),
            OBFUSCATE("0_Toggle_Enable Esp"),//0
            OBFUSCATE("1_Toggle_ESP Line"),//1
            OBFUSCATE("2_Toggle_ESP Box"),//1   
            OBFUSCATE("3_Toggle_ESP Health"),//1
            OBFUSCATE("4_Toggle_ESP Distance"),//1
            OBFUSCATE("13_Toggle_ESP 3D BOX"),
			OBFUSCATE("400_Toggle_ESP Random Color"),//1
			OBFUSCATE("Category_Chams"),
            OBFUSCATE("25_Toggle_DEFAULT CHAMS"), //0 Case
            OBFUSCATE("16_Toggle_WIREFRAME CHAMS"), //1 Case
            OBFUSCATE("17_Toggle_GLOW CHAMS"), //2 Case
            OBFUSCATE("18_Toggle_OUTLINE CHAMS"), //3 Case
            OBFUSCATE("19_Toggle_RAINBOW CHAMS"), //4 Case
            OBFUSCATE("20_SeekBar_LINE WIDTH_0_10"),//5 Case
            OBFUSCATE("21_SeekBar_COLOR RED_0_255"),//6 Case
            OBFUSCATE("22_SeekBar_COLOR GREEN_0_255"),//7 Case
            OBFUSCATE("23_SeekBar_COLOR BLUE_0_255"),//8 Case
       
            
    };

    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;

        switch (featNum) {
        case 0:
            ESP = boolean;
		//	ESPCircle = boolean;
            break;
        case 1:
            ESPLine = boolean;
            
            break;
         case 2:
            ESPBox = boolean;
            
            break;   
         
        case 3:
            ESPHealth = boolean;
            
            break;
        case 4:
            ESPDistance = boolean;
            break;
        case 5:
            IsAimBot = boolean;
            break;
        case 6:
            Ammo = boolean;

            break;
         case 13:
             ESPBox3d = boolean;
             break;
        case 7:
            Grenade = boolean;
            break;
        case 8:
            Gold = boolean;
            break;
        case 9:
            Diamond = boolean;
            break;
        case 10:
            Money = boolean;
            break;
        case 11:
            Medkits = boolean;
            break;
        case 12:          
            Ammo = boolean;
        break;
        case 130:
            Glove = boolean;
            break;
         case 14:
             
             Gunskin = boolean;
            
             break;
         case 15:
             Skin = boolean;
             break;
         case 25:
            SetWallhack(boolean); 
            break;    
        case 16:           
            SetWallhackW(boolean);
            break;    
        case 17:          
            SetWallhackG(boolean);
            break;     
        case 18:          
            SetWallhackO(boolean);
            break;    
        case 19:     
            SetRainbow(boolean);
            break;
        case 20:
            SetW(value);
            break;         
        case 21:
            SetR(value);
            break;
        case 22:
            SetG(value);
            break;
        case 23:
            SetB(value);
            break; 	
        case 400:
			
			ESPrandom = boolean;
			break;
			case 401:
				UnlimitedHealth = boolean;
				break;
				case 402:
				Drone = boolean;
				break;
				case 403:
				fly = boolean;
				break;
				case 404:		
            switch (value) {
        case 0:
            axis = 2;
            break;
            
        case 1:
            axis = 1.7;
            break;
            
        case 2:
            axis = 3.3;
            break;
            
        case 3:
            axis = 4.8;
            break;
        
        case 4:
            axis = 5;
            break;
            
        case 5:
            axis = 6;
            break;
            
            case 6:
                axis = 7;
                break;
                
                case 7:
                    axis = 8;
                    break;
                    
                    case 8:
                        axis = 9;
                        break;
                        
                        case 9:
                            axis = 10;
                            break;
                            case 10:
                                axis = 20;
                                case 11:
            axis = 21;
            break;
            
        case 12:
            axis = 22;
            break;
            
        case 13:
            axis = 23;
            break;
            
        case 14:
            axis = 28;
            break;
        
        case 15:
            axis = 30;
            break;
            
        case 16:
            axis = 31;
            break;
            
            case 17:
                axis = 35;
                break;
                
                case 18:
                    axis = 38;
                    break;
                    
                    case 19:
                        axis = 39;
                        break;
                        
                        case 20:
                            axis = 40;
                            break;
                            case 21:
                                axis = 50;
            }
            break;
            break;
				case 405:
				WinA = boolean;
				break;
				case 406:
				Grenade = boolean;
				break;
				case 407:
				Aidkit = boolean;
				break;
				case 409:
                Health = boolean;
                break;
                case 414:
				LightRadius = value;
				break;
				case 410:
					Aimbotm = boolean;
					break;
					case 411:
						Freezombie = boolean;
						break;
						case 412:
							Resume = boolean;
							break;
							case 413:
							LevelRank = value;
							break;
							case 415:
							DamageX = boolean;
							break;
							case 416:
								isMasskill = boolean;
								IsAimBot = boolean;
								break;
								case 417:
									isTelekill = boolean;
									break;
									case 418:
										ESPCount = boolean;
										break;
										}
										}

__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}
/*Dont Touch Me*/
#include "Includes/canva.h"
