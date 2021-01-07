#include "Compose.h"

/********************************* Transition 0 *******************************/
const Node Compose::root[6] PROGMEM              = { {{6, 0}, nullptr}, 
	{{L3, KEY_TAB}, l3Tab},
	{{L2, KEY_EQUAL}, l2Equal},
	{{L6, KEY_RIGHT_BRACE}, l6RBr},
	{{L2, KEY_TILDE}, l2Tilde},
	{{L3, KEY_TILDE}, l3Tilde}
};


/********************************* Transition 1 *******************************/
const Node Compose::l3Tab[59] PROGMEM            = { {{59, 0}, nullptr}, 
	{{L1, KEY_B}, l3TabB},
	{{L1, KEY_E}, l3TabE},
	{{L2, KEY_E}, l3TabL2E},
	{{L3, KEY_E}, l3TabL3E},
	{{L2, KEY_F}, l3TabL2F},
	{{L1, KEY_G}, l3TabG},
	{{L1, KEY_H}, l3TabH},
	{{L2, KEY_H}, l3TabL2H},
	{{L3, KEY_H}, l3TabL3H},
	{{L1, KEY_J}, l3TabJ},
	{{L2, KEY_J}, l3TabL2J},
	{{L1, KEY_K}, l3TabK},
	{{L2, KEY_K}, l3TabL2K},
	{{L1, KEY_L}, l3TabL},
	{{L2, KEY_L}, l3TabL2L},
	{{L3, KEY_L}, l3TabMinus},
	{{L1, KEY_O}, l3TabO},
	{{L2, KEY_O}, l3TabL2O},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L1, KEY_R}, l3TabR},
	{{L1, KEY_S}, l3TabS},
	{{L2, KEY_S}, l3TabL2S},
	{{L3, KEY_U}, l3TabL3U},
	{{L1, KEY_V}, l3TabV},
	{{L1, KEY_W}, l3TabL3W},
	{{L3, KEY_Y}, l3TabL3Y},
	{{L1, KEY_1}, l3Tab1},
	{{L1, KEY_2}, l3Tab2},
	{{L1, KEY_3}, l3Tab3},
	{{L1, KEY_4}, l3Tab4},
	{{L5, KEY_4}, l3TabL54},
	{{L1, KEY_5}, l3Tab5},
	{{L5, KEY_5}, l3TabL55},
	{{L1, KEY_7}, l3Tab7},
	{{L1, KEY_TAB}, composeSymbols + 0},
	{{L3, KEY_TAB}, composeSymbols + 0},
	{{L5, KEY_SPACE}, l3TabL5Space},
	{{L1, KEY_MINUS}, l3TabMinus},
	{{L3, KEY_LEFT_BRACE}, l3TabL3LBr},
	{{L1, KEY_SEMICOLON}, l3TabSemicolon},
	{{L2, KEY_SEMICOLON}, l3TabL2Semicolon},
	{{L3, KEY_SEMICOLON}, l3TabL3Semicolon},
	{{L6, KEY_SEMICOLON}, l3TabL6Semicolon},
	{{L3, KEY_RIGHT_BRACE}, l3TabRBr},
	{{L1, KEY_PERIOD}, l3TabPeriod},
	{{L2, KEY_PERIOD}, l3TabL2Period},
	{{L1, KEYPAD_SUBTRACT}, l3TabMinus},
	{{L1, KEYPAD_1}, l3Tab1},
	{{L1, KEYPAD_2}, l3Tab2},
	{{L1, KEYPAD_3}, l3Tab3},
	{{L1, KEYPAD_4}, l3Tab4},
	{{L1, KEYPAD_5}, l3Tab5},
	{{L1, KEYPAD_7}, l3Tab7},
	{{L2, KEYPAD_7}, l3TabL2Kp7},
	{{L2, KEYPAD_8}, l3TabL2Kp8},
	{{L2, KEYPAD_9}, l3TabL2Kp9},
	{{L2, KEYPAD_0}, l3TabL2Kp0},
	{{L6, KEYPAD_0}, l3TabL6Kp0}
};

const Node Compose::l2Equal[15] PROGMEM           = { {{15, 0}, nullptr},
	{{L1, KEY_A}, composeSymbols + 136},
	{{L2, KEY_A}, composeSymbols + 135},
	{{L1, KEY_D}, composeSymbols + 128},
	{{L2, KEY_D}, composeSymbols + 127},
	{{L1, KEY_F}, composeSymbols + 132},
	{{L2, KEY_F}, composeSymbols + 131},
	{{L1, KEY_G}, composeSymbols + 138},
	{{L2, KEY_G}, composeSymbols + 137},
	{{L1, KEY_R}, composeSymbols + 130},
	{{L2, KEY_R}, composeSymbols + 129},
	{{L1, KEY_S}, composeSymbols + 134},
	{{L2, KEY_S}, composeSymbols + 133},
	{{L1, KEY_SPACE}, composeSymbols + 125},
	{{L2, KEY_EQUAL}, composeSymbols + 126}
};

const Node Compose::l6RBr[6] PROGMEM             = { {{6, 0}, nullptr},
	{{L1, KEY_U}, composeSymbols + 108},
	{{L2, KEY_U}, composeSymbols + 107},
	{{L5, KEY_4}, composeSymbols + 109},
	{{L1, KEY_SPACE}, composeSymbols + 105},
	{{L6, KEY_RIGHT_BRACE}, composeSymbols + 106}
};

const Node Compose::l2Tilde[24] PROGMEM           = { {{24, 0}, nullptr},
	{{L1, KEY_1}, composeSymbols + 116},
	{{L1, KEY_2}, composeSymbols + 117},
	{{L1, KEY_3}, composeSymbols + 118},
	{{L1, KEY_4}, composeSymbols + 119},
	{{L1, KEY_5}, composeSymbols + 120},
	{{L1, KEY_6}, composeSymbols + 121},
	{{L1, KEY_7}, composeSymbols + 122},
	{{L1, KEY_8}, composeSymbols + 123},
	{{L1, KEY_9}, composeSymbols + 124},
	{{L1, KEY_0}, composeSymbols + 115},
	{{L3, KEY_TAB}, l2TildeL3Tab},
	{{L1, KEY_SPACE}, composeSymbols + 110},
	{{L2, KEY_TILDE}, composeSymbols + 111},
	{{L1, KEYPAD_1}, composeSymbols + 116},
	{{L1, KEYPAD_2}, composeSymbols + 117},
	{{L1, KEYPAD_3}, composeSymbols + 118},
	{{L1, KEYPAD_4}, composeSymbols + 119},
	{{L1, KEYPAD_5}, composeSymbols + 120},
	{{L1, KEYPAD_6}, composeSymbols + 121},
	{{L1, KEYPAD_7}, composeSymbols + 122},
	{{L1, KEYPAD_8}, composeSymbols + 123},
	{{L1, KEYPAD_9}, composeSymbols + 124},
	{{L1, KEYPAD_0}, composeSymbols + 115}
};

const Node Compose::l3Tilde[11] PROGMEM           = { {{11, 0}, nullptr},
	{{L5, KEY_4}, composeSymbols + 172},
	{{L3, KEY_Q}, composeSymbols + 64},
	{{L3, KEY_R}, composeSymbols + 173},
	{{L1, KEY_SPACE}, composeSymbols + 139},
	{{L3, KEY_TILDE}, composeSymbols + 139},
	{{L2, KEY_EQUAL}, l3TildeL2Equal},
	{{L4, KEY_RIGHT_BRACE}, l3TildeL4RBr},
	{{L6, KEY_RIGHT_BRACE}, l3TildeL6RBr},
	{{L3, KEY_SEMICOLON}, composeSymbols + 171},
	{{L3, KEYPAD_3}, composeSymbols + 174}
};


/********************************* Transition 2 *******************************/
const Node Compose::l3TabB[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 15},
	{{L1, KEY_U}, composeSymbols + 15}
};

const Node Compose::l3TabE[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 29},
	{{L1, KEY_PERIOD}, composeSymbols + 11},
};

const Node Compose::l3TabL2E[4] PROGMEM          = { {{4, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 27},
	{{L2, KEY_SLASH}, composeSymbols + 28},
	{{L1, KEY_PERIOD}, composeSymbols + 12}
};

const Node Compose::l3TabL3E[1] PROGMEM          = { {{L3, KEY_R}, composeSymbols + 92} };

const Node Compose::l3TabL2F[1] PROGMEM          = { {{L2, KEY_F}, composeSymbols + 10} };

const Node Compose::l3TabG[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_V}, l3TabGV},
	{{L1, KEY_SPACE}, composeSymbols + 1}
};

const Node Compose::l3TabH[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_L}, composeSymbols + 21},
	{{L1, KEY_COMMA}, composeSymbols + 6}
};

const Node Compose::l3TabL2H[1] PROGMEM          = { {{L1, KEY_COMMA}, composeSymbols + 7} };

const Node Compose::l3TabL3H[4] PROGMEM          = { {{4, 0}, nullptr},
	{{L3, KEY_Y}, composeSymbols + 59},
	{{L1, KEY_2}, composeSymbols + 58},
	{{L1, KEYPAD_2}, composeSymbols + 58}
};

const Node Compose::l3TabJ[1] PROGMEM            = { {{L1, KEY_SLASH}, composeSymbols + 30} };

const Node Compose::l3TabL2J[3] PROGMEM          =  { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 31},
	{{L2, KEY_SLASH}, composeSymbols + 32}
};

const Node Compose::l3TabL2K[19] PROGMEM         = { {{19, 0}, nullptr},
	{{L1, KEY_1}, l3TabL2K1},
	{{L1, KEY_2}, composeSymbols + 34},
	{{L1, KEY_3}, composeSymbols + 35},
	{{L1, KEY_4}, composeSymbols + 36},
	{{L1, KEY_5}, composeSymbols + 37},
	{{L1, KEY_6}, composeSymbols + 38},
	{{L1, KEY_7}, composeSymbols + 39},
	{{L1, KEY_8}, composeSymbols + 40},
	{{L1, KEY_9}, composeSymbols + 41},
	{{L1, KEYPAD_1}, l3TabL2K1},
	{{L1, KEYPAD_2}, composeSymbols + 34},
	{{L1, KEYPAD_3}, composeSymbols + 35},
	{{L1, KEYPAD_4}, composeSymbols + 36},
	{{L1, KEYPAD_5}, composeSymbols + 37},
	{{L1, KEYPAD_6}, composeSymbols + 38},
	{{L1, KEYPAD_7}, composeSymbols + 39},
	{{L1, KEYPAD_8}, composeSymbols + 40},
	{{L1, KEYPAD_9}, composeSymbols + 41}
};

const Node Compose::l3TabK[19] PROGMEM           = { {{19, 0}, nullptr},
	{{L1, KEY_1}, l3TabK1},
	{{L1, KEY_2}, composeSymbols + 46},
	{{L1, KEY_3}, composeSymbols + 47},
	{{L1, KEY_4}, composeSymbols + 48},
	{{L1, KEY_5}, composeSymbols + 49},
	{{L1, KEY_6}, composeSymbols + 50},
	{{L1, KEY_7}, composeSymbols + 51},
	{{L1, KEY_8}, composeSymbols + 52},
	{{L1, KEY_9}, composeSymbols + 53},
	{{L1, KEYPAD_1}, l3TabK1},
	{{L1, KEYPAD_2}, composeSymbols + 46},
	{{L1, KEYPAD_3}, composeSymbols + 47},
	{{L1, KEYPAD_4}, composeSymbols + 48},
	{{L1, KEYPAD_5}, composeSymbols + 49},
	{{L1, KEYPAD_6}, composeSymbols + 50},
	{{L1, KEYPAD_7}, composeSymbols + 51},
	{{L1, KEYPAD_8}, composeSymbols + 52},
	{{L1, KEYPAD_9}, composeSymbols + 53}
};

const Node Compose::l3TabL[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_M}, composeSymbols + 85},
	{{L1, KEY_COMMA}, composeSymbols + 8} 
};

const Node Compose::l3TabL2L[1] PROGMEM          = { {{L1, KEY_COMMA}, composeSymbols + 9} };

const Node Compose::l3TabO[4] PROGMEM            = { {{4, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 16},
	{{L1, KEY_O}, composeSymbols + 17},
	{{L1, KEY_S}, composeSymbols + 18}
};

const Node Compose::l3TabL2O[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 19},
	{{L1, KEY_S}, composeSymbols + 20}
};

const Node Compose::l3TabL3Q[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L3, KEY_C}, composeSymbols + 64},
	{{L1, KEY_G}, composeSymbols + 1}
};

const Node Compose::l3TabR[4] PROGMEM            = { {{4, 0}, nullptr},
	{{L1, KEY_J}, l3TabRJ},
	{{L3, KEY_S}, l3TabRSlash},
	{{L1, KEYPAD_DIVIDE}, l3TabRSlash}
};

const Node Compose::l3TabS[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_S}, composeSymbols + 13},
	{{L1, KEY_SLASH}, composeSymbols + 23}
};

const Node Compose::l3TabL2S[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L2, KEY_S}, composeSymbols + 14},
	{{L2, KEY_SLASH}, composeSymbols + 22}
};

const Node Compose::l3TabL3U[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L1, KEY_3}, composeSymbols + 90},
	{{L1, KEYPAD_3}, composeSymbols + 90}
};

const Node Compose::l3TabV[3] PROGMEM  = { {{3, 0}, nullptr},
	{{L1, KEY_G}, l3TabVG},
	{{L1, KEY_O}, composeSymbols + 97}
};

const Node Compose::l3TabL3W[1] PROGMEM          = { {{L3, KEY_W}, composeSymbols + 2} };

const Node Compose::l3TabL3Y[5] PROGMEM          = { {{5, 0}, nullptr},
	{{L3, KEY_H}, composeSymbols + 60},
	{{L1, KEY_2}, composeSymbols + 57},
	{{L6, KEY_SEMICOLON}, composeSymbols + 95},
	{{L1, KEYPAD_2}, composeSymbols + 57}
};

const Node Compose::l3TabRBr[1] PROGMEM          = { {{L3, KEY_RIGHT_BRACE}, composeSymbols + 3} };

const Node Compose::l3TabPeriod[3] PROGMEM       =  { {{3, 0}, nullptr},
	{{L3, KEY_S}, l3TabPeriodSlash},
	{{L1, KEYPAD_DIVIDE}, l3TabPeriodSlash}
};

const Node Compose::l3TabL2Period[1] PROGMEM     = { {{L2, KEY_PERIOD}, composeSymbols + 103} };

const Node Compose::l3TabL5Space[1] PROGMEM      = { {{L5, KEY_SPACE}, composeSymbols + 65} };

const Node Compose::l3TabL3LBr[1] PROGMEM      = { {{L1, KEY_L}, composeSymbols + 104} };

const Node Compose::l3TabSemicolon[3] PROGMEM    =  { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 24},
	{{L1, KEY_D}, l3TabSemicolonD}
};

const Node Compose::l3TabL2Semicolon[3] PROGMEM  =  { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 25},
	{{L2, KEY_B}, composeSymbols + 26}
};

const Node Compose::l3TabL3Semicolon[3] PROGMEM  =  { {{3, 0}, nullptr},
	{{L3, KEY_J}, composeSymbols + 84},
	{{L3, KEY_K}, composeSymbols + 83}
};

const Node Compose::l3TabL6Semicolon[1] PROGMEM  = { {{L3, KEY_Y}, composeSymbols + 95} };

const Node Compose::l3Tab1[19] PROGMEM           = { {{19, 0}, nullptr},
	{{L3, KEY_H}, l3Tab1L3H},
	{{L4, KEY_H}, l3Tab1L4H},
	{{L3, KEY_S}, composeSymbols + 79},
	{{L3, KEY_Y}, l3Tab1L3Y},
	{{L4, KEY_Y}, l3Tab1L4Y},
	{{L1, KEY_2}, composeSymbols + 81},
	{{L1, KEY_3}, composeSymbols + 67},
	{{L1, KEY_4}, composeSymbols + 80},
	{{L1, KEY_5}, composeSymbols + 69},
	{{L1, KEY_6}, composeSymbols + 73},
	{{L1, KEY_8}, composeSymbols + 75},
	{{L1, KEYPAD_DIVIDE}, composeSymbols + 79},
	{{L1, KEYPAD_2}, composeSymbols + 81},
	{{L1, KEYPAD_3}, composeSymbols + 67},
	{{L1, KEYPAD_4}, composeSymbols + 80},
	{{L1, KEYPAD_5}, composeSymbols + 69},
	{{L1, KEYPAD_6}, composeSymbols + 73},
	{{L1, KEYPAD_8}, composeSymbols + 75}
};

const Node Compose::l3Tab2[7] PROGMEM            = { {{7, 0}, nullptr},
	{{L3, KEY_H}, composeSymbols + 58},
	{{L3, KEY_Y}, composeSymbols + 57},
	{{L1, KEY_3}, composeSymbols + 68},
	{{L1, KEY_5}, composeSymbols + 70},
	{{L1, KEYPAD_3}, composeSymbols + 68},
	{{L1, KEYPAD_5}, composeSymbols + 70}
};

const Node Compose::l3Tab3[7] PROGMEM            = { {{7, 0}, nullptr},
	{{L1, KEY_4}, composeSymbols + 82},
	{{L1, KEY_5}, composeSymbols + 71},
	{{L1, KEY_8}, composeSymbols + 76},
	{{L1, KEYPAD_4}, composeSymbols + 82},
	{{L1, KEYPAD_5}, composeSymbols + 71},
	{{L1, KEYPAD_8}, composeSymbols + 76}
};

const Node Compose::l3Tab4[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_5}, composeSymbols + 72},
	{{L1, KEYPAD_5}, composeSymbols + 72}
};

const Node Compose::l3TabL54[3] PROGMEM          = {  {{3, 0}, nullptr},
	{{L5, KEY_4}, composeSymbols + 87},
	{{L5, KEY_5}, composeSymbols + 89} 
};

const Node Compose::l3Tab5[5] PROGMEM            = { {{5, 0}, nullptr},
	{{L1, KEY_6}, composeSymbols + 74},
	{{L1, KEY_8}, composeSymbols + 77},
	{{L1, KEYPAD_6}, composeSymbols + 74},
	{{L1, KEYPAD_8}, composeSymbols + 77}
};

const Node Compose::l3TabL55[3] PROGMEM          = {  {{3, 0}, nullptr},
	{{L5, KEY_4}, composeSymbols + 89},
	{{L5, KEY_5}, composeSymbols + 88} 
};

const Node Compose::l3Tab7[5] PROGMEM            = { {{5, 0}, nullptr},
	{{L1, KEY_7}, composeSymbols + 66},
	{{L1, KEY_8}, composeSymbols + 78},
	{{L1, KEYPAD_7}, composeSymbols + 66},
	{{L1, KEYPAD_8}, composeSymbols + 78}
};

const Node Compose::l3TabMinus[4] PROGMEM        = { {{4, 0}, nullptr},
	{{L1, KEY_U}, composeSymbols + 4},
	{{L2, KEY_U}, composeSymbols + 5},
	{{L4, KEY_6}, composeSymbols + 98}
};

const Node Compose::l3TabL2Kp7[1] PROGMEM        = { {{L6, KEYPAD_0}, composeSymbols + 93} };

const Node Compose::l3TabL2Kp8[1] PROGMEM        = { {{L6, KEYPAD_0}, composeSymbols + 94} };

const Node Compose::l3TabL2Kp9[1] PROGMEM        = { {{L2, KEYPAD_9}, composeSymbols + 63} };

const Node Compose::l3TabL2Kp0[1] PROGMEM        = { {{L2, KEYPAD_0}, composeSymbols + 96} };

const Node Compose::l3TabL6Kp0[3] PROGMEM        = { {{3, 0}, nullptr},
	{{L2, KEYPAD_7}, composeSymbols + 93},
	{{L2, KEYPAD_8}, composeSymbols + 94}
};

const Node Compose::l2TildeL3Tab[3] PROGMEM      = { {{3, 0}, nullptr},
	{{L1, KEY_SEMICOLON}, l2TildeL3TabSemicolon},
	{{L2, KEY_SEMICOLON}, l2TildeL3TabL2Semicolon}
};

const Node Compose::l3TildeL2Equal[5] PROGMEM    = { {{5, 0}, nullptr},
	{{L1, KEY_SPACE}, composeSymbols + 140},
	{{L2, KEY_EQUAL}, composeSymbols + 143},
	{{L1, KEY_F}, composeSymbols + 146},
	{{L2, KEY_F}, composeSymbols + 145}
};

const Node Compose::l3TildeL4RBr[15] PROGMEM      = {  {{15, 0}, nullptr},
	{{L1, KEY_SPACE}, composeSymbols + 141},
	{{L4, KEY_RIGHT_BRACE}, composeSymbols + 144},
	{{L1, KEY_A}, composeSymbols + 158},
	{{L2, KEY_A}, composeSymbols + 157},
	{{L1, KEY_D}, composeSymbols + 148},
	{{L2, KEY_D}, composeSymbols + 147},
	{{L1, KEY_F}, composeSymbols + 150},
	{{L2, KEY_F}, composeSymbols + 149},
	{{L1, KEY_G}, composeSymbols + 154},
	{{L2, KEY_G}, composeSymbols + 153},
	{{L1, KEY_K}, composeSymbols + 156},
	{{L2, KEY_K}, composeSymbols + 155},
	{{L1, KEY_S}, composeSymbols + 152},
	{{L2, KEY_S}, composeSymbols + 151}
};

const Node Compose::l3TildeL6RBr[14] PROGMEM      = { {{14, 0}, nullptr},
	{{L6, KEY_RIGHT_BRACE}, composeSymbols + 142},
	{{L1, KEY_A}, composeSymbols + 170},
	{{L2, KEY_A}, composeSymbols + 169},
	{{L1, KEY_D}, composeSymbols + 160},
	{{L2, KEY_D}, composeSymbols + 159},
	{{L1, KEY_F}, composeSymbols + 162},
	{{L2, KEY_F}, composeSymbols + 161},
	{{L1, KEY_G}, composeSymbols + 166},
	{{L2, KEY_G}, composeSymbols + 165},
	{{L1, KEY_K}, composeSymbols + 168},
	{{L2, KEY_K}, composeSymbols + 167},
	{{L1, KEY_S}, composeSymbols + 164},
	{{L2, KEY_S}, composeSymbols + 163}
};

/********************************* Transition 3 *******************************/
const Node Compose::l3TabGV[1] PROGMEM           = { {{L1, KEY_L}, composeSymbols + 100} };

const Node Compose::l3TabK1[8] PROGMEM           = { {{8, 0}, nullptr},
	{{L1, KEY_1}, composeSymbols + 55},
	{{L1, KEY_2}, composeSymbols + 56},
	{{L1, KEY_0}, composeSymbols + 54},
	{{L1, KEY_SPACE}, composeSymbols + 45},
	{{L1, KEYPAD_1}, composeSymbols + 55},
	{{L1, KEYPAD_2}, composeSymbols + 56},
	{{L1, KEYPAD_0}, composeSymbols + 54}
};

const Node Compose::l3TabL2K1[8] PROGMEM         = { {{8, 0}, nullptr},
	{{L1, KEY_1}, composeSymbols + 43},
	{{L1, KEY_2}, composeSymbols + 44},
	{{L1, KEY_0}, composeSymbols + 42},
	{{L1, KEY_SPACE}, composeSymbols + 33},
	{{L1, KEYPAD_1}, composeSymbols + 43},
	{{L1, KEYPAD_2}, composeSymbols + 44},
	{{L1, KEYPAD_0}, composeSymbols + 42}
};

const Node Compose::l3TabRJ[1] PROGMEM           = { {{L1, KEY_SEMICOLON}, composeSymbols + 91} };

const Node Compose::l3TabRSlash[1] PROGMEM       = { {{L1, KEY_G}, composeSymbols + 86} };

const Node Compose::l3TabVG[1] PROGMEM           = { {{L1, KEY_S}, composeSymbols + 99} };

const Node Compose::l3Tab1L3H[1] PROGMEM         = { {{L3, KEY_Y}, composeSymbols + 61} };

const Node Compose::l3Tab1L4H[1] PROGMEM         = { {{L4, KEY_Y}, composeSymbols + 62} };

const Node Compose::l3Tab1L3Y[1] PROGMEM         = { {{L3, KEY_H}, composeSymbols + 61} };

const Node Compose::l3Tab1L4Y[1] PROGMEM         = { {{L4, KEY_H}, composeSymbols + 62} };

const Node Compose::l3TabSemicolonD[1] PROGMEM   = { {{L1, KEY_I}, composeSymbols + 101} };

const Node Compose::l3TabPeriodSlash[1] PROGMEM  = { {{L1, KEY_PERIOD}, composeSymbols + 102} };

const Node Compose::l2TildeL3TabSemicolon[1] PROGMEM = { {{L1, KEY_B}, composeSymbols + 114} };

const Node Compose::l2TildeL3TabL2Semicolon[3] PROGMEM = {  {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 113},
	{{L2, KEY_B}, composeSymbols + 112},
};

/********************************* Characters *********************************/
/*
 * one big array to store all the unicode, simplest solution for not making up
 * new variable names each time and find out if a pointer points here.
 */
const uint16_t Compose::composeSymbols[] PROGMEM = {
	0x266B, 0x25CC, 0x0332, 0x02BC, 0x0127, 0x0126, 0x0219, 0x0218, //   8
	0x021B, 0x021A, 0x018F, 0x0140, 0x013F, 0x0131, 0x0130, 0x0292, //  16
	0xFB02, 0xFB00, 0xFB01, 0xFB04, 0xFB03, 0xFB06, 0x0132, 0x0133, //  24
	0x01F3, 0x01F2, 0x01F1, 0x01C8, 0x01C7, 0x01C9, 0x01CC, 0x01CB, //  32
	0x01CA, 0x2160, 0x2161, 0x2162, 0x2163, 0x2164, 0x2165, 0x2166, //  40
	0x2167, 0x2168, 0x2169, 0x216A, 0x216B, 0x2170, 0x2171, 0x2172, //  48
	0x2173, 0x2174, 0x2175, 0x2176, 0x2177, 0x2178, 0x2179, 0x217A, //  56
	0x217B, 0x203C, 0x2047, 0x2048, 0x2049, 0x203D, 0x2E18, 0x2021, //  64
	0x22EE, 0x002D, 0x204A, 0x2153, 0x2154, 0x2155, 0x2156, 0x2157, //  72
	0x2158, 0x2159, 0x215A, 0x215B, 0x215C, 0x215D, 0x215E, 0x215F, //  80
	0x00BC, 0x00BD, 0x00BE, 0x263A, 0x2639, 0x2122, 0x2105, 0x26A2, //  88
	0x26A3, 0x26A4, 0x2665, 0x262E, 0x25A1, 0x2611, 0x2612, 0x26A0, //  96
	0x237D, 0x20B0, 0x20A4, 0x2318, 0x2325, 0x2020, 0x2052, 0x2023, // 104
	0xFB05, 0x02D8, 0x0306, 0x1E2A, 0x162B, 0x263F, 0x02C7, 0x030C, // 112
	0x01C4, 0x01C5, 0x01C6, 0x2080, 0x2081, 0x2082, 0x2083, 0x2084, // 120
	0x2085, 0x2086, 0x2087, 0x2088, 0x2089, 0x00B8, 0x0327, 0x0104, // 128
	0x0105, 0x00C7, 0x00E7, 0x0118, 0x0119, 0x012E, 0x012F, 0x0172, // 136
	0x0173, 0x01EA, 0x01EB, 0x21BB, 0x02DB, 0x02F5, 0x0311, 0x0328, // 144
	0x030F, 0x0228, 0x0229, 0x0200, 0x0201, 0x0204, 0x0205, 0x0208, // 152
	0x0209, 0x020C, 0x020D, 0x0210, 0x0211, 0x0214, 0x0215, 0x0202, // 160
	0x0203, 0x0206, 0x0207, 0x020A, 0x020B, 0x020E, 0x020F, 0x0212, // 168
	0x0213, 0x0216, 0x0217, 0x2025, 0x2641, 0x2423, 0x21CB
};


/********************************* Functions *********************************/
uint16_t Compose::transition(uint8_t layer, uint8_t key) {
	Node* cur = currentNode;
	Node val_cur;
	memcpy_P(&val_cur, currentNode, sizeof(val_cur));
	uint16_t len = (val_cur.ptr.value == nullptr) ? val_cur.x.len : 1; 

	//stupid linear search, could be optimized
	for (uint16_t i = 0; i < len; i++) {
		memcpy_P(&val_cur, cur, sizeof(val_cur));
		if (val_cur.ptr.value != nullptr && //discard length element
			val_cur.x.layeredKey.layer == layer && 
			val_cur.x.layeredKey.keycode == key) { //found
			
			//pointer points to element of composeSymbols List
			if (val_cur.ptr.value >= composeSymbols && 
				val_cur.ptr.value <  (char*) composeSymbols + sizeof(composeSymbols)) {
				
				currentNode = const_cast<Node*>(root);
				return pgm_read_word(val_cur.ptr.unicode);
				
			} else { //found, waiting for next key
				currentNode = const_cast<Node*>(val_cur.ptr.nodes);
				return 1; 
			}
		}
		cur++;
	}
	
	//not found
	currentNode = const_cast<Node*>(root);
	return 0;
}

void Compose::reset(){
	currentNode = const_cast<Node*>(root);
}