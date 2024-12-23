lib l2cpp;
Address transformOff,
        getpos, 
        wtsp, 
        getCam, 
        getHp,
        getMaxHp,
		HowBox,
		MagicBullet,
		LatUpdate,
		SetDamage,
        UpDate,
		Lamage,
        AutoplayUpdate,
        isAutoPlayBattle, 
        isAutoProcessMission,
        Medikit,
        RotateSpeed, 
        levell,
        amage,
        grenade,
        isShot,
        AmmoOffset,
        MoneyOffset,
        Win,
        WinUpdate,
        HealthUpdate,
        GoldOffset,
        DiamondOffset,
        UnlockGloveIdOffset,
        UnlockGunByNameOffset,
        UnlockDroneOffset,
        UnlockGunSkinOffset,
        HealthUp,
        Destroy,
        setlocal,
		HealthOffset,
		setpos,
        UnGloveUpdate;

void getAddress() {
    l2cpp.name = "libil2cpp.so";
    l2cpp.open();
    
    Uclass Component = l2cpp.getClass("UnityEngine", "Component");
    transformOff = Component.dump("get_transform");
    
    Uclass Tranf = l2cpp.getClass("UnityEngine", "Transform");
    getpos = Tranf.dump("get_position_Injected", 1);
    setpos = Tranf.dump("set_position_Injected", 1);
    setlocal = Tranf.dump("set_localScale_Injected", 1);
    
    Uclass Cam = l2cpp.getClass("UnityEngine", "Camera");
    wtsp = Cam.dump("WorldToScreenPoint_Injected", 3);
    getCam = Cam.dump("get_main");
    
    Uclass ZombieBase = l2cpp.getClass("DProject", "ZombieBase");
    getMaxHp = ZombieBase.dump("get_totalHP");
    getHp = ZombieBase.dump("get_curTotalHP");
    Destroy = ZombieBase.dump("OnDestroy");
    UpDate = ZombieBase.dump("LateUpdate");
    
    
    Uclass GunController = l2cpp.getClass("DProject", "GunController");
    AmmoOffset = GunController.dump("get_curBullet");
    LatUpdate = GunController.dump("LateUpdate");
    SetDamage = GunController.dump("SetDamageRate", 1);
    
    
        Uclass PlayerController = l2cpp.getClass("DProject", "PlayerController");
    HealthUp = PlayerController.dump("Update");
    
    
    Uclass DSystem = l2cpp.getClass("DProject", "DSystem");
    MoneyOffset = DSystem.dump("get_gameMoney");
    HowBox = DSystem.dump("get_HOWBox");
    grenade = DSystem.dump("get_grenadesCount");
    Medikit = DSystem.dump("get_aidKitCount");
    GoldOffset = DSystem.dump("get_payMoney");
    DiamondOffset = DSystem.dump("get_Diamond");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

void *getTransform(void *player) {
    if (!player) return NULL;
    static const auto get_transform_injected = reinterpret_cast<uint64_t(__fastcall *)(void *)>(transformOff.getAddr());
    return (void *) get_transform_injected(player);
}
Vector3 get_position(void *transform) {
    if (!transform)return Vector3();
    Vector3 position;
    static const auto get_position_injected = reinterpret_cast<uint64_t(__fastcall *)(void *,Vector3 &)>(getpos.getAddr());
    get_position_injected(transform, position);
    return position;
}
void set_position(void* transform, Vector3 test) {
    if (transform) {
        static const auto set_position_injected = reinterpret_cast<uintptr_t(__fastcall*)(void*, Vector3)>(setpos.getAddr());
        set_position_injected(transform, test);
        }

 }
Vector3 WorldToScreenPoint(void *transform, Vector3 test) {
    if (!transform)return Vector3();
    Vector3 position;
    static const auto WorldToScreenPoint_Injected = reinterpret_cast<uint64_t(__fastcall *)(void *,Vector3, int, Vector3 &)>(wtsp.getAddr());
      WorldToScreenPoint_Injected(transform, test, 4, position);
      return position;
}
void *get_camera() {
    static const auto get_camera_injected = reinterpret_cast<uint64_t(__fastcall *)()>(getCam.getAddr());
    return (void *) get_camera_injected();
}
Vector3 GetPlayerLocation(void *player) {
    return get_position(getTransform(player));
}
int GetPlayerHealth(void *player) {
    if (!player) return NULL;
    static const auto get_Health = reinterpret_cast<uint64_t(__fastcall *)(void *)>(getHp.getAddr());
    return (int) get_Health(player);
}
int GetMaxHealth(void *player) {
    if (!player) return NULL;
    static const auto get_MaxHealth = reinterpret_cast<uint64_t(__fastcall *)(void *)>(getMaxHp.getAddr());
    return (int) get_MaxHealth(player);
}

bool PlayerAlive(void *player) {
    return player != NULL && GetPlayerHealth(player) > 0;
}

bool IsPlayerDead(void *player) {
    return player == NULL && GetPlayerHealth(player) < 1;
}
int string_to_int(string str) 
{ 
    int value;
    value = std::stoi(str);
    return value;
}
string float_to_string (int value) 
{
    string str; 
    str = std::to_string(value);
    str += "M";
    return str;
}
