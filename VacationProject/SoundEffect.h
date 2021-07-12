#pragma once

class SoundEffect final
{
public:
	SoundEffect();
	SoundEffect(const string& soundFilePath, bool loop = false);
	SoundEffect(const SoundEffect&) = delete;
	SoundEffect& operator=(const SoundEffect&) = delete;
	~SoundEffect();
private:

	string filePath{};
	Sound* sounds = nullptr;
	SoundBuffer* soundBuffer = nullptr;

	float volume = 10.f;
	bool loop = false;

	map<string, Sound*> effectSound;
	map<string, SoundBuffer*> effectSoundBuffer;

	float effectVolume = 15.f;
private:
	void Init();
public:

	void Destroy();

	void AddEffectSound(const string& soundFilePath,const string& effectName);
	void EffectPlay(const string& effectName);
	void Play();
	void Pause();
	void Stop();

};

