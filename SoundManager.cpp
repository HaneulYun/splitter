#include "stdafx.h"
#include "SoundManager.h"

CSoundManager::CSoundManager()
{
	if (instance == nullptr)
		instance = this;
	m_pChannel = nullptr;
	Initialize();
}

CSoundManager::~CSoundManager()
{
	for (auto& v : vSound)
		if (v)
			v->release();
	vSound.clear();
	if (soundSystem)
		soundSystem->close();
}

void CSoundManager::Initialize()
{
	FMOD::System_Create(&soundSystem);
	soundSystem->init(64, FMOD_INIT_NORMAL, NULL);
	soundSystem->getMasterChannelGroup(&m_BGMChannel);

	soundSystem->createChannelGroup("BGM", &m_BGMChannel);
	soundSystem->createChannelGroup("SFX", &m_effectSoundChannel);
	m_BGMChannel->setVolume(0.5);
	m_effectSoundChannel->setVolume(0.5);

	vSound.resize(8);

	soundSystem->createSound("resources/sound/11. Main Menu Theme.mp3", FMOD_LOOP_NORMAL, 0, &vSound[0]);
	soundSystem->createSound("resources/sound/10. Reverse.mp3", FMOD_LOOP_NORMAL, 0, &vSound[1]);
	soundSystem->createSound("resources/sound/01. Bad Squares.mp3", FMOD_LOOP_NORMAL, 0, &vSound[2]);
	soundSystem->createSound("resources/sound/02. Hexagonal.mp3", FMOD_LOOP_NORMAL, 0, &vSound[3]);
	soundSystem->createSound("resources/sound/03. Hyper Spin.mp3", FMOD_LOOP_NORMAL, 0, &vSound[4]);
	soundSystem->createSound("resources/sound/bullet1.wav", FMOD_DEFAULT, 0, &vSound[5]);
	soundSystem->createSound("resources/sound/break1.mp3", FMOD_DEFAULT, 0, &vSound[6]);
	soundSystem->createSound("resources/sound/break2.mp3", FMOD_DEFAULT, 0, &vSound[7]);
}
void CSoundManager::Pulse()
{
	soundSystem->update();
}
void CSoundManager::Pulse(FMOD::Channel*& channel, int tag)
{
	if(tag < 5)
		soundSystem->playSound(vSound[tag], m_BGMChannel, 0, &channel);
	else
		soundSystem->playSound(vSound[tag], m_effectSoundChannel, 0, &channel);
}
void CSoundManager::SetVolume(FMOD::Channel*& channel, float volume)
{
	channel->setVolume(volume);
}
void CSoundManager::ChannelStop(FMOD::Channel*& channel)
{
	channel->stop();
	soundSystem->update();
}