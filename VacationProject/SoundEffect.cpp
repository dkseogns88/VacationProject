#include "framework.h"
#include "SoundEffect.h"

SoundEffect::SoundEffect()
{
	Init();
}

SoundEffect::SoundEffect(const string& soundFilePath, bool loop)
	:filePath(soundFilePath),loop(loop)
{
	Init();
}

SoundEffect::~SoundEffect()
{
	
}

void SoundEffect::Init()
{
	sounds = new Sound;
	soundBuffer = new SoundBuffer;
	if (!soundBuffer->loadFromFile(filePath))
	{
		cout << "not load sound" << filePath << endl;
	}

	sounds->setBuffer(*soundBuffer);
	sounds->setVolume(this->volume);
	sounds->setLoop(this->loop);
}

void SoundEffect::Play()
{
	sounds->play();
}

void SoundEffect::Pause()
{
	sounds->pause();
}

void SoundEffect::Stop()
{
	sounds->stop();
}
void SoundEffect::Destroy()
{
	DELETE(sounds);
	DELETE(soundBuffer);
	for (auto& s : effectSound)
	{
		DELETE(s.second);
	}

	effectSound.clear();
	for (auto& sb : effectSoundBuffer)
	{
		DELETE(sb.second);
	}
	effectSoundBuffer.clear();

}

void SoundEffect::AddEffectSound(const string& soundFilePath, const string& effectName)
{
	effectSound[effectName] = new Sound;
	effectSoundBuffer[effectName] = new SoundBuffer;

	if (!effectSoundBuffer[effectName]->loadFromFile(soundFilePath))
	{
		cout << "not load sound" << soundFilePath << endl;
	}

	effectSound[effectName]->setBuffer(*effectSoundBuffer[effectName]);
	effectSound[effectName]->setVolume(effectVolume);
	effectSound[effectName]->setLoop(false);
}

void SoundEffect::EffectPlay(const string& effectName)
{
	effectSound[effectName]->play();
}
