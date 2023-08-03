#include "pch.h"
#include "SA2ModLoader.h"
#include "FunctionHook.h"
#include "UsercallFunctionHandler.h"
#include <map>
#include <vector>
using std::map;
using std::vector;

char currentChar = -1;
char currentCostume = 0;
int charTexCount = 0;

struct CostumeInfo
{
	const char* model;
	const char* texture;
	const char* motion;
};

map<char, vector<CostumeInfo>> costumes = {
	{
		Characters_Sonic,
		{
			{ },
			{ "SONIC1MDL.PRS", "SONIC1TEX", nullptr }
		}
	},
	{
		Characters_Shadow,
		{
			{ },
			{ "SHADOW1MDL.PRS", "SHADOW1TEX", nullptr }
		}
	},
	{
		Characters_Tails,
		{
			{ }
		}
	},
	{
		Characters_Eggman,
		{
			{ }
		}
	},
	{
		Characters_Knuckles,
		{
			{ },
			{ "BKNUCKMDL.PRS", "BKNUCKTEX", nullptr }
		}
	},
	{
		Characters_Rouge,
		{
			{ },
			{ "BROUGEMDL.PRS", "BROUGETEX", nullptr }
		}
	},
	{
		Characters_MechTails,
		{
			{ },
			{ "TWALK1MDL.PRS", "TWALK1TEX", nullptr }
		}
	},
	{
		Characters_MechEggman,
		{
			{ },
			{ "EWALK2MDL.PRS", "EWALK2TEX", nullptr }
		}
	},
	{
		Characters_Amy,
		{
			{ }
		}
	},
	{
		Characters_SuperSonic,
		{
			{ }
		}
	},
	{
		Characters_SuperShadow,
		{
			{ }
		}
	},
	{
		Characters_MetalSonic,
		{
			{ }
		}
	},
	{
		Characters_Tikal,
		{
			{ }
		}
	},
	{
		Characters_Chaos,
		{
			{ }
		}
	},
	{
		Characters_ChaoWalker,
		{
			{ }
		}
	},
	{
		Characters_DarkChaoWalker,
		{
			{ }
		}
	}
};

FunctionHook<void, int> LoadSonic_h(LoadSonic);
void LoadSonic_r(int playerNum)
{
	currentChar = Characters_Sonic;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadSonic_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadShadow_h(LoadShadow);
void LoadShadow_r(int playerNum)
{
	currentChar = Characters_Shadow;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadShadow_h.Original(playerNum);
	currentChar = -1;
}

UsercallFuncVoid(LoadTails_, (int playerNum), (playerNum), 0x74CF00, rEAX);
void LoadTails_r(int playerNum)
{
	currentChar = Characters_Tails;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadTails_.Original(playerNum);
	currentChar = -1;
}

UsercallFuncVoid(LoadEggman_, (int playerNum), (playerNum), 0x73C220, rEAX);
void LoadEggman_r(int playerNum)
{
	currentChar = Characters_Eggman;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadEggman_.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadKnuckles_h(LoadKnuckles);
void LoadKnuckles_r(int playerNum)
{
	currentChar = Characters_Knuckles;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadKnuckles_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadRouge_h(LoadRouge);
void LoadRouge_r(int playerNum)
{
	currentChar = Characters_Rouge;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadRouge_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadMechTails_h(LoadMechTails);
void LoadMechTails_r(int playerNum)
{
	currentChar = Characters_MechTails;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadMechTails_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadMechEggman_h(LoadMechEggman);
void LoadMechEggman_r(int playerNum)
{
	currentChar = Characters_MechEggman;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadMechEggman_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadAmy_h(LoadAmy);
void LoadAmy_r(int playerNum)
{
	currentChar = Characters_Amy;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadAmy_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void> LoadSuperSonic_h(reinterpret_cast<void(*)()>(LoadSuperSonic));
void LoadSuperSonic_r()
{
	currentChar = Characters_SuperSonic;
	currentCostume = AltCostume[0];
	charTexCount = 0;
	LoadSuperSonic_h.Original();
	currentChar = -1;
}

FunctionHook<void> LoadSuperShadow_h(reinterpret_cast<void(*)()>(LoadSuperShadow));
void LoadSuperShadow_r()
{
	currentChar = Characters_SuperShadow;
	currentCostume = AltCostume[1];
	charTexCount = 0;
	LoadSuperShadow_h.Original();
	currentChar = -1;
}

FunctionHook<void, int> LoadMetalSonic_h(LoadMetalSonic);
void LoadMetalSonic_r(int playerNum)
{
	currentChar = Characters_MetalSonic;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadMetalSonic_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadTikal_h(LoadTikal);
void LoadTikal_r(int playerNum)
{
	currentChar = Characters_Tikal;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadTikal_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadChaos_h(LoadChaos);
void LoadChaos_r(int playerNum)
{
	currentChar = Characters_Chaos;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadChaos_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadChaoWalker_h(LoadChaoWalker);
void LoadChaoWalker_r(int playerNum)
{
	currentChar = Characters_ChaoWalker;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadChaoWalker_h.Original(playerNum);
	currentChar = -1;
}

FunctionHook<void, int> LoadDarkChaoWalker_h(LoadDarkChaoWalker);
void LoadDarkChaoWalker_r(int playerNum)
{
	currentChar = Characters_DarkChaoWalker;
	currentCostume = AltCostume[playerNum];
	charTexCount = 0;
	LoadDarkChaoWalker_h.Original(playerNum);
	currentChar = -1;
}

FastcallFunctionHook<NJS_TEXLIST*, const char*> LoadCharTextures_h(reinterpret_cast<NJS_TEXLIST* (__fastcall*)(const char*)>(LoadCharTextures));
NJS_TEXLIST* __fastcall LoadCharTextures_r(const char* filename)
{
	if (currentChar != -1 && charTexCount++ == 0)
	{
		auto tmp = costumes[currentChar][currentCostume].texture;
		if (tmp)
			filename = tmp;
	}
	return LoadCharTextures_h.Original(filename);
}

UsercallFunc(ModelIndex*, LoadMDLFile_, (const char* filename), (filename), 0x459590, rEAX, rEAX);
ModelIndex* LoadMDLFile_r(const char* filename)
{
	if (currentChar != -1)
	{
		auto tmp = costumes[currentChar][currentCostume].model;
		if (tmp)
			filename = tmp;
	}
	return LoadMDLFile_.Original(filename);
}

UsercallFunc(AnimationIndex*, LoadMTNFile_, (const char* filename), (filename), 0x459740, rEAX, rEAX);
AnimationIndex* LoadMTNFile_r(const char* filename)
{
	if (currentChar != -1)
	{
		auto tmp = costumes[currentChar][currentCostume].motion;
		if (tmp)
			filename = tmp;
	}
	return LoadMTNFile_.Original(filename);
}

extern "C"
{
	__declspec(dllexport) int RegisterCostume(char charID, const char* model, const char* texture, const char* motion)
	{
		auto& list = costumes[charID];
		int cid = list.size();
		list.push_back({ model, texture, motion });
		return cid;
	}

	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		LoadSonic_h.Hook(LoadSonic_r);
		LoadShadow_h.Hook(LoadShadow_r);
		LoadTails_.Hook(LoadTails_r);
		LoadEggman_.Hook(LoadEggman_r);
		LoadKnuckles_h.Hook(LoadKnuckles_r);
		LoadRouge_h.Hook(LoadRouge_r);
		LoadMechTails_h.Hook(LoadMechTails_r);
		LoadMechEggman_h.Hook(LoadMechEggman_r);
		LoadAmy_h.Hook(LoadAmy_r);
		LoadMetalSonic_h.Hook(LoadMetalSonic_r);
		LoadTikal_h.Hook(LoadTikal_r);
		LoadChaos_h.Hook(LoadChaos_r);
		LoadChaoWalker_h.Hook(LoadChaoWalker_r);
		LoadDarkChaoWalker_h.Hook(LoadDarkChaoWalker_r);
		LoadSuperSonic_h.Hook(LoadSuperSonic_r);
		LoadSuperShadow_h.Hook(LoadSuperShadow_r);
		LoadCharTextures_h.Hook(LoadCharTextures_r);
		LoadMDLFile_.Hook(LoadMDLFile_r);
		LoadMTNFile_.Hook(LoadMTNFile_r);
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}