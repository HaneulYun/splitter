#pragma once

#define g_pSoundManager	CSoundManager::Instance()

class CSoundManager
{
public:
	FMOD::System* soundSystem;
	std::deque<FMOD::Sound*> vSound;
	FMOD::ChannelGroup* channelGroup;
	FMOD::ChannelGroup* m_effectSoundChannel;
	FMOD::ChannelGroup* m_BGMChannel;

	FMOD::Channel* m_pChannel;

	static CSoundManager* instance;
public:
	CSoundManager();
	~CSoundManager();

	void Initialize();
	void Pulse();
	void Pulse(FMOD::Channel*& channel, int tag);

	void SetVolume(FMOD::Channel*& channel, float volume);
	void ChannelStop(FMOD::Channel*& channel);

	static CSoundManager* Instance()
	{
		if (instance == nullptr)
			instance = new CSoundManager;
		return instance;
	}
};

