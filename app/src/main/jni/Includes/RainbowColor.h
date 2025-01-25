//credits - NepMods
Color Ka = Color(0,0,0,255);
bool inR = false;
bool inG = false;
bool inB = false;
bool R;
bool G;
bool B;

Color RainbowColor() {
    if (Ka.r == 0 && Ka.g == 0 && Ka.b == 0) {
        Ka.r = 255;
        G = true;
        Ka.b = 0;
    }
    if (Ka.r == 0 && Ka.g == 255 && Ka.b == 0) {
        B = true;
        R = false;
        G = false;
    }
    if (Ka.r == 0 && Ka.g == 0 && Ka.b == 255) {
        R = true;
        G = false;
        B = false;
    }
    if (Ka.r == 255 && Ka.g == 0 && Ka.b == 0) {
        G = true;
        R = false;
        B = false;
    }
    if (R) {
        Ka.r += 1;
        Ka.g = 0;
        Ka.b -= 1;
    }
    if (G) {
        Ka.r -= 1;
        Ka.g += 1;
        Ka.b = 0;
    }
    if (B) {
        Ka.r = 0;
        Ka.g -= 1;
        Ka.b += 1;
    }
	
    return Ka;
}
