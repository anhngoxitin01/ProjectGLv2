#include "ResourceManagers.h"
#include "GameObject/Shader.h"
#include "GameObject/Texture.h"
#include "GameObject/Model.h"
#include "GameObject/Camera.h"
#include "GameObject/Font.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/Sprite3D.h"
#include "GameObject/Text.h"



ResourceManagers::ResourceManagers()
{
	std::string dataPath = "..\\Data\\";
	m_ShaderPath = dataPath + "Shaders\\";
	m_TexturePath = dataPath + "Textures\\";
	m_ModelsPath = dataPath + "Models\\";
	m_FontPath = dataPath + "fonts\\";
	m_SoundPath = dataPath + "Sounds\\";
	m_Soloud.init();
}

ResourceManagers::~ResourceManagers()
{
	m_Soloud.deinit();
}

void ResourceManagers::AddShader(const std::string& name)
{
	auto it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return;
	}

	std::shared_ptr<Shader>  shaders;
	shaders = std::make_shared<Shader>();
	std::string vs = m_ShaderPath + name + ".vs";
	std::string fs = m_ShaderPath + name + ".fs";

	shaders->Init(vs, fs);

	m_MapShader.insert(std::pair<std::string, std::shared_ptr<Shader>>(name, shaders));

}

void ResourceManagers::AddModel(const std::string& name)
{
	auto it = m_MapModels.find(name);
	if (it != m_MapModels.end())
	{
		return;
	}
	std::string path = m_ModelsPath + name;
	std::shared_ptr<Model> model = std::make_shared<Model>(path, NFG);
	m_MapModels.insert(std::pair<std::string, std::shared_ptr<Model>>(name, model));
}

void ResourceManagers::AddTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return;
	}
	std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	std::string file = m_TexturePath + name;
	texture->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	m_MapTexture.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, texture));
}

void ResourceManagers::AddFont(const std::string& name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end())
	{
		return;
	}
	std::string path = m_FontPath + name;
	std::shared_ptr<Font> font = std::make_shared<Font>(path);
	m_MapFont.insert(std::pair<std::string, std::shared_ptr<Font>>(name, font));
}

void ResourceManagers::RemoveShader(const std::string& name)
{
	m_MapShader.erase(name);
}

void ResourceManagers::RemoveModel(const std::string& name)
{
	m_MapModels.erase(name);
}

void ResourceManagers::RemoveTexture(const std::string& name)
{
	m_MapTexture.erase(name);
}

void ResourceManagers::RemoveFont(const std::string& name)
{
	m_MapFont.erase(name);
}

std::shared_ptr<Shader> ResourceManagers::GetShader(const std::string& name)
{
	auto it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return it->second;
	}

	std::shared_ptr<Shader>  shaders;
	shaders = std::make_shared<Shader>();
	std::string vs = m_ShaderPath + name + ".vs";
	std::string fs = m_ShaderPath + name + ".fs";

	shaders->Init(vs, fs);

	m_MapShader.insert(std::pair<std::string, std::shared_ptr<Shader>>(name, shaders));

	return shaders;
}

std::shared_ptr<Texture> ResourceManagers::GetTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return it->second;
	}
	std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	std::string file = m_TexturePath + name;
	texture->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	m_MapTexture.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, texture));
	return texture;
}

std::shared_ptr<Model> ResourceManagers::GetModel(const std::string& name)
{
	auto it = m_MapModels.find(name);
	if (it != m_MapModels.end())
	{
		return it->second;
	}
	std::string path = m_ModelsPath + name;
	std::shared_ptr<Model> model = std::make_shared<Model>(path, NFG);
	m_MapModels.insert(std::pair<std::string, std::shared_ptr<Model>>(name, model));

	return model;
}

std::shared_ptr<Font> ResourceManagers::GetFont(const std::string& name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end())
	{
		return it->second;
	}
	std::string path = m_FontPath + name;
	std::shared_ptr<Font> font = std::make_shared<Font>(path);
	m_MapFont.insert(std::pair<std::string, std::shared_ptr<Font>>(name, font));
	return font;
}

//Sound
void ResourceManagers::AddSound(const std::string& name)
{
	auto it = m_MapWave.find(name);
	if (it != m_MapWave.end())
	{
		return;
	}
	std::shared_ptr<SoLoud::Wav> wave;
	std::string sound = m_SoundPath + name;
	wave = std::make_shared<SoLoud::Wav>();
	wave->load(sound.c_str());
	m_MapWave.insert(std::pair<std::string, std::shared_ptr<SoLoud::Wav>>(name, wave));
}

void ResourceManagers::PlaySound(const std::string& name, bool loop)
{
	std::shared_ptr<SoLoud::Wav> wave;
	auto it = m_MapWave.find(name);
	if (it != m_MapWave.end())
	{
		wave = it->second;
	}
	else
	{
		std::string sound = m_SoundPath + name;
		wave = std::make_shared<SoLoud::Wav>();
		wave->load(sound.c_str());
		m_MapWave.insert(std::pair<std::string, std::shared_ptr<SoLoud::Wav>>(name, wave));
	}
	wave->setLooping(loop);
	m_Soloud.play(*wave);
}

void ResourceManagers::StopSound(const std::string& name)
{
	std::shared_ptr<SoLoud::Wav> wave;
	auto it = m_MapWave.find(name);
	if (it != m_MapWave.end())
	{
		wave = it->second;
	}
	m_Soloud.stopAudioSource(*wave);
}

void ResourceManagers::changeIsPLayingSoundMenu(bool isPLayingSoundMenu)
{
	isPlayingSoundMenu = isPLayingSoundMenu;
}

bool ResourceManagers::isPLayingSoundMenu()
{
	return isPlayingSoundMenu;
}

//============ MAP ================
Map* ResourceManagers::managerMap()
{
	return &m_map;
}

int ResourceManagers::getLevelMap()
{
	return m_levelMap;
}

void ResourceManagers::setLevelMap(int levelMap)
{
	m_levelMap = levelMap;
}

//============ PLAYER ================

Player* ResourceManagers::managerPlayer()
{
	return &m_player;
}

void ResourceManagers::autoSetSponToPlayerFromMap()
{
	int player_x;
	int player_y;
	m_map.getSponPlayerByValue(player_x, player_y);
	m_player.setPlayerLocation(player_x, player_y);
}

std::list<Enermy*>* ResourceManagers::managerEnermy()
{
	return &m_enermies;
}

void ResourceManagers::autoSetSponToEnermyFromMap()
{
	m_enermies = *m_map.getSponEnermy();
}

Boss* ResourceManagers::managerBoss()
{
	return m_boss;
}

void ResourceManagers::autoSetSponBossFromMap()
{
	m_boss = m_map.getBoss();
}

std::list<ItemPlayer*>* ResourceManagers::managerItemPLayer()
{
	return &m_itemPlayer;
}

void ResourceManagers::autoSetSponToItemPLayerFromMap()
{
	m_itemPlayer = ResourceManagers::GetInstance()->managerMap()->getItemPlayer();
}

void ResourceManagers::addRandomItemPlayer(MRectangle rec)
{
	//auto random in range 0 - 1000 
			//if it < 300 genertar the item player
	int check = (rand() % 1001);
	if (check < 300)
	{
		/*
		* random the kind of item
		* 0 is BOMB
		* 1 is BOMBSIZE
		* 2 is SHOE
		*/
		check = check % 3;
		// generate item player
		ItemPlayer* ip = new ItemPlayer(check, rec);
		m_itemPlayer.push_back(ip);
	}
}

void ResourceManagers::checkListItemPLayer()
{
	printf("===== list item player ====\n");
	for (auto *ip : m_itemPlayer)
	{
		ip->show();
	}
	printf("===== list item player ====\n");
}

void ResourceManagers::resetData()
{
	//player
	m_player.resetData();

	//enermy
	// generate map will clear the data for you

	//boss
	if(m_boss != nullptr)
		m_boss = nullptr;

	//itemPLayer
	for (auto* x : m_itemPlayer)
	{
		delete x;
	}
	m_itemPlayer.clear();

	//boom
	for (auto *x : *m_player.getPlayerListBoom())
	{
		for (auto wb : *x->getListWaterBoom())
			delete wb;
		delete x;
	}
	m_player.getPlayerListBoom()->clear();

	//itemMap
	//do not need to delete
}
