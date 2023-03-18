// Gt Tool.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <fstream>
#include <string>
#include <iostream>
#ifndef __linux__
#include <conio.h>
#endif
#include "json.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

string secret = "PBG892FXX982ABC*";

using json = nlohmann::json;

bool decode()
{
	json jdata;
	std::ifstream file("items.dat", std::ios::binary | std::ios::ate);
	int size = file.tellg();
	if (size == -1) {
		cout << "Failed to open file, are you sure that you have items.dat in current directory?" << std::endl;
		return 0;
	}
	char* data = new char[size];
	file.seekg(0, std::ios::beg);

	if (file.read((char*)(data), size))
	{
		cout << "Decoding items data..." << endl;

	}
	else {
		cout << "Decoding of items data has failed..." << endl;
#ifndef __linux__
		_getch();
#endif
		exit(0);
	}
	int itemCount;
	int memPos = 0;
	int16_t itemsdatVersion = 0;
	memcpy(&itemsdatVersion, data + memPos, 2);
	memPos += 2;
	memcpy(&itemCount, data + memPos, 4);
	memPos += 4;
	jdata["itemsdatVersion"] = itemsdatVersion;
	jdata["itemCount"] = itemCount;
	for (int i = 0; i < itemCount; i++) {
		json j;
		int itemID = 0;
		char editableType = 0;
		char itemCategory = 0;
		char actionType = 0;
		char hitSoundType = 0;
		string name = "";
		string texture = "";
		int textureHash = 0;
		char itemKind = 0;
		int val1;
		char textureX = 0;
		char textureY = 0;
		char spreadType = 0;
		char isStripeyWallpaper = 0;
		char collisionType = 0;
		char breakHits = 0;
		int dropChance = 0;
		char clothingType = 0;
		int16_t rarity = 0;
		unsigned char maxAmount = 0;
		string extraFile = "";
		int extraFileHash = 0;
		int audioVolume = 0;
		string petName = "";
		string petPrefix = "";
		string petSuffix = "";
		string petAbility = "";
		char seedBase = 0;
		char seedOverlay = 0;
		char treeBase = 0;
		char treeLeaves = 0;
		int seedColor = 0;
		int seedOverlayColor = 0;
		int growTime = 0;
		short val2;
		short isRayman = 0;
		string extraOptions = "";
		string texture2 = "";
		string extraOptions2 = "";
		string punchOptions = "";
		{
			memcpy(&itemID, data + memPos, 4);
			memPos += 4;
		}
		{
			editableType = data[memPos];
			memPos += 1;
		}
		{
			itemCategory = data[memPos];
			memPos += 1;
		}
		{
			actionType = data[memPos];
			memPos += 1;
		}
		{
			hitSoundType = data[memPos];
			memPos += 1;
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				name += data[memPos] ^ (secret[(j + itemID) % secret.length()]);
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				texture += data[memPos];
				memPos++;
			}
		}
		memcpy(&textureHash, data + memPos, 4);
		memPos += 4;
		itemKind = memPos[data];
		memPos += 1;
		memcpy(&val1, data + memPos, 4);
		memPos += 4;
		textureX = data[memPos];
		memPos += 1;
		textureY = data[memPos];
		memPos += 1;
		spreadType = data[memPos];
		memPos += 1;
		isStripeyWallpaper = data[memPos];
		memPos += 1;
		collisionType = data[memPos];
		memPos += 1;
		breakHits = data[memPos];
		memPos += 1;
		memcpy(&dropChance, data + memPos, 4);
		memPos += 4;
		clothingType = data[memPos];
		memPos += 1;
		memcpy(&rarity, data + memPos, 2);
		memPos += 2;
		maxAmount = data[memPos];
		memPos += 1;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraFile += data[memPos];
				memPos++;
			}
		}
		memcpy(&extraFileHash, data + memPos, 4);
		memPos += 4;
		memcpy(&audioVolume, data + memPos, 4);
		memPos += 4;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petName += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petPrefix += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petSuffix += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petAbility += data[memPos];
				memPos++;
			}
		}
		{
			seedBase = data[memPos];
			memPos += 1;
		}
		{
			seedOverlay = data[memPos];
			memPos += 1;
		}
		{
			treeBase = data[memPos];
			memPos += 1;
		}
		{
			treeLeaves = data[memPos];
			memPos += 1;
		}
		{
			memcpy(&seedColor, data + memPos, 4);
			memPos += 4;
		}
		{
			memcpy(&seedOverlayColor, data + memPos, 4);
			memPos += 4;
		}
		memPos += 4; // deleted ingredients
		{
			memcpy(&growTime, data + memPos, 4);
			memPos += 4;
		}
		memcpy(&val2, data + memPos, 2);
		memPos += 2;
		memcpy(&isRayman, data + memPos, 2);
		memPos += 2;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraOptions += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				texture2 += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraOptions2 += data[memPos];
				memPos++;
			}
		}
		memPos += 80;
		if (itemsdatVersion >= 11) {
			{
				int16_t strLen = *(int16_t*)&data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					punchOptions += data[memPos];
					memPos++;
				}
			}
		}
		if (itemsdatVersion >= 12) {
			// TODO: find what those data mean
			memPos += 13;
		}
		if(itemsdatVersion >= 13) {
			memPos += 4;
		}
		if (itemsdatVersion >= 14) {
			memPos += 4;
		}
		if (itemsdatVersion >= 15) {
			memPos += 25;
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2 + strLen;
		}
		if (i != itemID)
			cout << "Item are unordered!" << endl;
		j["itemID"] = itemID;
		j["hitSoundType"] = hitSoundType;
		j["name"] = name;
		j["texture"] = texture;
		j["textureHash"] = textureHash;
		j["val1"] = val1;
		j["itemKind"] = itemKind;
		j["editableType"] = editableType;
		j["itemCategory"] = itemCategory;
		j["actionType"] = actionType;
		j["textureX"] = textureX;
		j["textureY"] = textureY;
		j["spreadType"] = spreadType;
		j["isStripeyWallpaper"] = isStripeyWallpaper;
		j["collisionType"] = collisionType;
		j["breakHits"] = breakHits;
		j["dropChance"] = dropChance;
		j["clothingType"] = clothingType;
		j["rarity"] = rarity;
		j["maxAmount"] = maxAmount;
		j["extraFile"] = extraFile;
		j["extraFileHash"] = extraFileHash;
		j["audioVolume"] = audioVolume;
		j["petName"] = petName;
		j["petPrefix"] = petPrefix;
		j["petSuffix"] = petSuffix;
		j["petAbility"] = petAbility;
		j["seedColor"] = seedColor;
		j["seedBase"] = seedBase;
		j["seedOverlay"] = seedOverlay;
		j["treeBase"] = treeBase;
		j["treeLeaves"] = treeLeaves;
		j["seedOverlayColor"] = seedOverlayColor;
		j["growTime"] = growTime;
		j["val2"] = val2;
		j["isRayman"] = isRayman;
		j["extraOptions"] = extraOptions;
		j["texture2"] = texture2;
		j["extraOptions2"] = extraOptions2;
		j["punchOptions"] = punchOptions;
		jdata["items"].push_back(j);
	}
	std::ofstream o("data.json");
	o << std::setw(4) << jdata << std::endl;
	cout << "Succesfully decoded" << endl;
#ifndef __linux__
	_getch();
#endif
	return 0;
}
int getFilesize(string name)
{
	ifstream file(name, std::ios::ate | std::ios::binary);
	return file.tellg();
}
string encodename(string name, int id)
{
	int secretLen = secret.length();
	int len = name.length();
	string output;
	for (int i = 0; i < len; i++)
	{
		int charpos = (i + id) % secretLen;
		char secretchar = secret[charpos];
		output += name[i] ^ secretchar;
	}
	return output;
}

bool encode()
{
	cout << "Encoding data.json.. ";
	ifstream file("data.json");
	json jf;
	file >> jf;
	size_t size = getFilesize("data.json");
	if (size == -1)
	{
		cout << "Please make sure that items.json is in the same directory!" << endl;
		return 0;
	}
	ofstream dat("items.dat", ios::binary);
	uint32_t pos = 0;
	uint8_t* data = static_cast<uint8_t*>(malloc(size));
	auto write_string = [&](const std::string& str)
	{
		uint16_t strsize = static_cast<uint16_t>(str.size());
		memcpy(data + pos, &strsize, 2);
		pos += 2;
		for (int i = 0; i < strsize; ++i)
			data[pos++] = static_cast<uint8_t>(str[i]);
	};
	memset(data, 0, size);
	int16_t item_version = jf["itemsdatVersion"];
	int item_count = jf["itemCount"];
	memcpy(data + pos, &item_version, 2);
	memcpy(data + pos + 2, &item_count, 4);
	pos += 6;
	for (int i = 0; i < item_count; i++)
	{
		int32_t id = jf["items"][i]["itemID"];
		string texture = jf["items"][i]["texture"];
		memcpy(data + pos, &id, 4);
		pos += 4;
		string name = jf["items"][i]["name"];
		cout << "Encode: " + name + ", ID: " + to_string(i) << endl;
		int8_t m_item_category = jf["items"][i]["itemCategory"];
		uint8_t m_editable_type = jf["items"][i]["editableType"];
		memcpy(data + pos, &m_editable_type, 1);
		pos += 1;
		memcpy(data + pos, &m_item_category, 1);
		pos += 1;
		int actionType = jf["items"][i]["actionType"];
		memcpy(data + pos, &actionType, 1);
		pos += 1;
		int hitSoundType = jf["items"][i]["hitSoundType"];
		memcpy(data + pos, &hitSoundType, 1);
		pos += 1;
		write_string(encodename(name, id));
		write_string(texture);
		int textureHash = jf["items"][i]["textureHash"];
		memcpy(data + pos, &textureHash, 4);
		pos += 4;
		int itemKind = jf["items"][i]["itemKind"];
		memcpy(data + pos, &itemKind, 1);
		pos += 1;
		short val1 = jf["items"][i]["val1"];
		memcpy(data + pos, &val1, 4);
		pos += 4;
		int texturex = jf["items"][i]["textureX"];
		int texturey = jf["items"][i]["textureY"];
		memcpy(data + pos, &texturex, 1);
		pos += 1;
		memcpy(data + pos, &texturey, 1);
		pos += 1;
		short spread_type = jf["items"][i]["spreadType"];
		memcpy(data + pos, &spread_type, 1);
		pos += 1;
		int isStripeyWallpaper = jf["items"][i]["isStripeyWallpaper"];
		memcpy(data + pos, &isStripeyWallpaper, 1);
		pos += 1;
		short collisionType = jf["items"][i]["collisionType"];
		memcpy(data + pos, &collisionType, 1);
		pos += 1;
		int breakHits = jf["items"][i]["breakHits"];
		memcpy(data + pos, &breakHits, 1);
		pos += 1;
		int dropChance = jf["items"][i]["dropChance"];
		memcpy(data + pos, &dropChance, 4);
		pos += 4;
		int clothingType = jf["items"][i]["clothingType"];
		memcpy(data + pos, &clothingType, 1);
		pos += 1;
		int rarity = jf["items"][i]["rarity"];
		memcpy(data + pos, &rarity, 2);
		pos += 2;
		int maxAmount = jf["items"][i]["maxAmount"];
		memcpy(data + pos, &maxAmount, 1);
		pos += 1;
		string extraFile = jf["items"][i]["extraFile"];
		write_string(extraFile);
		int extraFileHash = jf["items"][i]["extraFileHash"];
		memcpy(data + pos, &extraFileHash, 4);
		pos += 4;
		int audioVolume = jf["items"][i]["audioVolume"];
		memcpy(data + pos, &audioVolume, 4);
		pos += 4;
		string petName = jf["items"][i]["petName"];
		string petPrefix = jf["items"][i]["petPrefix"];
		string petSuffix = jf["items"][i]["petSuffix"];
		string petAbility = jf["items"][i]["petAbility"];
		write_string(petName);
		write_string(petPrefix);
		write_string(petSuffix);
		write_string(petAbility);
		int seedBase = jf["items"][i]["seedBase"];
		int seedOverlay = jf["items"][i]["seedOverlay"];
		int treeBase = jf["items"][i]["treeBase"];
		int treeLeaves = jf["items"][i]["treeLeaves"];
		int seedColor = jf["items"][i]["seedColor"];
		memcpy(data + pos, &seedBase, 1);
		pos += 1;
		memcpy(data + pos, &seedOverlay, 1);
		pos += 1;
		memcpy(data + pos, &treeBase, 1);
		pos += 1;
		memcpy(data + pos, &treeLeaves, 1);
		pos += 1;
		memcpy(data + pos, &seedColor, 4);
		pos += 4;
		int seedOverlayColor = jf["items"][i]["seedOverlayColor"];
		memcpy(data + pos, &seedOverlayColor, 4);
		pos += 4;
		uint32_t m_ingredient = 0;
		memcpy(data + pos, &m_ingredient, 4);
		pos += 4;
		int growTime = jf["items"][i]["growTime"];
		memcpy(data + pos, &growTime, 4);
		pos += 4;
		int val2 = jf["items"][i]["val2"];
		memcpy(data + pos, &val2, 2);
		pos += 2;
		short isRayman = jf["items"][i]["isRayman"];
		memcpy(data + pos, &isRayman, 2);
		pos += 2;
		string extraOptions = jf["items"][i]["extraOptions"];
		string texture2 = jf["items"][i]["texture2"];
		string extraOptions2 = jf["items"][i]["extraOptions2"];
		write_string(extraOptions);
		write_string(texture2);
		write_string(extraOptions2);
		uint8_t m_reserved[80] = { 0 };
		memcpy(data + pos, m_reserved, 80);
		pos += 80;
		string punchOptions = jf["items"][i]["punchOptions"];
		if (item_version >= 11)
		{
			write_string(punchOptions);
		}
		if (item_version >= 12)
		{
			pos += 13;
		}
		if (item_version >= 13)
		{

			pos += 4;
		}
		if (item_version >= 14)
		{
			pos += 4;
		}
		if (item_version >= 15)
		{
			pos += 25;
			int16_t strLen = *(int16_t*)&data[pos];
			pos += 2 + strLen;
		}
	}
	dat.write(reinterpret_cast<char*>(data), pos);
	dat.close();
	free(data);
	cout << "Encode successfully!" << endl;
}

int main()
{
	system("color c");
	int select;
	cout << "Welcome to itemsdat encoder/decoder. (App Maded By Aamon)" << endl;
	cout << "Please pick what type u want" << endl;
	cout << "For decode press 1, for encode press 2: ";
	cin >> select;

	if (select == 1)
		decode();
	else if (select == 2)
		encode();
	else
		cout << "Wrong Number, try again...";
}
